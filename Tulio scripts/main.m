%% Main script to do a PID controller for the linear pendulum
clear all
clc
close all

%% PARAMETERS
m=135.4e-3; % Pendulum mass
M=879.5e-3; % Cart
kp=20;
kd=10;
lb=141.451e-3; % Distance from the pin to the bar
tet0=pi/6; % initial condition
tetp0=0;
g=9.81; 
Va=0;
Ra=3.92;
Jm=3.1e-7;
Jp=1774.274e-6; % Inertia of the pendulum to the center of mass
r=0.01; % Damping of the cart
rt=0.01; % Rotational damping
Rg=(13.55+11.04)/4; % Gear's radius of the motor
Kf=7.44e-3; % Kphi
La=35e-6; %H
% Constantes do tulio

%% COMPUTING THE MATRICES
%z = [xp x thetap theta Ia]
MA=[M+m+Jm/Rg^2 0 m*lb 0 0; 0 1 0 0 0; m*lb 0 Jp+m*lb^2 0 0; 0 0 0 1 0;0 0 0 0 1]; %multipling Zp
N=[-r 0 0 0 Kf/Rg;1 0 0 0 0;0 0 -rt -m*g*lb 0;0 0 1 0 0;-Kf/Rg/La 0 0 0 -Ra/La]; %multipling Z
P=[0;0;0;0;1/Ra]; % multipling Va
Minv=inv(M);
A=(Minv*N);  B=Minv*P;
C=[0 0 0 1 0];
D = [];
sys = ss(A,B,C,D);
[V,D] = eig(A);
eigenvalues = diag(D);

%% EVALUATE EQUILIBRIUM POSITION FOR NON-LINEAR
%pend_nonlin(z,Mc,Mp,Jp,Jm,lp,Beq,Bp,Kg,Kphi,Rg,g,Ra,La,Va)
