close all; clear all; clc;
data=load('data3.txt');
voltage=data(:,3);
fsamp=100;
dt=1/fsamp;
N=length(data(:,3));

t=0:dt:(N-1)*dt;

index=find(t>11);
t=t(index);
voltage=voltage(index);
N=length(voltage);

figure
plot(t,voltage)
title('time history')
% building fourier transform
T=N*dt;
f1=1/T;
fmax=(fsamp/2);
if fmax==floor(fsamp/2)
    disp('ok')
end

nfft=2^(nextpow2(2*N))
voltage_f=fft(voltage,nfft);
v_f=voltage_f(1:N/2+1);
v_f(1)=v_f(1)/N;
v_f(2:N/2)=v_f(2:N/2)*2/N;
v_f(N/2+1)=v_f(N/2+1)/N;

figure
plot([1:N/2+1]*1/T,abs(v_f))

