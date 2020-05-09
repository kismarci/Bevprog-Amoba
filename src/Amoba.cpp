#include "Amoba.h"
#include <string.h>
using namespace genv;

Amoba::Amoba(int x, int y, int w, int h, int n, JatekMester *jj, int(JatekMester::*f)(const int*, int)) : Widget(x,y,w,h), palya_meret(n)
{
    kijelolt=new int[palya_meret*palya_meret];
    valasztott=new int[palya_meret*palya_meret];
    memset(kijelolt, 0, palya_meret*palya_meret*sizeof(int));
    memset(valasztott, 0, palya_meret*palya_meret*sizeof(int));
    lepeskoz=(int)X/palya_meret;
    jatekos=true;///true ha az elso, false ha masodik jatekos kovetkezik
    jm=jj;
    amoba_func=f;
}

Amoba::~Amoba()
{
    //dtor
}

void Amoba::rajzol(){
    int boarderx = 2, boardery = 2;
    gout << color(100,100,100)<< move_to(left,top) << box(sizex, sizey);
    gout << color(120,120,180) << move_to(left+boarderx,top+boardery) << box(sizex-boarderx*2, sizey-boardery*2);
    for(int j=0;j<palya_meret;j++){
        gout<<color(0,0,0)<<move_to((j+1)*lepeskoz,0)<<line(0,Y-1);///elvalaszto vonalak kirajzolasa
        gout<<color(0,0,0)<<move_to(0,(j+1)*lepeskoz)<<line(X-1,0);
        for(int i=0;i<palya_meret;i++){
                if(kijelolt[j*palya_meret+i]==1){
                    gout<<color(100,100,200)<<move_to(i*lepeskoz+1,j*lepeskoz+1)<<box(lepeskoz-1,lepeskoz-1);///+1, -1 csak azert, hogy latszodjanak a vonalak mikozben az eger a kocka folott van
                }
                if(valasztott[j*palya_meret+i]==1){
                    gout<<color(50,50,50)<<move_to(i*lepeskoz+1,j*lepeskoz+1)<<box(lepeskoz-1,lepeskoz-1);
                }
                if(valasztott[j*palya_meret+i]==-1){
                    gout<<color(150,150,150)<<move_to(i*lepeskoz+1,j*lepeskoz+1)<<box(lepeskoz-1,lepeskoz-1);
                }

            }
    }
}

void Amoba::event_handle(const event& e){
    if(focus && e.type == ev_mouse && e.button==btn_left){
        for(int j=0;j<palya_meret;j++){ ///oszlop index
            for(int i=0;i<palya_meret;i++){ ///sor index
                if(e.pos_x>(i)*lepeskoz && e.pos_x<(i+1)*lepeskoz && e.pos_y>j*lepeskoz && e.pos_y<(j+1)*lepeskoz){
                    if(valasztott[j*palya_meret+i]==0){///ha még üres a mezo
                        valasztott[j*palya_meret+i] = jatekos ? 1 : -1; ///elsõ->1, masodik->-1;
                        jatekos=!jatekos;
                        //printf("%i %i\n", i, j);
                    }
                }
            }
        }
        allas=(jm->*amoba_func)(valasztott, palya_meret);
    }
}

void Amoba::kijelol(const int& mx, const int& my){
    for(int j=0;j<palya_meret;j++){
            for(int i=0;i<palya_meret;i++){
                if(mx>(i)*lepeskoz && mx<(i+1)*lepeskoz && my>j*lepeskoz && my<(j+1)*lepeskoz){
                    kijelolt[j*palya_meret+i]=1;
                } else if(mx !=0 && my!=0){
                        kijelolt[j*palya_meret+i]=0;
                }
            }
    }
}
