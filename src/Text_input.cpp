#include "Text_input.h"

using namespace genv;

Text_input::Text_input(int a, int b, int sx, int sy, std::string d) : Textbox(a,b,sx,sy,d)
{}

Text_input::~Text_input()
{}

void Text_input::rajzol(){
    gout << (focus ? color(255,179,26) : color(102,102,153))<< move_to(left,top) << box(sizex, sizey);
    int offsetx = sizex/10, offsety = sizey/10;
    gout << color(163,163,194) << move_to(left+offsetx,top+offsety) << box(sizex-offsetx*2, sizey-offsety*2);
    int tsize = gout.twidth(data);
    std::string write = data + (time_counter < 15 ? "|" : "");
    gout << color(0, 0, 0) << move_to(left+(sizex/2 - tsize/2), top+sizey/2+gout.cdescent()) << text(write);
    //printf("%s /n", write.c_str());
}

void Text_input::event_handle(const event& e){
    if(focus && e.type == ev_key){
        if(e.keycode == key_backspace){
            deleting = true;
        }else if(e.keycode == -key_backspace){
            deleting = false;
        }else if(e.keycode > 0){
            data += static_cast<char>(e.keycode);
        }
    }
}

void Text_input::update(){
    if(focus){
        //printf("%i\n",time_counter);
        --time_counter;
        if(deleting && time_counter % 4 == 0 && data != ""){ ///A 8 update csak "érzésre" lett kiválasztva
            data.erase(data.size()-1);
        }
        if(time_counter == 0) time_counter = 30;
    }
}

void Text_input::unfocus(){
    focus = false;
    deleting = false;
    time_counter = 30;
}
