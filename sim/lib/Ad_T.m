function [Ad] = Ad_T(T)
%Ad_T calcul ladjoite de la matrice T
%
R = T(1:3,1:3); %partie rotation de la matrice de transformation T
t = T(1:3,4); %position de la matrice de transformation T
t_x = [0 -t(3) t(2);
      t(3) 0 -t(1);
     -t(2) t(1) 0]; %matrice anti-symetrique de t pour la produit vect
Ad = [R zeros(3);t_x*R R]; %definition de ladjointe
end

