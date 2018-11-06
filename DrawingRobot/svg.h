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
			
			svg::beizer _beizer;

			float x, y;

			for (float i = 0.0; i < 1.0; i += 0.009)
			{
				x = _bezierCubic(P1.x, P2.x, P3.x, P4.x, i);
				y = _bezierCubic(P1.y, P2.y, P3.y, P4.y, i);
				//OJO MODIFICAMOS x=y y=x
				degrees _degree = calculaCinematica2dof(Eigen::Vector2f(x,y));
				_degrees.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_bio_degree, (svgdom::real)_degree.elbow_bio_degree});
				_angles.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_angle, (svgdom::real)_degree.elbow_angle });
				_coordinates.coordinate.push_back(_coordinate = { (svgdom::real)x, (svgdom::real)y });
				

			}
			
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
				
				_beizer_degrees.coordinate.push_back(_coordinate = { (svgdom::real)_degree.shoulder_bio_degree, (svgdom::real)_degree.elbow_bio_degree });
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