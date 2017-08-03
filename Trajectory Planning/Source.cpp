#ifdef _DEBUG
//Debugモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300d.lib")            // opencv_core
#else
//Releaseモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300.lib") 
#endif


#include "clothoidcurve.hpp"
#include "trajectoryplanning.hpp"

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
#include "opencv2/highgui/highgui_c.h"
#include <omp.h>

using namespace std;
using namespace cv;


int main(){
	TrajectoryPlanning trj;
	vector<vector<Point2d> > trajectory;

	int num = 4;
	double i = 0.0;

	while (1){

		trj.SetPoint(
			Point2d(0                                ,0                     ), 
			Point2d(num * 100 + cos(i*0.3) * num * 10, sin(i*0.3) * 10 * num),
			0,
			sin(i) * 0.5,
			0*-sin(i)/100.0,
			0*sin(i)/100.0);
		trj.CreateTrajectory(num);
		trj.GetTrajectory(trajectory);


		//画像出力
		int scale = 10;
		Mat image(Size(pow(2, scale), pow(2, scale)), CV_8U, Scalar::all(0));
		line(image, Point(0, 511), Point(1023, 511), Scalar(127), 1, CV_AA);
		line(image, Point(511, 0), Point(511, 1023), Scalar(127), 1, CV_AA);

		for (int i = 0; i < trajectory.size(); ++i){
			for (int j = 0; j < trajectory[0].size(); j += 1){
				image.at<unsigned char>(trajectory[i][j] + Point2d(pow(2, scale - 1) - 1, pow(2, scale - 1) - 1)) = 255;
			}
		}
		resize(image, image, Size(), 1, 1);
		imshow("ClothoidCurve", image);

		if (waitKey(1) == 27){ break; }
		i += 0.1;
	}

	return 0;
}