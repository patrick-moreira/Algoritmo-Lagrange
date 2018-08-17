/*
	@ title: Polynomial interpolation: Lagrange method (using a degree 2 and degree 3 interpolation polynomial)
	@author: Patrick Moreira
	@date: 2018/07/01

	-----------------------------------------------------------------
	->The Lagrange Interpolator Polynomial is given by the following formula: 
	L(x) = y0.L0(x) + y1.L1(x) + ... + yn.Ln(x)
	___________________________________________
	
	-> To determine Lk(X):
	L0(X) = [(x-x1).(x-x2)] / [(x0-x1).(x0-x2)]			
				
	L1(X) = [(x-x0).(x-x2)] / [(x1-x0).(x1-x2)]			
			
	L2(X) = [(x-x0).(x-x1)] / [(x2-x0).(x2-x1)]			
			
	Ln (X) = [(...)]
	___________________________________________

------------------------------------------------------------------ */

 /* General Comments:
  * In the first line of the file "points.txt" it is possible to choose which degree the interpolator polynomial you want.
  * For example: If I want an interpolator polynomial of degree 2 I should choose 3 points, so the parameter in the file must be equal to 3.
  */


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef struct{
	double x;
	double y;
}Points; 

#define DISTANCE 1.9 // Minimum average safety distance between bicycles and cars. 

Points* readFilePoints (int&);
double lagrange (Points*, int);
void printPoints (Points*, int);  

int main (){
	Points* points;
	int degree; 	
	double pn;

	points = readFilePoints (degree);
	printPoints (points, degree);
	
	//cout << "CALCULO DE Li(X):" << endl; // Delete the comment from 'line 99' to view the Li (X) calculations, but this is not necessary. 
	pn = lagrange (points, degree);
	cout << endl;
	cout << "The Lagrange interpolator polynomial of degree " << degree-1 << " is approximately " << fixed << setprecision(4) << pn << endl;	

	return 0;
}

Points* readFilePoints (int& n){
	Points *points;
	fstream file;
	file.open ("points.txt");
	if (file.is_open ()){
		file >> n;
		points = new Points[n];	
		for (int i = 0; i < n; i++){
			file >> points[i].x;
			file >> points[i].y;
		}
		file.close();
	}else{
		cout << "Can not open file." << endl;	
	}
	return points;
}

double lagrange (Points* points, int n){
	double prod_numerator [n]; 
	double prod_denominator [n];
	double lk [n];
	double lip = 0.0; 

	for (int i = 0; i < n; i++){ // They initialize with the '1' the vectors that will be used in the production, and with '0' those that will be used sum, in the calculations of Lk (X) and 'lip' respectively.		
		prod_numerator[i] = 1;
		prod_denominator[i] = 1;
		lk[i] = 0;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j != i){ // Do not divide by zero
				prod_numerator[i] *= (DISTANCE-points[j].x); 
				prod_denominator[i] *= (points[i].x-points[j].x); 
			}	
		}	
		lk[i] = prod_numerator[i]/prod_denominator[i]; // Formula to calculate Lk(X).
		//cout << "L" << i << "(X) = " << fixed << setprecision(4) << lk[i] << endl; // 'linha 99' referenced on line '54'.
		lip += (points[i].y*lk[i]); // Lagrange Interpolator Polynomial Formula.
	}
	return lip;
}

void printPoints (Points* points, int n){
	cout << endl;
	cout << "USED POINTS:" << endl;
	cout << " x   y" << endl;
	for (int i = 0; i < n; i++){
		cout << fixed << setprecision(1) << points[i].x << " " << points[i].y << endl;
	}
	cout << endl;
}
