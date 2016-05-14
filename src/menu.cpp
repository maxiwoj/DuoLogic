#include <curses.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
void play(int alternative[3][3],int conjuction[3][3],int negation[3]);
void printLogo(int y);
void printLogo_slanted(int x,int y);
void printInstruction();

void menu(int alternative[3][3],int conjuction[3][3],int negation[3]){
    int cols,rows;
    getmaxyx( stdscr, rows, cols );
    mvprintw(rows-1,0,"Przycisnij przycisk aby rozpoczac...\n");
    printLogo(10);

    noecho();
    keypad( stdscr, TRUE );
    //start displaing menu
    const char field1[] = "Graj!";
    const char field2[] = "Instrukcja";
    const char field3[] = "Wyjscie";
    int which = 1;
    int user_action;
    const short int min_choice = 1;
    const short int max_choice = 3;
    do{
        //get user_action
        user_action = getch();
        clear();
	//react to user_action
        if( user_action == 259 && which != min_choice ) which--;
        else if( user_action == 258 && which != max_choice ) which++;
        if( user_action == 10 ){
            switch( which ){
            case 1:
                clear();
                mvprintw(1,(cols/2)-3,"Gramy!");
                printLogo(10);
                mvprintw(rows-4,0,"pamietaj, ze jezeli wyjdziesz z gry poprzez nacisniecie przycisku, twoja gra nie zostanie zapisana!");
                mvprintw(rows-3,0,"Wcisnij dowolny przycisk aby rozpoczac...\n");
                printw("Esc - powrot do menu");
                move(rows-1,0);
                user_action=getch();
                if(user_action!=27) play(alternative,conjuction,negation);
                clear();
                break;
            case 2:
                clear();
                printLogo(0);
                printInstruction();
                while(user_action != 27) user_action=getch();
                clear();
                break;
            }

        }
        //display menu after user_action
        switch( which ){			//if the arrow up/down has been hit - the highlightened field changed, so print menu again, but change the field that is highlightened
        case 1:
            mvprintw( 6, 5, field2 );
            mvprintw( 7, 5, field3 );
            attron( A_REVERSE );
            mvprintw( 5, 5, field1 );
            break;

        case 2:
            mvprintw( 5, 5, field1 );
            mvprintw( 7, 5, field3 );
            attron( A_REVERSE );
            mvprintw( 6, 5, field2 );
            break;

        case 3:
            mvprintw( 5, 5, field1 );
            mvprintw( 6, 5, field2 );
            attron( A_REVERSE );
            mvprintw( 7, 5, field3 );
            break;
        }
        attroff( A_REVERSE );
        mvprintw(rows-1,0,"Game created and produced by Maksymilian Wojczuk");
        printLogo_slanted(5,cols-90);
    } while( which != 3 || user_action != 10 );			//to end the loop you need to hit enter on "exit"
}
//---------------------------------------------------------
void printLogo(int y){
mvprintw(y,14,".:;i1tfLCGG08@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@80GCLftt1i;:,.");
mvprintw(++y,14,".:;i1tfLCGG08@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@80GCLftt1i;:,.");
mvprintw(++y,14,"    ;tttti.   ;tt  ;tt   :C8@8C:   @@t      .t0@@0t     1G8@8Ci  @@@@@t  :L8@8G1        ");
mvprintw(++y,14,"    t@@ .f@@; t@@  t@@ .8@0: :0@8. @@t     t@@t..t@@t t@@,  ,10   t@@  .8@0; .i0        ");
mvprintw(++y,14,"    t@@ .f@@; t@@  t@@ .8@.   .@8. @@t     t@@.  .@@t t@@,        t@@  .8@0; .i0        ");
mvprintw(++y,14,"    t@@   f@@ t@@  t@@ t@@     @@t @@t     @@t    t@@ @@t ;tttt   t@@  t@@              ");
mvprintw(++y,14,"    t@@   G@C t@@  t@@ :@@t   t@@: @@t     C@8.  .8@C C@8:;tG@@   t@@  :@@f    i        ");
mvprintw(++y,14,"    t@@@@@8i   L@@@@8:  .C@@@@@C.  @@@@@@@  i8@@@@8i   ;8@@@@@8  @@@@@t .C@@@@@8        ");
mvprintw(++y,14,".,,::;;;ii11tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt111ii;;::,,...");
mvprintw(++y,14,".:;i1tfLCGG08@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@80GCLftt1i;:,.");
}

void printLogo_slanted(int y,int x){
    mvprintw(y,x,"    :;;:,");
    mvprintw(++y,x,"   .,;i1tfLCGGCt:");
    mvprintw(++y,x,"          :1L08@@@@@@8L1,");
    mvprintw(++y,x,"       t@@@8t.   .1L8@@@@@@@@0fi.");
    mvprintw(++y,x,"       @@f .C@L  L@G     :tC@@@@@@@@@Ct:");
    mvprintw(++y,x,"      t@@.  i@@,:@@1 .@@f  .i11,.if0@@@@@@@@8L1,");
    mvprintw(++y,x,"     .@@t  ;8@L C@0  f@@.:8@8LL8@8,  ;i.,1L8@@@@@@@@0f;.");
    mvprintw(++y,x,",;;::..if080f. .8@1 .@@t 8@L    t@8..@@t        :tG@@@@@@@@@C1:");
    mvprintw(++y,x,",;i1tffLCGCt;.  ,G@@@@L  8@L    C@0 f@@      t8@@@@G,  .if0@@@@@@@@8Li.");
    mvprintw(++y,x,"      ,ifG88@@@@@@C1:    .C@@88@@0..@@t     G@0,  :8@f  .1LCfi.,1C8@@@@@@@@Gt:");
    mvprintw(++y,x,"             .if0@@@@@@@@8Li..:.   L@@fi.  :@@;    L@0 G@@L1tG@@; fGt: ;tG@80GCLff1;,");
    mvprintw(++y,x,"                     ,1L8@@@@@@@@Gt; :tC@@. L@8i ,L@@it@@. ,   :  .C@@@f  .:;,.:i11i;::,");
    mvprintw(++y,x,"                             ;tG@@@@@@@@@C1, .10@88f. ;@@i;0@@@;  .@@1  f@@8G8@@L      .");
    mvprintw(++y,x,"                                    .if0@@@@@@@@0fi.   ,G@@@@@C   L@8  1@@,    :;       ");
    mvprintw(++y,x,"                                            ,1C8@@@@@@@@Gt; ..  C@@@01 t@8,              ");
    mvprintw(++y,x,"                                                    ;tG@@@@@@@@8L1,.i;  t@@8LLG;         ");
    mvprintw(++y,x,"                                                           .iL8@@@@@@@@0t;.,i;;          ");
    mvprintw(++y,x,"                                                                   :1C880GCLLfti,.       ");
    mvprintw(++y,x,"                                                                           :i11ii;:,.    ");
    mvprintw(++y,x,"                                                                                   .     ");
}

void printInstruction(){
    int y=12;
    mvprintw(y,0,"Witam uzytkowniku gry DuoLogic. Aby zagrac w gre musisz umiec podstawowe zasady rachunku zdan.");
    mvprintw(++y,0,"W grze bierze udzial 2 graczy - jeden jest graczem prawdy, a drugi graczem falszu. Zadaniem pierwszego jest sprawic, aby ");
    printw("jak najwieksza liczba zdan byla prawdziwa, natomiast drugiego- falszywa. Do dyspozycji mamy 3 rodzaje zdan: p - prawdziwe, q - falszywe ");
    printw(" X - nieznane. Zdania sa losowane przez komputer i ukladane na prostokatnej planszy 4x5. Obydwaj uzytkownicy posluguja sie operatorami logicznymi ");
    printw(" and, or oraz not. Poprzez umiejetne wykorzystywanie podanych operatorow w miejscach oznaczonych: '_' gracze sprawiaja, ze cale zdania 5-cio ");
    printw("lub 4-ro elementowe (1 element to: p/q/X) staja sie zdaniami o okreslonej wartosci - prawda, falsz lub nieznane. Jezeli zdanie jest ");
    printw("falszywe - punkt zostaje przyznany graczowi falszu, natomiast jezeli odwrotnie - graczowi prawdy. Jezeli zdanie jest nieznane, nikt nie ");
    printw("dostaje punktu. \n");
    printw("Gra toczy sie do momentu wstawienia wszystkich operatorow and oraz or (gracz falszu posluguje sie operatorem and, natomiast prawdy - or) ");
    printw("w miejsca do tego przeznaczone (wewnatrz zdan), natomiast przed kazdym zdaniem zostawione jest miejsce na ew. operator not. Aby gra sie zakonczyla ");
    printw("nie wszystkie operatory not musza zostac wykorzystane\n\n");
    printw("Uwaga: licza sie zdania zarowno poziome, jak i pionowe!\n");
    printw("Uwaga2: jezeli miejsce na operator jest w linii zdania, to odnosi sie on tylko do danego zdania (poziome lub pionowe), natomiast jezeli ");
    printw("operator jest pomiedzy czterema elementami - odnosi sie on do otaczajacych go 4 miejsc na operatory(wtedy bezposrednio w miejsce operatora");
    printw("nie mozna juz nic wstawic)");
    mvprintw(getmaxy(stdscr)-1,0,"Esc - powrot do menu");
}
