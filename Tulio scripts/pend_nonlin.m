function zp = pend_nonlin(z,Mc,Mp,Jp,Jm,lp,Beq,Bp,Kg,Kphi,Rg,g,Ra,La,Va)
% z = [xcp xc thetap theta Ia]
xcp = z(1); xc = z(2); thetap = z(3); theta = z(4); Ia = z(5);
AA = [Mc+Mp+Jm*(Kg/Rg)^2,0,-Mp*lp*cos(theta),0,0;
      0,1,0,0,0;
      -Mp*lp*cos(theta),0,Jp+Mp*lp^2,0,0;
      0,0,0,1,0;
      0,0,0,0,1];
F = [-Mp*lp*sin(theta)*thetap^2 - Beq*xcp - Kg*Kphi/Rg*Ia;
     xcp;
     -Bp*thetap - Mp*lp*g*sin(theta);
     thetap;
     -Ra/La*Ia - Kg*Kphi/Rg/La*xcp;
    ];
B = [0;0;0;0;1/La];

zp = inv(AA)*F+B*Va;

end
