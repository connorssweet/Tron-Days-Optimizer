#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

double getXEnd(double xs, double radius, double angle)
{
    double xe = 0;
    xe = radius * cos(angle);
    return xs + xe;
}

double getYEnd(double ys, double radius, double angle)
{
    double ye = 0;
    ye = radius * sin(angle);
    return ys + ye;
}

double getAngle1(double lengthL, double bottom, double side)
{
    double angle = acos((pow(bottom,2) - pow(lengthL,2) + pow(side, 2))/(2*bottom*side));
    return angle;
}

int main()
{
    const double BOTTOM_LENGTH = 20.0;
    const double SIDE_LENGTH = 33.0;
    const double MAX_LENGTH_1 = 48;
    const double SMALLEST_PIECE = 6.4;
    const double TETRIX_UNIT_INCREMENT = 1.6;
    const double TOL = 2;
    const double ANGLE_INCREMENT = M_PI/6;
    const double MIN_ANGLE = 0;
    const double MAX_ANGLE = M_PI/2;
    double xStart = 0, yStart = 0;
    
    cout << fixed << setprecision(2) << "X" << setw(8) << "Y" << setw (8) << "L" << setw(8) << "R" << setw(9) << "R2" << setw(12) << "Angle" << endl;
    
    for(double lengthL = TETRIX_UNIT_INCREMENT; lengthL <= 53; lengthL += TETRIX_UNIT_INCREMENT)
    {
        double angle = getAngle1(lengthL, BOTTOM_LENGTH, SIDE_LENGTH);
        if(angle < MAX_ANGLE && angle > MIN_ANGLE)
        	for (double radius = 1.6; radius < MAX_LENGTH_1; radius += TETRIX_UNIT_INCREMENT)
        		if (radius > lengthL)
            		for (double radius2 = SMALLEST_PIECE; radius2 < 25; radius2 += TETRIX_UNIT_INCREMENT)
                		for (double angle2 = -M_PI/2; angle2 < M_PI/2; angle2 += ANGLE_INCREMENT)
                		{     
								double xEnd = getXEnd(xStart, radius, angle);
    							double yEnd = getYEnd(yStart, radius, angle);
    				
    							xEnd = getXEnd(xEnd, radius2, angle);
    							yEnd = getYEnd(yEnd, radius2, angle);
    							
    							if((fabs(xEnd-20) <= TOL && fabs(yEnd-20) <= TOL) || (fabs(xEnd-31) <= TOL && fabs(yEnd-33) <= TOL) 
								|| (fabs(xEnd-45) <= TOL && fabs(yEnd-37) <= TOL) || (fabs(xEnd-45) <= TOL && fabs(yEnd-20) <= TOL))
								
									cout << xEnd << setw(8) << yEnd << setw(8) << lengthL << setw(8) << radius << setw(8) << radius2 << setw(8) << angle << endl;    			
						}
    }
    return EXIT_SUCCESS;
}

