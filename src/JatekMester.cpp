#include "JatekMester.h"

JatekMester::JatekMester(Amoba *a): amb(a), in_line_counter(0), allas(0)
{
}

int JatekMester::szamlalo(const int *v, int palya_meret){
    //printf("%i", v[1]);
    find_row(v, palya_meret);
    return allas;
}

void JatekMester::find_row(const int *v, int palya_meret){
    for(int j=0;j<palya_meret;j++){
        int strike=1;
        for(int i=0;i<palya_meret;i++){
             if(v[j*palya_meret+i]!=0 && v[j*palya_meret+i]==v[j*palya_meret+(i+1)]){++strike;}
             if(strike==5){
                allas=1;///vmelyik jatekos nyert
                break;
             }
        }
    }
}

/*
 // check Winner
        //
        // check Horizontal Winner
        short streak = 1;
        for(short y=0; y<5; y++) {
            streak = 1;
            for(short x=0; x<4; x++) {
                if(board[y][x] == board[y][x+1]) {
                    streak++;

                    if(streak == 3) {
                        if(board[y][x] == 'A')
                            A = true;
                        else
                            B = true;
                    }
                } else
                    streak = 1;
            }
        }

        // check Vertical Winner
        if(!((A == true && B == true) || (A == false && B == false))) {
            for(short x=0; x<5; x++) {
                streak = 1;
                for(short y=0; y<4; y++) {
                    if(board[y][x] == board[y+1][x]) {
                        streak++;

                        if(streak == 3) {
                            if(board[y][x] == 'A')
                                A = true;
                            else
                                B = true;
                        }
                    } else
                        streak = 1;
                }
            }
        } else
            AB = true;

        //check diagonal winner---------------------------------
        if(AB == false) {
            short streak2;
            short streak3;
            short streak4;
            for(short j=0; j<4; j++) {
                streak = 1;
                streak2 = 1;
                streak3 = 1;
                streak4 = 1;
                for(short i=0; i<5-j; i++) {
                    if(board[i+j][i] == board[i+j+1][i+1]) {
                        streak++;
                        if(streak == 3)
                            if(board[i+j][i] == 'A')
                                A = true;
                            else
                                B = true;
                    } else
                        streak = 1;



                    if(board[i-1][i+j] == board[i][i+1+j]) {
                        streak2++;
                        if(streak2 == 3)
                            if(board[i-1][i+j] == 'A')
                                A = true;
                            else
                                B = true;
                    } else
                        streak2 = 1;



                    if(board[5-i-j][i-1] == board[5-i-1-j][i]) {
                        streak3++;
                        if(streak3 == 3)
                            if(board[5-i-j][i-1] == 'A')
                                A = true;
                            else
                                B = true;
                        } else
                            streak3 = 1;



                    if(board[5-i][i+j] == board[5-1-i][i+1+j]) {
                        streak4++;
                        if(streak4 == 3)
                            if(board[5-i][i+j] == 'A')
                                A = true;
                            else
                                B = true;
                    } else
                        streak4 = 1;
                }
*/
