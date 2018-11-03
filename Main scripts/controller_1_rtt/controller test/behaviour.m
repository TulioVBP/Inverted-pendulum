clear all
close all
clc

load('data01.txt');
load('data02.txt');
load('data03.txt');
F=100;
dt=1/F;

tv1=dt:dt:length(data01)/F;
tv2=dt:dt:length(data02)/F;
tv3=dt:dt:length(data03)/F;

figure(1)
subplot 331
plot(tv1,data01(:,1)); grid;
subplot 334
plot(tv2,data02(:,1)); grid;
subplot 337
plot(tv3,data03(:,1)); grid;

subplot 332
plot(tv1,data01(:,2)); grid;
subplot 335
plot(tv2,data02(:,2)); grid;
subplot 338
plot(tv3,data03(:,2)); grid;

subplot 333
plot(tv1,data01(:,3)); grid;
subplot 336
plot(tv2,data02(:,3)); grid;
subplot 339
plot(tv3,data03(:,3)); grid;