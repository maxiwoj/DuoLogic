#include <curses.h>
#include <cstdlib>
#include <iostream>
#include <cstring>

void addnegation(char *string, int pInt[3]);
void addconjunction(char *string, int pInt[3][3]);
void addalternative(char *string, int pInt[3][3]);
void readFilesAdded(int argc, char *argv[],int alternative[3][3],int conjuction[3][3],int negation[3]);
void menu(int alternative[3][3],int conjuction[3][3],int negation[3]);
void printLogo(int y);



using namespace std;
int main(int argc, char *argv[]){
    int alternative[3][3];
    int conjuction[3][3];
    int negation[3];
    if(argc<6){
        cout<<"Podaj pliki, ktore zawieraja definicje operatorow logicznych!"<<endl;
        cout<<"Np: ./run_my_game --not not.txt --and and.txt --or or.txt\n";
        system("PAUSE");
        exit(1);
    }
    else{
        readFilesAdded(argc,argv,alternative,conjuction,negation);
        initscr();
        menu(alternative,conjuction,negation);
        clear();
        mvprintw(getmaxy(stdscr)-1,0, "Koniec programu, przycisnij przycisk..." );
        mvprintw(0,0,"Game created and produced by Maksymilian Wojczuk");
        printLogo(10);
        getch();
        endwin();
    }
}
//-----------------------------------------------------------------------
void readFilesAdded(int argc, char *argv[],int alternative[3][3],int conjuction[3][3],int negation[3]){
    for(int i=1;i<argc;i++){
        if(!strcmp("--not",argv[i])){
            addnegation(argv[++i], negation);
        }
        else if(!strcmp("--and",argv[i])){
            addconjunction(argv[++i], conjuction);
        }
        else if(!strcmp("--or",argv[i])){
            addalternative(argv[++i], alternative);
        }
        else if(!strcmp("--impl",argv[i])){
            cout<<"Program nie wykorzystuje konstruktora impl";
            exit(1);
        }
        else{
            cout<<"Podales zly argument, przykladowe wywolanie programu:"<<endl;
            cout<<"./game --not not.txt --and and.txt --or or.txt";
            exit(1);
        }
    }
}
//-----------------------------------------------------------------------------
void addalternative(char *string, int pInt[3][3]) {
    int p,q,result;
    FILE *alternative;
    if ((alternative=fopen(string, "r"))==NULL){
        printf ("Nie moge otworzyc pliku %s\n",string);
        exit(1);
    }
    for(int i=0;i<9 && !feof(alternative);i++){
        if(fscanf(alternative,"%d %d %d",&p,&q,&result)!=3) {
            printf("Blad przy odczycie alternative \n");
        }
        pInt[p][q]=result;
    }
    return;
}
void addconjunction(char *string, int pInt[3][3]) {
    int p,q,result;
    FILE *conjuction;
    if ((conjuction=fopen(string, "r"))==NULL) {
        printf ("Nie moge otworzyc pliku %s\n",string);
        exit(1);
    }
    for(int i=0;i<9 && !feof(conjuction);i++){
        if(fscanf(conjuction,"%d %d %d",&p,&q,&result)!=3) {
            printf("Blad przy odczycie conjuction \n");
        }
        pInt[p][q]=result;
    }
    return;
}
void addnegation(char *string, int pInt[3]) {
    int p,result;
    FILE *negation;
    if ((negation=fopen(string, "r"))==NULL) {
        printf ("Nie moge otworzyc pliku %s\n",string);
        exit(1);
    }
    for(int i=0;i<3 && !feof(negation);i++){
        if(fscanf(negation,"%d %d",&p,&result)!=2) {
            printf("Blad przy odczycie negation\n");
        }
        pInt[p]=result;
    }
    return;
}
