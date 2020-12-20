
#include<graphics.h>
#include"menu.h"


void opening_page()
{

    initwindow(1300,700,"Catch Eggs");
    setbkcolor(CYAN);
    readimagefile("1st.bmp",0,0,1300,700);
    delay(1000);
    readimagefile("press any key.bmp",0,0,1300,700);
    while(!kbhit())
    {

    }
    readimagefile("nl.bmp",0,0,1300,700);
    delay(1000);
    readimagefile("nl..bmp",0,0,1300,700);
    delay(1000);
    readimagefile("nl...bmp",0,0,1300,700);
    delay(1000);
    //closegraph(CURRENT_WINDOW);
    menu();
}


