#ifndef TRAJECTORYPLANNING_HPP
#define TRAJECTORYPLANNING_HPP


#include "clothoidcurve.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
/*数値計算ライブラリ*/
#define _USE_MATH_DEFINES
#include <math.h>
/*可変長リストライブラリ*/
#include <vector>
/*OpenCVライブラリ*/
#include "opencv2/opencv.hpp"
#include <omp.h>




class TrajectoryPlanning{
	cv::Point2d point_start;
	cv::Point2d point_goal;

	double angle_start;
	double angle_goal;

	double curvature_start;
	double curvature_goal;

	std::vector<std::vector<cv::Point2d> > trajectory;

public:
	void SetPoint(cv::Point2d p_start, cv::Point2d p_goal, double a_start, double a_goal, double c_start, double c_goal){
		point_start = p_start;
		point_goal = p_goal;

		angle_start = a_start;
		angle_goal = a_goal;

		curvature_start = c_start;
		curvature_goal = c_goal;
	}
	void CreateTrajectory(int num){
		trajectory.clear();



		//std::vector<cv::Point2d> curve;
		//TripleClothoidCurve clothoid;
		//clothoid.SetMaxLineLength(2);
		//clothoid.SetMaxa12(10);
		//clothoid.SetDrawStep(0.001);
		//clothoid.SetS1S2(0.25, 0.75);
		//clothoid.SetPoint(point_start, point_goal);
		//clothoid.SetAccuracy(0.1, 1, 0.01, 0.01);
		//clothoid.SetAngle(angle_start, angle_goal);
		//clothoid.SetCurvature(curvature_start, curvature_goal);

		//
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}

		//clothoid.SetPoint(point_start, point_goal + cv::Point2d(0, num * 10));
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}

		//clothoid.SetPoint(point_start, point_goal - cv::Point2d(0, num * 10));
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}

		//clothoid.SetPoint(point_start, point_goal + cv::Point2d(0, num * 20));
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}

		//clothoid.SetPoint(point_start, point_goal - cv::Point2d(0, num * 20));
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}

		//clothoid.SetPoint(point_start, point_goal + cv::Point2d(0, num * 5));
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}

		//clothoid.SetPoint(point_start, point_goal - cv::Point2d(0, num * 5));
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}

		//clothoid.SetPoint(point_start, point_goal + cv::Point2d(0, num * 15));
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}

		//clothoid.SetPoint(point_start, point_goal - cv::Point2d(0, num * 15));
		//if (!clothoid.CreateCurve(curve)){
		//	trajectory.push_back(curve);
		//}






		std::vector<cv::Point2d> curve1;
		TripleClothoidCurve clothoid1;
		int flag1 = 0;
		std::vector<cv::Point2d> curve2;
		TripleClothoidCurve clothoid2;
		int flag2 = 0;
		std::vector<cv::Point2d> curve3;
		TripleClothoidCurve clothoid3;
		int flag3 = 0;
		std::vector<cv::Point2d> curve4;
		TripleClothoidCurve clothoid4;
		int flag4 = 0;
		std::vector<cv::Point2d> curve5;
		TripleClothoidCurve clothoid5;
		int flag5 = 0;

#pragma omp parallel sections
		{
#pragma omp section
		{
			clothoid1.SetMaxLineLength(2);
			clothoid1.SetMaxa12(10);
			clothoid1.SetDrawStep(0.001);
			clothoid1.SetS1S2(0.25, 0.75);
			clothoid1.SetPoint(point_start, point_goal + cv::Point2d(0, num * 10));
			clothoid1.SetAccuracy(0.1, 1, 0.01, 0.01);
			clothoid1.SetAngle(angle_start, angle_goal);
			clothoid1.SetCurvature(curvature_start, curvature_goal);
			if (!clothoid1.CreateCurve(curve1)){
				flag1 = 1;
			}
		}
#pragma omp section
		{
			clothoid2.SetMaxLineLength(2);
			clothoid2.SetMaxa12(10);
			clothoid2.SetDrawStep(0.001);
			clothoid2.SetS1S2(0.25, 0.75);
			clothoid2.SetPoint(point_start, point_goal - cv::Point2d(0, num * 10));
			clothoid2.SetAccuracy(0.1, 1, 0.01, 0.01);
			clothoid2.SetAngle(angle_start, angle_goal);
			clothoid2.SetCurvature(curvature_start, curvature_goal);

			if (!clothoid2.CreateCurve(curve2)){
				flag2 = 1;
			}
		}
#pragma omp section
		{
			clothoid3.SetMaxLineLength(2);
			clothoid3.SetMaxa12(10);
			clothoid3.SetDrawStep(0.001);
			clothoid3.SetS1S2(0.25, 0.75);
			clothoid3.SetPoint(point_start, point_goal + cv::Point2d(0, num * 20));
			clothoid3.SetAccuracy(0.1, 1, 0.01, 0.01);
			clothoid3.SetAngle(angle_start, angle_goal);
			clothoid3.SetCurvature(curvature_start, curvature_goal);
			if (!clothoid3.CreateCurve(curve3)){
				flag3 = 1;
			}
		}
#pragma omp section
		{
			clothoid4.SetMaxLineLength(2);
			clothoid4.SetMaxa12(10);
			clothoid4.SetDrawStep(0.001);
			clothoid4.SetS1S2(0.25, 0.75);
			clothoid4.SetPoint(point_start, point_goal - cv::Point2d(0, num * 20));
			clothoid4.SetAccuracy(0.1, 1, 0.01, 0.01);
			clothoid4.SetAngle(angle_start, angle_goal);
			clothoid4.SetCurvature(curvature_start, curvature_goal);
			if (!clothoid4.CreateCurve(curve4)){
				flag4 = 1;
			}
		}
#pragma omp section
		{
			clothoid5.SetMaxLineLength(2);
			clothoid5.SetMaxa12(10);
			clothoid5.SetDrawStep(0.001);
			clothoid5.SetS1S2(0.25, 0.75);
			clothoid5.SetPoint(point_start, point_goal);
			clothoid5.SetAccuracy(0.1, 1, 0.01, 0.01);
			clothoid5.SetAngle(angle_start, angle_goal);
			clothoid5.SetCurvature(curvature_start, curvature_goal);
			if (!clothoid5.CreateCurve(curve5)){
				flag5 = 1;
			}
		}
		}
		if (flag1){ trajectory.push_back(curve1); }
		if (flag2){ trajectory.push_back(curve2); }
		if (flag3){ trajectory.push_back(curve3); }
		if (flag4){ trajectory.push_back(curve4); }
		if (flag5){ trajectory.push_back(curve5); }

	}
	void GetTrajectory(std::vector<std::vector<cv::Point2d> > &trj){
		trj = trajectory;
		return;
	}
};

#endif