/*
    Crashing Trashing Bots is a 3D game in freeglut
    Copyright (C) 2015 Mladen Markovic,Tamara Plazinic,Nikola Banjac

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef TACKA
#define TACKA


/* Klasa koja pamti tacke i sluzi za rad sa tackama */
class Tacka
{
public:
    /* Konstruktori */
    Tacka();
    Tacka(const float & x,const float & y,const float & z);

    /* Getteri */
    float get_x() const;
    float get_y() const;
    float get_z() const;

    /* Setteri */
    void set_x(const float x);
    void set_y(const float y);
    void set_z(const float z);

    /* Sabiranje Tacke sa koordinatama */
    void add(const float x,const float y,const float z);

    /* Sabiranje Tacke sa Tackom */
    void add(Tacka t);

    float norm() const ;

    /* rastojanje dve tacke */
    float distance(Tacka &t2);

    /* Vektor od 2 tacke */
    Tacka vek(Tacka t);
    
    /* operatori dodela operacija za Tacku */
    Tacka& operator+= (const Tacka& t2);
    Tacka& operator-= (const Tacka& t2);
    Tacka& operator*= (float k);
    Tacka& operator/= (float k);
    bool operator== (const Tacka& t2);

private:
    /* Promenljive za koordinatu tacke */
    float _x;
    float _y;
    float _z;
};

//ostali operatori ne moraju biti friendovi jer imamo sve getere

/* operatori za rad sa 2 tacke */
Tacka operator+ (Tacka t1, Tacka t2);
Tacka operator- (Tacka t1, Tacka t2);

/* operatori za rad sa tackom i konstantom */
Tacka operator* (Tacka t1, float k);
Tacka operator/ (Tacka t1, float k);


#include "tacka.cpp"


#endif // TACKA
