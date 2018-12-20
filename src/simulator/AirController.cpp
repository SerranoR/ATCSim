/*
 * AirController.cpp
 *
 *  Created on: 21/07/2014
 *      Author: paco
 *
 *  Copyright 2014 Francisco Martín
 *
 *  This file is part of ATCSim.
 *
 *  ATCSim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AirController.h"
#include "Airport.h"
#include "Flight.h"
#include "Position.h"
#include <list>
#include <fstream>

namespace atcsim{

AirController::AirController() {
	// TODO Auto-generated constructor stubs

}

AirController::~AirController() {
	// TODO Auto-generated destructor stub
}
/*
Route
AirController::SetRoute(const Position& pos, const float& v)
{
	atcsim::Route r
	r.pos = pos;
	r.speed = v;
	return r;
}*/

void
AirController::doWork()
{
		std::list<Flight*> flights = Airport::getInstance()->getFlights();
		std::list<Flight*>::iterator it;

		float x1, x2, x3, x4;
		x1 = 15000.0;
		x2 = 9000.0;
		x3 = 3000.0;
		x4 = -4000.0;
		float y1, y2;
		y1 = 16000.0;
		y2 = 3500.0;
		float z1_hi, z1, z1_lo, z2_hi, z2, z2_lo, z3_hi, z3, z3_lo;
		z1_hi = 3000.0;
		z1 = 2700.0;
		z1_lo = 2500.0;
		z2_hi =1800.0;
		z2 = 1600.0;
		z2_lo = 1400.0;
		z3_hi =900.0;
		z3 = 700.0;
		z3_lo = 500.0;


		//Circuito 1
		Position pos_circuito1_1(x1, y1, z1_hi);
		Position pos_circuito1_2(x1, y2, z1);
		Position pos_circuito1_3(x2, y2, z1);
		Position pos_circuito1_4(x2, y1, z1_lo);
		Position pos_circuito1_5(x1, y1, z2_hi);
		Position pos_circuito1_6(x1, y2, z2);
		Position pos_circuito1_7(x2, y2, z2);
		Position pos_circuito1_8(x2, y1, z2_lo);
		Position pos_circuito1_9(x1, y1, z3_hi);
		Position pos_circuito1_10(x1, y2, z3);
		Position pos_circuito1_11(x2, y2, z3_lo);
		Position pos_circuito1_12(x2, y1, z3_lo);
		//Circuito 2
		Position pos_circuito2_1(x1, -y1, z1_hi);
		Position pos_circuito2_2(x1, -y2, z1);
		Position pos_circuito2_3(x2, -y2, z1);
		Position pos_circuito2_4(x2, -y1, z1_lo);
		Position pos_circuito2_5(x1, -y1, z2_hi);
		Position pos_circuito2_6(x1, -y2, z2);
		Position pos_circuito2_7(x2, -y2, z2);
		Position pos_circuito2_8(x2, -y1, z2_lo);
		Position pos_circuito2_9(x1, -y1, z3_hi);
		Position pos_circuito2_10(x1, -y2, z3);
		Position pos_circuito2_11(x2, -y2, z3_lo);
		Position pos_circuito2_12(x2, -y1, z3_lo);
		//Circuito 3
		Position pos_circuito3_1(x3, y1, z1_hi);
		Position pos_circuito3_2(x3, y2, z1);
		Position pos_circuito3_3(x4, y2, z1);
		Position pos_circuito3_4(x4, y1, z1_lo);
		Position pos_circuito3_5(x3, y1, z2_hi);
		Position pos_circuito3_6(x3, y2, z2);
		Position pos_circuito3_7(x4, y2, z2);
		Position pos_circuito3_8(x4, y1, z2_lo);
		Position pos_circuito3_9(x3, y1, z3_hi);
		Position pos_circuito3_10(x3, y2, z3);
		Position pos_circuito3_11(x4, y2, z3_lo);
		Position pos_circuito3_12(x4, y1, z3_lo);
		//Circuito 4
		Position pos_circuito4_1(x3, -y1, z1_hi);
		Position pos_circuito4_2(x3, -y2, z1);
		Position pos_circuito4_3(x4, -y2, z1);
		Position pos_circuito4_4(x4, -y1, z1_lo);
		Position pos_circuito4_5(x3, -y1, z2_hi);
		Position pos_circuito4_6(x3, -y2, z2);
		Position pos_circuito4_7(x4, -y2, z2);
		Position pos_circuito4_8(x4, -y1, z2_lo);
		Position pos_circuito4_9(x3, -y1, z3_hi);
		Position pos_circuito4_10(x3, -y2, z3);
		Position pos_circuito4_11(x4, -y2, z3_lo);
		Position pos_circuito4_12(x4, -y1, z3_lo);

		Position pos0(3500.0, 0.0, 100.0);
		Position pos1(1500.0, 0.0, MAINTAIN_ALT);
		Position pos2(200.0, 0.0, 25.0);
		Position pos3(-750.0, 0.0, 25.0);

		Route ra0, ra1, ra2, ra3;
		Route r1c1, r1c2, r1c3, r1c4, r1c5, r1c6, r1c7, r1c8, r1c9, r1c10, r1c11, r1c12;
		Route r2c1, r2c2, r2c3, r2c4, r2c5, r2c6, r2c7, r2c8, r2c9, r2c10, r2c11, r2c12;
		Route r3c1, r3c2, r3c3, r3c4, r3c5, r3c6, r3c7, r3c8, r3c9, r3c10, r3c11, r3c12;
		Route r4c1, r4c2, r4c3, r4c4, r4c5, r4c6, r4c7, r4c8, r4c9, r4c10, r4c11, r4c12;

		//ra0 = SetRoute(pos_aterrizaje_0, 500.0);
		ra0.pos = pos0;
		ra0.speed = 500.0;
		ra1.pos = pos1;
		ra1.speed = 100.0;
		ra2.pos = pos2;
		ra2.speed = 19.0;
		ra3.pos = pos3;
		ra3.speed = 15.0;

		r1c1.pos = pos_circuito1_1;
		r1c1.speed = 800.0;
		r1c2.pos = pos_circuito1_2;
		r1c2.speed = 800.0;
		r1c3.pos = pos_circuito1_3;
		r1c3.speed = 800.0;
		r1c4.pos = pos_circuito1_4;
		r1c4.speed = 800.0;
		r1c5.pos = pos_circuito1_5;
		r1c5.speed = 800.0;
		r1c6.pos = pos_circuito1_6;
		r1c6.speed = 600.0;
		r1c7.pos = pos_circuito1_7;
		r1c7.speed = 600.0;
		r1c8.pos = pos_circuito1_8;
		r1c8.speed = 600.0;
		r1c9.pos = pos_circuito1_9;
		r1c9.speed = 600.0;
		r1c10.pos = pos_circuito1_10;
		r1c10.speed = 600.0;
		r1c11.pos = pos_circuito1_11;
		r1c11.speed = 600.0;
		r1c12.pos = pos_circuito1_12;
		r1c12.speed = 600.0;

		r2c1.pos = pos_circuito2_1;
		r2c1.speed = 800.0;
		r2c2.pos = pos_circuito2_2;
		r2c2.speed = 800.0;
		r2c3.pos = pos_circuito2_3;
		r2c3.speed = 800.0;
		r2c4.pos = pos_circuito2_4;
		r2c4.speed = 800.0;
		r2c5.pos = pos_circuito2_5;
		r2c5.speed = 800.0;
		r2c6.pos = pos_circuito2_6;
		r2c6.speed = 600.0;
		r2c7.pos = pos_circuito2_7;
		r2c7.speed = 600.0;
		r2c8.pos = pos_circuito2_8;
		r2c8.speed = 600.0;
		r2c9.pos = pos_circuito2_9;
		r2c9.speed = 600.0;
		r2c10.pos = pos_circuito2_10;
		r2c10.speed = 600.0;
		r2c11.pos = pos_circuito2_11;
		r2c11.speed = 600.0;
		r2c12.pos = pos_circuito2_12;
		r2c12.speed = 600.0;

		r3c1.pos = pos_circuito3_1;
		r3c1.speed = 800.0;
		r3c2.pos = pos_circuito3_2;
		r3c2.speed = 800.0;
		r3c3.pos = pos_circuito3_3;
		r3c3.speed = 800.0;
		r3c4.pos = pos_circuito3_4;
		r3c4.speed = 800.0;
		r3c5.pos = pos_circuito3_5;
		r3c5.speed = 800.0;
		r3c6.pos = pos_circuito3_6;
		r3c6.speed = 600.0;
		r3c7.pos = pos_circuito3_7;
		r3c7.speed = 600.0;
		r3c8.pos = pos_circuito3_8;
		r3c8.speed = 600.0;
		r3c9.pos = pos_circuito3_9;
		r3c9.speed = 600.0;
		r3c10.pos = pos_circuito3_10;
		r3c10.speed = 600.0;
		r3c11.pos = pos_circuito3_11;
		r3c11.speed = 600.0;
		r3c12.pos = pos_circuito3_12;
		r3c12.speed = 600.0;

		r4c1.pos = pos_circuito4_1;
		r4c1.speed = 800.0;
		r4c2.pos = pos_circuito4_2;
		r4c2.speed = 800.0;
		r4c3.pos = pos_circuito4_3;
		r4c3.speed = 800.0;
		r4c4.pos = pos_circuito4_4;
		r4c4.speed = 800.0;
		r4c5.pos = pos_circuito4_5;
		r4c5.speed = 800.0;
		r4c6.pos = pos_circuito4_6;
		r4c6.speed = 800.0;
		r4c7.pos = pos_circuito4_7;
		r4c7.speed = 600.0;
		r4c8.pos = pos_circuito4_8;
		r4c8.speed = 600.0;
		r4c9.pos = pos_circuito4_9;
		r4c9.speed = 600.0;
		r4c10.pos = pos_circuito4_10;
		r4c10.speed = 600.0;
		r4c11.pos = pos_circuito4_11;
		r4c11.speed = 600.0;
		r4c12.pos = pos_circuito4_12;
		r4c12.speed = 600.0;

		if(!Airport::getInstance()->is_booked_landing())
		{
			Flight* primero = *(flights.begin());
			primero->getRoute()->clear();
		}

		for(it = flights.begin(); it!=flights.end(); ++it)
		{
			if((*it)->getRoute()->empty())
			{
				if(Airport::getInstance()->is_booked_landing())
				{
					if((*it)->getPosition().get_y() > 0 && (*it)->getPosition().get_x() > 8000){
						if((*it)->getPosition().get_y() < 10000)
								(*it)->getRoute()->push_back(r1c2);
						else if((*it)->getPosition().get_x() < 13000){
								(*it)->getRoute()->push_back(r1c4);
								(*it)->getRoute()->push_back(r1c1);
								(*it)->getRoute()->push_back(r1c2);
						}else{
							(*it)->getRoute()->push_back(r1c1);
							(*it)->getRoute()->push_back(r1c2);
						}
						(*it)->getRoute()->push_back(r1c3);
						(*it)->getRoute()->push_back(r1c4);
						(*it)->getRoute()->push_back(r1c5);
						(*it)->getRoute()->push_back(r1c6);
						(*it)->getRoute()->push_back(r1c7);
						(*it)->getRoute()->push_back(r1c8);
						(*it)->getRoute()->push_back(r1c9);
						(*it)->getRoute()->push_back(r1c10);
						(*it)->getRoute()->push_back(r1c11);
						(*it)->getRoute()->push_back(r1c12);
						(*it)->getRoute()->push_back(r1c5);
						(*it)->getRoute()->push_back(r1c6);
						(*it)->getRoute()->push_back(r1c7);
						(*it)->getRoute()->push_back(r1c8);

					}else if((*it)->getPosition().get_y() < 0 && (*it)->getPosition().get_x() > 8000){
						if((*it)->getPosition().get_y() > -10000)
								(*it)->getRoute()->push_back(r2c2);
						else if((*it)->getPosition().get_x() < 13000){
								(*it)->getRoute()->push_back(r2c4);
								(*it)->getRoute()->push_back(r2c1);
								(*it)->getRoute()->push_back(r2c2);
						}else{
							(*it)->getRoute()->push_back(r2c1);
							(*it)->getRoute()->push_back(r2c2);
						}
						(*it)->getRoute()->push_back(r2c3);
						(*it)->getRoute()->push_back(r2c4);
						(*it)->getRoute()->push_back(r2c5);
						(*it)->getRoute()->push_back(r2c6);
						(*it)->getRoute()->push_back(r2c7);
						(*it)->getRoute()->push_back(r2c8);
						(*it)->getRoute()->push_back(r2c9);
						(*it)->getRoute()->push_back(r2c10);
						(*it)->getRoute()->push_back(r2c11);
						(*it)->getRoute()->push_back(r2c12);
						(*it)->getRoute()->push_back(r2c5);
						(*it)->getRoute()->push_back(r2c6);
						(*it)->getRoute()->push_back(r2c7);
						(*it)->getRoute()->push_back(r2c8);

					}else if((*it)->getPosition().get_y() > 0 && (*it)->getPosition().get_x() < 8000){
						if((*it)->getPosition().get_x() < 2000)
								(*it)->getRoute()->push_back(r3c4);
						(*it)->getRoute()->push_back(r3c1);
						(*it)->getRoute()->push_back(r3c2);
						(*it)->getRoute()->push_back(r3c3);
						(*it)->getRoute()->push_back(r3c4);
						(*it)->getRoute()->push_back(r3c5);
						(*it)->getRoute()->push_back(r3c6);
						(*it)->getRoute()->push_back(r3c7);
						(*it)->getRoute()->push_back(r3c8);
						(*it)->getRoute()->push_back(r3c9);
						(*it)->getRoute()->push_back(r3c10);
						(*it)->getRoute()->push_back(r3c11);
						(*it)->getRoute()->push_back(r3c12);
						(*it)->getRoute()->push_back(r3c5);
						(*it)->getRoute()->push_back(r3c6);
						(*it)->getRoute()->push_back(r3c7);
						(*it)->getRoute()->push_back(r3c8);

					}else if((*it)->getPosition().get_y() < 0 && (*it)->getPosition().get_x() < 8000){
						if((*it)->getPosition().get_x() < 2000)
								(*it)->getRoute()->push_back(r4c4);
						(*it)->getRoute()->push_back(r4c1);
						(*it)->getRoute()->push_back(r4c2);
						(*it)->getRoute()->push_back(r4c3);
						(*it)->getRoute()->push_back(r4c4);
						(*it)->getRoute()->push_back(r4c5);
						(*it)->getRoute()->push_back(r4c6);
						(*it)->getRoute()->push_back(r4c7);
						(*it)->getRoute()->push_back(r4c8);
						(*it)->getRoute()->push_back(r4c9);
						(*it)->getRoute()->push_back(r4c10);
						(*it)->getRoute()->push_back(r4c11);
						(*it)->getRoute()->push_back(r4c12);
						(*it)->getRoute()->push_back(r4c5);
						(*it)->getRoute()->push_back(r4c6);
						(*it)->getRoute()->push_back(r4c7);
						(*it)->getRoute()->push_back(r4c8);
					}
				}else{
					Airport::getInstance()->book_landing((*it)->getId());
					(*it)->getRoute()->push_back(ra0);
					(*it)->getRoute()->push_back(ra1);
					(*it)->getRoute()->push_back(ra2);
					(*it)->getRoute()->push_back(ra3);
					}
				}
			}
}

}  // namespace atcsim
