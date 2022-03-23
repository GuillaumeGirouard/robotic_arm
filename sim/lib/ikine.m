function [q1, q2] = ikine(T)
dwe=1.7;
l3=2.3;
W = T([1 2 3],4)-dwe.*T([1 2 3],3);
d = [W(3) W(2) W(1)-l3];
%determination de q1
    theta5 = acos(T(1,3));
    theta6 = atan2(-T(1,2),T(1,1));
    theta4 = atan2(T(2,3),-T(3,3));
    q1 = [d,theta4,theta5,theta6];
%determination de q2
    theta5 = -acos(T(1,3));
    theta6 = atan2(T(1,2),-T(1,1));
    theta4 = atan2(-T(2,3),T(3,3));
    q2 = [d,theta4,theta5,theta6];

end

