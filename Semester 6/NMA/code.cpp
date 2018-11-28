//#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

const int N_DIM = 2;
int p=0;
struct Vertex{
	double x,y;
	Vertex()
	{
		x=y=0;
	}
	Vertex(double X, double Y)
	{
		x=X;
		y=Y;
	}
	Vertex operator+=(const Vertex & v)
	{
		x+=v.x;
		y+=v.y;
		return *this;
	}
	Vertex operator/(double q)
	{
		return *(new Vertex(x/q,y/q));
	}
	friend Vertex operator * (Vertex v, double d)
	{
		return *(new Vertex(v.x*d,v.y*d));
	}
	friend Vertex operator - (Vertex v1, Vertex v2)
	{
		return *(new Vertex(v1.x-v2.x,v1.y-v2.y));
	}
	friend Vertex operator + (Vertex v1, Vertex v2)
	{
		return *(new Vertex(v1.x+v2.x,v1.y+v2.y));
	}
	friend double Dist (Vertex v1, Vertex v2)
	{
		return sqrt((v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y) * (v1.y-v2.y));
	}
public :
	void Out()
	{
		cout<<"x="<<x<<",y="<<y<<endl;
	}
};
class Simplex{
	public :
	Vertex v[N_DIM + 1];
	Simplex(Vertex z[])
	{
		for (int i=0; i<=N_DIM; i++)
			v[i]=z[i];
	}
public:
	void Out()
	{
		for (int i=0; i<=N_DIM; i++)
			v[i].Out();
		cout<<endl;
	}
};
bool QuitCase(Simplex* s)
{
	for (int i=0; i<=N_DIM; i++)
		for (int j=0; j<=N_DIM; j++)
			if (Dist(s->v[i],s->v[j])>0.1)
				return false;
	return true;
}
double Func(Vertex v)
{
	return 2*v.x*v.x+1*v.x*v.y+6*v.y*v.y-5*v.x-13*v.y;
}
void Sort(Simplex* smpl, double f[])
{
	double f1;
	Vertex v1;

	for (int i=1; i<=N_DIM; i++)
		for (int j=i; j>=1; j--)
			if (f[j-1]>f[j])
			{
				f1=f[j];
				v1=smpl->v[j];
				f[j]=f[j-1];
				smpl->v[j]=smpl->v[j-1];
				f[j-1]=f1;
				smpl->v[j-1]=v1;
			}
			else break;
}

double NMA(Simplex* smpl, double alpha=1.0, double beta=0.5, double gamma=2.0)
{
	double f[N_DIM + 1];
	double f_h, f_g, f_l, f_r, f_e, f_s, tempD;
	Vertex x_h, x_g, x_l, x_r, x_e, x_s, x_c, tempV;
	int i;
	bool flag;

	for (i=0; i<=N_DIM;i++)		f[i]=Func(smpl->v[i]);	// Вычисление значений функции на начальном симплексе

	while (!QuitCase(smpl))	// Проверка на условие выхода
	{	
		// Шаг 1. Сортировка 
		Sort(smpl,f); 
		x_h = smpl->v[N_DIM];		f_h = f[N_DIM];
		x_g = smpl->v[N_DIM - 1];	f_g = f[N_DIM - 1];
		x_l = smpl->v[0];			f_l = f[0];

		// Шаг 2. Вычисление центра тяжести симплекса
		x_c.x=x_c.y=0;
		for (i=0; i<N_DIM; i++) x_c += smpl->v[i];	
		x_c = x_c/N_DIM;
		cout<<"Центр тяжести:";x_c.Out();
		// 3Шаг . Отражение
		x_r = x_c * (1+alpha) - x_h * alpha;	f_r = Func(x_r); 
		cout<<"Отражение: ";x_r.Out();
		// Шаг 4.
		if (f_r <= f_l)
		{	// Шаг 4a.
			x_e = x_c * (1-gamma) + x_r * gamma;
			f_e = Func(x_e);
//			cout<<"Растяжение: "<<x_e<<"\t"<<f_e<<endl;
			if (f_e < f_l)
			{
				smpl->v[N_DIM] = x_e;
				f[N_DIM] = f_e;
			}
			else
			{
				smpl->v[N_DIM] = x_r;
				f[N_DIM] = f_r;
			}
		}
		if ((f_l < f_r) && (f_r <= f_g))
		{	// Шаг 4.b
			smpl->v[N_DIM] = x_r;
			f[N_DIM] = f_r;
		}
		flag = false;
		if ((f_h >= f_r) && (f_r > f_g))
		{	// Шаг 4c.
			flag = true;
			tempD=f_h;
			tempV=x_h;
			smpl->v[N_DIM] = x_r;
			f[N_DIM] = f_r;
			x_r=tempV;
			f_r=tempD;
		}
		// Шаг 4d.
		if (f_r > f_h)	flag = true;
		if (flag)
		{	// Шаг 5. Сжатие
			x_s = x_h * beta + x_c * (1 - beta);
			f_s = Func(x_s);
			cout<<"Сжатие: ";x_s.Out();
			if (f_s < f_h)
			{	// 6.
				tempD=f_h;
				tempV=x_h;
				smpl->v[N_DIM] = x_s;
				f[N_DIM] = f_s;
				x_s=tempV;
				f_s=tempD;
			}
			else
			{	// Шаг 7. Глобальное сжатие
				cout<<"Редукция"<<endl;
				for (i=0; i<=N_DIM; i++)
					smpl->v[i]=x_l + (smpl->v[i] - x_l)/2;
			}
		}
		cout<<"iteration #"<<p<<endl;p++;
		cout<<"x_h: ("<<x_h.x<<";"<<x_h.y<<")\tf(x_h)="<<f_h<<endl;
		cout<<"x_g: ("<<x_g.x<<";"<<x_g.y<<")\tf(x_g)="<<f_g<<endl;
		cout<<"x_l: ("<<x_l.x<<";"<<x_l.y<<")\tf(x_l)="<<f_l<<endl;
	}
	
	return f_l;

}


int main()
{
	setlocale(LC_ALL,"");
	char c;
	Vertex v1(0,-1), v2(0,2), v3(-1,1);
	Vertex s[3];
	s[0]=v1;
	s[1]=v2;
	s[2]=v3;
	Simplex* sm = new Simplex(s);

	cout<<"NMA: "<<NMA(sm)<<endl;

	cin>>c;
	return 0;
}

	