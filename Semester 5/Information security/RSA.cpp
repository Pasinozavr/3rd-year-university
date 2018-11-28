// RSA.cpp : RSA.
//


//#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;


/////////////////////////////////////////////////////////////////////
//�������� "������ ���������". �������� ��� ������� �����
//�� ��������� (�������� ����������������).
int sundaram(int n)
{
int *a = new int [n], i, j, k;
memset(a, 0, sizeof(int) * n);
for(i = 1; 3*i+1 < n; i++)
{
for(j = 1; (k = i+j+2*i*j) < n && j <= i; j++)
a[k] = 1;
}
//�������� �� ������ ������� ����� ��������� � ���������.
for(i = n-1; i >= 1; i--)
if(a[i] == 0)
{
return (2 * i + 1);
break;
}
delete [] a;
}
/////////////////////////////////////////////////////////////////////
//�������� �������. �������� ��� ���������� �����������
//������ �������� ���� ����� �����. ������������ ��� ��������
//����� �� ��������������.
int gcd(int a, int b)
{
int c;
while (b)
{
c = a % b;
a = b;
b = c;
}
return abs(a);
}
/////////////////////////////////////////////////////////////////////
int main()
{
cout << "Please wait... Key generation procces." << endl << endl;
// ��������� ���� ����� � ����� ���� ������� �����.
srand( (unsigned)time( NULL ) );
int p = rand()%100;
int q = rand()%100;
cout<<"OUR P="<<p<<endl<<"OUR Q="<<q<<endl;
int p_simple = sundaram(p);
int q_simple = sundaram(q);
//������� ����� n.
unsigned int n = p_simple*q_simple;

cout<<"OUR N="<<n<<endl;
//��������� ����� d � �������� ��� �� ��������������
//� ������ ((p_simple-1)*(q_simple-1)).
int d, d_simple = 0;
while (d_simple !=1)
{
d = rand()%100;
d_simple = gcd (d, ((p_simple-1)*(q_simple-1)));
}
//����������� ����� e, ��� �������� �������� ��������
//����������� (e*d)%((p_simple-1)*(q_simple-1))=1.
unsigned int e = 0, e_simple = 0;
while (e_simple !=1)
{
e += 1;
e_simple = (e*d)%((p_simple-1)*(q_simple-1));
}
//��������������� �����.
cout << '{' << setw(12) << e << ',' << setw(12) << n << '}' << " - Open key" << endl;
cout << '{' << setw(12) << d << ',' << setw(12) << n << '}' << " - Secret key" << endl << endl;
//���� ��������� ������.
const int MAX = 20;
char *Text = new char [MAX];
//cout << "Please enter the Text. Use <Enter> button when done." << endl;


	//cin.get(Text, MAX);
FILE*to;
to=fopen("to2.txt","w+");
FILE*f;
f=fopen("from.txt","r");
fscanf(f,"%s",Text);
fclose(f);
//������ ��� �������� �����������.
unsigned int *CryptoText = new unsigned int [MAX];
unsigned int *Tdecrypt = new unsigned int [MAX];
//��������� �� �������� ������ ����������� ���� ASCII �
//���������� ��� �������������� �� ������� ci = (mj^e)%n.
int b = 301;
int c;

cout << endl << setw(5) << "Text" << setw(6) << "ASCII"
<< setw(20) <<"CryptoText/Block#" << setw(14)
<< "ASCIIdecrypt" << setw(14) << "Text decrypt" << endl
<< "------------------------------------------------------------" << endl;
for (int j = 0; j < MAX; j++)
{
c = 1;
unsigned int i = 0;
int ASCIIcode = (static_cast<int>(Text[j]))+b;
while (i<e)
{
c = c*ASCIIcode;
c = c%n;
i++;
}
CryptoText[j] = c;
b+=1;
}
FILE*f1;
f1=fopen("to.txt","w+");
fprintf(f1,"%s",&CryptoText);
fclose(f1);
cin.get();
FILE*f2;
f2=fopen("to.txt","r");
fprintf(f2,"%d",&CryptoText);
fclose(f2);
//����������� ����������� ���� �� ������� mi = (ci^d)%n
//� ������� ��� � ���������� ��� ASCII.
b = 301;
int m;
for (int j = 0; j < MAX; j++)
{
m = 1;
unsigned int i = 0;
while (i<d)
{
m = m*CryptoText[j];
m = m%n;
i++;
}
m = m-b;
Tdecrypt[j] = m;
b+=1;
}

for (int j = 0; j < MAX; j++)
{
	fprintf(to,"\t%c\t%d\t%d\t%d\t%c\n",Text[j],static_cast<int>(Text[j]),CryptoText[j],Tdecrypt[j] ,static_cast<char>(Tdecrypt[j]));

cout << setw(5) << Text[j] << setw(6) << static_cast<int>(Text[j]) << setw(20)
<< CryptoText[j] << setw(14) << Tdecrypt[j] << setw(14) << static_cast<char>(Tdecrypt[j]) << endl;
}

fclose(to);


delete [] Text;
delete [] CryptoText;
delete [] Tdecrypt;
cin.get();
system("pause");
return 0;
}

/*
int _tmain(int argc, _TCHAR* argv[])
{
return 0;
}*/