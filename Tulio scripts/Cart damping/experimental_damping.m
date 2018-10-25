%% Script to recover data
clear all;clc;close all;

%% Loading data - Long way cart
cart = [];
N = 5; % Number of data text files
for ii = 1:N
    filename = "cart" + int2str(ii) + ".txt";
    data = load(filename);
    if ii ~= 1 && length(data) ~= size(cart,1)
       difer = length(data) - size(cart,1);
       if difer > 0 
            cart = [cart; -1*ones(difer,size(cart,2))];
       else
           data = [data;-1*ones(-difer,size(data,2))];
       end
    end
    cart = [cart data(:,2)];
end
    
Rg=6.35; % Radius of the gear (mm)
g=9.81;

cart = cart*(2*pi*Rg)/2048; % Steps to mm

fs = 100; % Hz
dt = 1/fs;
% Time vectors
time= 0:dt:(length(cart)-1)*dt;
figure
ylabel('Cart displacement [mm]')
xlabel('Time [s]')
for ii = 1:N
    plot(time(cart(:,ii)>=0),cart(cart(:,ii)>=0,ii));
    hold on
end

%% Choosing the sampling points
sampling_points = zeros(size(cart));
for jj = 1:N
    for ii = 2:size(cart,1)-1
        dx_back = cart(ii,jj) - cart(ii-1,jj);
        dx_forward = cart(ii+1,jj) - cart(ii,jj);
        if cart(ii,jj) > 0 && dx_back > 1e-10 && dx_forward > 1e-10
            sampling_points(ii,jj) = 1;
        end
    end
end

% Ploting
for ii = 1:N
    plot(time(sampling_points(:,ii) == 1),cart(sampling_points(:,ii) == 1,ii),'pr');
    hold on
end
grid on

%% Velocity evaluation
figure
for choice = 1:N
    %choice = 1;
    % Calculate the velocity curve
    x = cart(sampling_points(:,choice) ==1,choice);
    t = time(sampling_points(:,choice) ==1);
    t = t - min(t);
    v = diff(x)./diff(t); 

    plot(t,x)
    hold on
    grid on
end
xlabel('t [s]')
ylabel('Velocity [mm/s]')
    