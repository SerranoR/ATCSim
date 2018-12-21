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

Route
AirController::SetRoute(const Position& pos, const float& v)
{
	atcsim::Route r;
	r.pos = pos;
	r.speed = v;
	return r;
}

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


		//loop 1
		Position pos_loop1_1(x1, y1, z1_hi);
		Position pos_loop1_2(x1, y2, z1);
		Position pos_loop1_3(x2, y2, z1);
		Position pos_loop1_4(x2, y1, z1_lo);
		Position pos_loop1_5(x1, y1, z2_hi);
		Position pos_loop1_6(x1, y2, z2);
		Position pos_loop1_7(x2, y2, z2);
		Position pos_loop1_8(x2, y1, z2_lo);
		Position pos_loop1_9(x1, y1, z3_hi);
		Position pos_loop1_10(x1, y2, z3);
		Position pos_loop1_11(x2, y2, z3_lo);
		Position pos_loop1_12(x2, y1, z3_lo);
		//loop 2
		Position pos_loop2_1(x1, -y1, z1_hi);
		Position pos_loop2_2(x1, -y2, z1);
		Position pos_loop2_3(x2, -y2, z1);
		Position pos_loop2_4(x2, -y1, z1_lo);
		Position pos_loop2_5(x1, -y1, z2_hi);
		Position pos_loop2_6(x1, -y2, z2);
		Position pos_loop2_7(x2, -y2, z2);
		Position pos_loop2_8(x2, -y1, z2_lo);
		Position pos_loop2_9(x1, -y1, z3_hi);
		Position pos_loop2_10(x1, -y2, z3);
		Position pos_loop2_11(x2, -y2, z3_lo);
		Position pos_loop2_12(x2, -y1, z3_lo);
		//loop 3
		Position pos_loop3_1(x3, y1, z1_hi);
		Position pos_loop3_2(x3, y2, z1);
		Position pos_loop3_3(x4, y2, z1);
		Position pos_loop3_4(x4, y1, z1_lo);
		Position pos_loop3_5(x3, y1, z2_hi);
		Position pos_loop3_6(x3, y2, z2);
		Position pos_loop3_7(x4, y2, z2);
		Position pos_loop3_8(x4, y1, z2_lo);
		Position pos_loop3_9(x3, y1, z3_hi);
		Position pos_loop3_10(x3, y2, z3);
		Position pos_loop3_11(x4, y2, z3_lo);
		Position pos_loop3_12(x4, y1, z3_lo);
		//loop 4
		Position pos_loop4_1(x3, -y1, z1_hi);
		Position pos_loop4_2(x3, -y2, z1);
		Position pos_loop4_3(x4, -y2, z1);
		Position pos_loop4_4(x4, -y1, z1_lo);
		Position pos_loop4_5(x3, -y1, z2_hi);
		Position pos_loop4_6(x3, -y2, z2);
		Position pos_loop4_7(x4, -y2, z2);
		Position pos_loop4_8(x4, -y1, z2_lo);
		Position pos_loop4_9(x3, -y1, z3_hi);
		Position pos_loop4_10(x3, -y2, z3);
		Position pos_loop4_11(x4, -y2, z3_lo);
		Position pos_loop4_12(x4, -y1, z3_lo);

		Position pos0(3500.0, 0.0, 100.0);
		Position pos1(1500.0, 0.0, MAINTAIN_ALT);
		Position pos2(200.0, 0.0, 25.0);
		Position pos3(-750.0, 0.0, 25.0);

		Route rl0, rl1, rl2, rl3;
		Route rne1, rne2, rne3, rne4, rne5, rne6, rne7, rne8, rne9, rne10, rne11, rne12;
		Route rnw1, rnw2, rnw3, rnw4, rnw5, rnw6, rnw7, rnw8, rnw9, rnw10, rnw11, rnw12;
		Route rse1, rse2, rse3, rse4, rse5, rse6, rse7, rse8, rse9, rse10, rse11, rse12;
		Route rsw1, rsw2, rsw3, rsw4, rsw5, rsw6, rsw7, rsw8, rsw9, rsw10, rsw11, rsw12;

		//Landing
		rl0 = SetRoute(pos0, 500.0);
		rl1 = SetRoute(pos1, 100.0);
		rl2 = SetRoute(pos2, 19.0);
		rl3 = SetRoute(pos3, 15.0);
		//NorthEast circuit
		rne1 = SetRoute(pos_loop1_1, 800.0);
		rne2 = SetRoute(pos_loop1_2, 800.0);
		rne3 = SetRoute(pos_loop1_3, 800.0);
		rne4 = SetRoute(pos_loop1_4, 800.0);
		rne5 = SetRoute(pos_loop1_5, 800.0);
		rne6 = SetRoute(pos_loop1_6, 800.0);
		rne7 = SetRoute(pos_loop1_7, 600.0);
		rne8 = SetRoute(pos_loop1_8, 600.0);
		rne9 = SetRoute(pos_loop1_9, 600.0);
		rne10 = SetRoute(pos_loop1_10, 600.0);
		rne11 = SetRoute(pos_loop1_11, 600.0);
		rne12 = SetRoute(pos_loop1_11, 600.0);
		//NorthWest circuit
		rnw1 = SetRoute(pos_loop2_1, 800.0);
		rnw2 = SetRoute(pos_loop2_2, 800.0);
		rnw3 = SetRoute(pos_loop2_3, 800.0);
		rnw4 = SetRoute(pos_loop2_4, 800.0);
		rnw5 = SetRoute(pos_loop2_5, 800.0);
		rnw6 = SetRoute(pos_loop2_6, 800.0);
		rnw7 = SetRoute(pos_loop2_7, 600.0);
		rnw8 = SetRoute(pos_loop2_8, 600.0);
		rnw9 = SetRoute(pos_loop2_9, 600.0);
		rnw10 = SetRoute(pos_loop2_10, 600.0);
		rnw11 = SetRoute(pos_loop2_11, 600.0);
		rnw12 = SetRoute(pos_loop2_11, 600.0);
		//SouthEast circuit
		rse1 = SetRoute(pos_loop3_1, 800.0);
		rse2 = SetRoute(pos_loop3_2, 800.0);
		rse3 = SetRoute(pos_loop3_3, 800.0);
		rse4 = SetRoute(pos_loop3_4, 800.0);
		rse5 = SetRoute(pos_loop3_5, 800.0);
		rse6 = SetRoute(pos_loop3_6, 800.0);
		rse7 = SetRoute(pos_loop3_7, 600.0);
		rse8 = SetRoute(pos_loop3_8, 600.0);
		rse9 = SetRoute(pos_loop3_9, 600.0);
		rse10 = SetRoute(pos_loop3_10, 600.0);
		rse11 = SetRoute(pos_loop3_11, 600.0);
		rse12 = SetRoute(pos_loop3_11, 600.0);
		//SouthWest circuit
		rsw1 = SetRoute(pos_loop4_1, 800.0);
		rsw2 = SetRoute(pos_loop4_2, 800.0);
		rsw3 = SetRoute(pos_loop4_3, 800.0);
		rsw4 = SetRoute(pos_loop4_4, 800.0);
		rsw5 = SetRoute(pos_loop4_5, 800.0);
		rsw6 = SetRoute(pos_loop4_6, 800.0);
		rsw7 = SetRoute(pos_loop4_7, 600.0);
		rsw8 = SetRoute(pos_loop4_8, 600.0);
		rsw9 = SetRoute(pos_loop4_9, 600.0);
		rsw10 = SetRoute(pos_loop4_10, 600.0);
		rsw11 = SetRoute(pos_loop4_11, 600.0);
		rsw12 = SetRoute(pos_loop4_11, 600.0);


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
								(*it)->getRoute()->push_back(rne2);
						else if((*it)->getPosition().get_x() < 13000){
								(*it)->getRoute()->push_back(rne4);
								(*it)->getRoute()->push_back(rne1);
								(*it)->getRoute()->push_back(rne2);
						}else{
							(*it)->getRoute()->push_back(rne1);
							(*it)->getRoute()->push_back(rne2);
						}
						(*it)->getRoute()->push_back(rne3);
						(*it)->getRoute()->push_back(rne4);
						(*it)->getRoute()->push_back(rne5);
						(*it)->getRoute()->push_back(rne6);
						(*it)->getRoute()->push_back(rne7);
						(*it)->getRoute()->push_back(rne8);
						(*it)->getRoute()->push_back(rne9);
						(*it)->getRoute()->push_back(rne10);
						(*it)->getRoute()->push_back(rne11);
						(*it)->getRoute()->push_back(rne12);
						(*it)->getRoute()->push_back(rne5);
						(*it)->getRoute()->push_back(rne6);
						(*it)->getRoute()->push_back(rne7);
						(*it)->getRoute()->push_back(rne8);

					}else if((*it)->getPosition().get_y() < 0 && (*it)->getPosition().get_x() > 8000){
						if((*it)->getPosition().get_y() > -10000)
								(*it)->getRoute()->push_back(rnw2);
						else if((*it)->getPosition().get_x() < 13000){
								(*it)->getRoute()->push_back(rnw4);
								(*it)->getRoute()->push_back(rnw1);
								(*it)->getRoute()->push_back(rnw2);
						}else{
							(*it)->getRoute()->push_back(rnw1);
							(*it)->getRoute()->push_back(rnw2);
						}
						(*it)->getRoute()->push_back(rnw3);
						(*it)->getRoute()->push_back(rnw4);
						(*it)->getRoute()->push_back(rnw5);
						(*it)->getRoute()->push_back(rnw6);
						(*it)->getRoute()->push_back(rnw7);
						(*it)->getRoute()->push_back(rnw8);
						(*it)->getRoute()->push_back(rnw9);
						(*it)->getRoute()->push_back(rnw10);
						(*it)->getRoute()->push_back(rnw11);
						(*it)->getRoute()->push_back(rnw12);
						(*it)->getRoute()->push_back(rnw5);
						(*it)->getRoute()->push_back(rnw6);
						(*it)->getRoute()->push_back(rnw7);
						(*it)->getRoute()->push_back(rnw8);

					}else if((*it)->getPosition().get_y() > 0 && (*it)->getPosition().get_x() < 8000){
						if((*it)->getPosition().get_x() < 2000)
								(*it)->getRoute()->push_back(rse4);
						(*it)->getRoute()->push_back(rse1);
						(*it)->getRoute()->push_back(rse2);
						(*it)->getRoute()->push_back(rse3);
						(*it)->getRoute()->push_back(rse4);
						(*it)->getRoute()->push_back(rse5);
						(*it)->getRoute()->push_back(rse6);
						(*it)->getRoute()->push_back(rse7);
						(*it)->getRoute()->push_back(rse8);
						(*it)->getRoute()->push_back(rse9);
						(*it)->getRoute()->push_back(rse10);
						(*it)->getRoute()->push_back(rse11);
						(*it)->getRoute()->push_back(rse12);
						(*it)->getRoute()->push_back(rse5);
						(*it)->getRoute()->push_back(rse6);
						(*it)->getRoute()->push_back(rse7);
						(*it)->getRoute()->push_back(rse8);

					}else if((*it)->getPosition().get_y() < 0 && (*it)->getPosition().get_x() < 8000){
						if((*it)->getPosition().get_x() < 2000)
								(*it)->getRoute()->push_back(rsw4);
						(*it)->getRoute()->push_back(rsw1);
						(*it)->getRoute()->push_back(rsw2);
						(*it)->getRoute()->push_back(rsw3);
						(*it)->getRoute()->push_back(rsw4);
						(*it)->getRoute()->push_back(rsw5);
						(*it)->getRoute()->push_back(rsw6);
						(*it)->getRoute()->push_back(rsw7);
						(*it)->getRoute()->push_back(rsw8);
						(*it)->getRoute()->push_back(rsw9);
						(*it)->getRoute()->push_back(rsw10);
						(*it)->getRoute()->push_back(rsw11);
						(*it)->getRoute()->push_back(rsw12);
						(*it)->getRoute()->push_back(rsw5);
						(*it)->getRoute()->push_back(rsw6);
						(*it)->getRoute()->push_back(rsw7);
						(*it)->getRoute()->push_back(rsw8);
					}
				}else{
					Airport::getInstance()->book_landing((*it)->getId());
					(*it)->getRoute()->push_back(rl0);
					(*it)->getRoute()->push_back(rl1);
					(*it)->getRoute()->push_back(rl2);
					(*it)->getRoute()->push_back(rl3);
					}
				}
			}
}

}  // namespace atcsim
