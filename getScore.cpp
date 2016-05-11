#include <curses.h>

void evaluate_line1_horizontal(bool notsHorizontal[4],bool operandsHorizontal[4][4],int fields[4][5], int lines_horizontal[4],int alternative[3][3],int conjuction[3][3],int negation[3]);
void evaluate_line2_horizontal(bool notsHorizontal[4],bool operandsHorizontal[4][4],int fields[4][5], int lines_horizontal[4],int alternative[3][3],int conjuction[3][3],int negation[3]);
void evaluate_line3_horizontal(bool notsHorizontal[4],bool operandsHorizontal[4][4],int fields[4][5], int lines_horizontal[4],int alternative[3][3],int conjuction[3][3],int negation[3]);
void evaluate_line4_horizontal(bool notsHorizontal[4],bool operandsHorizontal[4][4],int fields[4][5], int lines_horizontal[4],int alternative[3][3],int conjuction[3][3],int negation[3]);
void evaluate_line1_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]);
void evaluate_line2_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]);
void evaluate_line3_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]);
void evaluate_line4_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]);
void evaluate_line5_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]);
void fireworks();
void player_of_justice_wins();
void player_of_lies_wins();


void getscore(bool notsHorizontal[4],bool notsVertical[5],bool operandsHorizontal[4][4],bool operandsVertical[3][5],int fields[4][5],int alternative[3][3],int conjuction[3][3],int negation[3]){
       int lines_horizontal[4];
       int lines_vertical[5];
       int player_of_truth=0;
       int player_of_false=0;
       evaluate_line1_horizontal(notsHorizontal,operandsHorizontal,fields,lines_horizontal,alternative,conjuction,negation);
       evaluate_line2_horizontal(notsHorizontal,operandsHorizontal,fields,lines_horizontal,alternative,conjuction,negation);
       evaluate_line3_horizontal(notsHorizontal,operandsHorizontal,fields,lines_horizontal,alternative,conjuction,negation);
       evaluate_line4_horizontal(notsHorizontal,operandsHorizontal,fields,lines_horizontal,alternative,conjuction,negation);
       evaluate_line1_vertical(notsVertical,operandsVertical,fields,lines_vertical,alternative,conjuction,negation);
       evaluate_line2_vertical(notsVertical,operandsVertical,fields,lines_vertical,alternative,conjuction,negation);
       evaluate_line3_vertical(notsVertical,operandsVertical,fields,lines_vertical,alternative,conjuction,negation);
       evaluate_line4_vertical(notsVertical,operandsVertical,fields,lines_vertical,alternative,conjuction,negation);
       evaluate_line5_vertical(notsVertical,operandsVertical,fields,lines_vertical,alternative,conjuction,negation);
       for(int i=0;i<4;i++){
        if(lines_horizontal[i]==1) player_of_truth++;
        else if(lines_horizontal[i]==0)player_of_false++;
       }
       for(int i=0;i<5;i++){
        if(lines_vertical[i]==1) player_of_truth++;
        else if(lines_vertical[i]==0) player_of_false++;
        else {
            clear();
            mvprintw(getmaxy(stdscr)-1,(getmaxx(stdscr)/2)-5,"REMIS!!");
            return;
        }
       }
       for(int i=0;i<4;i++) mvprintw(11+(2*i),45,"%d",lines_horizontal[i]);
       for(int i=0;i<5;i++) mvprintw(20,18+(5*i),"%d",lines_vertical[i]);
       mvprintw(getmaxy(stdscr)-1,0,"Wcisnij dowolny klawisz, aby kontynuowac...");
       getch();
       clear();
       if(player_of_false<player_of_truth) player_of_justice_wins();
       else player_of_lies_wins();
       getch();
       fireworks();
}
//----------------------------------------------------------------------------------------
void evaluate_line1_horizontal(bool notsHorizontal[4],bool operandsHorizontal[4][4],int fields[4][5], int lines_horizontal[4],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp1,tmp2;
    if(operandsHorizontal[0][0]) tmp1=conjuction[fields[0][0]][fields[0][1]];
    else tmp1=alternative[fields[0][0]][fields[0][1]];

    if(operandsHorizontal[0][2]) tmp2=conjuction[fields[0][2]][fields[0][3]];
    else tmp2=alternative[fields[0][2]][fields[0][3]];
    if(operandsHorizontal[0][3]) tmp2=conjuction[tmp2][fields[0][4]];
    else tmp2=alternative[tmp2][fields[0][4]];

    if(operandsHorizontal[0][1]) lines_horizontal[0]=conjuction[tmp1][tmp2];
    else lines_horizontal[0]=alternative[tmp1][tmp2];

    if(notsHorizontal[0]) lines_horizontal[0]=negation[lines_horizontal[0]];
}
void evaluate_line2_horizontal(bool notsHorizontal[4],bool operandsHorizontal[4][4],int fields[4][5], int lines_horizontal[4],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp1,tmp2;
    if(operandsHorizontal[1][1]) tmp1=conjuction[fields[1][1]][fields[1][2]];
    else tmp1=alternative[fields[1][1]][fields[1][2]];
    if(operandsHorizontal[1][0]) tmp1=conjuction[fields[1][0]][tmp1];
    else tmp1=alternative[fields[1][0]][tmp1];

    if(operandsHorizontal[1][3]) tmp2=conjuction[fields[1][3]][fields[1][4]];
    else tmp2=alternative[fields[1][3]][fields[1][4]];

    if(operandsHorizontal[1][2]) lines_horizontal[1]=conjuction[tmp1][tmp2];
    else lines_horizontal[1]=alternative[tmp1][tmp2];

    if(notsHorizontal[1]) lines_horizontal[1]=negation[lines_horizontal[1]];
}
void evaluate_line3_horizontal(bool notsHorizontal[4],bool operandsHorizontal[4][4],int fields[4][5], int lines_horizontal[4],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp1,tmp2;
    if(operandsHorizontal[2][0]) tmp1=conjuction[fields[2][0]][fields[2][1]];
    else tmp1=alternative[fields[2][0]][fields[2][1]];

    if(operandsHorizontal[2][2]) tmp2=conjuction[fields[2][2]][fields[2][3]];
    else tmp2=alternative[fields[2][2]][fields[2][3]];

    if(operandsHorizontal[2][1]) tmp1=conjuction[tmp1][tmp2];
    else tmp1=alternative[tmp1][tmp2];

    if(operandsHorizontal[2][3]) lines_horizontal[2]=conjuction[tmp1][fields[2][4]];
    else lines_horizontal[2]=alternative[tmp1][fields[2][4]];

    if(notsHorizontal[2]) lines_horizontal[2]=negation[lines_horizontal[2]];
}
void evaluate_line4_horizontal(bool notsHorizontal[4],bool operandsHorizontal[4][4],int fields[4][5], int lines_horizontal[4],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp1,tmp2;
    if(operandsHorizontal[3][1]) tmp1=conjuction[fields[3][1]][fields[3][2]];
    else tmp1=alternative[fields[3][1]][fields[3][2]];
    if(operandsHorizontal[3][0]) tmp1=conjuction[fields[3][0]][tmp1];
    else tmp1=alternative[fields[3][0]][tmp1];

    if(operandsHorizontal[3][3]) tmp2=conjuction[fields[3][3]][fields[3][4]];
    else tmp2=alternative[fields[3][3]][fields[3][4]];

    if(operandsHorizontal[3][2]) lines_horizontal[3]=conjuction[tmp1][tmp2];
    else lines_horizontal[3]=alternative[tmp1][tmp2];

    if(notsHorizontal[3]) lines_horizontal[3]=negation[lines_horizontal[3]];
}
//-------------------------------------------------------------------
void evaluate_line1_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp1,tmp2;

    if(operandsVertical[0][0]) tmp1=conjuction[fields[0][0]][fields[1][0]];
    else tmp1=alternative[fields[0][0]][fields[1][0]];

    if(operandsVertical[2][0]) tmp2=conjuction[fields[2][0]][fields[3][0]];
    else tmp2=alternative[fields[2][0]][fields[3][0]];

    if(operandsVertical[1][0]) lines_vertical[0]=conjuction[tmp1][tmp2];
    else lines_vertical[0]=alternative[tmp1][tmp2];

    if(notsVertical[0]) lines_vertical[0]=negation[lines_vertical[0]];
}

void evaluate_line2_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp;

    if(operandsVertical[1][1]) tmp=conjuction[fields[1][1]][fields[2][1]];
    else tmp=alternative[fields[1][1]][fields[2][1]];
    if(operandsVertical[2][1]) tmp=conjuction[fields[3][1]][tmp];
    else tmp=alternative[fields[3][1]][tmp];

    if(operandsVertical[0][1]) lines_vertical[1]=conjuction[fields[0][1]][tmp];
    else lines_vertical[1]=alternative[fields[0][1]][tmp];

    if(notsVertical[1]) lines_vertical[1]=negation[lines_vertical[1]];
}
void evaluate_line3_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp;

    if(operandsVertical[2][2]) tmp=conjuction[fields[2][2]][fields[3][2]];
    else tmp=alternative[fields[2][2]][fields[3][2]];
    if(operandsVertical[1][2]) tmp=conjuction[fields[1][2]][tmp];
    else tmp=alternative[fields[1][2]][tmp];

    if(operandsVertical[0][2]) lines_vertical[2]=conjuction[fields[0][2]][tmp];
    else lines_vertical[2]=alternative[fields[0][2]][tmp];

    if(notsVertical[2]) lines_vertical[2]=negation[lines_vertical[2]];
}
void evaluate_line4_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp1,tmp2;

    if(operandsVertical[0][3]) tmp1=conjuction[fields[0][3]][fields[1][3]];
    else tmp1=alternative[fields[0][3]][fields[1][3]];

    if(operandsVertical[2][3]) tmp2=conjuction[fields[2][3]][fields[3][3]];
    else tmp2=alternative[fields[2][3]][fields[3][3]];

    if(operandsVertical[1][3]) lines_vertical[3]=conjuction[tmp1][tmp2];
    else lines_vertical[3]=alternative[tmp1][tmp2];

    if(notsVertical[3]) lines_vertical[3]=negation[lines_vertical[3]];
}
void evaluate_line5_vertical(bool notsVertical[5],bool operandsVertical[3][5],int fields[4][5],int lines_vertical[5],int alternative[3][3],int conjuction[3][3],int negation[3]){
    int tmp;

    if(operandsVertical[0][4]) tmp=conjuction[fields[0][4]][fields[1][4]];
    else tmp=alternative[fields[0][4]][fields[1][4]];
    if(operandsVertical[1][4]) tmp=conjuction[fields[2][4]][tmp];
    else tmp=alternative[fields[2][4]][tmp];

    if(operandsVertical[2][4]) lines_vertical[4]=conjuction[fields[3][4]][tmp];
    else lines_vertical[4]=alternative[fields[3][4]][tmp];

    if(notsVertical[4]) lines_vertical[4]=negation[lines_vertical[4]];
}
