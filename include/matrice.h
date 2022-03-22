#ifndef MATRICE_H
#define MATRICE_H
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct Size{
    unsigned int row;
    unsigned int col;
};


class Matrice{
    public:
        Matrice(vector<vector<double>> values);                                 // fonctionne
        Matrice();                                                              // fonctionne
        ~Matrice();                                                             // fonctionne
        Matrice operator=(Matrice a);                                           // fonctionne

        Matrice operator*(Matrice& b);                                          // fonctionne
        Matrice operator*(double scal);                                         // fonctionne
        Matrice operator*(int scal);                                            // fonctionne
        friend Matrice operator*(double scalar, Matrice& a);                    // fonctionne
        friend Matrice operator*(int scalar, Matrice& a);                       // fonctionne
        friend ostream& operator<<(ostream& os, Matrice& a);                    // fonctionne
        Matrice operator+(Matrice& a);                                          // fonctionne
        Matrice operator-(Matrice& a);                                          // fonctionne
        double operator()(int row, int col);                                    // fonctionne
        Matrice operator()(int row_min,int row_max, int col_min, int col_max);  //fonctionne
        Matrice operator|(Matrice& a);                                          // fonctionne
        Matrice& operator+=(Matrice& a);                                        // fonctionne
        Matrice& operator-=(Matrice& a);                                        // fonctionne
        Matrice& operator*=(Matrice& a);                                        // fonctionne
        Matrice& operator*=(int scal);                                          // fonctionne
        Matrice& operator*=(double scal);                                       // fonctionne
        //autre idee: operrateur ^ et ^=, operateur |=, logm, solve, pseudo_inv
        double det();                                                           // fonctionne
        Size getSize();                                                         // fonctionne
        Matrice inv();                                                          // fonctionne
        Matrice identity(int size);                                             // fonctionne             
        Matrice expm();
        Matrice transpose();                                                    // fonctionne
        Matrice strip(int row, int col);                                        // fonctionne

    private:
        Size size_;
        vector<vector<double>> values_;
};

#endif