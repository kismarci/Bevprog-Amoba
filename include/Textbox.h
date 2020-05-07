#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <Widget.h>


class Textbox : public virtual Widget ///Virtu�lis �r�kl�d�s
{
    public:
        Textbox() = delete;
        Textbox(int, int, int, int, std::string);
        virtual ~Textbox();
        virtual void rajzol();
        virtual void event_handle(const genv::event& e);

    protected:
        std::string data;
    private:
};

#endif // TEXTBOX_H
