#include <curses.h>

void wins();

void player_of_justice_wins(){
    int i=7;
    int j=18;
    mvprintw(i,j,"  t@@@@   t@       @@    @@@@@@@@@ @@@@@@@@@@@t @@@@@     @@@@@@@@0  @@@@@@@@@ ");
    mvprintw(++i,j,"     t@   t@       @@   @L              @@        @t    0@,       ;  @@          ");
    mvprintw(++i,j,"     t@   t@       @@   @@:             @@        @t   :@i           @@          ");
    mvprintw(++i,j,"     t@   t@       @@     L@@@@@@       @@        @t   t@            @@@@@@      ");
    mvprintw(++i,j,"     t@   1@.      @@           0@      @@        @t    @L           @@          ");
    mvprintw(++i,j,"     G@    @@     ;@f   L       @@      @@        @t    1@0       @  @@        ");
    mvprintw(++i,j," @@@@8      i@@@@@0     t@@@@@@@.       @@      @@@@@     ;@@@@@@C   @@@@@@@@@ ");
    wins();

}
void player_of_lies_wins(){
    int i=7;
    int j=25;
    mvprintw(i,j,"@@@@@@@@   f@@f     t@        @@8ff0@@   tG@tt @@@@@@@@@@@@@     8@.  ");
    mvprintw(++i,j,"@@        .@ff@.    t@       @@           t@       t@      8@   @@    ");
    mvprintw(++i,j,"@@@@@@@   @@  @@    t@        @@@C1       t@       t@       t@:@0     ");
    mvprintw(++i,j,"@@       0@    @0   t@             1@@i   t@       t@        .@t      ");
    mvprintw(++i,j,"@@      i@;    ;@i  t@               @8   t@       t@         @t      ");
    mvprintw(++i,j,"@@      @8      8@  t@@@@@@@ @@@@@@@@C   @@@@@     t@         @t      ");
    wins();
}

void wins(){
    int i=18;
    int j=20;
    mvprintw(i,j,"     t@.   .@@    @@  @@@@@   @@@    @@   ,@@@@@@@@    @1    8@     @1 ");
    mvprintw(++i,j,"      @@   @t@:   @1    @t    @@1@   @@   @f           @i    0@     @i ");
    mvprintw(++i,j,"      i@  .@ f@  0@     @t    @@ f@  @@   8@@1.        @;    G@     @; ");
    mvprintw(++i,j,"       @8 @f  @, @1     @t    @@  C@ @@       iC@@8    @:    L@     @: ");
    mvprintw(++i,j,"       ;@.@   f@L@      @t    @@   0@@@          t@    ''    ''     '' ");
    mvprintw(++i,j,"        @@f    @@i    tt@Gt   @@    8@@   @@@LtC@@;    @t    @@     @t ");
}
