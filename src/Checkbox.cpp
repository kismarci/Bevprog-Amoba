#include "Checkbox.h"
using namespace genv; ///Megjegyzés: Fejléc fájlba nem igazán szabad using namespace-t rakni, mert könnyen tud konfliktust okozni (lásd. videó). Forrásfájlba nyugodtan lehet rakni.

Checkbox::Checkbox(int a, int b, int sx, int sy):
    Widget(a,b,sx,sy)
    {}

Checkbox::~Checkbox(){}

void Checkbox::draw(){
    gout << color(102,102,153) << move_to(left,top) << box(sizex, sizey);
    int offsetx = sizex/10, offsety = sizey/10;
    gout << (checked ? color(51,51,77) : color(163,163,194)) << move_to(left+offsetx,top+offsety) << box(sizex-offsetx*2, sizey-offsety*2);
}

void Checkbox::handle(const event& e){
    if(e.type == ev_mouse && e.button == btn_left &&
    e.pos_x > left && e.pos_x < left+sizex && e.pos_y > top && e.pos_y < top+sizey){
        checked = !checked;
    }
}
