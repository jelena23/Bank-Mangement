//
//  main.cpp
//  CS323-ProjekatC++
//
//  Created by Jelena on 5/31/16.
//  Copyright © 2016 Jelena. All rights reserved.
//


#include<iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "Racun.hpp"
using namespace std;

void upisiRacun();              //funkcija koja upisuje u binarni fajl
void prikaziPodatke(int);       //funkcija koja prikazuje podatke o racunu
void doradiRacun(int);          //funkcija pomocu koje se mogu promeniti podaci o racunu
void obrisiRacun(int);          //funkcija koja brise racun
void prikaziSveRacune();		//funkcija koja prikazuje sve podatke o racunu
void uplataIsplata(int, int);//funkcija za uplatu/isplatu
void upisiStedniRacun();
void izracunajKamatu(int);
//void izracunajKamatu(double); //funkcija koja racuna kamatu na ustedjevinu
void intro();                   //pocetna poruka

vector <Racun> vektor;

int main()
{
    int n;
    int num = 0;
    intro();
    do
    {
        cout<<"\n\n\n\tGLAVNI MENI";
        cout<<"\n\n\t01. NOVI RACUN";
        cout<<"\n\n\t02. UPLATA";
        cout<<"\n\n\t03. ISPLATA";
        cout<<"\n\n\t04. TRENUTNO STANJE NA RACUNU";
        cout<<"\n\n\t05. NOSIOCI RACUNA";
        cout<<"\n\n\t06. ZATVARANJE RACUNA";
        cout<<"\n\n\t07. MODIFIKACIJA RACUNA";
        cout<<"\n\n\t09. STEDNJA";
        cout<<"\n\n\t08. IZLAZ";
        cout<<"\n\n\tOdaberite opciju (1-8) ";
        cin>>n;
        switch(n)
        {
            case (1):
                upisiRacun();
                break;
            case (2):
                cout<<"\n\n\tUnesite broj racuna : "; cin>>num;
                uplataIsplata(num, 1);
                break;
            case (3):
                cout<<"\n\n\tUnesite broj racuna : "; cin>>num;
                uplataIsplata(num, 2);
                break;
            case (4):
                cout<<"\n\n\tUnesite broj racuna : "; cin>>num;
                prikaziPodatke(num);
                break;
            case (5):
                prikaziSveRacune();
                break;
            case (6):
                cout<<"\n\n\tUnesite broj racuna : "; cin>>num;
                obrisiRacun(num);
                break;
            case (7):
                cout<<"\n\n\tUnesite broj racuna : "; cin>>num;
                doradiRacun(num);
                break;
            case (8):
                cout<<"\n\n\tIzlaz!";
                break;
            case (9):
                upisiStedniRacun();
                break;
            case (10):
                izracunajKamatu(num);
            default :cout<<"\a";
        }
        cin.ignore();
        cin.get();
    }while(n != 8);
    return 0;
}

//funkcija koja upisuje u binarni fajl
void upisiRacun()
{
    Racun ac;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ac.napraviRacun();
    vektor.push_back(ac);
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Racun));
    outFile.close();
}

//funkcija koja prikazuje podatke o racunu
void prikaziPodatke(int n)
{
    Racun ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Nije moguce otvoriti fajl! Pritisnite enter da se vratite na pocetni meni.";
        return;
    }
    cout<<"\nPrikaz racuna\n";
    
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Racun)))
    {
        if(ac.getBrojRacuna()==n)
        {
            ac.prikaziRacun();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nBroj racuna koji ste uneli ne postoji!";
}

//funkcija pomocu koje se mogu promeniti podaci o racunu
void doradiRacun(int n)
{
    bool found=false;
    Racun ac;
    fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"Nije moguce otvoriti fajl! Pritisnite enter da se vratite na pocetni meni.";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Racun));
        if(ac.getBrojRacuna()==n)
        {
            ac.prikaziRacun();
            cout<<"\n\nUnesite nove podatke o racuna koji zelite da promenite: "<<endl;
            ac.doradi();
            int pos=(-1)*static_cast<int>(sizeof(Racun));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Racun));
            cout<<"\n\n\t Izmene su sacuvane.";
            found=true;
        }
    }
    vektor.push_back(ac);
    File.close();
    if(found==false)
        cout<<"\n\n Racun nije pronadjen!";
}

//funkcija koja brise racun
void obrisiRacun(int n)
{
    Racun ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Nije moguce otvoriti fajl! Pritisnite enter da se vratite na pocetni meni.";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Racun)))
    {
        if(ac.getBrojRacuna()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Racun));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"\n\n\tRacun je obrisan.";
}

//funkcija koja prikazuje sve podatke o racunu
void prikaziSveRacune()
{
    Racun ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Nije moguce otvoriti fajl! Pritisnite enter da se vratite na pocetni meni.";
        return;
    }
    cout<<"\n\n\t\tSVI NOSIOCI RACUNA U BANCI\n\n";
    cout<<"====================================================\n";
    cout<<"BROJ RACUNA      IME           TIP  TRENUTNO STANJE\n";
    cout<<"====================================================\n";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Racun)))
    {
        ac.prikaz();
    }
    inFile.close();
}

//funkcija za uplatu/isplatu
void uplataIsplata(int n, int option)
{
    int amt;
    bool found = false;
    Racun ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"Nije moguce otvoriti fajl! Pritisnite enter da se vratite na pocetni meni.";
        return;
    }
    while(!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Racun));
        if(ac.getBrojRacuna()==n)
        {
            ac.prikaziRacun();
            if(option==1)
            {
                cout<<"\n\n\tIZNOS ZA UPLATU ";
                cout<<"\n\nUnesite iznos koji zelite da uplatite na racun: ";
                cin>>amt;
                ac.uplati(amt);
            }
            if(option==2)
            {
                cout<<"\n\n\tIZNOS ZA ISPLATU ";
                cout<<"\n\nUnesite iznos koji zelite da podignete sa racuna: ";
                cin>>amt;
                int bal=ac.getDepozit()-amt;
                if((bal<10000 && ac.getTip() == 'S') || (bal<50000 && ac.getTip() == 'C'))
                    cout<<"Nemate dovoljno sredstava na racunu!";
                else
                    ac.isplati(amt);
            }
            int pos=(1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Racun));
            cout<<"\n\n\t Novo stanje je sacuvano.";
            found=true;
	       }
    }
    vektor.push_back(ac);
    File.close();
    if(found==false)
        cout<<"\n\n Racun nije pronadjen! ";
}

void upisiStedniRacun()
{
    Stednja sa;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    sa.napraviStednju();
    vektor.push_back(sa);
    outFile.write(reinterpret_cast<char *> (&sa), sizeof(Stednja));
    outFile.close();
}

void izracunajKamatu(int n)
{
    Stednja sa;
    double bal;
    bool found = false;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"Nije moguce otvoriti fajl! Pritisnite enter da se vratite na pocetni meni.";
        return;
    }
    while(!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *> (&sa), sizeof(Stednja));
        if(sa.getBrojRacuna()==n)
        {
            sa.prikaziRacun();
            bal = sa.getDepozit() * sa.getKamata();
          
            int pos=(1)*static_cast<int>(sizeof(sa));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&sa), sizeof(Stednja));
            cout<<"\n\n\t Novo stanje je sacuvano.";
            found=true;
	       }
    }
    vektor.push_back(sa);
    File.close();
    if(found==false)
        cout<<"\n\n Racun nije pronadjen! ";
}

void intro()
{
    cout<<"\n\n\n\t SISTEM";
    cout<<"\n\n\t  RADA";
    cout<<"\n\n\t BANKE";

}
