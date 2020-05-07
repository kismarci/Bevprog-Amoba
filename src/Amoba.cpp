#include "Amoba.h"
using namespace genv;

Amoba::Amoba(int x, int y, int w, int h, int n) : Widget(x,y,w,h), palya_meret(n)
{
}

Amoba::~Amoba()
{
    //dtor
}

void Amoba::rajzol(){
    int boarderx = 2, boardery = 2;
    gout << color(100,100,100)<< move_to(left,top) << box(sizex, sizey);
    gout << color(120,120,180) << move_to(left+boarderx,top+boardery) << box(sizex-boarderx*2, sizey-boardery*2);
    int lepes=(int)X/palya_meret;
    for(int i=1;i<palya_meret;i++){
        gout<<color(0,0,0)<<move_to(i*lepes,0)<<line(0,Y-1);
        gout<<color(0,0,0)<<move_to(0,i*lepes)<<line(X-1,0);
    }
}

void Amoba::event_handle(const event& e){}
