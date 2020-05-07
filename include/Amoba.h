#ifndef AMOBA_H
#define AMOBA_H

#include <Widget.h>


class Amoba : public Widget
{
    public:
        Amoba(int,int,int,int,int);
        virtual ~Amoba();
        virtual void rajzol();
        virtual void event_handle(const genv::event&);
    protected:

    private:
        int palya_meret;
};

#endif // AMOBA_H
