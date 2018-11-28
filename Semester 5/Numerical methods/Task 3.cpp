#include <iostream>
#include <math.h>
using namespace std;
double t=0.412975;
double f(double x){
	return ((2*x)/((2*x*x+1)*(2*x*x+1)));
}
double rectangle(double a,double b,double n){
	double h=(b-a)/n;
	double result=0;
	for(double i=a;i<=b+0.01;i+=h){
		result+=f(i);
	cout<<"res="<<f(i)<<endl;
	}
	
	result*=h;
	return result;
}
double trapezoid(double a,double b,double n){
	double sum=(f(a)+f(b))/2;
	double step=(b-a)/n;
	for(double i=a+step;i<=b-step+0.01;i+=step){
		sum+=f(i);
		cout<<"res="<<f(i)<<endl;
	}
	//sum+=(f(a)+f(b))/2;
	sum*=step;
	return sum;
}
int main(){
	double znach1,znach2;
	znach1=rectangle(-1,2,3);
	znach2=trapezoid(-1,2,3);
	cout<<"rectangles method\nthe value of the integral is: "<<znach1<<endl;
	cout<<"method of trapezoids\nthe value of the integral is: "<<znach2<<endl;
	//cout<<"value from online calculator is: "<<t<<endl;
	//Newton, Gauss, Stirling, Bessel÷¸
	double x[6]={2.4,2.6,2.8,3.0,3.2,3.4};
	double y[6]={3.526,3.782,3.945,4.043,4.104,4.155};
	double y1[5],y2[4],y3[3];
	for(int i=0;i<5;i++){
		y1[i]=y[i+1]-y[i];
	}
	for(int i=0;i<4;i++){
		y2[i]=y1[i+1]-y1[i];
	}
	for(int i=0;i<3;i++){
		y3[i]=y2[i+1]-y2[i];
	}

	cout<<"Create daigonal table:\n";
	cout<<"x\ty(x)\t^y(x)\t^2y(x)\t^3y(x)\n";
	for(int i=0;i<6;i++){
		cout<<x[i]<<"\t"<<y[i];
		if(i==0 || i==1 || i==2){cout<<"\t"<<y1[i]<<"\t"<<y2[i]<<"\t"<<y3[i]<<endl;}
		if(i==3){
			cout<<"\t"<<y1[i]<<"\t"<<y2[i]<<endl;
		}
		if(i==4){
			cout<<"\t"<<y1[i]<<endl;
		}
		if(i==5){
			cout<<endl;
		}
	}
	double x0=2.4;
	double X=2.45;
	double h=x[2]-x[1];
	double t=(X-x0)/(h);
	cout.precision(5);
	cout<<"Newton\n";
	cout<<"x=2.4+0.05n=2.45\nx0=2.4, then: t=(x-x0)/h=(2.45-2.4)/0.2="<<t<<endl;
	cout<<"y'(x0)~1/h(^y0-1/2^2y0+1/3^3y0+...)\ny''(x)~1/(h^2)(^2y0-^3y0+...)\n";
	cout<<"y'(2.45)=1/"<<h<<"("<<y1[0]<<"+"<<((2*t-1.)/2.)*y2[0]<<"+"<<((3*t*t-6*t+2.)/6.)*y3[0]<<")="<<(1/h)*(y1[0]+((2*t-1.)/2.)*y2[0]+((3*t*t-6*t+2.)/6.)*y3[0])<<"\n";
	cout<<"y''(2.45)=1/("<<h<<")^2*("<<y2[0]<<"+"<<(t-1.0)*y3[0]<<")="<<(y2[0]+(t-1.0)*y3[0])/(h*h)<<"\n";
	cout<<"Bessel\n";
	cout<<"x=3.12+0.03n=3.15\n";
	X=3.15;
	x0=3.0;
	t=(X-x0)/h;
	cout<<"x0=3.0 then t=(3.15-3.0)/0.2="<<t<<endl;
	cout<<"y'(3.15)="<<1/(h)*(y1[3]+(2*t-1)/2*(y2[3]+y2[2])+(3*t*t-3*t+1./2)/6*y3[2])<<endl;
	system("pause");
	return 0;}