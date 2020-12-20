


char name[100];

void name_add()
{
    int i,j=0;
    char ch;
    initwindow(1300,700,"Enter Name");
    setbkcolor(MAGENTA);
    setcolor(RED);
    setfillstyle(1,MAGENTA);
    floodfill(10,10,WHITE);

    readimagefile("newhighscore.gif",150,50,1150,200);

    settextstyle(1,HORIZ_DIR,6);
    outtextxy(350,300,"Enter Your Name:");

    name[0]='_';
    name[1]='\0';
    setcolor(BLACK);
    settextstyle(1,HORIZ_DIR,2);
    outtextxy(500,400,name);
    while(1)
    {
        if(kbhit())
        {
            ch=getch();
            if(ch=='\r')
            {
                name[j]='\0';
                break;
            }
            else if(ch=='\b')
            {
        setbkcolor(MAGENTA);
        setcolor(MAGENTA);
        settextstyle(1,HORIZ_DIR,2);
        outtextxy(500,400,name);

                j--;
                if(j<0)
                    j=0;
                name[j]='_';
                name[j+1]='\0';
            }
            else if(j<20)
            {
                name[j]=ch;
                j++;
                name[j]='_';
                name[j+1]='\0';
            }
        setbkcolor(MAGENTA);
        setcolor(BLACK);
        settextstyle(1,HORIZ_DIR,2);
        outtextxy(500,400,name);
        }

    }

}


void is_in_high_score(int point)
{
    struct hscore{
   char nm[100];
   int score;
   } highscore[11],test;


    int i=0,j;
    FILE *fr;
    fr=fopen("highscore.txt","r");
    while(i<10)
    {
        fscanf(fr,"%[^\n]",highscore[i].nm);
        fscanf(fr,"%d ",&highscore[i].score);
        i++;
    }
    fclose(fr);
    if(point<=highscore[9].score)
    {
        initwindow(1300,700,"FOR AGAIN PLAY");
        setbkcolor(MAGENTA);
         return ;
    }

    else
    {
        name_add();
        strcpy(highscore[9].nm,name);
        highscore[9].score=point;
        for(i=9;i>0;i--)
        {
            for(j=i-1;j>=0;j--)
            {
                if(highscore[i].score>highscore[j].score)
                {
                    test=highscore[i];
                    highscore[i]=highscore[j];
                    highscore[j]=test;
                }
            }
        }
        fr=fopen("highscore.txt","w");

        for(i=0;i<10;i++)
        {
            fprintf(fr,"%s\n",highscore[i].nm);
            fprintf(fr,"%d\n",highscore[i].score);
        }

        fclose(fr);



     return;
    }
}


void end_game(int point)
{
   char scrshow[100];

   initwindow(1300,700,"Score Show");
   setfillstyle(1,GREEN);
   floodfill(1,1,WHITE);
   setbkcolor(GREEN);
   setcolor(BLACK);
   settextstyle(1,HORIZ_DIR,6);
   outtextxy(200,300,"YOUR SCORE :");
   sprintf(scrshow,"%d",point);
   outtextxy(800,300,scrshow);
   delay(1000);
   closegraph();
   is_in_high_score(point);
}
