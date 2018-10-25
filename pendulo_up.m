function zp = pendulo_up(z,Va,parameters,Mp,Mc,Jm,rm,lp,Ip,Ra,La,Kg,Kp,Beq,Bu,g)
%% Function to describe thae non-linear behaviour of the pendulum upwards
% z = {dxc,xc,dthetau,thetau,Ia}
A = [(Mp+Mc+Jm/rm^2) 0 Mp*lp*cos(z(4)) 0 0;
    0,1,0,0,0;
    Mp*lp*cos(z(4)) 0 (Mp*lp^2+Ip) 0 0;
    0 0 0 1 0;
    0 0 0 0 La
    ];
F = [Mp*lp*sin(z(4))*z(3)^2+Kg*Kp/rm*z(5) - Beq*z(1);
    Mp*lp*g*sin(z(4))-Bu*z(3);
    -Ra*Ia-Kg*Kp/rm*z(1)];
B = [0;0;0;0;1];
zp = A\(F + B*Va);
