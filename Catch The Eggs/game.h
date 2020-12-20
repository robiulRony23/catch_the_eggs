#include"end_game_cheak.h"

int e_c,h_p,point=0,level=1,life=3,endgame=0,page=0,gameplayed=0;
char a[5];


void life_bar()
{
    setcolor(RED);
    outtextxy(1050,100,"Life :");
    rectangle(1050,145,1260,205);
    rectangle(1040,135,1270,215);

    line(1115,145,1115,205);
    line(1125,145,1125,205);

    line(1185,145,1185,205);
    line(1195,145,1195,205);

    setfillstyle(1,RED);
    floodfill(1041,136,RED);

    floodfill(1116,146,RED);
    floodfill(1186,146,RED);

    if(life>=3)
    {
        readimagefile("life.jpg",1060,150,1110,200);
        readimagefile("life.jpg",1130,150,1180,200);
        readimagefile("life.jpg",1200,150,1250,200);
    }
    else if(life==2)
    {
        readimagefile("life.jpg",1060,150,1110,200);
        readimagefile("life.jpg",1130,150,1180,200);
    }
    else if(life==1)
    {
        readimagefile("life.jpg",1060,150,1110,200);
    }

}

void hen_add()
{
    if(h_p==0)
    {
        readimagefile("h2.jpg",200,0,300,100);
        readimagefile("h1.jpg",500,0,600,100);
        readimagefile("h1.jpg",800,0,900,100);
    }

    else if(h_p==1)
    {
        readimagefile("h1.jpg",200,0,300,100);
        readimagefile("h2.jpg",500,0,600,100);
        readimagefile("h1.jpg",800,0,900,100);
    }
    else if(h_p==2)
    {
        readimagefile("h1.jpg",200,0,300,100);
        readimagefile("h1.jpg",500,0,600,100);
        readimagefile("h2.jpg",800,0,900,100);
    }
}

void basket_add(int p)
{
    if(p>950)
        p=950;
    else if(p<50)
        p=50;
    readimagefile("basket.jpg",p-50,650,p+50,700);
}

void point_cheak()
{
    sprintf(a,"%d",point);
    outtextxy(1230,50,a);
    settextstyle(6,0,2);
    outtextxy(1050,50,"Total Points:");
}

void lay_egg( int yp )
{
    int c=e_c%6,xp;

    if(c==3)
        c=14;
    else if(c==1 ||c==4)
        c=11;
    else
        c=15;


    if(h_p==0)
    {
        xp=250;
    }

    else if(h_p==1)
    {
        xp=550;
    }
    else
        xp=850;

    if((xp-50<=mousex() && mousex()<=xp+50) && yp>=650)
    {
        if(c==14)
            point+=50;
        else if(c==15)
            point+=10;
        else if(c==11)
            point+=20;
    }


    else if(yp>=650)
    {
        life--;
        readimagefile("be.bmp",xp-50,650,xp+50,700);
    }
    else
    {
        setcolor(c);
        setfillstyle(SOLID_FILL,c);
        fillellipse(xp,yp,20,30);
        ellipse(xp,yp,0,0,20,30);
    }
    life_bar();
    point_cheak();

}

void red_egg()
{

}

void stoll_fall()
{

}


void level_cheak()
{
    if(point>=200 && level==1)
    {
        level=2;

        readimagefile("Level1c2.jpg",0,0,1000,700);
        setvisualpage(1);
        delay(1000);
        //  while(!kbhit())
        // {

        //}

    }
    else if(point>=500 && level==2)
    {
        level=3;
        readimagefile("Level2c2.jpg",0,0,1000,700);
        setvisualpage(1);
        delay(1000);
    }
    else if(point>1000)
    {
        endgame=1;
        readimagefile("com.jpg",0,0,1300,700);
        setvisualpage(1);
        delay(1000);
    }
}

void life_cheak()
{
    if(life==0)
    {
        endgame=1;
        readimagefile("gameover.jpg",0,0,1300,700);
        setvisualpage(1);
        delay(1000);
    }

}

void start_game()
{
    if(gameplayed)
        point=0,level=1,life=3,endgame=0,page=0;

    while(1)
    {

        h_p=(rand()%373)%3;
        e_c=(rand()%127);
        int e_p=118;

        while(e_p<690)
        {
            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
            readimagefile("bk.jpg",0,0,1000,700);
            hen_add();
            basket_add(mousex());
            lay_egg(e_p);

            if(level==2)
                red_egg();
            if(level==3)
                stoll_fall();
                e_p+=50;
          /*  if(point<100)
            e_p+=50;
            else if(point<200)
                e_p+=60;
            else if(point<300)
                e_p+=70;
            if(level==2)
              e_p+=75;*/
            page=1-page;
        }

        level_cheak();
        life_cheak();
        if(endgame==1)
        {
            gameplayed=1;
            end_game(point);
            break;
        }


    }
}
