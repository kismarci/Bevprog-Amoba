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


int main()
{
    Ablak Ablakom(X,Y);
    //widgetek.push_back(new Textbox(400,450,100,50,"static textb"));
    Ablakom.widgetek.push_back(new Text_input(400,450,100,50));

    Ablakom.run();
}
