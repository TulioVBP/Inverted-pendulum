%% Script per ricuperare i dati

clear all;clc;close all;

data0 = load('data0000.txt');
data1 = load('data0001.txt');
data2 = load('data0002.txt');

Rg=17.5e-3;

fs = 100; % Hz
dt = 1/fs;
data= [data0; data1; data2];
time= 0:dt:(length(data)-1)*dt;

% Treating data
data(:,1)=360/2000*data(:,1);
pendulum = data(:,1); %degrees
cart = (360/2048*Rg)*data(:,2);

subplot 411
plot(time,pendulum)
hold on
subplot 412
plot(time,cart)


N=find(time==12.01);
%M=find(time==46.5);
M=4651;
data=data(N:M,:);
cart=cart(N:M,:);
time=time(N:M);

subplot 413
plot(time,data(:,1))
hold on
subplot 414
plot(time,cart)

[P,loc]= findpeaks(data(:,1),time,'MinPeakDistance',0.9);
subplot 413
plot(loc,P,'ro')
h=[];
for i=1:length(P)-1
    h(i)=log(P(i)/P(i+1))/2/pi;
end

h=h(find(h>=0.001));
h_av=sum(h)/length(h)
diffl=diff(loc);
tlap=diffl(end);

freq=2*pi/tlap;

om=2*pi*freq;

Jp=1774.274e-6;

r=2*Jp*om*h_av