#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<cmath>
#include <fstream>

using namespace std;

float ms= 1.0;
float G= (2.9769*pow(10,-4));
float mt= 3.00273*pow(10,-6);



float posicion_tierra_sol_libre_euler(float x0_t, float y0_t, float vx0_t, float vy0_t, float x0_s, float y0_s, float vx0_s, float vy0_s, int n_datos, float t, float G, float ms, float mt, float h);
float posicion_tierra_sol_libre_LeapFrog(float x0_t, float y0_t, float vx0_t, float vy0_t, float x0_s, float y0_s, float vx0_s, float vy0_s, int n_datos, float t, float G, float ms, float mt, float h);

int main(){
	float e=posicion_tierra_sol_libre_euler(1, 0, 0, 0.01721094, 0.00465047, 0, 0, (8.08009*pow(10, -5)), 2190, 2190, (2.9769*pow(10,-4)), 1.0, (3.00273*pow(10,-6)),10);
	float lf=posicion_tierra_sol_libre_LeapFrog(1, 0, 0, 0.01721094, 0.00465047, 0, 0, (8.08009*pow(10, -5)), 2190, 2190, (2.9769*pow(10,-4)), 1.0, (3.00273*pow(10,-6)),1);
	
}


float posicion_tierra_sol_libre_euler(float x0_t, float y0_t, float vx0_t, float vy0_t, float x0_s, float y0_s, float vx0_s, float vy0_s, int n_datos, float t, float G, float ms, float mt, float h){
	char data[n_datos];
	
	// open a file in write mode.
   ofstream outfile;
   outfile.open("Posicion de la tierra respecto al sol libre euler");
   
	float r[n_datos];
	//float t[n_datos];
	float vx_t[n_datos];
	float vy_t[n_datos];
	float x_t[n_datos];
	float y_t[n_datos];
	float vx_s[n_datos];
	float vy_s[n_datos];
	float x_s[n_datos];
	float y_s[n_datos];
	x_t[0]=x0_t;
	y_t[0]=y0_t;
	vx_t[0]= vx0_t;
	vy_t[0]=vy0_t;
	x_s[0]=x0_s;
	y_s[0]=y0_s;
	vx_s[0]= vx0_s;
	vy_s[0]=vy0_s;
	r[0]=sqrt(pow(x0_t-x0_s,2)+(pow(y0_t-y0_s,2)));
// 	t[0]=0
	outfile<<x_t[0]<<" | "<<y_t[0]<<endl;
	
	for (int i=1; i<n_datos; i++){
		x_t[i]= x_t[i-1] + h*(vx_t[i-1]);
		y_t[i]= y_t[i-1] + h*(vy_t[i-1]);
		
		x_s[i]= x_s[i-1] + h*(vx_s[i-1]);
		y_s[i]= y_s[i-1] + h*(vy_s[i-1]);
		
		vx_t[i]= vx_t[i-1] + h*((-G*ms)/(pow(r[i-1],3.0)))*x_t[i];
		vy_t[i]= vy_t[i-1] + h*((-G*ms)/(pow(r[i-1],3.0)))*y_t[i];
		
		vx_s[i]= vx_s[i-1] + h*((G*mt)/(pow(r[i-1],3.0)))*x_s[i];
		vy_s[i]= vy_s[i-1] + h*((G*mt)/(pow(r[i-1],3.0)))*y_s[i];
		
		r[i]=sqrt(pow(x_t[i]-x_s[i],2)+(pow(y_t[i]-y_s[i],2)));
		
		outfile<<x_t[i]<<" | "<<y_t[i]<<endl;
	}
	outfile.close();
	
  	outfile.open("Posicion del sol libre euler");
  	 
  	outfile<<x_s[0]<<" | "<<y_s[0]<<endl;
	   
	for (int i=1; i<n_datos; i++){
			
		outfile<<x_s[i]<<" | "<<y_s[i]<<endl;
	}	
	outfile.close();
	
}

float posicion_tierra_sol_libre_LeapFrog(float x0_t, float y0_t, float vx0_t, float vy0_t, float x0_s, float y0_s, float vx0_s, float vy0_s, int n_datos, float t, float G, float ms, float mt, float h){
	char data[n_datos];
	
	// open a file in write mode.
   ofstream outfile;
   outfile.open("Posicion de la tierra respecto al sol libre LeapFrog");
   
	float r[n_datos];
	//float t[n_datos];
	float vx_t[n_datos];
	float vy_t[n_datos];
	float x_t[n_datos];
	float y_t[n_datos];
	float vx_s[n_datos];
	float vy_s[n_datos];
	float x_s[n_datos];
	float y_s[n_datos];
	x_t[0]=x0_t;
	y_t[0]=y0_t;
	x_s[0]=x0_s;
	y_s[0]=y0_s;
	r[0]=sqrt(pow(x0_t-x0_s,2)+(pow(y0_t-y0_s,2)));
	vx_t[0]= vx0_t + (1.0/2)*h*((-G*ms)/(pow(r[0],3.0)))*x_t[0];
	vy_t[0]=vy0_t + (1.0/2)*h*((-G*ms)/(pow(r[0],3.0)))*y_t[0];
	vx_s[0]= vx0_s + (1.0/2)*h*((G*mt)/(pow(r[0],3.0)))*x_s[0];
	vy_s[0]=vy0_s + (1.0/2)*h*((G*mt)/(pow(r[0],3.0)))*y_s[0];
// 	t[0]=0
	outfile<<x_t[0]<<" | "<<y_t[0]<<endl;
		
	for (int i=1; i<n_datos; i++){
		x_t[i]= x_t[i-1] + h*(vx_t[i-1]);
		y_t[i]= y_t[i-1] + h*(vy_t[i-1]);
		
		x_s[i]= x_s[i-1] + h*(vx_s[i-1]);
		y_s[i]= y_s[i-1] + h*(vy_s[i-1]);
		
		vx_t[i]= vx_t[i-1] + h*((-G*ms)/(pow(r[i-1],3.0)))*x_t[i];
		vy_t[i]= vy_t[i-1] + h*((-G*ms)/(pow(r[i-1],3.0)))*y_t[i];
		
		vx_s[i]= vx_s[i-1] + h*((G*mt)/(pow(r[i-1],3.0)))*x_s[i];
		vy_s[i]= vy_s[i-1] + h*((G*mt)/(pow(r[i-1],3.0)))*y_s[i];
		
		r[i]=sqrt((pow(x_t[i],2))+(pow(y_t[i],2)));
		
		outfile<<x_t[i]<<" | "<<y_t[i]<<endl;
	}
	outfile.close();
	
  	outfile.open("Posicion del sol libre LeapFrog");
  	 
  	outfile<<x_s[0]<<" | "<<y_s[0]<<endl;
	   
	for (int i=1; i<n_datos; i++){
			
		outfile<<x_s[i]<<" | "<<y_s[i]<<endl;
	}	
	outfile.close();
}
