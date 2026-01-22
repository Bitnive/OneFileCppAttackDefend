#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int health=100, armor=0, attack=60;
    int dhealth=100, darmor=0, dattack=50;
    bool live = false;
    bool dlive = false;

    int secenek;
    cout<<"Oyuna baslamak icin secim yap\n1-Basla\n2-Cikis\nSeciminiz: ";
    cin>>secenek;
    switch(secenek){
    case 1:
        live=true;
        dlive=true;
        cout<<"\033[2J\033[1;1H";
        break;
    case 2:
        cout<<"Tekrar Bekleriz";
        break;
    default:
        cout<<"Sunulan secenekler disinda secenek bulunmuyor!";
        return 0;
    }
    bool hile=false;
    cout<<"Hile acmak istermisiniz ?(1-Evet / 0-Hayır)\nSeciminiz: ";
    cin>>hile;


    while(live&&dlive){
        int karar= rand() % 2;
        cout<<"Dusmanin bilgileri\n";
        cout<<"Dusman Cani:"<<dhealth<<endl;
        cout<<"Dusmanin kalkani: "<<darmor<<endl;
        if(hile){ if(karar==0){cout<<"Dusman Pasif\n";}else if(karar==1){cout<<"Dusman Agresif\n";}}
        cout<<endl;
        cout<<"Caniniz: "<<health<<" Kalkaniniz: "<<armor<<endl;

        int secim;
        cout<<"\nSaglik al = 1\nSaldir = 2\nZirh yenile = 3\nSeciminiz: ";
        cin>>secim;

        switch(secim){
        case 1:
            health+=50;
            cout<<"\033[2J\033[1;1H";
            break;
        case 2:
            if (darmor>0) {
                darmor-=attack;
                if (darmor<0) {
                    dhealth+=darmor;
                    darmor=0;
                }
            } else {dhealth-=dattack;}
            cout<<"\033[2J\033[1;1H";
            break;
        case 3:
            armor+=50;
            cout<<"\033[2J\033[1;1H";
            break;
        default:
            cout<<"\033[2J\033[1;1H";
            cout<<"\nVerilen secenekler disinda gizli secenek yok!";
            break;
        }



        if(health>100){
            health=100;
        }else if(armor>100){
            armor=100;
        }


        if (karar==1) {
            if (armor>0) {
                armor-=dattack;
                if (armor<0) {
                    health+=armor;
                    armor=0;
                }
            } else {health-=dattack;}
        }
        else if (karar==0) {
            dhealth += 30;
            if(dhealth>100){dhealth=100;}
            if(dhealth==100){
                darmor+=30;
                if(darmor>100){darmor=100;}
            }
        }



        system("clear");

        if(health>0){
            live=true;
        }else{live=false;}
        if(dhealth>0){
            dlive=true;
        }else{dlive=false;}
    }
    if(!dlive){
        cout<<"Kazandiniz WHOOOO!";
    }else{
        cout<<"Her zaman kazanilmaz bir dahaki sefere";
    }
}
