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


/* Ukljucivanje potrebnih zaglavlja */
#include "delovi.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "provera.h"


/* Konstruktor za robotica 1 */
Robot_1::Robot_1(float ticksPerSecond,int player,Tacka t)
    : Robot(ticksPerSecond,player,t,Tacka(0,0,-20),0,
            5*ticksPerSecond,5*ticksPerSecond,5*ticksPerSecond,5*ticksPerSecond,
            Tacka(-15,0,-20),Tacka(15,0,-20),Tacka(15,0,20),Tacka(-15,0,20),20)
    {}

/* Iscrtavanje robotica 1 */
void Robot_1::draw()
{

    glutcpp::push();
        glutcpp::translate(this->_center);
        glutcpp::rotate(-this->_ugao,0,1,0);
        glutcpp::rotate(90,0,1,0);
        this->model();
        this->ability_1();
        this->ability_3();
    glutcpp::pop();

    this->ability_2();

    /* Test */
    glutcpp::translate(0,20,0);
    glutcpp::push();
        glutcpp::color(1,0,0,1);
        glutcpp::translate(provera::position(_northWest,_center,_ugao));
        glutcpp::cube(5);
    glutcpp::pop();

    glutcpp::push();
        glutcpp::color(0,1,0,1);
        glutcpp::translate(provera::position(_northEast,_center,_ugao));
        glutcpp::cube(5);
    glutcpp::pop();

    glutcpp::push();
        glutcpp::color(0,0,1,1);
        glutcpp::translate(provera::position(_southEast,_center,_ugao));
        glutcpp::cube(5);
    glutcpp::pop();

    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(provera::position(_southWest,_center,_ugao));
        glutcpp::cube(5);
    glutcpp::pop();
/*
    std::cout << _ugao << " "
              << _center.get_x() << " "
              << _center.get_y() << " "
              << _center.get_z()
              << std::endl;*/


    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(_center);
        glutcpp::cube(10);
    glutcpp::pop();

    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(getFront());
        glutcpp::cube(5);
    glutcpp::pop();

}


/* Model robotica 1 */
void Robot_1::model()
{

    int ugao_tocak=0;

    if(this->_left_right==KEY_LEFT)
        ugao_tocak=30;
    else if(this->_left_right==KEY_RIGHT)
        ugao_tocak=-30;

    /* tockovi */
    this->ugao_rotacije_tocak++;
    glutcpp::push();
        glutcpp::translate(15,5,-15);
        Delovi::tocak(5,2,this->ugao_rotacije_tocak,ugao_tocak);
        glutcpp::translate(-30,0,0);
        Delovi::tocak(5,2,this->ugao_rotacije_tocak,0);
        glutcpp::translate(0,0,28);
        Delovi::tocak(5,2,this->ugao_rotacije_tocak,0);
        glutcpp::translate(30,0,0);
        Delovi::tocak(5,2,this->ugao_rotacije_tocak,ugao_tocak);
    glutcpp::pop();

    /* popunjavanje kod tockova */
    glutcpp::push();
        glutcpp::color(0.5,0.5,0.5,1);
        glutcpp::translate(0,6,0);
        glutcpp::kvadar(20,30,8);
    glutcpp::pop();

    /* glavni deo robotica */
    glutcpp::push();
        glutcpp::color(0.5,0.5,0,1);
        glutcpp::translate(5,10,0);
        glutcpp::kvadar(Tacka(-25,0,15),Tacka(15,0,15),Tacka(15,0,-15),Tacka(-25,0,-15),
                     Tacka(-30,5,10),Tacka(10,5,10),Tacka(10,5,-10),Tacka(-30,5,-10));
    glutcpp::pop();
}


//NOTE: tacka udarca -> centar + Tacka(30,0,0);
/* MELEE ABILITY */
/* Cekic */
void Robot_1::ability_1()
{

    float ugao_cekic;

    if(this->_ability_1>4.5*_ticksPerSecond)
        ugao_cekic=(this->_ability_1 - 4.5*_ticksPerSecond)*2;
    else if(this->_ability_1>2.5*_ticksPerSecond)
        ugao_cekic=(4.5*_ticksPerSecond - this->_ability_1)/2;
    else
        ugao_cekic=_ticksPerSecond;

    ugao_cekic=ugao_cekic/_ticksPerSecond;

    glutcpp::push();
        glutcpp::translate(10,13,0);
        glutcpp::rotate(90*ugao_cekic,0,0,1);

        glutcpp::color(0.2,0.2,0.2,1);

        glutcpp::push();
            glutcpp::translate(0,0,-15);
            glutcpp::kvadar(Tacka(-1,-1,0),Tacka(1,-1,0),Tacka(1,1,0),Tacka(-1,1,0),
                         Tacka(-1,-1,5),Tacka(1,-1,5),Tacka(1,1,5),Tacka(-1,1,5));
            glutcpp::kvadar(Tacka(-1,-1,-1),Tacka(-1,1,-1),Tacka(-1,1,1),Tacka(-1,-1,1),
                         Tacka(20,-1,-1),Tacka(20,1,-1),Tacka(20,1,1),Tacka(20,-1,1));
        glutcpp::pop();

        glutcpp::push();
            glutcpp::translate(0,0,15);
            glutcpp::kvadar(Tacka(-1,-1,0),Tacka(1,-1,0),Tacka(1,1,0),Tacka(-1,1,0),
                         Tacka(-1,-1,-5),Tacka(1,-1,-5),Tacka(1,1,-5),Tacka(-1,1,-5));
            glutcpp::kvadar(Tacka(-1,-1,-1),Tacka(-1,1,-1),Tacka(-1,1,1),Tacka(-1,-1,1),
                         Tacka(20,-1,-1),Tacka(20,1,-1),Tacka(20,1,1),Tacka(20,-1,1));
        glutcpp::pop();

        glutcpp::push();
            glutcpp::translate(20,-8,0);
            glutcpp::rotate(90,-1,0,0);
            glutcpp::cone(10,15);
        glutcpp::pop();

        glutcpp::push();
            glutcpp::translate(20,8,0);
            glutcpp::rotate(90,1,0,0);
            glutcpp::cone(10,15);
        glutcpp::pop();

        glutcpp::push();
            glutcpp::translate(19,0,0);
            glutcpp::kvadar(2,30,2);

        glutcpp::pop();
    glutcpp::pop();

}


//NOTE: tacka udarca -> this->tacka_raketa + Tacka(20,0,0);
/* RANGE ABILITY */
/* Raketa */
void Robot_1::ability_2()
{

    float number=0;
    if(this->_ability_2>0)
        number=5*_ticksPerSecond-this->_ability_2;
    else
    {
        this->tacka_raketa=this->_center;
        this->ugao_raketa=this->_ugao-90;
    }

    glutcpp::push();
        glutcpp::translate(this->tacka_raketa);
        glutcpp::rotate(-this->ugao_raketa,0,1,0);
        glutcpp::translate(10*number-5,5,0);
        if(number>0)
        {
            glutcpp::color(1,0.5,0,0.5);
            for(int i=0;i<25;i++)
            {
                float x=((float)std::rand()/RAND_MAX)*5.0;
                float y=-3+((float)std::rand()/RAND_MAX)*6.0;
                float c=-1+((float)std::rand()/RAND_MAX)*2.0;
                glutcpp::linija(Tacka(-x,-y,0),Tacka(-(3+x),-(y+c),0));
            }
        }
        glutcpp::rotate(90,0,1,0);
        glutcpp::color(0.5,0.5,0.5,1);
        glutcpp::cylinder(3,15);
        glutcpp::rotate(-90,0,1,0);
        glutcpp::translate(15,0,0);
        glutcpp::rotate(90,0,1,0);
        glutcpp::color(1,0,0,0.8);
        glutcpp::cone(5,6);
    glutcpp::pop();


}


/* DEFENSIVE ABILITY */
/* Energetski Shield */
void Robot_1::ability_3()
{
    float number=this->_ability_3/(float)this->_ability_3_cooldown;

    if(this->_ability_3)
    {
        glutcpp::push();
            glutcpp::color(1,1,1,0.8*number);
            glutcpp::translate(-2.5,10,0);
            glutcpp::kvadar(50,30,20);
        glutcpp::pop();
    }

}
