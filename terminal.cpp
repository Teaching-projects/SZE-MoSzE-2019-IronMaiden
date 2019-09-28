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
rm -rf mappa torol mappat es a benne levoket is
rm ha ures mappa torol
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
        int e =mappanevek[j].length();
        for (int i=0;i<e;i++){        //kereses.
            seged=seged+mappanevek[j][i];
            if(seged==akt){
                for (int l=i+1;l<e;l++){
                    if (mappanevek[j][l]=='/'){
                        pont=true;
                    }
                }
                if(pont==false){
                    cout<<"[";
                for(int k=(seged.length());k<e;k++){             
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
                 //almappak / elvalasztas
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
        cout<<"Root directory\n";
    }

   // cout<< "["<<akt<<"[\n";
    //torlendo csak seged!!!
}

//force torles
void fdelet(string resz){
    bool name = false;
    for (int j = 0; j < hasznal; j++){
        string seged="";
        string seged2="";
        int e =mappanevek[j].length();
        for (int i=0;i<e;i++){
            seged=seged+mappanevek[j][i];
            if(seged==akt){
                for (int l=i+1;l<e;l++){
                    seged2=seged2+mappanevek[j][l];
                    if (seged2==resz){
                        mappanevek[j]="";       //memoria szemet
                        name=true;
                    }
                }    
            }
        }
    }
    if (name==false){
        cout << "Directory does not exist\n";
    }
}

//torles
void del(string resz){
    bool name = false;      //folder name not found
    bool emp = false;       //if folder exist
    int ext;                //folder space in dy
    for (int j = 0; j < hasznal; j++){
        string seged="";
        string seged2="";
        int e =mappanevek[j].length();
        for (int i=0;i<e;i++){
            seged=seged+mappanevek[j][i];
            if(seged==akt){
                for (int l=i+1;l<e;l++){
                    seged2=seged2+mappanevek[j][l];
                    if(mappanevek[j][l]=='/'){
                        emp = true;
                    }
                    if (seged2==resz){
                        name=true;
                        ext=j;
                    }
                }    
            }
        }
    }
    if (name==false){
        cout << "Directory does not exist\n";
    }
    if(emp==false and name==true){
        mappanevek[ext]="";             //memoria szemet
    }
    if(emp==true and name == true){
        cout<< "Directory is not empty\n";
    }
}

//main!!
int main(){
string be;
do{
string masodik;
cout<<"\033[1;32madmin\033[0m:"<<"\033[1;34m~"<<akt<<"\033[0m$";     //zold szin32    
getline (cin,be);

//darabolas
int count =0;
string elso ="";
string harmadik;
int e = be.length();
for (int i=0;i<e;i++){
    if (isspace(be[i])){
            count++;
    }else{
        switch (count)
        {
        case 1:
           masodik=masodik+(be[i]);
            break;
        case 2:
            harmadik=harmadik+(be[i]);
            break;
        case 0: 
            elso=elso+(be[i]);
            break;
        default:
            break;
        }
    }
}

//utvalaszto     lehetosegek
if (elso =="ls"){
    listazas();
}
if(elso == "rm" and masodik== "-rf"){
    fdelet(harmadik);
}
if(elso=="rm"){
    del(masodik);
}
if(elso=="mkdir"){
    mappa(masodik);
}
if(elso=="cd" and masodik!=".."){
    cdbe(masodik);
}
if(elso=="cd" and masodik==".."){
    cdki();
}
}while (be!="exit");

//dynamic array delete
delete[] mappanevek;
    return 0;
}
