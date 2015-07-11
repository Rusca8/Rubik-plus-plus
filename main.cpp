//
//  main.cpp
//  Rubik++
//
//  Created by David Ruscalleda Gómez on 03/04/13.
//  Copyright (c) 2013 David Ruscalleda Gómez. All rights reserved.
//

#include <iostream>
using namespace std;

char Cub[6][3][3];
char Color[6]={'O','N','E','L','A','V'};

void rotar (int p1c, int p1x, int p1y,/**/ int p2c, int p2x, int p2y,/**/ int p3c, int p3x, int p3y,/**/ int p4c, int p4x, int p4y){
    char r;
    
    r=Cub[p4c][p4x][p4y];
    Cub[p4c][p4x][p4y]=Cub[p3c][p3x][p3y];
    Cub[p3c][p3x][p3y]=Cub[p2c][p2x][p2y];
    Cub[p2c][p2x][p2y]=Cub[p1c][p1x][p1y];
    Cub[p1c][p1x][p1y]=r;
}

void dibuixaCub(){ //Dibuixar Cub - - - - - - - - - - - //
    int i,j,k;
    i=0;
    j=0;
    k=0;
    cout<<endl;
    //Cara U//
    while(j<3){
        cout<<"     ";
        while(k<3){
            cout<<Cub[i][j][k];
            k++;
        }
        cout<<endl;
        k=0;
        j++;
    }
    cout<<endl;
    //Cares LFRB//
    j=0;
    i=1;
    k=0;
    while(j<3){
        cout<<" ";
        while(i<5){
            while(k<3){
                cout<<Cub[i][j][k];
                k++;
            };
            cout<<" ";
            k=0;
            i++;
        };
        cout<<endl;
        k=0;
        i=1;
        j++;
    };
    cout<<endl;
    //Cara D//
    i=5;
    j=0;
    k=0;
    while(j<3){
        cout<<"     ";
        while(k<3){
            cout<<Cub[i][j][k];
            k++;
        }
        cout<<endl;
        k=0;
        j++;
    }
}

void rE(int c){// - - - - - - - - - - - - - - - - - - - - - - - -funcions rotació (encara per simplificar) - - - - - //
    rotar(c,0,0,c,0,2,c,2,2,c,2,0);
}
void rA(int c){
    rotar(c,0,1,c,1,2,c,2,1,c,1,0);
}

void rotarF(){
    rE(2);
    rA(2);
    rotar(1,2,2,0,2,0,3,0,0,5,0,2); //b
    rotar(1,1,2,0,2,1,3,1,0,5,0,1); //m
    rotar(1,0,2,0,2,2,3,2,0,5,0,0); //h
}

void rotarU(){
    rE(0);
    rA(0);
    rotar(1,0,2,4,0,2,3,0,2,2,0,2); //b
    rotar(2,0,1,1,0,1,4,0,1,3,0,1); //m
    rotar(1,0,0,4,0,0,3,0,0,2,0,0); //h
}

void rotarL(){
    rE(1);
    rA(1);
    rotar(4,2,2,0,0,0,2,0,0,5,0,0); //b
    rotar(4,1,2,0,1,0,2,1,0,5,1,0); //m
    rotar(4,0,2,0,2,0,2,2,0,5,2,0); //h
}

void rotarR(){
    rE(3);
    rA(3);
    rotar(2,2,2,0,2,2,4,0,0,5,2,2); //b
    rotar(5,1,2,2,1,2,0,1,2,4,1,0); //m
    rotar(2,0,2,0,0,2,4,2,0,5,0,2); //h
}

void rotarB(){
    rE(4);
    rA(4);
    rotar(3,2,2,0,0,2,1,0,0,5,2,0); //b
    rotar(5,2,1,3,1,2,0,0,1,1,1,0); //m
    rotar(3,0,2,0,0,0,1,2,0,5,2,2); //h
}

void rotarD(){
    rE(5);
    rA(5);
    rotar(1,2,0,2,2,0,3,2,0,4,2,0); //b
    rotar(4,2,1,1,2,1,2,2,1,3,2,1); //m
    rotar(1,2,2,2,2,2,3,2,2,4,2,2); //h
}

int main(){ // - - - - - - - - - - - - - - - - - - - - - - - - - MAIN - - - - - - - - - - - - - - - - - - - - - - - - - - //
    
    int i,j,k;
    char mov='O';
    
    //init Cub - - - - - - - - - - - - - - - - - - - -//
    i=0;
    j=0;
    k=0;
    while(i<6){
        while(j<3){
            while(k<3){
                Cub[i][j][k]=Color[i];
                k++;
            }
            k=0;
            j++;
        }
        j=0;
        i++;
    }
    //-------------//
    dibuixaCub();
    
    while (mov!='X'){
        
        cout<<"Moviment: ";
        cin>>mov;
        
        if(mov=='U'){rotarU();}
        if(mov=='F'){rotarF();}
        if(mov=='L'){rotarL();}
        if(mov=='R'){rotarR();}
        if(mov=='B'){rotarB();}
        if(mov=='D'){rotarD();}
        
        dibuixaCub();
    }
    
    return 0;
}