#ifndef MACIERZKW_HH
#define MACIERZKW_HH

#include "Wektor.hh"

enum Wyz{Gauss, Sarruss, Bareiss}; //wybor metody liczenia wyznacznika

enum Odw{_Gauss, _Dopel}; //wybor metody liczenia odwrotnosci

/*Klasa opisujaca macierz kwadratowa*/
class MacierzKw
{
private:
    Wektor tab[ROZMIAR]; //kazdemu wierszowi odpowiada wektor

    /*METODY WEWNETRZNE*/
    const double w_gauss() const; //pojawil sie problem z dokladnoscia double
    const double w_bareiss() const;
    const double w_sarruss() const;

public:
    /*KONSTRUKTORY*/
    MacierzKw(){}
    MacierzKw(Wektor *W); //przyjmuje tablice wektorow
    MacierzKw(Wektor W1, Wektor W2, Wektor W3); //przyjmuje 3 wektory
    
    /*OPERATORY*/
    const Wektor & operator[](int index) const;
    Wektor & operator[](int index);

    bool operator==(const MacierzKw &M2) const;
    bool operator!=(const MacierzKw &M2) const;

    const MacierzKw operator+(const MacierzKw &M2) const;
    const MacierzKw & operator+=(const MacierzKw &M2);

    const MacierzKw operator-(const MacierzKw &M2) const;
    const MacierzKw & operator-=(const MacierzKw &M2);

    const MacierzKw operator*(const MacierzKw &M2) const; //mnozenie dwoch macierzy

    /*API*/
    void utworzI(); //tworzy macierz jednostkowa

    const MacierzKw schodkowa() const; //zwraca macierz schodkowa

    const MacierzKw transpozycja() const; 

    double wyznacznik(Wyz metoda = Bareiss) const;

    const MacierzKw odwrotnosc(Odw metoda = _Gauss) const; //WIP
};

/*OPERATORY ZEWNETRZNE*/
MacierzKw operator*(double l1, const MacierzKw M2); //mnozenie macierzy przez liczbe

std::ostream & operator<<(std::ostream &strm, const MacierzKw &M); //wyswietlanie wierszami
std::istream & operator>>(std::istream &strm, MacierzKw &M); //wczytywanie wierszami


#endif