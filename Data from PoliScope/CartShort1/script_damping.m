%% Script per ricuperare i dati

clear all;clc;close all;

data0 = load('data0000.txt');

Rg=6.35e-3;
g=9.81;

fs = 100; % Hz
dt = 1/fs;
data= [data0];
time= 0:dt:(length(data)-1)*dt;

% Treating data
cart = (2*pi/2048*Rg)*data(:,2);

figure(1)
plot(time,cart)
grid on
hold on


n=find(cart<=cart(end)-0.0001);

cart = cart(n);
time = time(n);

%cutting part of interest

x_old=cart;
xp_old=diff(x_old)/dt;

q = find(xp_old==max(xp_old));
x_old = x_old(q:end);

%filtering displacement

for ii=1:2
     for i= 1:length(x_old)-1
         x_1(i)= (x_old(i)+x_old(i+1))/2;
     end
     
     x_1(length(x_old))=x_old(end);

     x(1)=x_old(1);
     for i= 2:length(x_1)
         x(i)= (x_1(i)+x_1(i-1))/2;
     end

     x_old=x;
end
x=x_old;
xp_old = xp_old(q:end);




figure(2)
plot([q*dt:dt:(q+(length(xp_old)-1))*dt],xp_old)
grid on; hold on



for ii=1:2
     for i= 1:length(xp_old)-1
         xp_1(i)= (xp_old(i)+xp_old(i+1))/2;
     end
     
     xp_1(length(xp_old))=xp_old(end);

     xp(1)=xp_1(1);
     for i= 2:length(xp_1)
         xp(i)= (xp_1(i)+xp_1(i-1))/2;
     end

     xp_old=xp;
end

plot([q*dt:dt:(q+(length(xp)-1))*dt],xp)
title('velocities')

xpp_old=diff(x,2)/dt;

figure(3)
plot([q*dt:dt:(q+(length(xpp_old)-1))*dt],xpp_old)
grid on; hold on
fin_val=xpp_old(end);
for ii=1:5
     for i= 1:length(xpp_old)-1
         xpp_1(i)= (xpp_old(i)+xpp_old(i+1))/2;
     end
     
     xpp_1(length(xpp_old))=xpp_old(end);

     xpp(1)=xpp_1(1);
     for i= 2:length(xpp_1)
         xpp(i)= (xpp_1(i)+xpp_1(i-1))/2;
     end

     xpp_old=xpp;
end

plot([q*dt:dt:(q+(length(xpp)-1))*dt],xpp)
title('acceleration')

figure(1)
plot([q*dt:dt:(q+(length(x)-1))*dt],x,'linewidth',3)
title('data')
legend('original data','considered data')
figure(4)
plot([q*dt:dt:(q+(length(x)-1))*dt],x)
hold on; grid on
plot([q*dt:dt:(q+(length(xp)-1))*dt],xp)
plot([q*dt:dt:(q+(length(xpp)-1))*dt],xpp)

title('final x, x_p, x_p_p')
legend('x','x_p','x_p_p')
M=879.5e-3;
F_old = M*xpp;
F=F_old;

%ploting relationship between F and v
figure
plot(xp(1:end-1),F,'linewidth',1)
grid on
title('function F = f(v)')

%if we can assume a model similar to F = mu*M*g
xppav=sum(xpp)/length(xpp);
mu=xppav/g;



xpn=fliplr(xp);
m=find(xpn<=0.1549);

Fnf=fliplr(F);
Fn=Fnf(m);
xpn=xpn(m);

n=find(xpn>=0.02325);


Fn=Fnf(n);
xpn=xpn(n);

figure
plot(fliplr(xpn),fliplr(Fn))


