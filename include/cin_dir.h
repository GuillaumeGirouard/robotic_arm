#include"matrice.h"
#include<fstream>

using namespace std;

class CinDir{
    public:
        CinDir();
        ~CinDir();
        void init();
        Matrice calcForwCin(vector<double> angles);
        Matrice Rot(double angle, char axe, vector<double> pos);
        Matrice Trans(double trans, char axe, vector<double> pos);
    private:
        Matrice* cin_dir_;
        vector<double> angles_;
};