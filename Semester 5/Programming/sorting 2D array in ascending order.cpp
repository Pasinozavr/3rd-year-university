//���������� ����������� �������
//�� �����������
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
    setlocale(0,"");//���� ������� ������ �� ������
    srand(time(NULL));   
    int n;
	cout<<"������� �����������:";
	cin>>n;

int**arr=new int*[n];
for(int i=0;i<n;i++){
	arr[i]=new int [n];}
    
	for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
	{cout<<"������� �������:";cin>>arr[i][j];}

	}
int inext, jnext;
    int i, j;
    int temp;
    bool sorted=false;
    while(!sorted){
        sorted=true;
        i=0; j=0;
        for(inext=0; inext<n; inext++)
            for(jnext=(inext?0:1); jnext<n; jnext++)
            {
                if(arr[i][j]>arr[inext][jnext]){
                    temp=arr[i][j];
                    arr[i][j]=arr[inext][jnext];
                    arr[inext][jnext]=temp;
                    sorted=false;
                }
                i=inext;
                j=jnext;
            }
    
    }
    cout<<"����� ���������� �� �����������""\n\n\n\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n\n\n\n";
    }
    system("pause");
}