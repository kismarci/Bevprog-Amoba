#include "Widget.h"
using namespace genv;

Widget::Widget(int x, int y, int w, int h):
    left(x),
    top(y),
    sizex(w),
    sizey(h){}

Widget::~Widget(){}

bool Widget::is_selected(const int& mx, const int& my){
    if(mx > left && mx < left+sizex && my > top && my < top+sizey){
        focus = true;
        return true;
    }
    return false;
}

void Widget::update(){}
void Widget::unfocus(){
    focus=false;
}
void Widget::kijelol(const int& mx, const int& my){}

void Widget::move_widget(const int& evx, const int& evy, const int &mx,const int& my){
    if(holding){
        left = std::min(std::max(0,evx-mx), X-sizex-1);
        top = std::min(std::max(0,evy-my), Y-sizey-1);
    }
}

std::string Widget::get_value(){}

