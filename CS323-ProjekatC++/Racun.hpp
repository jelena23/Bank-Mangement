//
//  Racun.hpp
//  CS323-ProjekatC++
//
//  Created by Jelena on 5/31/16.
//  Copyright © 2016 Jelena. All rights reserved.
//

#ifndef Racun_hpp
#define Racun_hpp

#include <stdio.h>
#include <string>

#endif /* Racun_hpp */

class Racun
{
public:
    Racun();
    Racun(int brojRacuna, std::string imeNosioca, int depozit, char tip);
    void setBrojRacuna(int brojRacuna);
    const int getBrojRacuna();
    void setImeNosioca(std::string imeNosioca);
    const std::string getImeNosioca();
    void setDepozit(int depozit);
    const int getDepozit();
    void setTip(char tip);
    const char getTip();
    
    void napraviRacun();
    void prikaziRacun() const;
    void doradi();
    void uplati(int);
    void isplati(int);
    void prikaz() const;

    
protected:
    int brojRacuna, depozit;
    std::string imeNosioca;
    char tip;
};

class Stednja : public Racun
{
protected:
    double kamata = 2.5;
public:
    Stednja();
    Stednja(int brojRacuna, std::string imeNosioca, int depozit, char tip, double kamata);
    void setKamata(double kamata);
    const double getKamata();
    void napraviStednju();
    void racunajKamatu();
    
};
