#include"matrice.h"
#include<fstream>

using namespace std;

class CinDir{
    public:
        CinDir();
        ~CinDir();
        void init();
        Matrice calcForwCin(vector<double> angles);

    private:
        Matrice* cin_dir_;
        vector<double> angles_;
};