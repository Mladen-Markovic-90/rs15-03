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


/* Klasa za robotic 3 i rad sa njim */


/* Ukljucivanje potrebnih zaglavlja */
#include "robot_3.h"
#include "glut.h"
#include <cmath>
#include <iostream>


/* Konstruktor za robotica 3 */
Robot_3::Robot_3(int player,Tacka t)
    : Robot(player,t,t+Tacka(0,0,0),0,5*SECOND,5*SECOND,5*SECOND,5*SECOND)
    {}


/* Animacija i izracunavanje za robotic 3, izvrsava se u klasi timer */
void Robot_3::animation()
{
    this->_energy+=(5.0/(1.0*SECOND));
    if(this->_energy > 100)
        this->_energy=100;

    //std::cout << this->_energy << std::endl;
    if(this->_ability_1>0)
        this->_ability_1--;
    if(this->_ability_2>0)
        this->_ability_2--;
    if(this->_ability_3>0)
        this->_ability_3--;
    if(this->_ability_4>0)
        this->_ability_4--;
    if(this->_left_right==KEY_LEFT)
        this->_center.add(-this->_speed,0,0);
    else if(this->_left_right==KEY_RIGHT)
        this->_center.add(this->_speed,0,0);

    if(this->_up_down==KEY_UP)
        this->_center.add(0,0,-this->_speed);

    else if(this->_up_down==KEY_DOWN)
        this->_center.add(0,0,this->_speed);

}


/* Iscrtavanje robotica 3 */
void Robot_3::draw()
{
    glut::push();
        glut::translate(this->_center);


        int ugao_naginjanja_napred_nazad=0;

        if(this->_up_down==KEY_DOWN)
            ugao_naginjanja_napred_nazad=5;
        else if(this->_up_down==KEY_UP)
            ugao_naginjanja_napred_nazad=-5;

        glut::rotate(ugao_naginjanja_napred_nazad,1,0,0);


        int ugao_naginjanja_levo_desno=0;

        if(this->_left_right==KEY_LEFT)
            ugao_naginjanja_levo_desno=5;
        else if(this->_left_right==KEY_LEFT)
            ugao_naginjanja_levo_desno=-5;

        glut::rotate(ugao_naginjanja_levo_desno,0,0,1);

        this->model();
        this->ability_1();
        this->ability_2();
        this->ability_3();
        this->ability_4();
    glut::pop();
}


/* Model robotica 3 */
void Robot_3::model()
{
    this->_ugao_rotacije++;


    glut::rotate(21*this->_ugao_rotacije,0,-1,0);
    glut::push();
        glut::color(0.5,0.5,0.5,this->_fade);
        glut::translate(0,10,0);
        glut::rotate(90,1,0,0);
        glut::cone(15,15);
    glut::pop();

    glut::push();
        glut::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                     Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
        glut::rotate(45,0,1,0);
        glut::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                     Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
    glut::pop();


    glut::push();
        glut::color(0.1,0.1,0.1,this->_fade);
        glut::translate(0,12,0);
        glut::rotate(90,1,0,0);
        glut::cylinder(15,2);
    glut::pop();

}


/* MELEE ABILITY */
/* Nozici */
void Robot_3::ability_1()
{

    this->_radius_nozevi=0;
    float number=0;
    if(this->_ability_1>4*SECOND)
        number=5*SECOND-this->_ability_1;
    else if(this->_ability_1>3.5*SECOND)
        number=SECOND;
    else if(this->_ability_1>2.5*SECOND)
        number=this->_ability_1 - 2.5*SECOND;
    else
        number=0;

    number=number/(SECOND*1.0);

    this->_radius_nozevi=15.0*number+10;

    if(number > 0)
    {
        glut::push();
            glut::translate(0,11,0);
            if(this->_lava==true)
                glut::color(2,0,0,1);
            else
                glut::color(0.5,0.5,0.5,this->_fade);
            for(int i=0;i<8;i++)
            {
                glut::push();
                    glut::rotate(i*45,0,1,0);
                    glut::translate(0,0,15.0*number);
                    glut::kvadar(Tacka(0,0.5,0),Tacka(0,0.5,0),Tacka(0,0,10),Tacka(5,0.5,0),
                                 Tacka(0,-0.5,0),Tacka(0,-0.5,0),Tacka(0,0,10),Tacka(5,-0.5,0));
                glut::pop();
            }

        glut::pop();
    }


}



//NOTE:
/* RANGE ABILITY */
/* Kruzni Laser */
void Robot_3::ability_2()
{
    this->_radius_laser=0;
    if(this->_ability_2 > 4.5*SECOND)
    {
        glut::push();
            float number=(float)this->_ability_2/this->_ability_2_cooldown;

            glut::color(0,1,0,number-0.2);

            glut::translate(0,10,0);
            glut::rotate(90,1,0,0);
            glut::cylinder((1.0-number)*1000,1);
            this->_radius_laser=(1.0-number)*1000;
        glut::pop();
    }


}


/* DEFENSIVE ABILITY */
/* Fade Shield */
void Robot_3::ability_3()
{
    this->_fade=1.0;
    if(this->_ability_3 > 0)
    {
        float number=(float)this->_ability_3/this->_ability_3_cooldown;
        number=number/2.0;
        //std::cout << number << std::endl;
        this->_fade=1.0-number;
    }

}



/* SPECIAL ABILITY */
/* Speed + Lava nozevi */
void Robot_3::ability_4()
{

    this->_speed=5;
    this->_lava=false;
    if(this->_ability_4 > 0)
    {
        this->_speed=10;
        this->_lava=true;
        this->_ability_1=4*SECOND;
    }
}
