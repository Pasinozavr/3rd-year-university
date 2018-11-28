#include <iostream> 
#include <Windows.h>
using namespace std;

int main() 
{ 
int n,i,j; 
FILE *f; 
f=fopen("C:\\Danya\\Matrix.txt","r"); 
fscanf(f,"%d",&n); 
if(n==0) 
{ 
cout<<"There's no elements. End program.."<<endl; 
system("pause"); 
return 0; 
} 
if(n%2!=0){//если н нечетное, то диагонали пересекаются
cout<<"Sorry, but matrix's diagonals cross, so end program\n";
system("pause"); 
return 0; 
} 
int **A = new int *[n];
for(i=0;i<n;i++){
	A[i]=new int [n];
}
for(int i=0;i<n;i++){
for (j = 0; j < n; j++) 
{ 
fscanf(f,"%d",&A[i][j]); 
} 
}
fclose(f);
cout<<"so, we read matrix:\n";
for(int i=0;i<n;i++){
for (j = 0; j < n; j++) 
{ 
cout<<A[i][j]<<"\t"; 
} 
cout<<endl;
}

//сортировка главной диагонали
int p=1;
while (p != 0)
            {
                p = 0;
                for (int i = 0; i < n-1; i++)
                {
                    if (A[i][i] > A[i + 1][i + 1])
                    {
                        int key = A[i][i];
                        A[i][i] = A[i + 1][i + 1];
                        A[i + 1][i + 1] = key;
                        p++;
                    }
                }
            }

			cout<<"after first sort:\n";
for(i=0;i<n;i++){
for (j = 0; j < n; j++) 
{ 
cout<<A[i][j]<<"\t"; 
} 
cout<<endl;
}

for (int i = 0; i < n-1; i++)     // Сортировка побочной диагонали по возрастанию
     { for (int j = i+1; j < n; j++)  // (пузырьковая)
         { if (A[j][n-1-j] > A[i][n-1-i])
            { int t = A[j][n-1-j];
              A[j][n-1-j] = A[i][n-1-i];
              A[i][n-1-i] = t;
            }
         }
     }

			cout<<"after second sort:\n";
for(i=0;i<n;i++){
for (j = 0; j < n; j++) 
{ 
cout<<A[i][j]<<"\t"; 
} 
cout<<endl;
}


system("pause");
return 0;
}

