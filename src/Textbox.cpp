#include "Textbox.h"
using namespace genv;

Textbox::Textbox(int a, int b, int sx, int sy, std::string d) : Widget(a,b,sx,sy), data(d){}

Textbox::~Textbox(){}

void Textbox::rajzol(){
    gout << color(80,80,80) << move_to(left,top) << box(sizex, sizey);
    int offsetx = 4, offsety = 4;
    gout << color(180,180,240) << move_to(left+offsetx,top+offsety) << box(sizex-offsetx*2, sizey-offsety*2);
    int tsize = gout.twidth(data);
    gout << color(0, 0, 0) << move_to(left+(sizex/2 - tsize/2), top+sizey/2+gout.cdescent()) << text(data);
}


void Textbox::event_handle(const event& e){}
