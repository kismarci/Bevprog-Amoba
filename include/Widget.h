#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"
#include "vector"
#define X 600
#define Y 600
class Widget
{
    public:
        Widget() = delete;
        Widget(int, int, int, int);
        virtual ~Widget();
        virtual void rajzol() = 0;
        virtual void event_handle(const genv::event&) = 0;
        virtual void kijelol(const int&, const int&);
        virtual bool is_selected(const int&, const int&);
        virtual void unfocus();
        virtual void move_widget(const int&, const int&, const int&, const int&);
        virtual std::string get_value();
    protected:
        int left, top, sizex, sizey;
        bool focus = false;
        bool holding=false;
};
#endif // WIDGET_H
