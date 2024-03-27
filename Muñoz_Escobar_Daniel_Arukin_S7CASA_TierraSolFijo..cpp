#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<cmath>
#include <fstream>

using namespace std;

float ms= 1.0;
float G= (2.9769*pow(10,-4));

float posicion_tierra_sol_fijo_euler(float x0, float y0, float vx0, float vy0, int n_datos, float t, float G, float ms, float h);
float posicion_tierra_sol_fijo_LeapFrog(float x0, float y0, float vx0, float vy0, int n_datos, float t, float G, float ms, float h);

int main(){
	float e=posicion_tierra_sol_fijo_euler(1, 0, 0, 0.01721094, 2190, 2190, (2.9769*pow(10,-4)), 1.0, 1);
	float lf=posicion_tierra_sol_fijo_LeapFrog(1, 0, 0, 0.01721094, 2190, 2190, (2.9769*pow(10,-4)), 1.0, 1);
}


float posicion_tierra_sol_fijo_euler(float x0, float y0, float vx0, float vy0, int n_datos, float t, float G, float ms, float h){
	char data[n_datos];
	
	// open a file in write mode.
   ofstream outfile;
   outfile.open("Posicion de la tierra respecto al sol fijo euler");
   
	float r[n_datos];
	//float t[n_datos];
	float vx[n_datos];
	float vy[n_datos];
	float x[n_datos];
	float y[n_datos];
	x[0]=x0;
	y[0]=y0;
	vx[0]= vx0;
	vy[0]=vy0;
	r[0]=sqrt((x0*x0)+(y0*y0));
// 	t[0]=0
	outfile<<x[0]<<" | "<<y[0]<<endl;
	
	for (int i=1; i<n_datos; i++){
		x[i]= x[i-1] + h*(vx[i-1]);
		y[i]= y[i-1] + h*(vy[i-1]);
		vx[i]= vx[i-1] + h*((-G*ms)/(pow(r[i-1],3.0)))*x[i];
		vy[i]= vy[i-1] + h*((-G*ms)/(pow(r[i-1],3.0)))*y[i];
		r[i]=sqrt((pow(x[i],2))+(pow(y[i],2)));
		
		outfile<<x[i]<<" | "<<y[i]<<endl;
	}
	outfile.close();
}

float posicion_tierra_sol_fijo_LeapFrog(float x0, float y0, float vx0, float vy0, int n_datos, float t, float G, float ms, float h){
	char data[n_datos];
	
	// open a file in write mode.
   ofstream outfile;
   outfile.open("Posicion de la tierra respecto al sol fijo LeapFrog");
   
	float r[n_datos];
	//float t[n_datos];
	float vx[n_datos];
	float vy[n_datos];
	float x[n_datos];
	float y[n_datos];
	x[0]=x0;
	y[0]=y0;
	r[0]=sqrt((x0*x0)+(y0*y0));
	vx[0]= vx0 + (1.0/2)*h*((-G*ms)/(pow(r[0],3.0)))*x[0];
	vy[0]=vy0 + (1.0/2)*h*((-G*ms)/(pow(r[0],3.0)))*y[0];
// 	t[0]=0
	outfile<<x[0]<<" | "<<y[0]<<endl;
		
	for (int i=1; i<n_datos; i++){
		x[i]= x[i-1] + h*(vx[i-1]);
		y[i]= y[i-1] + h*(vy[i-1]);
		vx[i]= vx[i-1] + h*((-G*ms)/(pow(r[i-1],3.0)))*x[i];
		vy[i]= vy[i-1] + h*((-G*ms)/(pow(r[i-1],3.0)))*y[i];
		r[i]=sqrt((pow(x[i],2))+(pow(y[i],2)));
		
		outfile<<x[i]<<" | "<<y[i]<<endl;
	}
	outfile.close();
}
