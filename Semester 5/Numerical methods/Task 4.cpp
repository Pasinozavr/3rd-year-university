#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

double myfunc(const double& x, const double& y)
{
	return x+cos(y/sqrt(5.));
}

int main()
{
    int i, n; 
    double x, y, h;
	cout<< " a = 1.8 b = 2.8"<<endl;
    cout<< " h = 0.1\n"; h=0.1;
    cout<< " n = (a-b)/h = 10\n"; n=10;
    cout<< " x0 = 1.8\n"; x=1.8;
    cout<< " y0 = 2.6\n"; y=2.6;

    for (i = 0; i <= n; i++)
    {
        y += h * myfunc(x, y);
		
        cout << "y = " << y;
        cout << "   x = " << x << "\n";

        x += h;
    }
	cout<<"Mod\n";
	y=2.6;
	x=1.8;
	double fy,py;
	for (i = 0; i <= n; i++)
	{
		fy = myfunc(x, y);
		py = y + h * fy;
		y += h / 2 * (fy + myfunc(x, py));
		
		cout << "y = " << y;
		cout << "   x = " << x << "\n";

		x += h;
	}


    system("PAUSE");
    return 0;
}