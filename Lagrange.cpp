/*
	@title: Interpolação Polinomial: Método de Lagrange (Utilizando um polinomio interpolador de grau 2 e outro de grau 3) 
 	@author: Patrick Moreira 
 	@date: 01/07/2018

	-----------------------------------------------------------------
	-> O Polinômio Interpolador de Lagrange é dado pela seguinte fórmula: 
	L(x) = y0.L0(x) + y1.L1(x) + ... + yn.Ln(x)
	___________________________________________
	
	-> Determinar Lk(X):
	L0(X) = [(x-x1).(x-x2)] / [(x0-x1).(x0-x2)]			
				
	L1(X) = [(x-x0).(x-x2)] / [(x1-x0).(x1-x2)]			
			
	L2(X) = [(x-x0).(x-x1)] / [(x2-x0).(x2-x1)]			
			
	Ln (X) = [(...)]
	___________________________________________

------------------------------------------------------------------ */

/* Comentarios Gerais:
 * Na primeira linha do arquivo "points.txt" e possivel escolher qual o grau polinomio interpolador desejado. 
 * Por exemplo: Se desejo um polinomio interpolador de grau 2 devo escolher 3 pontos, portanto, o parametro no arquivo deve ser igual a 3. 	
 */


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef struct{
	double x;
	double y;
}Points; 

#define DISTANCE 1.9 // Distancia media de seguranca minima entre as bicicletas e os carros. 

Points* readFilePoints (int&); // Leitura do arquivo que contém os pontos a serem utilizados no cálculo dos polinomios interpoladores. 
double lagrange (Points*, int);
void printPoints (Points*, int);  

int main (){
	Points* points;
	int degree; // Grau do polinomio a ser utilizado posteriormente.	
	double pn;

	points = readFilePoints (degree);
	printPoints (points, degree);
	
	//cout << "CALCULO DE Li(X):" << endl; // Pode-se descomentar a 'linha 99' para visualizar os calculos de Li(X), mas nao e necessario. 
	pn = lagrange (points, degree);
	cout << endl;
	cout << "O Polinomio Interpolador de Lagrange de grau " << degree-1 << " e aproximadamente " << fixed << setprecision(4) << pn << endl;	

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
		cout << "Nao foi possivel abrir o arquivo." << endl;	
	}
	return points;
}

double lagrange (Points* points, int n){
	double prod_numerator [n]; 
	double prod_denominator [n];
	double lk [n];
	double lip = 0.0; // 'lip' = polinomio interpolador de lagrange.

	for (int i = 0; i < n; i++){ // Inicializa-se com '1' os vetores que serao utilizados no produtorio e com '0' no somatorio, nos calculos dos Lk(X) e do 'lip' respectivamente.
		prod_numerator[i] = 1;
		prod_denominator[i] = 1;
		lk[i] = 0;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j != i){ // Dessa maneira nunca ocorrera uma divisao invalida (por zero).
				prod_numerator[i] *= (DISTANCE-points[j].x); 
				prod_denominator[i] *= (points[i].x-points[j].x); 
			}	
		}	
		lk[i] = prod_numerator[i]/prod_denominator[i]; // Formula para calcular Lk(X).
		//cout << "L" << i << "(X) = " << fixed << setprecision(4) << lk[i] << endl; // 'linha 99' referenciada na linha '54'.
		lip += (points[i].y*lk[i]); // Formula do Polinomio Interpolador de Lagrange.
	}
	return lip;
}

void printPoints (Points* points, int n){
	cout << endl;
	cout << "PONTOS ESCOLHIDOS:" << endl;
	cout << " x   y" << endl;
	for (int i = 0; i < n; i++){
		cout << fixed << setprecision(1) << points[i].x << " " << points[i].y << endl;
	}
	cout << endl;
}