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


/* Klasa za robotic 1 i rad sa njim */


/* Ukljucivanje potrebnih zaglavlja */
#include "robot_1.h"
#include "model_1.h"
#include <cmath>


/* Konstruktor za robotica 1 */
Robot_1::Robot_1(int player,Tacka t)
    : Robot(player,t,5*SECOND,5*SECOND,5*SECOND,5*SECOND)
    {}


// void Robot_1::animation()
// {
//     if(this->_left_right==KEY_LEFT)
//         this->_ugao-=5;
//     else if(this->_left_right==KEY_RIGHT)
//         this->_ugao+=5;

//     if(this->_up_down==KEY_UP)
//         this->_center.add(this->_speed*std::sin(this->_ugao/180*PII),0,-this->_speed*std::cos(this->_ugao/180*PII));
//     else if(this->_up_down==KEY_DOWN)
//         this->_center.add(-this->_speed*std::sin(this->_ugao/180*PII),0,this->_speed*std::cos(this->_ugao/180*PII));

//}


/* Iscrtavanje robotica 1 */
void Robot_1::draw()
{
    glut::push();
        glut::translate(this->_center);
        glut::rotate(-this->_ugao,0,1,0);
        glut::rotate(90,0,1,0);
        model_1();
    glut::pop();
}