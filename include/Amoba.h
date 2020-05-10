#ifndef AMOBA_H
#define AMOBA_H
#include <Widget.h>
#include <functional>
//class JatekMester; ///ez a cyclic dependendy megoldasahoz kellett
#include <JatekMester.h>
#include <Button.hpp>
#include <Textbox.h>

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
        int allas=0;
        int eredmeny_kezeles();
        void draw_x();
        void draw_o(int, int);
        Textbox *new_game;
};

#endif // AMOBA_H
