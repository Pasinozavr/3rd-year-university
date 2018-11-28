#include <iostream>
#include <math.h>
#include <glut.h>
#include <gl\gl.h>	
#include <gl\glu.h>	
using namespace std;
int choose;
double q(double x){
			if(choose==1){
			return 0.64768+2.2608*x;
			}
			if(choose==2){
				return 1.080871+0.7371309*x+1.289978*x*x;}
			if(choose==3){
				return 1.0176+1.0732*x+0.70701*x*x+0.33036*x*x*x;
			}
			if(choose==4){
			return 0.81991+2.3991*x-2.5696*x*x+3.871*x*x*x-1.4135*x*x*x*x;
			}
			if(choose==5){
			return 0.69494+2.9683*x-2.6416*x*x+0.62879*x*x*x+4.2565*x*x*x*x-2.8984*x*x*x*x*x;
			}
	
};
void resize(int width,int height)
{
    glViewport(0,0,width,height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(-11,11, -11,11, 2,12);
    gluLookAt( 0,0,5, 0,0,0, 0,1,0 );
    glMatrixMode( GL_MODELVIEW );
}
void display(void)
{
    long double x,y,i;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLineWidth(1.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    //ось Y
        glVertex2f(0.0f,10.0f);
        glVertex2f(0.0f,-10.0f);
    //ось X
        glVertex2f(10.0f,0.0f);
        glVertex2f(-10.0f,0.0f);
    for(i = -10;i<=10;i++)
    {
        glVertex2f(i,0.1);
        glVertex2f(i,-0.1);
    }
    for(i = -10;i<=10;i++)
    {
        glVertex2f(0.1,i);
        glVertex2f(-0.1,i);
    }
    glEnd();
    glPointSize(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
        for(i=0;i<=5;i+=0.0001)
        {
            x=i;
			if(choose==1){
			y=0.64768+2.2608*x;
			}
			if(choose==2){
				y=1.080871+0.7371309*x+1.289978*x*x;}
			if(choose==3){
				y=1.0176+1.0732*x+0.70701*x*x+0.33036*x*x*x;
			}
			if(choose==4){
			y=0.81991+2.3991*x-2.5696*x*x+3.871*x*x*x-1.4135*x*x*x*x;
			}
			if(choose==5){
			y=0.69494+2.9683*x-2.6416*x*x+0.62879*x*x*x+4.2565*x*x*x*x-2.8984*x*x*x*x*x;
			}
            glVertex2f(x,y);
        }
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(100,20,80);
    glVertex2f(0.43,1.63597);
    glVertex2f(0.48,1.73234);
    glVertex2f(0.55,1.87686);
    glVertex2f(0.62,2.03345);
    glVertex2f(0.70,2.22846);
    glVertex2f(0.75,2.35973);
    glEnd();
    glutSwapBuffers();
}
void showdata(float x[6], float y[6]){
	cout<<"Input data:\n";
	cout<<"xi\t";
	for(int i=0;i<6;i++){cout<<x[i]<<"\t";}
	cout<<endl;
	cout<<"yi\t";
	for(int i=0;i<6;i++){cout<<y[i]<<"\t";}
	cout<<endl;
}
void draw(int choose){
	float pos[4] = {3,3,3,1};
    float dir[3] = {-1,-1,-1};
    GLfloat mat_specular[] = {1,1,1,1};
    //glutInit(&argc, argv);
    glutInitWindowPosition(350, 25);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    glutCreateWindow("Лабораторная работа № 1");

    glutDisplayFunc(display);
    glutReshapeFunc(resize);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0);

	glutMainLoop();

}
void Gauss(float**matrix,int i,int j,int n,int m,float tmp,float*xx,int k){
//выводим массив
    cout << "matrix: " << endl;
      for (i=0; i<n; i++)
       {
          for (j=0; j<m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
       }
    cout << endl;
//Метод Гаусса
//Прямой ход, приведение к верхнетреугольному виду
    
    for (i=0; i<n; i++)
     {
       tmp=matrix[i][i];
         for (j=n;j>=i;j--)
             matrix[i][j]/=tmp;
           for (j=i+1;j<n;j++)
          {
             tmp=matrix[j][i];
               for (k=n;k>=i;k--)
             matrix[j][k]-=tmp*matrix[i][k];
          }
      }
  /*обратный ход*/
    xx[n-1] = matrix[n-1][n];
     for (i=n-2; i>=0; i--)
       {
           xx[i] = matrix[i][n];
           for (j=i+1;j<n;j++) xx[i]-=matrix[i][j]*xx[j];
       }
//Выводим решения
       for (i=0; i<n; i++)
           cout << xx[i] << " ";
       cout << endl;
}

int main(int argc, char** argv){
	int i=0, j=0, n, k=0;
	float tmp=0;
	cout<<"Select parametr 'm' (from 1 to 5): ";
	 cin>>choose;
	
	 
	 float x[6]={0.02,0.08,0.12,0.17,0.23,0.30};
    float y[6]={1.02316,1.09590,1.14725,1.21483,1.30120,1.40976};

	// float x[6]={0.43,0.48,0.55,0.62,0.70,0.75};
//	float y[6]={1.63597,1.73234,1.87686,2.03345,2.22846,2.35973};



	// float x[6]={0.68,0.73,0.8,0.88,0.93,0.99};
	// float y[6]={0.80866,0.89492,1.02964,1.20966,1.34087,1.52368};
	 showdata(x,y);
	cout<<"Processing..\n";
	if(choose>5 || choose<1){return 0;}
	else if(choose==1){
	float x0[6],x1[6],x2[6],x0y[6],xy[6];
	for(int i=0;i<6;i++){
		x0[i]=1;
		x1[i]=x[i];
		x2[i]=x[i]*x[i];
		x0y[i]=1*y[i];
		xy[i]=x[i]*y[i];
	}
	float s0=0,s1=0,s2=0,t0=0,t1=0;
	cout<<"i\txi0\txi1\txi2\txi0yi\txi1yi\n";
	for(int i=0;i<6;i++){
		cout.precision(3);
		cout<<i<<"\t"<<x0[i]<<"\t"<<x1[i]<<"\t"<<x2[i]<<"\t"<<x0y[i]<<"\t"<<xy[i]<<endl;
		s0+=x0[i];
		s1+=x1[i];
		s2+=x2[i];
		t0+=x0y[i];
		t1+=xy[i];
	}
	cout<<"So we have system:\n";
	cout<<s0<<"*a0+"<<s1<<"*a1="<<t0<<endl;
	cout<<s1<<"*a0+"<<s2<<"*a1="<<t1<<endl;
	cout<<"Gauss:\n";
 
    const int m=3;
	n=2;
	float  xx[m]; 
    float **matrix = new float *[n];
         for (i=0; i<n; i++)
             matrix[i] = new float [m];

 matrix[0][0]=s0;
 matrix[0][1]=matrix[1][0]=s1;
 matrix[1][1]=s2;

 matrix[0][2]=t0;
 matrix[1][2]=t1;

Gauss(matrix, i, j, n, m, tmp,xx, k);

 float a0,a1,a2;
 a0=xx[0];
 a1=xx[1];
 a2=xx[2];
 delete[] matrix;
 cout.precision(5);
cout<<"So, we have:\nQ1(xi)="<<a0<<"+"<<a1<<"*x\n";
cout<<"xi\tyi\tQm(xi)\tyi-Qm(xi)\n";
	for(int i=0;i<6;i++){
		cout<<x[i]<<"\t"<<y[i]<<"\t"<<q(x[i])<<"\t"<<y[i]-q(x[i])<<endl;
	}

	draw(choose);
}
	else if(choose==2){
	float x0[6],x1[6],x2[6],x3[6],x4[6],x0y[6],xy[6],x2y[6];
	for(int i=0;i<6;i++){
		x0[i]=1;
		x1[i]=x[i];
		x2[i]=x[i]*x[i];
		x3[i]=x[i]*x[i]*x[i];
		x4[i]=x[i]*x[i]*x[i]*x[i];
		x0y[i]=1*y[i];
		xy[i]=x[i]*y[i];
		x2y[i]=x[i]*x[i]*y[i];
	}
	float s0=0,s1=0,s2=0,s3=0,s4=0,t0=0,t1=0,t2=0;
	cout<<"i\txi0\txi1\txi2\txi3\txi4\txi0yi\txi1yi\txi2yi\n";
	for(int i=0;i<6;i++){
		cout.precision(3);
		cout<<i<<"\t"<<x0[i]<<"\t"<<x1[i]<<"\t"<<x2[i]<<"\t"<<x3[i]<<"\t"<<x4[i]<<"\t"<<x0y[i]<<"\t"<<xy[i]<<"\t"<<x2y[i]<<endl;
		s0+=x0[i];
		s1+=x1[i];
		s2+=x2[i];
		s3+=x3[i];
		s4+=x4[i];
		t0+=x0y[i];
		t1+=xy[i];
		t2+=x2y[i];
	}
	cout<<"So we have system:\n";
	cout<<s0<<"*a0+"<<s1<<"*a1+"<<s2<<"*a2="<<t0<<endl;
	cout<<s1<<"*a0+"<<s2<<"*a1+"<<s3<<"*a2="<<t1<<endl;
	cout<<s2<<"*a0+"<<s3<<"*a1+"<<s4<<"*a2="<<t2<<endl;
	cout<<"Gauss:\n";
 
    const int m=4;
	n=3;
	float  xx[m]; 
    float **matrix = new float *[n];
         for (i=0; i<n; i++)
             matrix[i] = new float [m];

 matrix[0][0]=s0;
 matrix[0][1]=matrix[1][0]=s1;
 matrix[0][2]=matrix[1][1]=matrix[2][0]=s2;
 matrix[1][2]=matrix[2][1]=s3;
 matrix[2][2]=s4;

 matrix[0][3]=t0;
 matrix[1][3]=t1;
 matrix[2][3]=t2;

Gauss(matrix, i, j, n, m, tmp,xx, k);

 float a0,a1,a2;
 a0=xx[0];
 a1=xx[1];
 a2=xx[2];
 delete[] matrix;
 cout.precision(5);
cout<<"So, we have:\nQ2(xi)="<<a0<<"+"<<a1<<"*x+"<<a2<<"*x^2\n";
cout<<"xi\tyi\tQm(xi)\tyi-Qm(xi)\n";

	for(int i=0;i<6;i++){
		cout<<x[i]<<"\t"<<y[i]<<"\t"<<q(x[i])<<"\t"<<y[i]-q(x[i])<<endl;
	}

	draw(choose);
}
	else if(choose==3){
	float x0[6],x1[6],x2[6],x3[6],x4[6],x5[6],x6[6],x0y[6],xy[6],x2y[6],x3y[6];
	for(int i=0;i<6;i++){
		x0[i]=1;
		x1[i]=x[i];
		x2[i]=x[i]*x[i];
		x3[i]=x[i]*x[i]*x[i];
		x4[i]=x[i]*x[i]*x[i]*x[i];
		x5[i]=x[i]*x[i]*x[i]*x[i]*x[i];
		x6[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x0y[i]=1*y[i];
		xy[i]=x[i]*y[i];
		x2y[i]=x[i]*x[i]*y[i];
		x3y[i]=x[i]*x[i]*x[i]*y[i];
	}
	float s0=0,s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,t0=0,t1=0,t2=0,t3=0;
//	cout<<"i\txi0\txi1\txi2\txi3\txi4\txi5\txi6\txi0yi\txi1yi\txi2yi\txi3yi\n";
	for(int i=0;i<6;i++){
		cout.precision(3);
	//	cout<<i<<"\t"<<x0[i]<<"\t"<<x1[i]<<"\t"<<x2[i]<<"\t"<<x3[i]<<"\t"<<x4[i]<<"\t"<<x5[i]<<"\t"<<x6[i]<<"\t"<<x0y[i]<<"\t"<<xy[i]<<"\t"<<x2y[i]<<"\t"<<x3y[i]<<endl;
		s0+=x0[i];
		s1+=x1[i];
		s2+=x2[i];
		s3+=x3[i];
		s4+=x4[i];
		s5+=x5[i];
		s6+=x6[i];
		t0+=x0y[i];
		t1+=xy[i];
		t2+=x2y[i];
		t3+=x3y[i];
	}
	cout<<"So we have system:\n";
	cout<<s0<<"*a0+"<<s1<<"*a1+"<<s2<<"*a2+"<<s3<<"*a3="<<t0<<endl;
	cout<<s1<<"*a0+"<<s2<<"*a1+"<<s3<<"*a2+"<<s4<<"*a3="<<t1<<endl;
	cout<<s2<<"*a0+"<<s3<<"*a1+"<<s4<<"*a2+"<<s5<<"*a3="<<t2<<endl;
	cout<<s3<<"*a0+"<<s4<<"*a1+"<<s5<<"*a2+"<<s6<<"*a3="<<t3<<endl;
	cout<<"Gauss:\n";
	const int m=5;
	n=4;
	float  xx[m]; 
    float **matrix = new float *[n];
         for (i=0; i<n; i++)
             matrix[i] = new float [m];
 matrix[0][0]=s0;
 matrix[0][1]=matrix[1][0]=s1;
 matrix[0][2]=matrix[1][1]=matrix[2][0]=s2;
 matrix[0][3]=matrix[1][2]=matrix[2][1]=matrix[3][0]=s3;
 matrix[1][3]=matrix[2][2]=matrix[3][1]=s4;
 matrix[2][3]=matrix[3][2]=s5;
 matrix[3][3]=s6;

 matrix[0][4]=t0;
 matrix[1][4]=t1;
 matrix[2][4]=t2;
 matrix[3][4]=t3;

 Gauss(matrix, i, j, n, m, tmp,xx, k);

 float a0,a1,a2,a3;
 a0=xx[0];
 a1=xx[1];
 a2=xx[2];
 a3=xx[3];
 delete[] matrix;
 cout.precision(5);
cout<<"So, we have:\nQ3(xi)="<<a0<<"+"<<a1<<"*x+"<<a2<<"*x^2+"<<a3<<"*x^3\n";
cout<<"xi\tyi\tQm(xi)\tyi-Qm(xi)\n";
	for(int i=0;i<6;i++){
		cout<<x[i]<<"\t"<<y[i]<<"\t"<<q(x[i])<<"\t"<<y[i]-q(x[i])<<endl;
	}
	draw(choose);
	}
	else if(choose==4){
		float x0[6],x1[6],x2[6],x3[6],x4[6],x5[6],x6[6],x7[6],x8[6],x0y[6],xy[6],x2y[6],x3y[6],x4y[6];
	for(int i=0;i<6;i++){
		x0[i]=1;
		x1[i]=x[i];
		x2[i]=x[i]*x[i];
		x3[i]=x[i]*x[i]*x[i];
		x4[i]=x[i]*x[i]*x[i]*x[i];
		x5[i]=x[i]*x[i]*x[i]*x[i]*x[i];
		x6[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x7[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x8[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x0y[i]=1*y[i];
		xy[i]=x[i]*y[i];
		x2y[i]=x[i]*x[i]*y[i];
		x3y[i]=x[i]*x[i]*x[i]*y[i];
		x4y[i]=x[i]*x[i]*x[i]*x[i]*y[i];
	}
	float s0=0,s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,t0=0,t1=0,t2=0,t3=0,t4=0;
//	cout<<"i\txi0\txi1\txi2\txi3\txi4\txi5\txi6\txi7\txi8\txi0yi\txi1yi\txi2yi\txi3yi\txi4yi\n";
	for(int i=0;i<6;i++){
		cout.precision(3);
	//	cout<<i<<"\t"<<x0[i]<<"\t"<<x1[i]<<"\t"<<x2[i]<<"\t"<<x3[i]<<"\t"<<x4[i]<<"\t"<<x5[i]<<"\t"<<x6[i]<<"\t"<<x7[i]<<"\t"<<x8[i]<<"\t"<<x0y[i]<<"\t"<<xy[i]<<"\t"<<x2y[i]<<"\t"<<x3y[i]<<"\t"<<x4y[i]<<endl;
		s0+=x0[i];
		s1+=x1[i];
		s2+=x2[i];
		s3+=x3[i];
		s4+=x4[i];
		s5+=x5[i];
		s6+=x6[i];
		s7+=x7[i];
		s8+=x8[i];
		t0+=x0y[i];
		t1+=xy[i];
		t2+=x2y[i];
		t3+=x3y[i];
		t4+=x4y[i];
	}
	cout<<"So we have system:\n";
	cout<<s0<<"*a0+"<<s1<<"*a1+"<<s2<<"*a2+"<<s3<<"*a3+"<<s4<<"*a4="<<t0<<endl;
	cout<<s1<<"*a0+"<<s2<<"*a1+"<<s3<<"*a2+"<<s4<<"*a3+"<<s5<<"*a4="<<t1<<endl;
	cout<<s2<<"*a0+"<<s3<<"*a1+"<<s4<<"*a2+"<<s5<<"*a3+"<<s6<<"*a4="<<t2<<endl;
	cout<<s3<<"*a0+"<<s4<<"*a1+"<<s5<<"*a2+"<<s6<<"*a3+"<<s7<<"*a4="<<t3<<endl;
	cout<<s4<<"*a0+"<<s5<<"*a1+"<<s6<<"*a2+"<<s7<<"*a3+"<<s8<<"*a4="<<t4<<endl;
	cout<<"Gauss:\n";
	const int m=6;
	n=5;
	float  xx[m]; 
    float **matrix = new float *[n];
         for (i=0; i<n; i++)
             matrix[i] = new float [m];
 matrix[0][0]=s0;
 matrix[0][1]=matrix[1][0]=s1;
 matrix[0][2]=matrix[1][1]=matrix[2][0]=s2;
 matrix[0][3]=matrix[1][2]=matrix[2][1]=matrix[3][0]=s3;
 matrix[1][3]=matrix[2][2]=matrix[3][1]=matrix[4][0]=matrix[0][4]=s4;
 matrix[2][3]=matrix[3][2]=matrix[4][1]=matrix[1][4]=s5;
 matrix[3][3]=matrix[4][2]=matrix[2][4]=s6;
 matrix[3][4]=matrix[4][3]=s7;
 matrix[4][4]=s8;

 matrix[0][5]=t0;
 matrix[1][5]=t1;
 matrix[2][5]=t2;
 matrix[3][5]=t3;
 matrix[4][5]=t4;

 Gauss(matrix, i, j, n, m, tmp,xx, k);
 float a0,a1,a2,a3,a4;
 a0=xx[0];
 a1=xx[1];
 a2=xx[2];
 a3=xx[3];
  a4=xx[4];
 delete[] matrix;
 cout.precision(5);
cout<<"So, we have:\nQ4(xi)="<<a0<<"+"<<a1<<"*x+"<<a2<<"*x^2+"<<a3<<"*x^3+"<<a4<<"*x^4\n";

cout<<"xi\tyi\tQm(xi)\tyi-Qm(xi)\n";
	for(int i=0;i<6;i++){
		cout<<x[i]<<"\t"<<y[i]<<"\t"<<q(x[i])<<"\t"<<y[i]-q(x[i])<<endl;
	}
	draw(choose);
	}
	else if(choose==5){
		float x0[6],x1[6],x2[6],x3[6],x4[6],x5[6],x6[6],x7[6],x8[6],x9[6],x10[6],x0y[6],xy[6],x2y[6],x3y[6],x4y[6],x5y[6];
	for(int i=0;i<6;i++){
		x0[i]=1;
		x1[i]=x[i];
		x2[i]=x[i]*x[i];
		x3[i]=x[i]*x[i]*x[i];
		x4[i]=x[i]*x[i]*x[i]*x[i];
		x5[i]=x[i]*x[i]*x[i]*x[i]*x[i];
		x6[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x7[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x8[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x9[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x10[i]=x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i]*x[i];
		x0y[i]=1*y[i];
		xy[i]=x[i]*y[i];
		x2y[i]=x[i]*x[i]*y[i];
		x3y[i]=x[i]*x[i]*x[i]*y[i];
		x4y[i]=x[i]*x[i]*x[i]*x[i]*y[i];
		x5y[i]=x[i]*x[i]*x[i]*x[i]*x[i]*y[i];
	}
	float s0=0,s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,s9=0,s10=0,t0=0,t1=0,t2=0,t3=0,t4=0,t5=0;
//	cout<<"i\txi0\txi1\txi2\txi3\txi4\txi5\txi6\txi7\txi8\txi9\txi10\txi0yi\txi1yi\txi2yi\txi3yi\txi4yi\txi5yi\n";
	for(int i=0;i<6;i++){
		cout.precision(3);
		//cout<<i<<"\t"<<x0[i]<<"\t"<<x1[i]<<"\t"<<x2[i]<<"\t"<<x3[i]<<"\t"<<x4[i]<<"\t"<<x5[i]<<"\t"<<x6[i]<<"\t"<<x7[i]<<"\t"<<x8[i]<<"\t"<<x9[i]<<"\t"<<x10[i]<<"\t"<<x0y[i]<<"\t"<<xy[i]<<"\t"<<x2y[i]<<"\t"<<x3y[i]<<"\t"<<x4y[i]<<"\t"<<x5y[i]<<endl;
		s0+=x0[i];
		s1+=x1[i];
		s2+=x2[i];
		s3+=x3[i];
		s4+=x4[i];
		s5+=x5[i];
		s6+=x6[i];
		s7+=x7[i];
		s8+=x8[i];
		s9+=x9[i];
		s10+=x10[i];
		t0+=x0y[i];
		t1+=xy[i];
		t2+=x2y[i];
		t3+=x3y[i];
		t4+=x4y[i];
		t5+=x5y[i];
	}
	cout<<"So we have system:\n";
	cout<<s0<<"*a0+"<<s1<<"*a1+"<<s2<<"*a2+"<<s3<<"*a3+"<<s4<<"*a4+"<<s5<<"*a5="<<t0<<endl;
	cout<<s1<<"*a0+"<<s2<<"*a1+"<<s3<<"*a2+"<<s4<<"*a3+"<<s5<<"*a4+"<<s6<<"*a5="<<t1<<endl;
	cout<<s2<<"*a0+"<<s3<<"*a1+"<<s4<<"*a2+"<<s5<<"*a3+"<<s6<<"*a4+"<<s7<<"*a5="<<t2<<endl;
	cout<<s3<<"*a0+"<<s4<<"*a1+"<<s5<<"*a2+"<<s6<<"*a3+"<<s7<<"*a4+"<<s8<<"*a5="<<t3<<endl;
	cout<<s4<<"*a0+"<<s5<<"*a1+"<<s6<<"*a2+"<<s7<<"*a3+"<<s8<<"*a4+"<<s9<<"*a5="<<t4<<endl;
	cout<<s5<<"*a0+"<<s6<<"*a1+"<<s7<<"*a2+"<<s8<<"*a3+"<<s9<<"*a4+"<<s10<<"*a5="<<t5<<endl;
	cout<<"Gauss:\n";
	const int m=7;
	n=6;
	float  xx[m]; 
    float **matrix = new float *[n];
         for (i=0; i<n; i++)
             matrix[i] = new float [m];
 matrix[0][0]=s0;
 matrix[0][1]=matrix[1][0]=s1;
 matrix[0][2]=matrix[1][1]=matrix[2][0]=s2;
 matrix[0][3]=matrix[1][2]=matrix[2][1]=matrix[3][0]=s3;
 matrix[1][3]=matrix[2][2]=matrix[3][1]=matrix[4][0]=matrix[0][4]=s4;
 matrix[2][3]=matrix[3][2]=matrix[4][1]=matrix[1][4]=matrix[0][5]=matrix[5][0]=s5;
 matrix[3][3]=matrix[4][2]=matrix[2][4]=matrix[1][5]=matrix[5][1]=s6;
 matrix[3][4]=matrix[4][3]=matrix[2][5]=matrix[5][2]=s7;
 matrix[4][4]=matrix[5][3]=matrix[3][5]=s8;
 matrix[4][5]=matrix[5][4]=s9;
 matrix[5][5]=s10;

 matrix[0][6]=t0;
 matrix[1][6]=t1;
 matrix[2][6]=t2;
 matrix[3][6]=t3;
 matrix[4][6]=t4;
 matrix[5][6]=t5;

 Gauss(matrix, i, j, n, m, tmp,xx, k);
 float a0,a1,a2,a3,a4,a5;
 a0=xx[0];
 a1=xx[1];
 a2=xx[2];
 a3=xx[3];
  a4=xx[4];
   a5=xx[5];
 delete[] matrix;
 cout.precision(5);
cout<<"So, we have:\nQ5(xi)="<<a0<<"+"<<a1<<"*x+"<<a2<<"*x^2+"<<a3<<"*x^3+"<<a4<<"*x^4+"<<a5<<"*x^5\n";

cout<<"xi\tyi\tQm(xi)\tyi-Qm(xi)\n";
	for(int i=0;i<6;i++){
		cout<<x[i]<<"\t"<<y[i]<<"\t"<<q(x[i])<<"\t"<<y[i]-q(x[i])<<endl;
	}
	draw(choose);
	}
	}