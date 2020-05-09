#include "JatekMester.h"

JatekMester::JatekMester(Amoba *a): amb(a), in_line_counter(0), allas(0)
{
}

int JatekMester::szamlalo(const int *v, int palya_meret){
    //printf("%i", v[1]);
    find_row(v, palya_meret);
    find_col(v,palya_meret);
    find_diag(v,palya_meret);
    dontetlen(v,palya_meret);
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
void JatekMester::find_col(const int *v, int palya_meret){
    for(int i=0;i<palya_meret;i++){
        int strike=1;
        for(int j=0;j<palya_meret;j++){
             if(v[j*palya_meret+i]!=0 && v[j*palya_meret+i]==v[(j+1)*palya_meret+i]){++strike;}
             if(strike==5){
                allas=1;///vmelyik jatekos nyert
                break;
             }
        }
    }
}
void JatekMester::find_diag(const int *v, int palya_meret){
    int k=0;
    int kk=0;
    for(int l=palya_meret;l>-palya_meret;l--){
        int i=(l>0 ? l : 0);
        while(i<palya_meret && i-l<palya_meret){
            if(v[i*palya_meret+(i-l)]==1){++k;}
            if(v[i*palya_meret+(i-l)]==-1){++kk;}
            if(k==5 || kk==5){
                allas=1;
                break;
            }
            i++;
        }
        k=0;
        kk=0;
    }

    for(int l=0; l<(palya_meret+palya_meret-1);l++){
        int i=(l<palya_meret ? 0 : l-palya_meret+1);
        while(l<palya_meret && l-i>=0){
            if(v[i*palya_meret+(l-i)]==1){++k;}
            if(v[i*palya_meret+(l-i)]==-1){++kk;}
            if(k==5 || kk==5){
                allas=1;
                break;
            }
            i++;
        }
        k=0;
        kk=0;
    }
}

void JatekMester::dontetlen(const int *v, int palya_meret){
    int c=0;
    for(int j=0;j<palya_meret;j++){
        for(int i=0;i<palya_meret;i++){
            if(v[j*palya_meret+i]==0) c++;
        }
    }
    if(c==0){
        allas=2;
    }
}







