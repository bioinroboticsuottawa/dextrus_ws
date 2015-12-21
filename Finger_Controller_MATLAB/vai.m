 function [g,t]=vai(grau,a)

encoderReset(a,0);
pause(0.01);
pos_atual=0;
n=38*grau;
erro=n-pos_atual;
g=pos_atual;
c=0;
I=0;
t=0;
pinMode(a,2,'output');

while(abs(erro)>max([0.005*abs(n),5]))
    k=tic;
    P=erro*0.014328;
    I=I+erro*0.0012082*c;
%     P=erro*0.0094095;
%     I=I+erro*0.00052423*c;
    PI=(P+I);
    if and(PI<1,PI>0)
       PI=1;
    elseif and(PI>-1,PI<0)
       PI=-1;
    elseif (PI<-145)
       PI=-110;
    elseif (PI>145)
       PI=110;
    end
    if (sign(PI)==1)
        digitalWrite(a,2,0);
        pause(0.001);
    end
    if (sign(PI)==-1)
        digitalWrite(a,2,1);
        pause(0.001);
    end
    PI
    analogWrite(a,3,abs(round(PI)));
    pause(0.001);
    pos_atual=encoderRead(a,0);
    pause(0.03);
    erro=n-pos_atual;
    g=[g,pos_atual];
    c=toc(k);
    t=[t,t(length(t))+c];
    %   

end
for i=1:10
k=tic;
g=[g,encoderRead(a,0)];
pause(0.03)
t=[t,t(length(t))+toc(k)];
analogWrite(a,3,0);
end
 end