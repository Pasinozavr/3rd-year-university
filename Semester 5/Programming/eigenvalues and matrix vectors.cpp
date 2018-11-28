//крылова

#include<iostream>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	float a[10][10],x[10]={1,0,1,0,1,0,1,0,1,0},c[10],d=0,temp;
	//икс это наш стартовый вектор, в общем случае произвольный
    int n,i,j;
   // clrscr();
	printf("Enter the order of matrix ? ");
    scanf("%d",&n);
	printf("\nCoefficients of matrix ");
    for(i=0;i<n;i++)
    {
		printf("\nrow  %d  ",i+1);
        for(j=0;j<n;j++){
			scanf(" %f",&a[i][j]);}
    }


    do
    {
        for(i=0;i<n;i++)
        {
            c[i]=0;
            for(j=0;j<n;j++)
                c[i]+=a[i][j]*x[j];//умножили матрицу на наш вектор икс
        }
        for(i=0;i<n;i++)
            x[i]=c[i];//и результат засунули в этот же вектор, стерев предыдущие данные в нем
            
        temp=d;
        d=0;
        
        for(i=0;i<n;i++)
        {
            if(fabs(x[i])>fabs(d))
                d=x[i];//если полученный по модулю вектор положительный,
			//то это наше собств значение
        }
        for(i=0;i<n;i++)
            x[i]/=d;//и наш вектор нужно поделить на это значение чтобы получить собств вектор
            
    }while(fabs(d-temp)>0.00001);//и мы это считаем до тех пор, пока разница между пред и текущим собств значением (условно) не будет достаточно ничтожна
	printf("Eigen value is : %.3f\n",d);

    printf("Eigenvector is: ");

    for(i=0;i<n;i++)
		printf("\n%.3f",x[i]);

    getch();
    return 0;
}