#include "graphics.hpp"
#include "time.h"
#include "stdlib.h"
#include <fstream>
#include "Widget.h"
//#include "Checkbox.h"
#include "Textbox.h"
#include "Text_input.h"
#include "Button.hpp"
#include "Ablak.hpp"
#include "Amoba.h"


int main()
{
    Ablak Ablakom(X,Y);
    //widgetek.push_back(new Textbox(400,450,100,50,"static textb"));
    Ablakom.widgetek.push_back(new Amoba(0,0,X-1, Y-1,15));

    Ablakom.run();
}
