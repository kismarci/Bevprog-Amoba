#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <Widget.h>


class Checkbox : public Widget
{
    public:
        Checkbox() = delete;
        Checkbox(int, int, int, int);
        virtual ~Checkbox();
        void draw();
        virtual void handle(const genv::event&);

    protected:

    private:
        bool checked = false;
};

#endif // CHECKBOX_H
