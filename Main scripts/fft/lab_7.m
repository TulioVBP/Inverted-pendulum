close all; clear all; clc;
f=440;
fsamp=5000;
dt=1/fsamp;
N=10000;
t=0:dt:(N-1)*dt;
data=sin(2*pi*f*t);
%soundsc(y,fsamp)
figure
plot(t,data)
title('time history')
% building fourier transform
T=N*dt;
f1=1/T;
fmax=(fsamp/2);
if fmax==floor(fsamp/2)
    disp('ok')
end

y=[];

for k=1:N
    e=exp(-2*i*pi*k*[1:N]/N);
    y(k)=(data*e');
end
y=y(1:N/2);
y(1)=y(1)/N;
y(2:N/2-1)=y(2:N/2-1)*2/N;
y(N/2)=y(N/2)/N;
figure
freq=0:f1:fmax-f1;
subplot(2,1,1)
plot(freq,abs(y))
subplot(2,1,2)
plot(freq,angle(y))
y=abs(fft(data));
yph=angle(fft(data));
figure
subplot(2,1,1)
plot(freq,2*y(1:N/2)/N)
subplot(2,1,2)
plot(freq,2*yph(1:N/2)/N)