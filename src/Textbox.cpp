#include "Textbox.h"
using namespace genv;

Textbox::Textbox(int a, int b, int sx, int sy, std::string d) : Widget(a,b,sx,sy), data(d){}

Textbox::~Textbox(){}

void Textbox::rajzol(){
    gout << color(102,102,153) << move_to(left,top) << box(sizex, sizey);
    int offsetx = sizex/10, offsety = sizey/10;
    gout << color(163,163,194) << move_to(left+offsetx,top+offsety) << box(sizex-offsetx*2, sizey-offsety*2);
    int tsize = gout.twidth(data);
    gout << color(0, 0, 0) << move_to(left+(sizex/2 - tsize/2), top+sizey/2+gout.cdescent()) << text(data);
}


void Textbox::event_handle(const event& e){}
