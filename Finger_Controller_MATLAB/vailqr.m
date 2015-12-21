function [x_d,t,contr,pos]=vailqr(n,a,A,B,C,D,Q,R,R0)
% Este programa controla o dedo da mão Dextrus através de um controlador
% LQR e com feedback de trajetória (time-varying LQR).
% A função aqui descrita recebe como parâmetros:
%                               n---> posição para qual o dedo vai
%                               a---> objeto do arduino (A contagem do
%                               encoder é feita por um arduino)
%                               A, B, C, D---> matrizes do modelo
%                               State-Space do dedo-motor
%                               Q, R---> matrizes da função custo-quadrático a
%                               ser minimizado (x^T*Q*x+u^T*R*u)
%                               R0---> análogo ao R acima, porém do
%                               controlador que uso para ajuste fino
%  
%  A=[0   1.000000000000000;
%  -44.229243700000019 -13.487281383990414] 
%  
% B=1.0e+03 *
%   [-0.025940195286963;
%    4.789845165687892]
% 
% C=[1 0]  D=0;
% 
% Q= 1.0e-09 *
%    [0.398000000000000                   0;
%                    0   0.000005000000000]
% R=8e-9; R0=5.9e-8;


 
% encoderReset(a,0);
% pause(0.03);
pos_atual=0;
g=pos_atual;
pos_ant=pos_atual;
[K,S]=lqr(A,B,Q,R);
[K0,S0]=lqr(A,B,Q,R0);
N=1/dcgain(A-B*K,B,C,D);
c=0.00001;
t=0;
S(:,:,100)=diag([0 0]);
% S(:,:,100)=Q;
Ktv(:,:,100)=R\B'*S(:,:,100);
u=n*ones(100,1);
tau=0:9/99:9;
[y,tau,x_d]=lsim(ss(A-B*K,B*N,C,D),u,tau);
yd=[0;diff(x_d(:,1))/(1/11)];
% u_d=-K*[x_d(:,1)-n*ones(length(x_d(:,1)),1), x_d(:,2)]';
% x_d(:,2)=yd;
u_d=-K*x_d'+n*N;

for j=99:-1:1
    [Ktv(:,:,j),S(:,:,j)]=lqr(.01*A-[1,0;0,1],B,.01*Q+S(:,:,j+1),100*R);
end

pinMode(a,2,'output');
pos=[0 0];
contr=0;
k_l=tic;
while (toc(k_l)<7)
    
    pos_atual=encoderRead(a,0);
    pause(0.01);
    k=tic;
    fprintf('pos_atual=%d\n',pos_atual);
%        x=[pos_atual (pos_atual-pos_ant)/c]';
        x=[pos_atual -0.003828*(pos_atual-pos_ant)/c+pos_atual*(0.213)]';
        toc(k_l)
        disp(x-x_d(find(tau>toc(k_l)-toc(k),1),:)');
        if toc(k_l)<1.8
        PI = u_d(find(tau>toc(k_l)-toc(k),1))-R\B'*S(:,:,find(tau>toc(k_l)-toc(k),1))*(x-x_d(find(tau>toc(k_l)-toc(k),1),:)')
        fprintf('x_d= %f , x= %f',x_d(find(tau>toc(k_l)-toc(k),1),2),x(2,1));
        %             PI=-K*(x-x0)-R\B'*S(:,:,find(tau>toc(k_l),1))*(x-x_d(find(tau>toc(k_l),1)));
        else
            x0=[n;0.2854*n];
            PI=-K0*(x-x0)
        end
        % PI=u_d(find(tau>toc(k_l),1))-Ktv(:,:,find(tau>toc(k_l),1))*(x-x_d(find(tau>toc(k_l),1)));
        %     PI=-K*x+n*N;
        %     PI=-K*(x-x0);
        contr=[contr,PI];
        if and(PI<1,PI>0)
            PI=1;
        elseif and(PI>-1,PI<0)
            PI=-1;
        elseif (PI<-215)
            PI=-215;
        elseif (PI>215)
            PI=215;
        end
        if (sign(PI)==1)
            digitalWrite(a,2,0);
            pause(0.001);
        end
        if (sign(PI)==-1)
            digitalWrite(a,2,1);
            pause(0.001);
        end
        PI;
        analogWrite(a,3,abs(round(PI)));
        pause(0.001);
        erro=n-pos_atual;
        pos_ant=pos_atual;
        g=[g,pos_atual];
        c=toc(k);
        t=[t,t(length(t))+c];
        pos=[pos;x'];
        %
end

analogWrite(a,3,0);
% end
end