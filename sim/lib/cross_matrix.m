function [w_x] = cross_matrix(w)
%sort la matrice de produit vectorielle
w_x = [0 -w(3) w(2); w(3) 0 -w(1); -w(2) w(1) 0];
end

