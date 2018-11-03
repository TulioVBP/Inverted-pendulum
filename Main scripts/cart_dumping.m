clear all; close all; clc


p1=0.0035;
p2=0.0058;
dxp=0.001;
xp=0:dxp:0.5;
r_eq=p1+p2./xp;
figure(1)
plot(xp,r_eq);
grid on; hold on

xp=-0.5:0.001:0.5;
f=2*p2/pi*atan(100*xp)+p1*xp;
r_eq=f./xp;
r_eq(501)=2*p2/pi*100+p1;
plot(xp,f,xp,r_eq)


r_eq=r_eq(501:end);
xp=xp(501:end);

plot(xp,p1.*xp+p2)
plot(-xp,-p1.*xp-p2)
    
    