#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include <Textbox.h>
#include <functional>
#include <iostream>


template <class T> ///templatos osztaly, egy forditasi egysegben kell legyen, a T a konstruktorban derul ki, hogy milyen class
class Button : public Textbox{
public:
    Button() = delete;
    Button(int, int, int, int, std::string, T*, void (T::*)());
    virtual ~Button();
    void rajzol();
    void handle(const genv::event& e);
protected:
private:
    T* parent;
    void (T::*btn_func)();///tagfuggveny pointer, a File_display egy tagfgv-re fog mutatni
};

template <class T>
Button<T>::Button(int a, int b, int sx, int sy, std::string data, T* p, void (T::*bf)()) : Textbox(a,b,sx,sy,data), parent(p), btn_func(bf){}

template <class T>
Button<T>::~Button(){}

template <class T>
void Button<T>::rajzol(){
    Textbox::rajzol();
}

template <class T>
void Button<T>::handle(const genv::event& e){
    if(is_selected(e.pos_x, e.pos_y) && e.button == genv::btn_left){
        (parent->*btn_func)();
    }
}

#endif // BUTTON_HPP_INCLUDED
