#include "game.h"

void menu()
{

    int x,y,startgame=0,q=0;

    readimagefile("menunn.bmp",0,0,1300,700);
    while(1)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if((x>415 && x<825) && (y>130 && y<195)) //enter in new game
        {
            readimagefile("menu1.bmp",0,0,1300,700);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                startgame=1;
                break;
            }
        }

        else  if((x>415 && x<835) && (y>217 && y<280)) //high score show
        {
            readimagefile("menu2.bmp",0,0,1300,700);
            if(ismouseclick(WM_LBUTTONDOWN))
            {


                int i=1,pnt,j=250;
                char name[100],scr[20];
                initwindow(1300,700,"HIGH SCORE");
                setbkcolor(CYAN);
                setfillstyle(1,CYAN);
                floodfill(10,10,WHITE);
                readimagefile("highscorer.gif",150,50,1150,150);
                setcolor(RED);
                settextstyle(1,HORIZ_DIR,4);
                outtextxy(250,200,"NAME");
                outtextxy(800,200,"SCORE");
                setcolor(BLACK);
                FILE *fr;
                fr=fopen("highscore.txt","r");
                while(i<11)
                {
                    fscanf(fr,"%[^\n]",name);
                    fscanf(fr,"%d ",&pnt);
                    sprintf(scr,"%d",pnt);
                    outtextxy(250,j,name);
                    outtextxy(800,j,scr);
                    j+=40,i++;
                }
                fclose(fr);




                readimagefile("back.gif",20,50,100,120);

                while(1)
                {

                     clearmouseclick(WM_LBUTTONDOWN);


                    if((mousex()>28 && mousex()<95)&& (mousey()>52 && mousey()<114))
                    {
                        readimagefile("back.gif",0,20,150,150);
                        if(ismouseclick(WM_LBUTTONDOWN))
                        {
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                        q=1;

                    }
                    else
                    {
                        if(q==1)
                        {
                        setcolor(CYAN);
                        setfillstyle(1,CYAN);
                        fillellipse(75,75,75,75);
                        readimagefile("back.gif",20,50,100,120);
                        q=0;
                        }
                        else
                        {
                           readimagefile("back.gif",20,50,100,120);

                        }

                    }

                }

            }
        }

        else  if((x>415 && x<605) && (y>300 && y<375)) //help
        {
            readimagefile("menu3.bmp",0,0,1300,700);
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                readimagefile("help1.bmp",0,0,1300,700);
                while(1)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    if((mousex()>119 && mousex()<265)&& mousey()>35 && (mousey()<70))
                    {
                        readimagefile("help2.bmp",0,0,1300,700);
                        if(ismouseclick(WM_LBUTTONDOWN))
                        {
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }

                    }
                    else
                        readimagefile("help1.bmp",0,0,1300,700);
                }
            }
        }

        else  if((x>415 && x<690) && (y>390 && y<445)) //credits
        {
            readimagefile("menu4.bmp",0,0,1300,700);
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                readimagefile("credits.bmp",0,0,1300,700);
                while(1)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    if((mousex()>123 && mousex()<278)&& mousey()>55 && (mousey()<92))
                    {
                        readimagefile("credits1.bmp",0,0,1300,700);
                        if(ismouseclick(WM_LBUTTONDOWN))
                        {
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }

                    }
                    else
                        readimagefile("credits.bmp",0,0,1300,700);
                }
            }
        }

        else  if((x>415 && x<580) && (y>472 && y<530)) //exit
        {
            readimagefile("menu5.bmp",0,0,1300,700);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                readimagefile("thanks.jpg",0,0,1300,700);
                delay(1000);
                break;
            }
        }

        else
            readimagefile("menunn.bmp",0,0,1300,700);
    }
    if(startgame==1)
    {
       // setvisualpage(1);
        start_game();
        menu();
    }

}
