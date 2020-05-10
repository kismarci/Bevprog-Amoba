#include "graphics.hpp"
#include "time.h"
#include "stdlib.h"
#include <fstream>
#include "Widget.h"
//#include "Checkbox.h"
//#include "Textbox.h"
//#include "Text_input.h"
#include "Ablak.hpp"
#include "Amoba.h"
#include "JatekMester.h"


int main()
{
    Ablak Ablakom(X,Y);
    JatekMester* jatek=new JatekMester();
    Amoba* amob=new Amoba(0,0,X-1, Y-1,15,jatek,JatekMester::szamlalo); ///5. parameter a palya merete
    Ablakom.widgetek.push_back(amob);
    Ablakom.run();
}
