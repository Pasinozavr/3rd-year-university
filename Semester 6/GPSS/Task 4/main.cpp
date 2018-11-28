#include <iostream>
#include <ctime>
#include<vector>
#include<list>

using namespace std;

int GENERATE_total;
pair<int, int> GENERATE1, GENERATE2;
pair<int, int> ADVANCE1_1, ADVANCE2_1, ADVANCE3_1, ADVANCE1_2, ADVANCE2_2, ADVANCE3_2;

int terminate_A1 = 0, terminate_A2 = 0, terminate_A3 = 0;
int element1 = 0, element2 = 0, element3 = 0, element4 = 0, element5 = 0, element6 = 0, final1 = 0, final2 = 0;
vector<int> A1_time, A2_time, A3_time, A11_time, A12_time, A13_time;
int A1Owner = 0, A2Owner = 0, A3Owner = 0;


int Facility_A1 = 0, Facility_A2 = 0, Facility_A3 = 0;
vector<int> Time1, Time2, Time3;
double srTime1, srTime2, srTime3;
int max1 = 0, max2 = 0, max3 = 0;
int entry1 = 0, entry2=0, entry3=0;

int det1=0,det2=0;

void numbers(){
	cout<<"Деталей первого типа:"<<(Facility_A1+Facility_A2+Facility_A3)/2-5<<endl<<"Деталей второго типа:"<<(Facility_A1+Facility_A2+Facility_A3)/2+5<<endl;
}
void Initialize()
{
	GENERATE_total = 480;

	GENERATE1.first = 25; GENERATE1.second = 4;
	GENERATE2.first = 25; GENERATE2.second = 6;

	ADVANCE1_1.first = 20; ADVANCE1_1.second = 4;
	ADVANCE2_1.first = 5; ADVANCE2_1.second = 2;
	ADVANCE3_1.first = 15; ADVANCE3_1.second = 5;
	ADVANCE1_2.first = 15; ADVANCE1_2.second = 5;
	ADVANCE2_2.first = 7; ADVANCE2_2.second = 3;
	ADVANCE3_2.first = 10; ADVANCE3_2.second = 3;
	for (int i = 0; i < GENERATE_total; i++)
	{
		int new_time = GENERATE1.second - (rand() % (GENERATE1.second)) * 2;
		if (A1_time.size() == 0 && new_time < GENERATE_total)
		{
			A1_time.push_back(new_time);
			i = A1_time[A1_time.size() - 1]; 
			
		}
		else if((new_time+ GENERATE1.first+ A1_time[A1_time.size()-1]) < GENERATE_total)
		{
			A1_time.push_back(new_time + GENERATE1.first + A1_time[A1_time.size() - 1]);
			i = A1_time[A1_time.size() - 1];
			
		}	
		
	}
	for (int i = 0; i < GENERATE_total; i++)
	{
		int new_time = GENERATE2.second - (rand() % (GENERATE2.second)) * 2;
		if (A11_time.size() == 0 && new_time < GENERATE_total)
		{
			A11_time.push_back(new_time);
			i = A11_time[A11_time.size() - 1];
			
		}
		else if ((new_time + GENERATE2.first + A11_time[A11_time.size() - 1]) < GENERATE_total)
		{
			A11_time.push_back(new_time + GENERATE2.first + A11_time[A11_time.size() - 1]);
			i = A11_time[A11_time.size() - 1];
			
		}
		
	}
}
void Type1(int sec)
{
	//Появление инициализатора детали
	for (int i = 0; i < A1_time.size(); i++)
		if (A1_time[i] == sec)
		{
			element1++;
			entry1++;
			if ((element1 + element5) > max1) max1 = element1 + element5;
		}
		
	//первый станок
	if (element1 > 0)
	{
		if (terminate_A1 == 0)
		{
			terminate_A1 = sec + ADVANCE1_1.first + (ADVANCE1_1.second - rand() % ADVANCE1_1.second * 2);
			Time1.push_back(terminate_A1 - sec);
			A1Owner = 1;
			element1--;
		}
	}
	if (terminate_A1 <= sec && terminate_A1 && A1Owner==1)
	{
		element2++; Facility_A1++; entry2++;
		if ((element2+element6) > max2) max2 = element2 + element6;
		A1Owner = 0;
		terminate_A1 = 0;
		if (element1 > 0 && rand() % 2)
		{
			element1--;
			A1Owner = 1;
			terminate_A1 = sec + ADVANCE1_1.first + (ADVANCE1_1.second - rand() % ADVANCE1_1.second * 2);
			Time1.push_back(terminate_A1 - sec);
		}
		
	}
	



	//Второй станок
	if (element2 > 0)
	{
		if (terminate_A2 == 0)
		{
			terminate_A2 = sec + ADVANCE2_1.first + (ADVANCE2_1.second - rand() % ADVANCE2_1.second * 2);
			Time2.push_back(terminate_A2 - sec);
			A2Owner = 1;
			element2--;
		}
	}
		if (terminate_A2 <= sec && terminate_A2 &&  A2Owner == 1)
		{
			element3++; Facility_A2++; entry3++;
			if ((element3+element4) > max3) max3 = element3 + element4;
			A2Owner = 0;
			terminate_A2 = 0;
			if (element2 > 0 && rand() % 2)
			{
				element2--;
				A2Owner = 1;
				terminate_A2 = sec + ADVANCE2_1.first + (ADVANCE2_1.second - rand() % ADVANCE2_1.second * 2);
				Time2.push_back(terminate_A2 - sec);
			}
		}
	

	//Третий станок
	if (element3 > 0)
	{
		if (terminate_A3 == 0)
		{
			terminate_A3 = sec + ADVANCE3_1.first + (ADVANCE3_1.second - rand() % ADVANCE3_1.second * 2);
			Time3.push_back(terminate_A3 - sec);
			A3Owner = 1;
			element3--;
		}
		
	}
		if (terminate_A3 <= sec && terminate_A3 && A3Owner == 1)
		{
			final1++; Facility_A3++;
			A3Owner = 0;
			terminate_A3 = 0;
			if (element3 > 0 && rand() % 2)
			{
				element3--;
				A3Owner = 1;
				terminate_A3 = sec + ADVANCE3_1.first + (ADVANCE3_1.second - rand() % ADVANCE3_1.second * 2);
				Time3.push_back(terminate_A3 - sec);
			}
			
		}
	

}
void Type2(int sec)
{
	//Появление инициализатора детали
	for (int i = 0; i < A11_time.size(); i++)
		if (A11_time[i] == sec)
		{
			element4++; entry3++;
			if ((element3 + element4) > max3) max3 = element3 + element4;
		}
		
	




	//Первый станок
	if (element5 > 0)
	{
		if (terminate_A1 == 0)
		{
			terminate_A1 = sec + ADVANCE1_2.first + (ADVANCE1_2.second - rand() % ADVANCE1_2.second * 2);
			Time1.push_back(terminate_A1 - sec);
			A1Owner = 2;
			element5--;
		}
	}
		if (terminate_A1 <= sec && terminate_A1 && A1Owner == 2)
		{
			element6++; Facility_A1++; entry1++;
			if ((element2 + element6) > max2) max2 = element2 + element6;
			A1Owner = 0;
			terminate_A1 = 0; 
			if (element5 > 0 && rand() % 2)
			{
				element5--;
				A1Owner = 2;
				terminate_A1 = sec + ADVANCE1_2.first + (ADVANCE1_2.second - rand() % ADVANCE1_2.second * 2);
				Time1.push_back(terminate_A1 - sec);
			}
		}

		//третий станок
	if (element4 > 0)
	{
		if (terminate_A3 == 0)
		{
			terminate_A3 = sec + ADVANCE3_2.first + (ADVANCE3_2.second - rand() % ADVANCE3_2.second * 2);
			Time3.push_back(terminate_A3 - sec);
			A3Owner = 2;
			element4--;
		}
	}
		if (terminate_A3 <= sec && terminate_A3 && A3Owner == 2)
		{
			element5++; Facility_A3++;
			if ((element1 + element5) > max1) max1 = element1 + element5;
			A3Owner = 0;
			terminate_A3 = 0;
			if (element4 > 0 && rand() % 2)
			{
				element4--;
				A3Owner = 2;
				terminate_A3 = sec + ADVANCE3_2.first + (ADVANCE3_2.second - rand() % ADVANCE3_2.second * 2);
				Time3.push_back(terminate_A3 - sec);
			}
			
		}
	//Второй станок
	if (element6 > 0)
	{
		if (terminate_A2 == 0)
		{
			terminate_A2 = sec + ADVANCE2_2.first + (ADVANCE2_2.second - rand() % ADVANCE2_2.second * 2);
			Time2.push_back(terminate_A2 - sec);
			A2Owner = 2;
			element6--;
		}
	}
		if (terminate_A2 <= sec && terminate_A2 && A2Owner == 2)
		{
			final2++; Facility_A2++; entry2++;
			A2Owner = 0;
			terminate_A2 = 0;
			if (element6 > 0 && rand() % 2)
			{
				element6--;
				A2Owner = 2;
				terminate_A2 = sec + ADVANCE2_2.first + (ADVANCE2_2.second - rand() % ADVANCE2_2.second * 2);
				Time2.push_back(terminate_A2 - sec);
			}
		
		}

}
void Count()
{
	for (int sec = 1; sec < GENERATE_total; sec++)
	{
		Type1(sec);
		Type2(sec);
	}
	for (int i = 0; i < Time1.size(); i++)
		srTime1 += Time1[i];
	srTime1 = srTime1 / Time1.size();

	for (int i = 0; i < Time2.size(); i++)
		srTime2 += Time2[i];
	srTime2 = srTime2 / Time2.size();

	for (int i = 0; i < Time3.size(); i++)
		srTime3 += Time3[i];
	srTime3 = srTime3 / Time3.size();
}
void Report()
{
	cout << "Станок\t\t" << "Поступлений\t" <<"Среднее время\t"<</*"Owner\t\t"<<*/endl
		<< "AA1\t\t" << Facility_A1 <<"\t\t"<< srTime1	<<"\t\t"	<< /*(A1Owner)<< */ endl
		<< "AA3\t\t" << Facility_A3 << "\t\t" << srTime3 << "\t\t" << /*(A3Owner) << */endl
		<< "AA2\t\t" << Facility_A2 << "\t\t" << srTime2 << "\t\t" <</* (A2Owner) <<*/ endl;

	cout << endl << endl;

	cout << "Очередь\t\t" << "Максимум\t" << "Текущие\t\t" <<"Поступлений\t"<< endl
		<< "A1\t\t" << max1 <<"\t\t"<<element1 + element5  <<"\t\t"<<entry1<< endl
		<< "A3\t\t" << max3 << "\t\t" << element3 + element4 << "\t\t" << entry3 << endl
		<< "A2\t\t" << max2 << "\t\t" << element2 + element6 << "\t\t" << entry2 << endl;

	numbers();
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	Initialize();
	Count();
	Report();
	system("pause");
	return 0;
}