#include "Kinematics.h"



degrees calculaCinematica2dof(Eigen::Vector2f coordenadas) {
	float C, D, elbow_angle, shoulder_angle, shoulder_pivot_angle, simulate_e_angle;
	float spa_angle,sa_angle, e_angle;
	degrees degrees;

	
	
	C = ((coordenadas.norm()*coordenadas.norm()) - (LongBrazo*LongBrazo) - (LongAntBr * LongAntBr)) / (2 * LongBrazo * LongAntBr);
	if ((C*C) <= 1) {
		D = sqrt(1 - (C*C));
		elbow_angle = atan2(D, C);
		if (coordenadas(1) > 0) {
		//if (coordenadas(0) > 0) {
			//  shoulder_angle = -(atan2(rvector.axis.x,sqrt(rvector.axis.z**2+rvector.axis.y**2))\+atan2(total_lower_arm_length*sin(elbow_angle),(Upper_Arm_Length+total_lower_arm_length*cos(elbow_angle))))+pi/2
			//shoulder_angle = -(atan2(coordenadas(0), sqrt((coordenadas(1)*coordenadas(1)))) + atan2(LongAntBr*sin(elbow_angle), (LongBrazo + LongAntBr * cos(elbow_angle)))) + (PI / 2);

			//flip coordendas x=y y=x
			shoulder_angle = -(atan2(coordenadas(1), sqrt((coordenadas(0)*coordenadas(0)))) + atan2(LongAntBr*sin(elbow_angle), (LongBrazo + LongAntBr * cos(elbow_angle)))) + (PI / 2);
		}
		else {
			//shoulder_angle = (atan2(-rvector.axis.x,sqrt(rvector.axis.z**2+rvector.axis.y**2))\-atan2(total_lower_arm_length*sin(elbow_angle),(Upper_Arm_Length+total_lower_arm_length*cos(elbow_angle))))+pi/2
			//shoulder_angle = (atan2(-coordenadas(0), sqrt((coordenadas(1)*coordenadas(1)))) - atan2(LongAntBr*sin(elbow_angle), (LongBrazo + LongAntBr * cos(elbow_angle)))) + (PI / 2);

			//flip coordendas x=y y=x		
			shoulder_angle = (atan2(-coordenadas(1), sqrt((coordenadas(0)*coordenadas(0)))) - atan2(LongAntBr*sin(elbow_angle), (LongBrazo + LongAntBr * cos(elbow_angle)))) + (PI / 2);
		}
		/**Z se vuelve Y y X se vuelve Z asi que Y se vuelve X*/
		//shoulder_pivot_angle = -atan2(coordenadas(1), 0);		
		//shoulder_pivot_angle *= 180 / PI;		
		
		shoulder_angle *= 180 / PI;
		elbow_angle *= 180 / PI;

		//OJO shoulder=elbow, elbow=shoulder
		spa_angle = int(3.5*((int(shoulder_pivot_angle) + 146) % 360));
		sa_angle = 1023 - int(3.5*((int(shoulder_angle) + 146) % 360));
		simulate_e_angle  = 1023 - int(3.5*((int(elbow_angle) + 146) % 360));
		//sa_angle = int(3.5*((int(shoulder_angle) + 146) % 360));
		e_angle  = int(3.5*((int(elbow_angle) + 146) % 360));

	}else {
		//std::cout << "OSTIAS PUTAS" << std::endl;
		//const IOFormat fmt(2, DontAlignCols, "\t");
		//std::cout << coordenadas.transpose().format(fmt) << std::endl;
		/**std::stringstream data;
		data << coordenadas;			
		fs << data.str();*/
		
	}
	
	//fs.close();
	
	degrees.shoulder_bio_degree = sa_angle;
	degrees.elbow_bio_degree = e_angle;
	degrees.shoulder_angle = (sa_angle *300)/1023;
    degrees.elbow_angle = (simulate_e_angle *300)/1023;
	//degrees.shoulder_angle = shoulder_angle;
	//degrees.elbow_angle = elbow_angle;

	return degrees;
}
