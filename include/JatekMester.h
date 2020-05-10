#ifndef JATEKMESTER_H
#define JATEKMESTER_H
#include <vector>

class JatekMester
{
    public:
        JatekMester();
        //virtual ~JatekMester();
        int szamlalo(const int*, int);
    protected:

    private:
        void find_row(const int*, int);
        void find_col(const int*, int);
        void find_diag(const int*,int);
        void dontetlen(const int*,int);
        int allas;

};

#endif // JATEKMESTER_H
