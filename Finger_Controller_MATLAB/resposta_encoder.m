x=0;
t=1;
T=0;
v=0;
passo=1;
encoderReset(a,0);
k=tic;
interv=50;
while(t<interv)
	
	if(t==1)
	analogWrite(a,3,195);
    pause(0.0001)
 	d=toc(k)
	end
	b=encoderRead(a,0);
	pause(0.015)
	x=[x,b];
	t=t+passo;
    c=toc(k);
	T=[T,c];
    v=[v,b-x(1,length(x)-1)];
end
analogWrite(a,3,0);

