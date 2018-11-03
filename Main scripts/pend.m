clear all
close all
clc

global m
global M
global Jp

m=135.4e-3;
M=879.5e-3;
kp=20;
kd=2;
ki=10;
lb=141.451e-3;
tet0=pi/6;
tetp0=0;
g=9.81;
Ra=3.92;
Jm=3.1e-7;
Jp=1774.274e-6;
rt=3.2067e-04;
Rg=6.35e-3;
Kf=7.44e-3;
La=35e-6; %H
p1=0.0035;
p2=0.0058;
Va=0;



r1t=m*lb/(M+m+Jm/Rg^2)/(Jp+m*lb^2)*rt;
r2t=rt/(Jp+m*lb^2);
r1x_max=0.37/(M+m+Jm/Rg^2);
r2x_max=m*lb/(M+m+Jm/Rg^2)/(Jp+m*lb^2)*0.37;
k1t=m^2*lb^2*g/(M+m+Jm/Rg^2)/(Jp+m*lb^2);
k2t=m*g*lb/(Jp+m*lb^2);
km=Kf^2/Rg^2/Ra;

R=[r1x_max+km+kd -r1t+kd; -r2x_max+km+kd r2t+kd]
det_R=det(R)

K=[kp -k1t+kp; kp k2t+kp]
det_K=det(K)