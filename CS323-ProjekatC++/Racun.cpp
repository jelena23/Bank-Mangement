//
//  Racun.cpp
//  CS323-ProjekatC++
//
//  Created by Jelena on 5/31/16.
//  Copyright © 2016 Jelena. All rights reserved.
//

#include "Racun.hpp"
#include <iostream>
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>

using namespace std;

Racun::Racun()
{
    
}
Racun::Racun(int brojRacuna, std::string imeNosioca, int depozit, char tip)
{
    this->brojRacuna = brojRacuna;
    this->imeNosioca = imeNosioca;
    this->depozit = depozit;
    this->tip = tip;
}
void Racun::setBrojRacuna(int brojRacuna)
{
    this->brojRacuna = brojRacuna;
}
const int Racun::getBrojRacuna()
{
    return brojRacuna;
}
void Racun::setImeNosioca(std::string imeNosioca)
{
    this->imeNosioca = imeNosioca;
}
const std::string Racun::getImeNosioca()
{
    return imeNosioca;
}
void Racun::setDepozit(int depozit)
{
    this->depozit = depozit;
}
const int Racun::getDepozit()
{
    return depozit;
}
void Racun::setTip(char tip)
{
    this->tip = tip;
}
const char Racun::getTip()
{
    return tip;
}

void Racun::napraviRacun()
{
    cout << "\nUnesite broj racuna :";
    cin >> brojRacuna;
    cout << "\n\nUnesite ime nosioca racuna : ";
    cin >> imeNosioca;
    cout << "\nUnesite tip racuna (C/S) : ";
    cin >> tip;
    cout << "\nUnesite pocetni iznos(>=10000 za stednju and >=50000 za tekuci racun ) : ";
    cin >> depozit;
    cout << "\n\n\nVas racun je napravljen.";
}

void Racun::prikaziRacun() const
{
    cout << "\nBroj racuna : " << brojRacuna;
    cout << "\nIme nosioca racuna : " << imeNosioca;
    cout << "\nTip racuna : " << tip;
    cout << "\nTrenutno stanje : " << depozit;
}


void Racun::doradi()
{
    cout << "\nBroj racuna : " << brojRacuna;
    cout << "\nPromeni ime nosioca racuna : ";
    cin >> imeNosioca;
    cout << "\nPromeni tip racuna : ";
    cin >> tip;
    //tip = toupper(tip);
    cout<<"\nPromeni trenutno stanje : ";
    cin >> depozit;
}
void Racun::uplati(int x)
{
    depozit+=x;
}

void Racun::isplati(int x)
{
    depozit-=x;
}
void Racun::prikaz() const
{
    cout << brojRacuna << setw(10) << " " << imeNosioca << setw(10) << " " << tip << setw(6) << depozit << endl;
}

Stednja::Stednja()
{
    
}
Stednja::Stednja(int brojRacuna, std::string imeNosioca, int depozit, char tip, double kamata)
{
    this->brojRacuna = brojRacuna;
    this->imeNosioca = imeNosioca;
    this->depozit = depozit;
    this->tip = tip;
    this->kamata = kamata;
}
void Stednja::setKamata(double kamata)
{
    this->kamata = kamata;
}
const double Stednja::getKamata()
{
    return kamata;
}

void Stednja::napraviStednju()
{
    cout << "\nUnesite broj racuna :";
    cin >> brojRacuna;
    cout << "\n\nUnesite ime nosioca racuna : ";
    cin >> imeNosioca;
    cout << "\nUnesite tip racuna (C/S) : ";
    cin >> tip;
    cout << "\nUnesite pocetni iznos(>=10000 za stednju and >=50000 za tekuci racun ) : ";
    cin >> depozit;
    cout << "\n\n\nVas racun je napravljen.";

}
void Stednja::racunajKamatu()
{
    depozit*=(kamata/100);
}
