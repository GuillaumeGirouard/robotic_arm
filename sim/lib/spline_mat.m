function [A,b] = spline_mat(t,f, v0)
k = length(t);
A = eye(k);
b = zeros(k,1);
h = zeros(k,1);
t = [t 0];
a = 1:k;
a(1) = v0;
for i=1:k
    h(i) = t(i+1)-t(i);
    for j=1:k
        if i==j
                if i == 1
                    A(i,j) = 2*h(i);
                elseif i == k
                    A(i,j) = 2*h(i-1);
                else
                     A(i,j) = 2*(h(i-1) + h(i));
                end
        elseif i == j+1 || j == i+1
              A(i,j) = h(min(i,j));
        else
            A(i,j) = 0;
        end
    end
end
end


