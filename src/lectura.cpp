#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdlib.h> 
//#include <cassert>
#include "Matriz.h"
using namespace std;

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
//std::cout << RED << "hello world" << RESET << std::endl;


/*struct Imagen
{
	int etiqueta;
	Matriz pixeles;
	Imagen(int e, Matriz p) : etiqueta(e), pixeles(p){}; //puede que no sea de ints
	Imagen(){};
	
};*/

/*
struct Imagenes
{
	vector<Imagen> imags;
	Imagenes(vector<Imagen> v) :	imags(v){}; //puede que no sea de ints
	Imagenes(){};
	
};
*/



Matriz lecturaTrain(istream& is, Matriz& etiquetas){
	string etiq;
	double pixel;
	int etiqueta;
	string delim;


	Matriz result = Matriz(42000, 784);

	for (int j = 1; j <= 42000; ++j)	

	{
		getline (is, etiq, '_');
		etiqueta= atof(etiq.c_str());
		for (int i = 1; i <= 783; ++i)
		{
			getline(is, delim, ' ');
			pixel =atof(delim.c_str());
			//vectorAux.push_back(pixel);
			result.Definir(j,i,pixel);
		}

	getline(is, delim, '/' );
	pixel = atof(delim.c_str());
	//vectorAux.push_back(pixel);
	result.Definir(j, 784, pixel);
	etiquetas.Definir(j,1,etiqueta);
	//Imagen imgAux = Imagen(etiqueta, vectorAux);
	//result.push_back(imgAux);		
	//cout <<j<<endl;
	}

	return result;
}

//28000 imagenes
Matriz lecturaTest(istream& is, Matriz& etiquetas){
	Matriz resultante = Matriz(28000, 784);
	string etiq;
	double pixel;
	string delim;


	for (int j = 1; j <= 28000; ++j)	
	{		
		for (int i = 1; i <= 784; ++i)
		{
			getline(is, delim, ' ');
			pixel =atof(delim.c_str());
			resultante.Definir(j, i, pixel);
		}
	getline(is, delim , '/' );
	etiquetas.Definir(j, 1, 10);
	}
	return resultante;	
}
Matriz lecturaFold(istream& is, int k){
	Matriz resultante(42000,k);
	string aux;
	for (int i = 1; i <=k; ++i)
	{
		for (int j = 1; j <= 42000; ++j)
		{
			getline(is, aux, ' ');
			resultante.Definir(j, i, atoi(aux.c_str()));			
		}
	}
	return resultante;

}

void mostrarImagen(const Matriz& i){
	
	double aux;
	int m = i.DameAncho();
	//cout << "Su etiqueta es: "<< i.etiqueta<< " y tiene " << i.pixeles.size()  << " pixeles" <<endl;
	for (int t = 0; t < 50; ++t){
		cout<<"-";
	}

	cout<<endl;
	
	for (int j = 1; j<m; ++j){
		aux = i.Obtener(1, j);
		if(aux != 0){
			cout  <<RED<<"0"<<RESET;
		}else{
			cout<<GREEN<<"0"<<RESET;	
		}
		
		if( j % 28 == 0 && j != 0){cout<<endl;}
	}
	cout<<endl;
	for (int f = 0; f < 50; ++f){
		cout<<"-";
	}
	cout<<endl;
	

}

// int promedioAltoArriba(Matriz& source){

// 	int sumaPromedio=0;
// 	int fila = source.DameAlto();

// 	for (int i = 0; i < fila; ++i){ //calculo todas mis imagenes 
// 		bool noEmpeze = true;
// 		int columna = 0;
// 		filaDondeEmpieza = 0;
// 		while(noEmpeze && columna < 784){
// 			noEmpeze = Obtener(i,columna)) == 0 && empeze;
// 			if(columna % 28 == 0){
// 				filaDondeEmpieza++;
// 			}
// 			columna++;
// 		}
// 		sumaPromedio = sumaPromedio + filaDondeEmpieza;
// 	}
// 	sumaPromedio = sumaPromedio/fila -1; //ver que onda esto
// 	return sumaPromedio;
// }

// int promedioAltoAbajo(Matriz& source){

// 	int sumaPromedio=0;
// 	int fila = source.DameAlto();

// 	for (int i = 0; i < fila; ++i){ //calculo todas mis imagenes 
// 		bool noEmpeze = true;
// 		int columna = 0;
// 		filaDondeEmpieza = 0;
// 		while(noEmpeze && columna > 0){
// 			noEmpeze = Obtener(i,columna)) == 0 && empeze;
// 			if(columna % 28 == 0){
// 				filaDondeEmpieza++;
// 			}
// 			columna--;
// 		}
// 		sumaPromedio = sumaPromedio + filaDondeEmpieza;
// 	}
// 	sumaPromedio = sumaPromedio/fila -1; //ver que onda esto
// 	return sumaPromedio;
// }

// int promedioAnchoIzquierda(Matriz& source){

// 	int sumaPromedio=0;
// 	int fila = source.DameAlto();

// 	for (int i = 0; i < fila; ++i){ //calculo todas mis imagenes 
// 		bool noEmpeze = true;
// 		int fila = 0;
// 		filaDondeEmpieza = 0;
// 		while(noEmpeze){
// 			noEmpeze = Obtener(i,fila)) == 0 && empeze;
// 			if(fila % 784 == 0){
// 				columnaDondeEmpieza++;
// 			}
// 			fila = fila+28;
// 		}
// 		sumaPromedio = sumaPromedio + columnaDondeEmpieza;
// 	}
// 	sumaPromedio = sumaPromedio/fila -1; //ver que onda esto
// 	return sumaPromedio;
// }

// int promedioAnchoIzquierda(Matriz& source){

// 	int sumaPromedio=0;
// 	int fila = source.DameAlto();

// 	for (int i = 0; i < fila; ++i){ //calculo todas mis imagenes 
// 		bool noEmpeze = true;
// 		int fila = 0;
// 		filaDondeEmpieza = 0;
// 		while(noEmpeze){
// 			noEmpeze = Obtener(i,fila)) == 0 && empeze;
// 			if(fila % 784 == 0){
// 				columnaDondeEmpieza++;
// 			}
// 			fila = fila+28;
// 		}
// 		sumaPromedio = sumaPromedio + columnaDondeEmpieza;
// 	}
// 	sumaPromedio = sumaPromedio/fila -1; //ver que onda esto
// 	return sumaPromedio;
// }

// int promedioAnchoDerecha(Matriz& source){// revisar esta verga que 

// 	int sumaPromedio=0;
// 	int fila = source.DameAlto();

// 	for (int i = 0; i < fila; ++i){ //calculo todas mis imagenes 
// 		bool noEmpeze = true;
// 		int fila = 0;
// 		filaDondeEmpieza = 784;
// 		while(noEmpeze){
// 			noEmpeze = Obtener(i,fila)) == 0 && empeze;
// 			if(fila % 784 == 0){
// 				columnaDondeEmpieza++;
// 			}
// 			fila = fila-28;
// 		}
// 		sumaPromedio = sumaPromedio + columnaDondeEmpieza;
// 	}
// 	sumaPromedio = sumaPromedio/fila -1; //ver que onda esto
// 	return sumaPromedio;
// }

/* Matriz convertirAMatrizTrain(Imagenes img, Matriz& etiquetas ){
 	// etiquetas = 784x1
 	assert(etiquetas.DameAlto() == 37000);
 	assert (img.imags.size() == 5000 && img.imags[0].pixeles.size() == 784);
 	Matriz resultante = Matriz(42000, 784);
 	for (int i = 0; i < 42000; ++i)
 	{
 		for (int j = 0; j < 784; ++j)
 		{
 			resultante.Definir(i+1, j+1, img.imags[i].pixeles[j] );
 		}
 		etiquetas.Definir(i+1, 1, img.imags[i].etiqueta);
 	}

 	return resultante;
 } 
*/
/*Matriz convertirAMatrizTest(Imagenes img, Matriz& etiquetas ){
 	// etiquetas = 784x1

 	assert(etiquetas.DameAlto() == 28000);
 	Matriz resultante = Matriz(28000, 784);
 	for (int i = 0; i < 28000; ++i)
 	{
 		for (int j = 0; j < 784; ++j)
 		{
 			resultante.Definir(i+1, j+1, img.imags[i].pixeles[j]);
 		}
 		etiquetas.Definir(i+1, 1, img.imags[i].etiqueta);
 	}

 	return resultante;
 }*/