function [T] = Mat_DH(theta,d,a,apha)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
T = [cos(theta), -sin(theta)*cos(alpha), sin(alpha)*sin(theta), a*cos(theta);
    sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha), a*sin(alpha);
    0, sin(alpha), cos(alpha), d;
    0, 0, 0, 1];
end

