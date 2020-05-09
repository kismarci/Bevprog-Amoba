#ifndef JATEKMESTER_H
#define JATEKMESTER_H
#include <Amoba.h>
#include <vector>
class Amoba;///forward declaration to deal with cyclic dependency

class JatekMester
{
    public:
        JatekMester(Amoba*);
        //virtual ~JatekMester();
        int szamlalo(const int*, int);
    protected:

    private:
        Amoba *amb;
        int in_line_counter;
        void find_row(const int*, int);
        void find_col(const int*, int);
        void find_diag(const int*,int);
        void dontetlen(const int*,int);
        int allas;

};

#endif // JATEKMESTER_H
