#include "../include/matrice.h"

using namespace std;

Matrice::Matrice(vector<vector<double>> values){
    values_ = values;
    size_.row = values.size();
    size_.col = values[1].size();
}
Matrice::Matrice(){
    size_.col=0;
    size_.row=0;
}
Matrice::~Matrice(){
}
Matrice Matrice::operator=(Matrice a){
    size_ = a.getSize();
    values_.clear();
    vector<vector<double>> vec;
    for(int i = 0; i<size_.row; i++){
        vector<double> temp;
        for(int j=0;j<size_.col; j++){
            temp.push_back(a(i,j));
        }
        vec.push_back(temp);
    }
    values_ = vec;
    vec.clear();
    return *this;
}

Size Matrice::getSize(){
    return size_;
}
double Matrice::det(){
    if(size_.col != size_.row || size_.row <2){
        cout << "cant calculate the det of non-square matrice or less than 2x2 matrice" << endl;
        exit(1);
    }
    double det = 0;
    // itere sur les colonnes de la matrice
    for(int i = 0; i<size_.col;i++){
        //si la matrice est 2x2, retourne a11*a22-a12*a21
        if(size_.row == 2){
            return values_[0][0]*values_[1][1] - values_[0][1]*values_[1][0];
        }
        //calcul le coefficiant de la ligne et le determinant de la matrice dont on enleve la ligne et colonne du coefficiant
        double signe = pow(-1,i)*values_[0][i];
         Matrice A = strip(0,i);
         det += signe*A.det();
    }
    return det;
}
Matrice Matrice::inv(){
    //verification de la possibilite dinversion de la matrice
    if(det() == 0){
        cout << "matrice non inversible" << endl;
        exit(1);
    }
    //algorithme inspire de linversion de Gauss-Jordan, donc une decente et une remonter des elements de la matrices:
    //initialise identity matrice:
    Matrice I = identity(size_.row);
    //met cote a cote la matrice a inverser et lidentite
    Matrice temp = *this|I;
    cout << "superpose Matrice" << endl << temp << endl;
    vector<Matrice> rows;
    //vecteur de matrice ligne possedant les lignes des matrices pour les operations
    for(int i=0; i<size_.row; i++){
        rows.push_back(temp(i,i,0,temp.getSize().col-1));
    }
    //descente:
    for(int n=0; n<size_.col-1; n++){
        rows[n] = rows[n]*(1/rows[n](0,n));
        for(int i=n+1; i<size_.row; i++){
            Matrice normalise = rows[n]*(rows[i](0,n)/rows[n](0,n));
            rows[i] = rows[i] - normalise;
        }
    }
    //normalisation de la derniere ligne
    rows[size_.col-1] = rows[size_.col-1]*(1/rows[size_.col-1](0,size_.col-1));
    //remonte:
    for(int n=size_.col-1; n>=0; n--){
        for(int i=n-1; i >=0 ; i--){
            Matrice normalise = rows[n]*(rows[i](0,n)/rows[n](0,n));
            rows[i] = rows[i] - normalise;
        }
    }
    //reconstruction matrice inverse
    vector<vector<double>> vec;
    for(int i=0; i<size_.row;i++){
        vector<double> t;
        for(int j=size_.col; j<rows[0].getSize().col;j++){
            t.push_back(rows[i](0,j));
        }
        vec.push_back(t);
    }
    //retourne la partie inverse
    cout << "return" << endl;
    return Matrice(vec);
}
Matrice Matrice::expm(){
    //formule de rodrigue
    return Matrice();
}
Matrice Matrice::identity(int size){
    vector<vector<double>> mat;
    vector<double> row;
    if(size < 1){
        row.push_back(1);
        mat.push_back(row);
        return Matrice(mat);
    }
    row.push_back(1);
    for(int i =0; i<size-1; i++){
        row.push_back(0);
    }
    mat.push_back(row);
    for(int i =1; i<size; i++){
        row[i-1] = 0;
        row[i]=1;
        mat.push_back(row);

    }
    return Matrice(mat);
}
Matrice Matrice::transpose(){
    vector<vector<double>> vec;
    for(int i = 0; i < size_.col; i++){
        vector<double> temp;
        for(int j = 0; j < size_.row; j++){
            temp.push_back(values_[j][i]);
        }
        vec.push_back(temp);
    }
    return Matrice(vec);
}

Matrice Matrice::operator|(Matrice& a){
    if(size_.row != a.getSize().row){
        cout << "impossible de joindre une matrice de nombre de ligne different" << endl;
        exit(1);
    }
    vector<vector<double>> vec = values_;
    for(int i = 0; i<size_.row; i++){
        for(int j =0; j<a.getSize().col;j++){
            vec[i].push_back(a(i,j));
        }
    }

    return Matrice(vec);
}
Matrice Matrice::operator*(Matrice& b){
    if(size_.col != b.getSize().row){
        cout<<"error, impossible de multiplier les matrices"<<endl;
        exit(1);
    }
    vector<vector<double>> vec;
    for(int i = 0; i<size_.row; i++){
        vector<double> temp;
        for(int j=0;j<b.getSize().col; j++){
            double acc_sum=0;
            for(int n=0; n<size_.col; n++){
                double coeff = values_[i][n]*b(n,j);
                acc_sum += coeff;
            }
            temp.push_back(acc_sum);
        }
        vec.push_back(temp);
    }
    return Matrice(vec);
}
Matrice Matrice::operator*(double scal){
    vector<vector<double>> vec;
    for(int i = 0; i<size_.row; i++){
        vector<double> temp;
        for(int j=0;j<size_.col; j++){
            temp.push_back(values_[i][j]*scal);
        }
        vec.push_back(temp);
    }
    return Matrice(vec); 
}
Matrice Matrice::operator*(int scal){
    Matrice temp = *this;
    return temp*double(scal);
}
Matrice Matrice::operator+(Matrice& a){
    if((size_.row != a.getSize().row) ||(size_.col != a.getSize().col) ){
        cout << "ne peut additionner des matrices de tailles différentes"<< endl;
    }
    vector<vector<double>> vec;
    for(int i = 0; i<size_.row; i++){
        vector<double> temp;
        for(int j=0;j<size_.col; j++){
            temp.push_back(values_[i][j] + a(i,j));
        }
        vec.push_back(temp);
    }
    Matrice ret = Matrice(vec);
    return ret;
}
Matrice Matrice::operator-(Matrice& a){
    if((size_.row != a.getSize().row) ||(size_.col != a.getSize().col) ){
        cout << "ne peut additionner des matrices de tailles différentes"<< endl;
    }
    vector<vector<double>> vec;
    for(int i = 0; i<size_.row; i++){
        vector<double> temp;
        for(int j=0;j<size_.col; j++){
            temp.push_back(values_[i][j] - a(i,j));
        }
        vec.push_back(temp);
    }
    Matrice ret = Matrice(vec);
    return ret;
}
double Matrice::operator()(int row, int col){
    return values_[row][col];
}
Matrice Matrice::operator()(int row_min,int row_max, int col_min, int col_max){
    vector<vector<double>> vec;
    for(int i =row_min; i<=row_max; i++){
        vector<double> temp;
        for(int j = col_min; j<=col_max; j++){
            temp.push_back(values_[i][j]);
        }
        vec.push_back(temp);
    }
    //probleme 1D matrice, met une couche de 0 pour debug probleme
    if(row_min == row_max || col_min == col_max){
        for(int i =row_min; i<=row_max; i++){
            vector<double> temp;
            for(int j = col_min; j<=col_max; j++){
                temp.push_back(0);
            }
            vec.push_back(temp);
        }
    }
    return Matrice(vec);
}
Matrice Matrice::strip(int row, int col){
    vector<vector<double>> vec;
    for(int i =0; i<size_.row; i++){
        if(i == row){continue;}
        vector<double> temp;
        for(int j = 0; j<size_.col; j++){
            if(j == col){continue;}
            temp.push_back(values_[i][j]);
        }
        vec.push_back(temp);
    }
    return Matrice(vec);
}
Matrice& Matrice::operator+=(Matrice& a){
    if((size_.row != a.getSize().row) ||(size_.col != a.getSize().col) ){
        cout << "ne peut additionner des matrices de tailles différentes"<< endl;
    }
    for(int i = 0; i<size_.row; i++){
        for(int j=0;j<size_.col; j++){
            values_[i][j] += a(i,j);
        }
    }
    return *this;

}
Matrice& Matrice::operator-=(Matrice& a){
    if((size_.row != a.getSize().row) ||(size_.col != a.getSize().col) ){
        cout << "ne peut additionner des matrices de tailles différentes"<< endl;
    }
    for(int i = 0; i<size_.row; i++){
        for(int j=0;j<size_.col; j++){
            values_[i][j] -= a(i,j);
        }
    }
    return *this;
}
Matrice& Matrice::operator*=(Matrice& a){
    if(size_.col != a.getSize().row){
        cout<<"error, impossible de multiplier les matrices"<<endl;
        exit(1);
    }
    for(int i = 0; i<size_.row; i++){
        vector<vector<double>> vec = values_;
        for(int j=0;j<a.getSize().col; j++){
            double acc_sum=0;
            for(int n=0; n<size_.col; n++){
                acc_sum += vec[i][n]*a(n,j);
            }
            values_[i][j] = acc_sum;
        }
    }
    return *this;
}
Matrice& Matrice::operator*=(double scal){
    for(int i = 0; i<size_.row; i++){
        for(int j=0;j<size_.col; j++){
            values_[i][j] *= scal;
        }
    }
    return *this;
}
Matrice& Matrice::operator*=(int scal){
    *this *= double(scal);
    return *this;
}

ostream& operator<<(ostream& os, Matrice& a){
    os << "Matrice :"<< endl;
    for(int i = 0; i<a.getSize().row; i++){
        os << "[|";
        for(int j=0;j<a.getSize().col; j++){
            double coeff = a(i,j);
            if(abs(coeff) < 1e-14){
                coeff = 0;
            }
            os << coeff << "|";
        }
        os << "]" << endl;
    }
    return os;

}
Matrice operator*(double scalar, Matrice& a){
    return a*scalar;
}
Matrice operator*(int scalar, Matrice& a){
    return a*double(scalar);
}