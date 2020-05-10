#ifndef ABLAK_HPP_INCLUDED
#define ABLAK_HPP_INCLUDED
#include "graphics.hpp"
#include "Widget.h"
using namespace genv;

class Ablak
{
    public:
        Ablak(int, int);
        std::vector<Widget*> widgetek;
        int run();
    private:
        void clear_window();
};

Ablak::Ablak(int x, int y){
    gout.open(X,Y);
    gout.load_font("LiberationSans-Regular.ttf",25);
}


void Ablak::clear_window(){
    gout << move_to(0,0) << color(200,200,200) << box(X-1, Y-1);
}

int Ablak::run(){
    Widget* selected = nullptr;
    event ev;
    gin.timer(30);
    while(gin >> ev && ev.keycode!=key_escape){
        if(ev.type == ev_mouse){
            if(ev.button == btn_left){
                if(selected){
                    selected->unfocus();
                }
                selected=nullptr;
                for(signed int i=widgetek.size()-1; i>=0;i--){
                    if(widgetek[i]->is_selected(ev.pos_x, ev.pos_y)){
                        selected=widgetek[i];
                        widgetek.erase(widgetek.begin()+i);
                        widgetek.push_back(selected);
                        break;
                    }
                }
            }
        }

        if(selected != nullptr){
            selected->event_handle(ev);
            selected->kijelol(ev.pos_x, ev.pos_y);
        }
        if(ev.type==ev_timer){
            clear_window();
            for(auto w : widgetek){
                w->rajzol();
            }
        }
        gout << refresh;
    }

    for(int i = 0; i < widgetek.size(); ++i){
        delete widgetek[i];
        widgetek[i] = nullptr;
    }
    return 0;
}


#endif // ABLAK_HPP_INCLUDED
