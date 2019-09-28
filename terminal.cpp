#include <iostream>
#include <string>
using namespace std;
//linuxon g++ al mukodik
/*          Feladat!
Mint ha terminal lenne kell kesziteni
C++
Ls listazas
Mkdir konyvar letrehozasa
Cd belepes
Cd.. kilepes
*/

//globalis valzotok
   int osszes = 1; 
   string *mappanevek = new string[osszes];      //letrehoz egy valtozot
   int hasznal = 0;               //aktualisan hasznalt tarolok
    string akt="/";                  //aktualis mappa ls cd folyamat kovetes!!

//ls
void listazas(){
    for (int j = 0; j < hasznal; j++){
        string seged="";
        bool pont =false;
        for (int i=0;i<mappanevek[j].length();i++){        //kereses.
            seged=seged+mappanevek[j][i];
            if(seged==akt){
                for (int l=i+1;l<mappanevek[j].length();l++){
                    if (mappanevek[j][l]=='/'){
                        pont=true;
                    }
                }
                if(pont==false){
                    cout<<"[";
                for(int k=(seged.length());k<(mappanevek[j].length());k++){             
                    //csak az aktualis mappa neve irja elotagokat nem
                    cout<<mappanevek[j][k];
                }
                cout<<"]\n";
                }                
                //cout <<"["<< mappanevek[j]<<"] \n";           teszt-hez
            }
        }
    }
}

//mkdir
void mappa(string nev){

            if (hasznal == osszes){
                osszes *= 2;
                string *mappanevek2 = new string[osszes];
                for (int i=0; i < hasznal; i++){
                    mappanevek2[i] = mappanevek[i];
                }
                delete[] mappanevek;
                mappanevek = mappanevek2;
            }
                 //almappak. elvalasztas
            mappanevek[hasznal] = (akt+nev);
            (hasznal)++;
}

//cdbe
void cdbe(string resz){
    // akt adja meg a mappa kezelest azt kell leptetni melyebre
    // nyilvan pontot nem hasznalhat eleresi utban
    akt=akt+resz+"/";
}

//cdki
void cdki(){
    //. eseten mar nem meghivhato
    if(akt!="/"){
        akt.pop_back();
        for(int i=akt.length()-1;i>0;i--){
            if(akt[i]!='/'){
                akt.pop_back();
            }else{
                i=0;
            }
        }
    }else{
        cout<<"gyökér könyvtár\n";
    }

   // cout<< "["<<akt<<"[\n";
    //torlendo csak seged!!!
}

//main!!
int main(){
string be;
do{
string resz;
cout<<"\033[1;32madmin\033[0m:"<<"\033[1;34m~"<<akt<<"\033[0m$";     //zold szin32    
getline (cin,be);

//darabolas
int count =0;
string elso ="";
for (int i=0;i<be.length();i++){

    if (isspace(be[i])){
            count=1;
    }else{
        if (count==1){
        resz=resz+(be[i]);
        }else{
        elso=elso+(be[i]);
        }
    }
}

//utvalaszto     lehetosegek
if (elso =="ls"){
    listazas();
}
if(elso=="mkdir"){
    mappa(resz);
}
if(elso=="cd" and resz!=".."){
    cdbe(resz);
}
if(elso=="cd" and resz==".."){
    cdki();
}
}while (be!="kilep");

//dinamikus adat torlese
delete[] mappanevek;
    return 0;
}
