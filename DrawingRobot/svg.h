#pragma once

#include "svgdom\dom.hpp"
#include "papki\FSFile.hpp"
#include "Kinematics.h"



//Coordenadas absolutas y unidades en mm.
//Restar Offset de Y dependiendo Width and Height (viewBox). Ver en inkscape cuanto tenemos que restar a Y para que cuadre la coordenada {0,0}.
//Definir viewBox (en base al workplace del brazo scara) y offset para calcular Y

//Agrupar PATH's por PATHID cuando exista???

//ReachaableWorkSpace(RWS) r1=L1+l2,r2=|l1-l2|, DexterousWorkSpace(DWS)=null,joint limists???

const float OFFSET_Y = 298.868;
const float OFFSET_X = 88.0;


namespace svg {

	

	struct coordinate {
		svgdom::real x, y;
		bool difference = false;
		float t;
		int speedX;
		int	speedY;
		int interpolateX;
		int interpolateY;
	}_coordinate;
	//lista de coordenadas
	struct coordinates {
		std::list<svg::coordinate> coordinate;
	}_coordinates; 

	//coordenadas beizerCubic and kinematics degrees.
	struct beizer {
		std::list<svg::coordinates> coordinates;
		std::list<svg::coordinates> degrees;
		std::list<svg::coordinates> angles;
	};
	//lista de coordenadas por tipo
	struct path {
		std::string path_id;
		std::list<std::string> type;
		std::list<svg::coordinates> coordinates;	
		//std::list<svg::coordinates> full_coordinates;
		//std::list<svg::coordinates> full_coordinates_degree;	
		std::list<svg::beizer> _beizer;
	}_path;

	//lista de paths
	struct paths {
		std::list<svg::path> paths;
	}_paths;

	coordinate _current_coordinate;


	//Visitor to remove all Line elements
	class Visitor : public svgdom::Visitor {

		svg::coordinate prev_feed;

		float mix(float a, float b, float t)
		{
			// degree 1
			return a * (1.0f - t) + b * t;
		}

		float _bezierQuadratic(float A, float B, float C, float t)
		{
			// degree 2
			float AB = mix(A, B, t);
			float BC = mix(B, C, t);
			return mix(AB, BC, t);
		}

		float _bezierCubic(float A, float B, float C, float D, float t)
		{
			// degree 3
			float ABC = _bezierQuadratic(A, B, C, t);
			float BCD = _bezierQuadratic(B, C, D, t);
			return mix(ABC, BCD, t);
		}


		svg::beizer beizerCubic(svg::coordinate P1, svg::coordinate P2, svg::coordinate P3, svg::coordinate P4) {
			
			svg::coordinates _coordinates;
			svg::coordinates _degrees;
			svg::coordinates _angles;
			svg::coordinate feed;
			svg::beizer _beizer;
			
			float x, y;
			
			prev_feed.x = -1;
			prev_feed.y = -1;

			const float c_numPoints = 1000;
			//for (int i = 0; i < c_numPoints; i +=8)
			for (int i = 0; i < c_numPoints; i +=50)
			//for (int i = 0; i < c_numPoints; ++i)
			{
				float t = ((float)i) / (float(c_numPoints - 1));

				x = _bezierCubic(P1.x, P2.x, P3.x, P4.x, t);
				y = _bezierCubic(P1.y, P2.y, P3.y, P4.y, t);
				
				degrees _degree = calculaCinematica2dof(Eigen::Vector2f(x,y));
				feed.x = _degree.shoulder_bio_degree;
				feed.y = _degree.elbow_bio_degree;
				feed.t = t;
				//_degrees.coordinate.push_back(feed);
				_degrees.coordinate.push_back(interPolateSetup(prev_feed, feed));
				prev_feed.x = _degree.shoulder_bio_degree;
				prev_feed.y = _degree.elbow_bio_degree;


				feed.x = _degree.shoulder_angle;
				feed.y = _degree.elbow_angle;	
				_angles.coordinate.push_back(feed);
				

				feed.x = x;
				feed.y = y;
				_coordinates.coordinate.push_back(feed);
				
				//_degrees.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_bio_degree, (svgdom::real)_degree.elbow_bio_degree});
				//_angles.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_angle, (svgdom::real)_degree.elbow_angle });
				//_coordinates.coordinate.push_back(_coordinate = { (svgdom::real)x, (svgdom::real)y });
				
				//printf("point at time %0.2f = (%0.2f, %0.2f)\n", t, x, y);

			}
			
			//_coordinates.coordinate.unique(is_idem());
			_degrees.coordinate.unique(is_idem());
			//_angles.coordinate.unique(is_idem());
			
			//_coordinates.coordinate.unique(is_XorYidem());
			//_degrees.coordinate.unique(is_XorYidem());
			//_angles.coordinate.unique(is_XorYidem());
			
			_beizer.coordinates.push_back(_coordinates);
			_beizer.angles.push_back(_angles);
			_beizer.degrees.push_back(_degrees);
			//_beizer.degrees.push_back(fillTheGap(_degrees));
			
			
			return _beizer;
		}

		svg::coordinate interPolateSetup(svg::coordinate pose, svg::coordinate nextpose) {
			
			svg::coordinate feed = pose;

			int time = 200;
			int frameLength = 33;

			int frames = (time / frameLength) + 1;
		

			if (pose.x == -1 && pose.y == -1) {
				svg::coordinate _feed = nextpose;
				_feed.interpolateX = _feed.x;
				_feed.interpolateY = _feed.y;
				return _feed;
			}else {

				if (nextpose.x > pose.x) {
					feed.speedX = ((nextpose.x - pose.x) / frames) + 1;
				}else {
					feed.speedX = ((pose.x - nextpose.x) / frames) + 1;
				}

				if (nextpose.y > pose.y) {
					feed.speedY = ((nextpose.y - pose.y) / frames) + 1;
				}
				else {
					feed.speedY= ((pose.y - nextpose.y) / frames) + 1;
				}
			
				int diffX = nextpose.x - pose.x;
				int diffY = nextpose.y - pose.y;

				if (diffX == 0) {
					feed.interpolateX = feed.x;
				}else {
					if (diffX > 0) {
						if (diffX < feed.speedX) {
							feed.interpolateX = nextpose.x;
						}else {
							feed.interpolateX = feed.x + feed.speedX;
						}
					}else {
						if ((-diffX) < feed.speedX) {
							feed.interpolateX = nextpose.x;
						}else {
							feed.interpolateX = feed.x - feed.speedX;
						}
					}
				}

				if (diffY == 0) {
					feed.interpolateY = feed.y;
				}
				else {
					if (diffY > 0) {
						if (diffY < feed.speedY) {
							feed.interpolateY = nextpose.y;
						}
						else {
							feed.interpolateY = feed.y + feed.speedY;
						}
					}
					else {
						if ((-diffY) < feed.speedY) {
							feed.interpolateY = nextpose.y;
						}
						else {
							feed.interpolateY = feed.y - feed.speedY;
						}
					}
				}
			return feed;
			}
		}

		svg::coordinates fillTheGap(svg::coordinates list) {
			
			svg::coordinates result;
			svg::coordinate feed;

			for (auto it1 = list.coordinate.begin(), it2 = ++list.coordinate.begin(); it2 != list.coordinate.end(); ++it1, ++it2) {
				
			    int gapX = abs(it1._Ptr->_Myval.x - it2._Ptr->_Myval.x) ;
				int gapY = abs(it1._Ptr->_Myval.y - it2._Ptr->_Myval.y) ;
				//veces que itera el mayor gap
				int maxSteps = 0;
				int minSteps = 0;
				(abs(gapX) > abs(gapY)) ? maxSteps = gapX : maxSteps = gapY;
				(abs(gapX) > abs(gapY)) ? minSteps = gapY : minSteps = gapX;
				if (maxSteps == 0 || minSteps == 0){
					feed = { it1._Ptr->_Myval.x, it1._Ptr->_Myval.y };
					feed.difference = false;
					result.coordinate.push_back(feed);
					continue;
				}
				//veces que itera el menor gap
				int max_divide_min_Steps = maxSteps/minSteps;
				int resto_max_divide_min_Steps = maxSteps%minSteps;
				bool x = false;
				bool y = false;
				if (abs(gapX) > abs(gapY)) {
					x = true;
				}
				if (abs(gapX) < abs(gapY)) {
					y = true;
				}

				int universal_gap = 1;
				svgdom::real resto;

				if (it1._Ptr->_Myval.x > it2._Ptr->_Myval.x) {
					//X descent
					if (it1._Ptr->_Myval.y > it2._Ptr->_Myval.y) {
						//X descent and Y descent
						// X mayor gap
						if (x) {
							for (int i = 0; i < gapX; ++i) {

								if (i == 0 && max_divide_min_Steps != 1) {
									feed = {  it1._Ptr->_Myval.x - (i + 1),it1._Ptr->_Myval.y - (universal_gap) };

								}
								else if (max_divide_min_Steps == 1) {
									if ((gapX - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { it1._Ptr->_Myval.x - (i + 1),resto };
									}
									else {
										feed = { it1._Ptr->_Myval.x - (i + 1),it1._Ptr->_Myval.y - (universal_gap++), };
										resto = feed.y;
									}
								}
								else {
									if ((gapX - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { it1._Ptr->_Myval.x - (i + 1),resto};
									}
									else if ((max_divide_min_Steps % (i)) != 0) {

										feed = { it1._Ptr->_Myval.x - (i + 1) ,it1._Ptr->_Myval.y - (universal_gap) };
										resto = feed.y;
									}
									else {
										feed = { it1._Ptr->_Myval.x - (i + 1) ,it1._Ptr->_Myval.y - (++universal_gap) };
										resto = feed.y;
									}
								}
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}else if (y) {
							for (int i = 0; i < gapY; ++i) {

								if (i == 0 && max_divide_min_Steps != 1) {
									feed = { it1._Ptr->_Myval.x - (universal_gap) , it1._Ptr->_Myval.y - (i + 1) };

								}else if (max_divide_min_Steps == 1){
									if ((gapY - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { resto ,it1._Ptr->_Myval.y - (i + 1) };
									}else {
										feed = { it1._Ptr->_Myval.x - (universal_gap++),it1._Ptr->_Myval.y - (i + 1) };
										resto = feed.x;
									}
								}else {
									if ((gapY - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { resto ,it1._Ptr->_Myval.y - (i + 1) };
									}else if ((max_divide_min_Steps%(i)) != 0) {

										feed = { it1._Ptr->_Myval.x - (universal_gap) , it1._Ptr->_Myval.y - (i + 1) };
										resto = feed.x;
									}
									else {
										feed = { it1._Ptr->_Myval.x - (++universal_gap),it1._Ptr->_Myval.y - (i + 1) };
										resto = feed.x;
									}
								}	
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}else {
							for (int i = 0; i < gapY; ++i) {
								feed = { it1._Ptr->_Myval.x - (i + 1),it1._Ptr->_Myval.y - (i + 1) };
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
					}else {
						//X descent and Y Ascent
						// X mayor gap
						if (x) {
							for (int i = 0; i < gapX; ++i) {

								if (i == 0 && max_divide_min_Steps != 1) {
									feed = { it1._Ptr->_Myval.x - (i + 1),it1._Ptr->_Myval.y + (universal_gap) };

								}
								else if (max_divide_min_Steps == 1) {
									if ((gapX - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { it1._Ptr->_Myval.x - (i + 1),resto };
									}
									else {
										feed = { it1._Ptr->_Myval.x - (i + 1),it1._Ptr->_Myval.y + (universal_gap++), };
										resto = feed.y;
									}
								}
								else {
									if ((gapX - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { it1._Ptr->_Myval.x - (i + 1),resto };
									}
									else if ((max_divide_min_Steps % (i)) != 0) {

										feed = { it1._Ptr->_Myval.x - (i + 1) ,it1._Ptr->_Myval.y + (universal_gap) };
										resto = feed.y;
									}
									else {
										feed = { it1._Ptr->_Myval.x - (i + 1) ,it1._Ptr->_Myval.y + (++universal_gap) };
										resto = feed.y;
									}
								}
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
						else if (y) {
							for (int i = 0; i < gapY; ++i) {

								if (i == 0 && max_divide_min_Steps != 1) {
									feed = { it1._Ptr->_Myval.x - (universal_gap) , it1._Ptr->_Myval.y + (i + 1) };

								}
								else if (max_divide_min_Steps == 1) {
									if ((gapY - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { resto ,it1._Ptr->_Myval.y + (i + 1) };
									}
									else {
										feed = { it1._Ptr->_Myval.x - (universal_gap++),it1._Ptr->_Myval.y + (i + 1) };
										resto = feed.x;
									}
								}
								else {
									if ((gapY - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { resto ,it1._Ptr->_Myval.y + (i + 1) };
									}
									else if ((max_divide_min_Steps % (i)) != 0) {

										feed = { it1._Ptr->_Myval.x - (universal_gap) , it1._Ptr->_Myval.y + (i + 1) };
										resto = feed.x;
									}
									else {
										feed = { it1._Ptr->_Myval.x - (++universal_gap),it1._Ptr->_Myval.y + (i + 1) };
										resto = feed.x;
									}
								}
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
						else {
							for (int i = 0; i < gapY; ++i) {
								feed = { it1._Ptr->_Myval.x - (i + 1),it1._Ptr->_Myval.y + (i + 1) };
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
					}
				}else {
					//X Ascent
					if (it1._Ptr->_Myval.y> it2._Ptr->_Myval.y) {
						//X ascent and Y descent
						// X mayor gap
						if (x) {
							for (int i = 0; i < gapX; ++i) {

								if (i == 0 && max_divide_min_Steps != 1) {
									feed = { it1._Ptr->_Myval.x + (i + 1),it1._Ptr->_Myval.y - (universal_gap) };

								}
								else if (max_divide_min_Steps == 1) {
									if ((gapX - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { it1._Ptr->_Myval.x + (i + 1),resto };
									}
									else {
										feed = { it1._Ptr->_Myval.x + (i + 1),it1._Ptr->_Myval.y - (universal_gap++), };
										resto = feed.y;
									}
								}
								else {
									if ((gapX - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { it1._Ptr->_Myval.x + (i + 1),resto , };
									}
									else if ((max_divide_min_Steps % (i)) != 0) {

										feed = { it1._Ptr->_Myval.x + (i + 1) ,it1._Ptr->_Myval.y - (universal_gap) };
										resto = feed.y;
									}
									else {
										feed = { it1._Ptr->_Myval.x + (i + 1) ,it1._Ptr->_Myval.y - (++universal_gap) };
										resto = feed.y;
									}
								}
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
						else if (y) {
							for (int i = 0; i < gapY; ++i) {

								if (i == 0 && max_divide_min_Steps != 1) {
									feed = { it1._Ptr->_Myval.x + (universal_gap) , it1._Ptr->_Myval.y - (i + 1) };

								}
								else if (max_divide_min_Steps == 1) {
									if ((gapY - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { resto ,it1._Ptr->_Myval.y - (i + 1) };
									}
									else {
										feed = { it1._Ptr->_Myval.x + (universal_gap++),it1._Ptr->_Myval.y - (i + 1) };
										resto = feed.x;
									}
								}
								else {
									if ((gapY - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { resto ,it1._Ptr->_Myval.y - (i + 1) };
									}
									else if ((max_divide_min_Steps % (i)) != 0) {

										feed = { it1._Ptr->_Myval.x + (universal_gap) , it1._Ptr->_Myval.y - (i + 1) };
										resto = feed.x;
									}
									else {
										feed = { it1._Ptr->_Myval.x + (++universal_gap),it1._Ptr->_Myval.y - (i + 1) };
										resto = feed.x;
									}
								}
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
						else {
							for (int i = 0; i < gapY; ++i) {
								feed = { it1._Ptr->_Myval.x + (i + 1),it1._Ptr->_Myval.y - (i + 1) };
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
					}else {
						//X Ascent and Y Ascent
						// X mayor gap
						if (x) {
							for (int i = 0; i < gapX; ++i) {

								if (i == 0 && max_divide_min_Steps != 1) {
									feed = { it1._Ptr->_Myval.x + (i + 1),it1._Ptr->_Myval.y + (universal_gap) };

								}
								else if (max_divide_min_Steps == 1) {
									if ((gapX - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { it1._Ptr->_Myval.x + (i + 1),resto };
									}
									else {
										feed = { it1._Ptr->_Myval.x + (i + 1),it1._Ptr->_Myval.y + (universal_gap++), };
										resto = feed.y;
									}
								}
								else {
									if ((gapX - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { it1._Ptr->_Myval.x + (i + 1),resto , };
									}
									else if ((max_divide_min_Steps % (i)) != 0) {

										feed = { it1._Ptr->_Myval.x + (i + 1) ,it1._Ptr->_Myval.y + (universal_gap) };
										resto = feed.y;
									}
									else {
										feed = { it1._Ptr->_Myval.x + (i + 1) ,it1._Ptr->_Myval.y + (++universal_gap) };
										resto = feed.y;
									}
								}
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
						else if (y) {
							for (int i = 0; i < gapY; ++i) {

								if (i == 0 && max_divide_min_Steps != 1) {
									feed = { it1._Ptr->_Myval.x + (universal_gap) , it1._Ptr->_Myval.y + (i + 1) };

								}
								else if (max_divide_min_Steps == 1) {
									if ((gapY - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { resto ,it1._Ptr->_Myval.y + (i + 1) };
									}
									else {
										feed = { it1._Ptr->_Myval.x + (universal_gap++),it1._Ptr->_Myval.y + (i + 1) };
										resto = feed.x;
									}
								}
								else {
									if ((gapY - i) == resto_max_divide_min_Steps) {
										resto_max_divide_min_Steps--;
										feed = { resto ,it1._Ptr->_Myval.y + (i + 1) };
									}
									else if ((max_divide_min_Steps % (i)) != 0) {

										feed = { it1._Ptr->_Myval.x + (universal_gap) , it1._Ptr->_Myval.y + (i + 1) };
										resto = feed.x;
									}
									else {
										feed = { it1._Ptr->_Myval.x + (++universal_gap),it1._Ptr->_Myval.y + (i + 1) };
										resto = feed.x;
									}
								}

								result.coordinate.push_back(feed);
							}
						}
						else {
							for (int i = 0; i < gapY; ++i) {
								feed = { it1._Ptr->_Myval.x + (i + 1),it1._Ptr->_Myval.y + (i + 1) };
								feed.difference = true;
								result.coordinate.push_back(feed);
							}
						}
					}
				}				
			}

			//result.coordinate.push_front(list.coordinate.begin()._Ptr->_Myval);
			//result.coordinate.push_back(list.coordinate.end()._Ptr->_Myval);
			
			return result;
		}

		struct is_idem {
			bool operator() (coordinate first, coordinate second)
			{
				if ((first.x == second.x && first.y == second.y) ) {
					return true;
				}
				else {
					return false;
				}
			}
		};
		struct is_XorYidem {
			bool operator() (coordinate first, coordinate second)
			{
				if (first.x == second.x || first.y == second.y) {
					return true;
				}
				else {
					return false;
				}
			}
		};
		//simple linear interpolation between two points
		void lerp(coordinate& dest, const coordinate& a, const coordinate& b, const float t)
		{
			dest.x = a.x + (b.x - a.x)*t;
			dest.y = a.y + (b.y - a.y)*t;
		}

		// evaluate a point on a bezier-curve. t goes from 0 to 1.0
		void bezier2(coordinate &dest, const coordinate& a, const coordinate& b, const coordinate& c, const coordinate& d, const float t)
		{
			coordinate ab, bc, cd, abbc, bccd;
			lerp(ab, a, b, t);           // point between a and b (green)
			lerp(bc, b, c, t);           // point between b and c (green)
			lerp(cd, c, d, t);           // point between c and d (green)
			lerp(abbc, ab, bc, t);       // point between ab and bc (blue)
			lerp(bccd, bc, cd, t);       // point between bc and cd (blue)
			lerp(dest, abbc, bccd, t);   // point on the bezier-curve (black)
		}
		svg::beizer bezier2(svg::coordinate P1, svg::coordinate P2, svg::coordinate P3, svg::coordinate P4) {
			svg::coordinates _coordinates;
			svg::coordinates _degrees;
			svg::coordinates _angles;

			svg::beizer _beizer;

			float x, y;
			for (int i = 0; i < 1000; i++)
			{

				coordinate p;
				float t = static_cast<float>(i) / 999.0;
				bezier2(p, P1, P2, P3, P4, t);

				degrees _degree = calculaCinematica2dof(Eigen::Vector2f(p.x, p.y));
				_degrees.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_bio_degree, (svgdom::real)_degree.elbow_bio_degree });
				_angles.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_angle, (svgdom::real)_degree.elbow_angle });
				_coordinates.coordinate.push_back(_coordinate = { (svgdom::real)p.x, (svgdom::real)p.y });
			}

			//_coordinates.coordinate.unique(is_idem());
			//_degrees.coordinate.unique(is_idem());
			//_angles.coordinate.unique(is_idem());
			_beizer.coordinates.push_back(_coordinates);
			_beizer.degrees.push_back(_degrees);
			_beizer.angles.push_back(_angles);
			return _beizer;

		}

	void getType(std::vector<svgdom::PathElement::Step>::iterator it, std::string id) {
		
			std::string currentPath;

			(id != "") ? id : id = "NO_ID";
			
			switch (it._Ptr->type) {
			case svgdom::PathElement::Step::Type_e::MOVE_ABS: {
				/**TRACE(<< id << " " << "MOVE_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/

				_path.type.push_back("MOVE_ABS");				
				
				_coordinates.coordinate.push_back(_coordinate = { it._Ptr->x + OFFSET_X, abs (OFFSET_Y -it._Ptr->y) });
				_path.coordinates.push_back(_coordinates);
				
				
				svg::coordinates _beizer_coordinates;
				svg::coordinates _beizer_degrees;
				svg::coordinates _beizer_angles;

				svg::beizer _beizer;

				//OJO MODIFICAMOS x=y y=x
				degrees _degree = calculaCinematica2dof(Eigen::Vector2f(it._Ptr->x + OFFSET_X, abs(OFFSET_Y - it._Ptr->y)));
				//degrees _degree = calculaCinematica2dof(Eigen::Vector2f( abs(OFFSET_Y - it._Ptr->y), it._Ptr->x + OFFSET_X));
				

				svg::coordinate feed;
				feed.x = _degree.shoulder_bio_degree;
				feed.y = _degree.elbow_bio_degree;
				feed.interpolateX = feed.x;
				feed.interpolateY = feed.y;

				//_beizer_degrees.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_bio_degree, (svgdom::real)_degree.elbow_bio_degree });
				_beizer_degrees.coordinate.push_back(feed);
				_beizer_angles.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_angle, (svgdom::real)_degree.elbow_angle });
				_beizer_coordinates.coordinate.push_back(_coordinate = { it._Ptr->x + OFFSET_X , abs(OFFSET_Y - it._Ptr->y) });
				
				_beizer.coordinates.push_back(_beizer_coordinates);
				_beizer.degrees.push_back(_beizer_degrees);
				_beizer.angles.push_back(_beizer_angles);
				
				_path._beizer.push_back(_beizer);
								
				_coordinates.coordinate.clear();
				_current_coordinate = { it._Ptr->x + OFFSET_X, abs( OFFSET_Y - it._Ptr->y )};
						
				break;
			}
			case svgdom::PathElement::Step::Type_e::MOVE_REL: {
				/**TRACE(<< id << " " << "MOVE_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;
			}
			case svgdom::PathElement::Step::Type_e::LINE_ABS: {
				/**TRACE(<< id << " " << "LINE_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/

				break;
			}
			case svgdom::PathElement::Step::Type_e::LINE_REL: {
				/**TRACE(<< id << " " << "LINE_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/

				break;
			}
			case svgdom::PathElement::Step::Type_e::HORIZONTAL_LINE_ABS: {
				/**TRACE(<< id << " " << "HORIZONTAL_LINE_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/

				break;
			}
			case svgdom::PathElement::Step::Type_e::HORIZONTAL_LINE_REL: {
				/**TRACE(<< id << " " << "HORIZONTAL_LINE_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/

				break;
			}
			case svgdom::PathElement::Step::Type_e::VERTICAL_LINE_ABS: {
				/**TRACE(<< id << " " << "VERTICAL_LINE_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/

				break;
			}
			case svgdom::PathElement::Step::Type_e::VERTICAL_LINE_REL: {
				/**TRACE(<< id << " " << "VERTICAL_LINE_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/

				break;
			}
			case svgdom::PathElement::Step::Type_e::CUBIC_ABS: {
				/**TRACE(<< id << " " << "CUBIC_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				
				_path.type.push_back("CUBIC_ABS");
				
				_coordinates.coordinate.push_back(_current_coordinate);
				_coordinates.coordinate.push_back(_coordinate = { it._Ptr->x + OFFSET_X, abs (OFFSET_Y - it._Ptr->y) });
				_coordinates.coordinate.push_back(_coordinate = { it._Ptr->x1 + OFFSET_X, abs (OFFSET_Y - it._Ptr->y2) });
				_coordinates.coordinate.push_back(_coordinate = { it._Ptr->x2 + OFFSET_X, abs (OFFSET_Y - it._Ptr->y2) });
				_path.coordinates.push_back(_coordinates);
				
				//calucalmos las coordenadas beizer y los grados de la kinematica.
				svg::beizer _beizer = beizerCubic(_current_coordinate, { it._Ptr->x1 + OFFSET_X, abs(OFFSET_Y - it._Ptr->y1) }, { it._Ptr->x2 + OFFSET_X, abs(OFFSET_Y - it._Ptr->y2) }, { it._Ptr->x + OFFSET_X , abs(OFFSET_Y - it._Ptr->y) });
				//svg::beizer _beizer = bezier2(_current_coordinate, { it._Ptr->x1 + OFFSET_X, abs(OFFSET_Y - it._Ptr->y1) }, { it._Ptr->x2 + OFFSET_X, abs(OFFSET_Y - it._Ptr->y2) }, { it._Ptr->x + OFFSET_X , abs(OFFSET_Y - it._Ptr->y) });
				_path._beizer.push_back(_beizer);
				
				_coordinates.coordinate.clear();
				_current_coordinate = { it._Ptr->x + OFFSET_X, abs(OFFSET_Y - it._Ptr->y) };
				
				break;
			}
			case svgdom::PathElement::Step::Type_e::CUBIC_REL: {
				/**TRACE(<< id << " " << "CUBIC_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;
			}
			case svgdom::PathElement::Step::Type_e::CUBIC_SMOOTH_ABS: {
				/**TRACE(<< id << " " << "CUBIC_SMOOTH_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;
			case svgdom::PathElement::Step::Type_e::CUBIC_SMOOTH_REL: {
				/**TRACE(<< id << " " << "CUBIC_SMOOTH_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);
				break;
			}
			case svgdom::PathElement::Step::Type_e::QUADRATIC_ABS: {
				/**TRACE(<< id << " " << "QUADRATIC_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;
			}
			case svgdom::PathElement::Step::Type_e::QUADRATIC_REL: {
				/**TRACE(<< id << " " << "QUADRATIC_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;
			}
			case svgdom::PathElement::Step::Type_e::QUADRATIC_SMOOTH_ABS: {
				/**TRACE(<< id << " " << "QUADRATIC_SMOOTH_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;
			}
			case svgdom::PathElement::Step::Type_e::QUADRATIC_SMOOTH_REL: {
				/**TRACE(<< id << " " << "QUADRATIC_SMOOTH_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;

			}
			case svgdom::PathElement::Step::Type_e::ARC_ABS: {
				/**TRACE(<< id << " " << "ARC_ABS" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;
			}
			case svgdom::PathElement::Step::Type_e::ARC_REL: {
				/**TRACE(<< id << " " << "ARC_REL" << " x=" << it._Ptr->x << " y=" << it._Ptr->y
					<< " rx=" << it._Ptr->rx << " ry=" << it._Ptr->ry
					<< " x1=" << it._Ptr->x1 << " y1=" << it._Ptr->y1
					<< " x2=" << it._Ptr->x2 << " y2=" << it._Ptr->y2
					<< "xAxisRot=" << it._Ptr->xAxisRotation
					<< std::endl);*/
				break;
			}
			default: {}
			}

			}
		}

	public:

		void visit(svgdom::SvgElement& e) override {
			this->relayAccept(e);
		}
		void visit(svgdom::GElement& e) override {
			this->relayAccept(e);
		}
		void visit(svgdom::DefsElement& e) override {

			TRACE(<< " DefsElement ID = " << e.id << std::endl);
		}
		void visit(svgdom::RectElement& e) override {

			TRACE(<< e.id << " " << "rx=" << e.rx << " ry=" << e.ry << std::endl);
		}
		void visit(svgdom::PathElement& e) override {

			for (auto it = e.path.begin(); it != e.path.end(); it++) {
				getType(it, e.id);
			}
			_path.path_id = e.id;
			_paths.paths.push_back(_path);
			
			_path.type.clear();
			_path.coordinates.clear();
			_path._beizer.clear();
			
			//_path.full_coordinates.clear();

		}
		void visit(svgdom::LineElement& e) override {
			TRACE(<< e.id << " " << "x1=" << e.x1 << " y1=" << e.y1 << " x2=" << e.x2 << " y2=" << e.y2 << std::endl);
		}
		void visit(svgdom::CircleElement& e) override {
			TRACE(<< e.id << " " << "cx=" << e.cx << " cy=" << e.cy << " r=" << e.r << std::endl);
		}
		void visit(svgdom::EllipseElement& e) override { 
			TRACE(<< " EllipseElement ID = " << e.id << std::endl);
		}
		void visit(svgdom::PolylineElement& e) override {
			TRACE(<< " PolylineElement ID = " << e.id << std::endl);
		}
		void visit(svgdom::PolygonElement& e) override {
			TRACE(<< " PolygonElement ID = " << e.id << std::endl);
		}

	};

	Visitor visitor;
}