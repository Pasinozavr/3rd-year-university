#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const char ch = '\n';
	int n=0;
	FILE*f;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);

	char**s=new char*[n];
	
	for(int i=0;i<n;i++)
	{
		char t[10];
		fscanf(f,"%s",t);
		printf("Word #%d - %s\n",i+1,t);
		int len=0;
		do{
			len++;
		}while(t[len]);
		//cout<<len<<endl;
		s[i]=new char [len];
		do{
			s[i][len]=t[len];
			len--;
		}while(len);
		s[i][len]=t[len];//ÒÀÊ ÍÀÄÎ
		//cout<<s[i]<<endl;
	}
	fclose(f);

	cout<<"Sorting\n";
	
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++){    
			
				bool older=false;
				//cout<<s[i]<<endl;
				int len1=strlen(s[i]);
				int len2=strlen(s[j]);
				int minlen=min(len1,len2);
				//cout<<"min("<<len1<<","<<len2<<")="<<minlen<<endl;
				for(int k=0;k<minlen;k++)
				{
					int a=s[i][k];
					int b=s[j][k];
					//cout<<"Sravnivaem "<< s[i][k] << " i " << s[j][k]<<endl;
					if(a>b){older=true;}
				}
            if (older==true) swap(s[i],s[j]);
		}
	cout<<"Solution:\n";
		for(int i=0;i<n;i++)
	{
		printf("Word #%d - %s\n",i+1,s[i]);
	}

	system("pause");
        return 0;
}