#include <curses.h>

void getVLine(int which,int fields[4][5],char line[4]);
void printVLine(int fields[4][5]);
void printBrain();

void createBoard(int fields[4][5]){
    move(10,15);
    printw("   _    _    _    _    _  ");			//always the same fields in the game
    mvprintw(11,15,"_ (      )_((      ) _  ))");
    mvprintw(12,15,"      _         _      _)");
    mvprintw(13,15,"_ (    (      )) (      )");
    mvprintw(14,15,"   _      _          _   ");
    mvprintw(15,15,"_((      )  (      ))   ");
    mvprintw(16,15,"      _         _      _");
    mvprintw(17,15,"_ (    (   _  )) (   _  )");
    mvprintw(24,0,"Legenda:");
    mvprintw(25,0,"p - prawda \nq - falsz \nX - nieznane");
    printVLine(fields);
    if(has_colors()){					//print info about basic game rules
        start_color();
        init_pair( 1, COLOR_BLACK, COLOR_WHITE );
        init_pair( 2, COLOR_BLACK, COLOR_GREEN );
        mvprintw(27,0,"oznaczenia kolorow: ");
        attron(COLOR_PAIR(1));
        printw("p  ");
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        printw("q  p");
        attroff(COLOR_PAIR(2));
        printw(" = (p  (q  p))    ");
        attron(COLOR_PAIR(1));
        printw("p  q");
        attroff(COLOR_PAIR(1));
        printw(" = (p  q)");
    }
    mvprintw(28,0,"and = a, or = o, not = n");
    mvprintw(getmaxy(stdscr)-1,0,"Esc - powrot do menu (gra nie zostanie zapisana!)");
    printBrain();
    move(11,18);
}
//----------------------------------------------------
void getVLine(int which,int fields[4][5],char line[4]){			//get vertical line, to print with colors
    for(int i=0;i<4;i++){
        switch (fields[i][which]){
    case 0:
        line[i]='q';
        break;
    case 1:
        line[i]='p';
        break;
    case 2:
        line[i]='X';
        break;
        }
    }
}
//--------------------------------------------------------------
void printVLine(int fields[4][5]){					//print lines vartically with colors
    char line[4];
    if( has_colors() ){
        start_color();
        init_pair( 1, COLOR_BLACK, COLOR_WHITE );
        init_pair( 2, COLOR_BLACK, COLOR_GREEN );

        getVLine(0,fields,line);          //first vertical Line
        attron( COLOR_PAIR(1) );
        mvprintw(11,18,"%c",line[0]);
        mvprintw(12,18," ");
        mvprintw(13,18,"%c",line[1]);
        mvprintw(15,18,"%c",line[2]);
        mvprintw(16,18," ");
        mvprintw(17,18,"%c",line[3]);
        attroff( COLOR_PAIR(1) );

        getVLine(1,fields,line);
        mvprintw(11,23,"%c",line[0]);
        attron(COLOR_PAIR(2));
        mvprintw(13,23,"%c",line[1]);
        mvprintw(14,23," ");
        mvprintw(15,23,"%c",line[2]);
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(1));
        mvprintw(16,23," ");
        mvprintw(17,23,"%c",line[3]);
        attroff(COLOR_PAIR(1));

        getVLine(2,fields,line);
        mvprintw(11,28,"%c",line[0]);
        attron(COLOR_PAIR(1));
        mvprintw(13,28,"%c",line[1]);
        mvprintw(14,28," ");
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        mvprintw(15,28,"%c",line[2]);
        mvprintw(16,28," ");
        mvprintw(17,28,"%c",line[3]);
        attroff(COLOR_PAIR(2));

        getVLine(3,fields,line);
        attron(COLOR_PAIR(1));
        mvprintw(11,33,"%c",line[0]);
        mvprintw(12,33," ");
        mvprintw(13,33,"%c",line[1]);
        mvprintw(15,33,"%c",line[2]);
        mvprintw(16,33," ");
        mvprintw(17,33,"%c",line[3]);
        attroff(COLOR_PAIR(1));

        getVLine(4,fields,line);
        attron(COLOR_PAIR(2));
        mvprintw(11,38,"%c",line[0]);
        mvprintw(12,38,"_");
        mvprintw(13,38,"%c",line[1]);
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(1));
        mvprintw(14,38," ");
        mvprintw(15,38,"%c",line[2]);
        attroff(COLOR_PAIR(1));
        mvprintw(17,38,"%c",line[3]);
    }
    else
    {
        mvprintw(0,0, "Twoja Konsolka nie obsluguje kolorow. :/ " );
    }

}
//---------------------------------------------------------------------
void printBrain(){
    int i=1;
    int j=getmaxx(stdscr)-60;
    mvprintw(i,j,"                       C@@@@@@@@C.");
    mvprintw(++i,j,"                 f@@@@@@@@@@@@@@@@@@@@@@C");
    mvprintw(++i,j,"              0@@@@@@@@@@@@@@@0@@@@@@@@@@@@@");
    mvprintw(++i,j,"            @@@@@@@@00@              @@@@@@@@@,");
    mvprintw(++i,j,"          i@@@@@@t                       @@@@@@@");
    mvprintw(++i,j,"         8@@@@8                            :@@@@@");
    mvprintw(++i,j,"        @@@@@                                @@@@@");
    mvprintw(++i,j,"       8@@@@                                 L@@@@@");
    mvprintw(++i,j,"      ,@@@@0                                  @@@@@");
    mvprintw(++i,j,"      @@@@@@C                                  @@@@t");
    mvprintw(++i,j,"      @@@@@@@@                                 @@@@C");
    mvprintw(++i,j,"      @@@@@@@@@@@@G;                           @@@@1");
    mvprintw(++i,j,"      @@@@@@@@@@@@@@@,                        @@@@@ ");
    mvprintw(++i,j,"    ;@@@@@@@@@@@@@@@@@8                      @@@@@0");
    mvprintw(++i,j,"   0@@@@@@@@@@@@@@@@@@@@@@@@                @@@@@@ ");
    mvprintw(++i,j,"  @@@@@@@@@@@@@@@@@@@@@@@@@@@.          @@@@@@@@@ ");
    mvprintw(++i,j," L@@@@@@@@@@@@@@@@@@@@@@@@@@@@   @:    @@@@@@@@f");
    mvprintw(++i,j,"     @@@@@@@@@@@@@@@@@@@@@@@@@8 t@@@@@@@@@@@@@ ");
    mvprintw(++i,j,"    1@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(++i,j,"      8@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
    mvprintw(++i,j,"     t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@C");
    mvprintw(++i,j,"      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.");
    mvprintw(++i,j,"     .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(++i,j,"      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(++i,j,"       ,G@@0;,  .@@@@@@@@@@@@@@@@@@@@@@@@@.");
    mvprintw(++i,j,"                 G@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(++i,j,"                 :@@@@@@@@@@@@@@@@@@@@@@@@@f");
    mvprintw(++i,j,"                  @@@@@@@@@@@@@@@@@@@@@@@@@@;");

}
