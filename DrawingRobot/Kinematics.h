#pragma once
#include <Eigen/Eigen>
#include <fstream>
#include <iostream>

constexpr auto PI = 3.14159265;


using namespace Eigen;


const float LongBrazo = 107;
const float LongAntBr = 195;

struct degrees {
	float shoulder_bio_degree, elbow_bio_degree,shoulder_angle, elbow_angle;
};

//static std::ofstream fs("k.txt");

//Eigen::Vector2f calculaCinematica2dof(Eigen::Vector2f);
degrees calculaCinematica2dof(Eigen::Vector2f);