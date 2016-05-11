#include <curses.h>
#include <cstdlib>
#include <time.h>

void createBoard(int fields[4][5]);
bool changableField(int x,int y,char z[2],bool changed [8][26]);
void getRandomValues(int fields[4][5]);
void notice_move(int x,int y,int user_action,bool operandsHorizontal[4][4],bool operandsVertical[3][5]);
void notice_negation_change(int x,int y,bool notsHorizontal[4],bool notsVertical[5]);
bool significantField(int x,int y);
void getscore(bool notsHorizontal[4],bool notsVertical[5],bool operandsHorizontal[4][4],bool operandsVertical[3][5],int fields[4][5],int alternative[3][3],int conjuction[3][3],int negation[3]);

void play(int alternative[3][3],int conjuction[3][3],int negation[3]){
    srand(time(NULL));
    int cols,rows;
    getmaxyx(stdscr,rows,cols);
    int x,y;
    bool operandsHorizontal[4][4];			//true - conjuction
    bool operandsVertical[3][5];
    bool notsHorizontal[4];
    for(int i=0;i<4;i++) notsHorizontal[i]=false;	//true - reverses the logical value of the sentence (true - negation)
    bool notsVertical[5];
    for(int i=0;i<5;i++) notsVertical[i]=false;
    bool changed [8][26];
    for(int i=0;i<8;i++){
        for(int j=0;j<26;j++){
            changed[i][j]=false;			//on every field players can write only once - cant be changed the second time
        }
    }
    int fields[4][5];
    int moves_couter=0;
    int user_action;
    int player=rand()%2;

    clear();
    getRandomValues(fields);
    createBoard(fields);
    if(player==1) mvprintw(6,9,"Teraz ruch gracza prawdy:");
    else mvprintw(6,9,"Teraz ruch gracza falszu:");
    getyx(stdscr,y,x);
    noecho();
    while(moves_couter<13){					//there are 13 significant moves, that can end the game
        user_action=getch();
        if(x<cols && y<rows){
                switch(user_action){
        case 260:
            move(y,--x);
            break;
        case 259:
            move(--y,x);
            break;
        case 261:
            move(y,++x);
            break;
        case 258:
            move(++y,x);
            break;
        case 27:
            return;
        default:
            char op[2];
            if(changableField(x,y,op,changed)){
                    if(op[0]==user_action | op[1]==user_action){
                            printw("%c",user_action);
                            changed[y-10][x-15]=true;
                            if(op[0]=='a'){
                                moves_couter++;
                                notice_move(x,y,user_action,operandsHorizontal,operandsVertical);
                                player=negation[player];
                                if(player==1) mvprintw(6,9,"Teraz ruch gracza prawdy:");
                                else mvprintw(6,9,"Teraz ruch gracza falszu:");
                            }
                            else{
                                notice_negation_change(x,y,notsHorizontal,notsVertical);
                            }
                            x++;

                    }
                    else if(op[0]=='n'){
                        mvprintw(0,0,"tutaj mozna uzywac tylko operatora negacji!");
                        getch();
                    }
                    else if (op[0]=='a'){
                        mvprintw(0,0,"tutaj mozna uzywac tylko operatora 'and' oraz 'or'!");
                        getch();
                    }
            }
            else{
                mvprintw(0,0,"nie mozna wpisywac w to miejsce!");
                user_action=getch();
            }
                mvprintw(0,0,"\n");
                move(y,x);
            }
        }
    }
    getch();
    getscore(notsHorizontal,notsVertical,operandsHorizontal,operandsVertical,fields,alternative,conjuction,negation);
}

//------------------------------------------------------------
bool changableField(int x,int y,char z[2],bool changed[8][26]){	//only some fields are changable
    if(((x==15 and (y==11 | y==13 | y==15 | y==17)) or (y==10 and (x==18 | x==23 | x==28 | x==33 | x==38))) && !changed[y-10][x-15]){ //places where player can put a "not"
        z[0]='n';
        z[1]=27;
        return true;
    }
    else if(((y==11 && (x==36 | x==25)) |
            (y==12 && (x==21 | x==31 | x==38)) |
            (y==14 && (x==18 | x==25 | x==36)) |
            (y==16 && (x==21 | x==31 | x==38)) |
            (y==17 && (x==26 | x==36))) && !changed[y-10][x-15]){	//fields where players can put operands (cant be changed already!)	
            z[0]='a';	
            z[1]='o';
            return true;
            }
    return false;
}
//----------------------------------------
void getRandomValues(int fields[4][5]){					//values of elements are random
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
	    int tmp=rand();
            if(tmp%13==0) tmp=2;
            else tmp=tmp%2;
            fields[i][j]=tmp;
        }
    }
}
//-----------------------------------------------------------
void notice_move(int x,int y, int user_action,bool operandsHorizontal[4][4],bool operandsVertical[3][5]){
    bool value;
    if(user_action==97) value=true;         //true means conjuction
    else value=false;
    if(significantField(x,y)){
        switch(y){
        case 12:
            if(x==21){
                operandsHorizontal[0][0]=operandsHorizontal[1][0]=operandsVertical[0][0]=operandsVertical[0][1]=value;
            }
            else{
                operandsHorizontal[0][2]=operandsHorizontal[1][2]=operandsVertical[0][2]=operandsVertical[0][3]=value;
            }
            break;
        case 14:
            if(x==25){
                operandsHorizontal[1][1]=operandsHorizontal[2][1]=operandsVertical[1][1]=operandsVertical[1][2]=value;
            }
            else{
                operandsHorizontal[1][3]=operandsHorizontal[2][3]=operandsVertical[1][3]=operandsVertical[1][4]=value;
            }
            break;
        case 16:
            if(x==21){
                operandsHorizontal[2][0]=operandsHorizontal[3][0]=operandsVertical[2][0]=operandsVertical[2][1]=value;
            }
            else{
                operandsHorizontal[2][2]=operandsHorizontal[3][2]=operandsVertical[2][2]=operandsVertical[2][3]=value;
            }
            break;

        }
    }
    else
        switch(y){
    case 11:
        if(x==25) operandsHorizontal[0][1]=value;
        else operandsHorizontal[0][3]=value;
    case 12:
        operandsVertical[0][4]=value;
    case 14:
        operandsVertical[1][0]=value;
    case 16:
        operandsVertical[2][4]=value;
    case 17:
        if(x==26) operandsHorizontal[3][1]=value;
        else operandsHorizontal[3][3]=value;
        }
}
//---------------------------------------------------------------
void notice_negation_change(int x,int y,bool notsHorizontal[4],bool notsVertical[5]){
    if(y==10) notsVertical[(x-18)/5]=true;            //possible values of x: 18,23,28,33,38 - for corresponding fields of notsVertical
    else notsHorizontal[(y-11)/2]=true;           //possible values of y: 11,13,15,17 - for corresponding fields of notsHorizontal
}
//---------------------------------------------------------------
bool significantField(int x,int y){
    return ((y==12 && (x==21 | x==31)) or (y==14 && (x==25 | x==36)) or (y==16 && (x==21 | x==31)));	//returns true if the field changes more than 1 operands
}
