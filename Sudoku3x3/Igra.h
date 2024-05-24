//
// Created by DT User on 09/02/2024.
//

#ifndef SUDOKU_IGRA_H
#define SUDOKU_IGRA_H
#include <iostream>
#include <string>

using namespace std;

class Igra {
private:
    char niz[9][11];
    int tip;
public:
    Igra(int a){
        for(int i=0; i<9; i++ ){
            for( int j=0; j<11; j++){
                if(i%3==2 && i!=8){
                    if(j%4==3){
                        niz[i][j]='|';
                    }else{
                        niz[i][j]='_';
                    }
                }else{
                    if(j%4==3){
                        niz[i][j]='|';
                    }else{
                        niz[i][j]=' ';
                    }
                }
            }
        }
        this->tip=a;
    }

    void Maska(){
        if(this->tip==1){
            niz[1][9]='1';
            niz[4][5]='2';
            niz[7][1]='3';
        }else if(this->tip==2){
            niz[1][9]='2';
            niz[4][1]='3';
            niz[7][5]='1';
        }else if(this->tip=3){
            niz[1][1]='3';
            niz[4][9]='1';
            niz[7][5]='2';
        }
    }

    bool Pobjeda(){
        if(this->tip==1){
            if(niz[1][1]=='2' && niz[1][5]=='3' && niz[1][9]=='1' && niz[4][1]=='1' && niz[4][5]=='2' && niz[4][9]=='3' && niz[7][1]=='3' && niz[7][5]=='1' && niz[7][9]=='2'){
                return true;
            }else{
                return false;
            }
        }else if(this->tip==2){
            if(niz[1][1]=='1' && niz[1][5]=='3' && niz[1][9]=='2' && niz[4][1]=='3' && niz[4][5]=='2' && niz[4][9]=='1' && niz[7][1]=='2' && niz[7][5]=='1' && niz[7][9]=='3'){
                return true;
            }else{
                return false;
            }
        }else if(this->tip==3){
            if(niz[1][1]=='3' && niz[1][5]=='1' && niz[1][9]=='2' && niz[4][1]=='2' && niz[4][5]=='3' && niz[4][9]=='1' && niz[7][1]=='1' && niz[7][5]=='2' && niz[7][9]=='3'){
                return true;
            }else{
                return false;
            }
        }
    }

    void Logika(){
        while(Pobjeda()==false){
            int red, kolona, broj;
            char br;
            if(this->tip==1){
                this->Maska();
                do{
                    cout << endl;
                    for(int i=0; i<9; i++ ){
                        for( int j=0; j<11; j++){
                            cout << niz[i][j];
                        }

                        cout << endl;
                    }
                    cout << endl;

                    do{
                        cout << "Unesite red koji zelite: ";
                        cin >> red;
                    }while(red<1 || red>3);

                    do{
                        cout << "Unesite kolonu koji zelite: ";
                        cin >> kolona;
                    }while(kolona<1 || kolona>3);

                    do{
                        cout << "Unesite broj od 1 do 3: ";
                        cin >> br;
                    }while(br!='1' && br!='2' && br!='3');

                    if(red==1){
                        if(kolona==1){

                                niz[1][1]=br;
                                if(Pobjeda()) {
                                    cout << endl << "Uspjesno ste rijesili sudoku!\n";
                                    break;
                                }

                        }else if(kolona==2){

                                niz[1][5]=br;

                                if(Pobjeda()){
                                    cout << endl << "Uspjesno ste rijesili sudoku!\n";
                                    break;
                                }



                        }else{
                            cout << "Nemoguce je unijeti znak ovdje!" << endl;
                        }
                    }else if(red==2){
                        if(kolona==1){

                                niz[4][1]=br;
                                if(Pobjeda()){
                                    cout << endl << "Uspjesno ste rijesili sudoku!\n";
                                    break;
                                }



                        }else if(kolona==3){

                                niz[4][9]=br;

                                if(Pobjeda()){
                                    cout << endl << "Uspjesno ste rijesili sudoku!\n";
                                    break;
                                }


                        }else if(kolona==2){
                            cout << "Nemoguce je unijeti znak ovdje!" << endl;
                        }
                    }else{
                        if(kolona==2){

                                niz[7][5]=br;
                                if(Pobjeda()){
                                    cout << endl << "Uspjesno ste rijesili sudoku!\n";
                                    break;
                                }



                        }else if(kolona==3){

                                niz[7][9]=br;
                                if(Pobjeda()){
                                    cout << endl << "Uspjesno ste rijesili sudoku!\n";
                                    break;
                                }



                        }else if(kolona==1){
                            cout << "Nemoguce je unijeti znak ovdje!" << endl;
                        }
                    }
                }while(red!=1 && kolona!=3 || red!=2 && kolona!=2 || red!=3 && kolona!=1);

            }
        }
    }


};


#endif //SUDOKU_IGRA_H
