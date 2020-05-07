#ifndef TEXT_INPUT_H
#define TEXT_INPUT_H

#include <Textbox.h>


class Text_input : public Textbox
{
    public:
        Text_input() = delete;
        Text_input(int, int, int, int, std::string="");
        virtual ~Text_input();

        virtual void rajzol();
        void event_handle(const genv::event&);
        void update();
        void unfocus();
    protected:

    private:
        bool deleting=false;
        int time_counter = 30;
};

#endif // TEXT_INPUT_H
