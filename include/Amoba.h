#ifndef AMOBA_H
#define AMOBA_H
#include <Widget.h>
#include <functional>
class JatekMester;
#include <JatekMester.h>

class Amoba : public Widget
{
    public:
        Amoba(int,int,int,int,int, JatekMester*, int(JatekMester::*)(const int*, int));
        virtual ~Amoba();
        virtual void rajzol();
        virtual void event_handle(const genv::event&);
        virtual void kijelol(const int&, const int&);
        int *valasztott;
        bool jatekos;
        int palya_meret;
    protected:

    private:
        int *kijelolt;
        int lepeskoz;
        JatekMester *jm;
        int(JatekMester::*amoba_func)(const int*, int);
        int allas;
};

#endif // AMOBA_H
