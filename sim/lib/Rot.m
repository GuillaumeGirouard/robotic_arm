function [T] = Rot(Q,w,theta)
%calcul la matrice de transformation resultant d'une rotation autour d'un
%axe w situé a un point Q de theta radiant

w_x = [0 -w(3) w(2); w(3) 0 -w(1); -w(2) w(1) 0];
R = eye(3) + sin(theta).*w_x +(1-cos(theta)).*(w_x*w_x);
p = (eye(3)-R)*Q;
T = [R(1,:) p(1); 
     R(2,:) p(2); 
     R(3,:) p(3);
     0 0 0 1];
end

