//variant 1
#include <iostream>
#include <math.h>
using namespace std;
void Gauss(double matrix[4][5],int n,int m,double*xx){
	int i,j,k;
	double tmp;
//выводим массив
    cout << "matrix: " << endl;
      for (i=0; i<n; i++)
       {
          for (j=0; j<m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
       }
    //cout << endl;
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
			 cout<<"tmp=matrix["<<j<<"]["<<i<<"]\n";
             for (k=n;k>=i;k--){
            cout<<"matrix["<<j<<"]["<<k<<"]-=tmp*matrix["<<i<<"]["<<k<<"]\n";			   
				 matrix[j][k]-=tmp*matrix[i][k];
			cout << "matrix: " << endl;
      for (int i=0; i<n; i++)
       {
          for (int j=0; j<m; j++){
			  cout << matrix[i][j] << " ";}
        cout << endl;
	  }		   
          }
		   
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
	 cout<<"Matrix's solution..\n";
       for (i=0; i<n; i++)
           cout << xx[i] << " ";
      cout << endl;
}
int main(){
	int n=4;
	double*xx=new double [n+1];
//	cout<<"Fill size of matrix: ";
//	cin>>n;
	int i,j,k=1;
	double**B;
	B=new double*[n];
	for(int i=0;i<n;i++)
	{
		B[i]=new double [n];
	}
	
	B[0][0]=0.23;B[0][1]=-0.04;B[0][2]=0.21;B[0][3]=-0.18;
	B[1][0]=0.45;B[1][1]=-0.23;B[1][2]=0.06;B[1][3]=0.0;
	B[2][0]=0.26;B[2][1]=0.34;B[2][2]=-0.11;B[2][3]=0.0;
	B[3][0]=0.05;B[3][1]=-0.26;B[3][2]=0.34;B[3][3]=-0.12;
	/*
	B[0][0]=2.2;B[0][1]=1;B[0][2]=0.5;B[0][3]=2;
	B[1][0]=1;B[1][1]=1.3;B[1][2]=2;B[1][3]=1;
	B[2][0]=0.5;B[2][1]=2;B[2][2]=0.5;B[2][3]=1.6;
	B[3][0]=2;B[3][1]=1;B[3][2]=1.6;B[3][3]=2;
	*/
	cout<<"Input data..\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<B[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"Processing..\n";
	cout<<"Creating not-null vector..\n";
	double**y=new double*[n];
	for(int i=0;i<n;i++){
		y[i]=new double[n+1];
	}
	double*y0=new double[n+1];
	double*y1=new double[n+1];
	double*y2=new double[n+1];
	double*y3=new double[n+1];
	double*y4=new double[n+1];
	y0[0]=1;	
	y0[1]=1;
	y0[2]=0;
	y0[3]=1;
	cout<<"y(0)=(";
	for(int i=0;i<4;i++){if(i!=3){cout<<y0[i]<<" ";}else{cout<<y0[i]<<")\n";}}
	for(int i=1;i<n;i++){
		for(int j=0;j<n+1;j++){
			y1[j]=y2[j]=y3[j]=y4[j]=xx[j]=0;
		}
	}
	for(j=0;j<4;j++){
	for(i=0;i<4;i++)
	{
		y1[j]+=B[j][i]*y0[i];
	}
	}
	cout<<"Find vectors y..\n";
cout<<"y(1)=(";
for(i=0;i<n;i++){cout<<y1[i]<<" ";}
cout<<")\n";
	for(j=0;j<4;j++){
	for(i=0;i<4;i++)
	{
		y2[j]+=B[j][i]*y1[i];
	}
	}
cout<<"y(2)=(";
for(i=0;i<n;i++){cout<<y2[i]<<" ";}
cout<<")\n";
	for(j=0;j<4;j++){
	for(i=0;i<4;i++)
	{
		y3[j]+=B[j][i]*y2[i];
	}
	}
cout<<"y(3)=(";
for(i=0;i<n;i++){cout<<y3[i]<<" ";}
cout<<")\n";

for(j=0;j<4;j++){
	for(i=0;i<4;i++)
	{
		y4[j]+=B[j][i]*y3[i];
	}
	}
cout<<"y(4)=(";
for(i=0;i<n;i++){cout<<y4[i]<<" ";}
cout<<")\n\n";

for(j=0;j<n;j++){
	cout<<y3[j]<<"*p1+"<<y2[j]<<"*p2+"<<y1[j]<<"*p3+"<<y0[j]<<"*p4="<<y4[j]<<"\n";

}
double matrix[4][5];
matrix[0][0]=y3[0];matrix[0][1]=y2[0];matrix[0][2]=y1[0];matrix[0][3]=y0[0];matrix[0][4]=y4[0];
matrix[1][0]=y3[1];matrix[1][1]=y2[1];matrix[1][2]=y1[1];matrix[3][3]=y0[1];matrix[1][4]=y4[1];
matrix[2][0]=y3[2];matrix[2][1]=y2[2];matrix[2][2]=y1[2];matrix[2][3]=y0[2];matrix[2][4]=y4[2];
matrix[3][0]=y3[3];matrix[3][1]=y2[3];matrix[3][2]=y1[3];matrix[1][3]=y0[3];matrix[3][4]=y4[3];

cout<<"Gauss..\n";
	Gauss(matrix,4,5,xx);
	//cout.precision(2);
	cout<<"Our polinom..\n";
	cout<<"(A means lyambda)\n";
	cout<<"A^4-("<<xx[0]<<")*A^3-("<<xx[1]<<")*A^2-("<<xx[2]<<")*A^1-("<<xx[3]<<")=0\n";
	system("pause");
	return 0;
}