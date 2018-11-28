#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
 
// объ€вление прототипов функций
void check_zero(int ** MATRIX, int ORDER, int *LC_NUMBER, bool *LC_CHECK);
int ** matrix_cut(int ** MATRIX, int ORDER, int CUT_LINE_NUMBER, int CUT_COLUMN_NUMBER);
int body(int ** MATRIX, int ORDER, int *LC_NUMBER, bool *LC_CHECK);
void matrix_output(int ** MATRIX, int STRINGS, int COLUMNS);
 
 
// объ€вление глобальных переменных
int LC = 0;
bool LC_ch = false;
double det = 0;
 
 
int main()
{
      int ord;
	  FILE *f; 
		f=fopen("C:\\Danya\\Matrix.txt","r"); 
      fscanf(f,"%d",&ord); 
 
      int ** mat_det = new int * [ord];
      for (int c = 0; c < ord; c++)
            mat_det[c] = new int [ord];
	
    
//            int ** mat_det = new int * [ord];
        //    for (int c = 0; c < ord; c++)
        //          mat_det[c] = new int [ord];

            for (int i = 0; i < ord; i++) {
                  for (int j = 0; j < ord; j++) {
                       fscanf(f,"%d",&mat_det[i][j]); 
                  }
                  cout << endl;
            }
 fclose(f);
            {
            matrix_output(mat_det, ord, ord);         // вывод исходной матрицы на экран
            cout << endl;                             // красиво смотритс€ кстати
            //getch();
            }
            
            {                                         // старт расчета, запуск рекурсии
            det = body(mat_det, ord, &LC, &LC_ch);
            }
 
            cout << "Determinant = " << det;
            getch();
 
            {                                         // блок обнулени€ переменных
                  for (int c = 0; c < ord; c++)
                        delete [] mat_det[c];
                  delete [] mat_det;
                  LC = 0; LC_ch = false;
                  det = 0;
            }     
 
           
 
      return 0;
}
 
 
int body(int ** MATRIX, int ORDER, int *LC_NUMBER, bool *LC_CHECK)
{
      double DET = 0;
 
      if (ORDER == 1)                           // если наконец разложили до первого пор€дка, то возвращаем число
            return MATRIX[0][0];
      else 
      {
            check_zero(MATRIX, ORDER, &LC, &LC_ch);    
 
            if (*LC_CHECK)                      // если раскладываем по строке, то так
            {   
                  for (int i = 0; i < ORDER; i++) 
                  {
                        if (MATRIX[*LC_NUMBER][i] == 0)
                              continue;
                        else 
                        {
                              DET += pow((double)-1, *LC_NUMBER + i) * MATRIX[*LC_NUMBER][i] * 
                                    body( matrix_cut(MATRIX, ORDER, *LC_NUMBER, i), ORDER-1, &LC, &LC_ch);
                        }
                  }
            }
            else                                // если по столбцу, то так.. фишка здесь в смене индексов
            {
                  for (int i = 0; i < ORDER; i++) 
                  {
                        if (MATRIX[i][*LC_NUMBER] == 0)
                              continue;
                        else 
                        {
                              DET += pow((double)-1, i + *LC_NUMBER) * MATRIX[i][*LC_NUMBER] * 
                                    body( matrix_cut(MATRIX, ORDER, i, *LC_NUMBER), ORDER-1, &LC, &LC_ch);
                        }
                  }
            }
      }
      return DET;
}
 
 
void check_zero(int ** MATRIX, int ORDER, int *LC_NUMBER, bool *LC_CHECK)
{     // смотрим в какой строке или в каком столбце больше нулей
      // в глобальную переменную LC присваиваетс€ номер строки или столбца
      // а в такую же глобальную LC_ch присваиваетс€ true дл€ строки и false дл€ столбца
 
      int ch_L = 0, ch_C = 0, max_L = 0, max_C = 0, line_num = 0, col_num = 0;
 
      for (int i = 0; i < ORDER; i++)
      {
            for (int j = 0; j < ORDER; j++)
            {
                  if (MATRIX[i][j] == 0)
                  {
                        ch_L++;
                        if (j == ORDER-1 && max_L < ch_L) {
                              max_L = ch_L;
                              line_num = i;
                        }
                  }                       // фишка оп€ть в смене индексов
                  if (MATRIX[j][i] == 0)
                  {
                        ch_C++;
                        if (j == ORDER-1 && max_C < ch_C) {
                              max_C = ch_C;
                              col_num = i;
                        }
                  }
            }
            ch_L = 0; ch_C = 0;
      }
      if (max_L >= max_C) {
            *LC_CHECK = true;
            *LC_NUMBER = line_num;
      }
      else {
            *LC_CHECK = false;
            *LC_NUMBER = col_num;
      }
}
 
 
int ** matrix_cut(int ** MATRIX, int ORDER, int CUT_LINE_NUMBER, int CUT_COLUMN_NUMBER)
{     // делает минор из матрицы n-ого пор€дка, 
      // т.е. создает матрицу (n-1)ого пор€дка с вырезанными строкой и столбцом
 
      int order_new = ORDER - 1;
      int **mat_new = new int *[order_new];
      for (int c = 0; c < ORDER-1; c++)
            mat_new[c] = new int [order_new];
 
      int m=0, n=0;
      for (int i = 0; i < ORDER; i++) {
            if (i != CUT_LINE_NUMBER) {
                  for (int j = 0; j < ORDER; j++) {
                        if (j != CUT_COLUMN_NUMBER) {
                              mat_new[m][n] = MATRIX[i][j];
                              n++;
                        }
                        else
                              continue;
                  }
                  m++;
                  n=0;
            }
            else
                  continue;
      }
 
      //check_zero(mat_new, order_new, &LC, &LC_ch);
      //matrix_output(mat_new, order_new, order_new);
      //cout << endl;
      //getch();
      return mat_new;
}
 
 
void matrix_output(int ** MATRIX, int STRINGS, int COLUMNS) {
      if (STRINGS == 1) {
            for (int c = 0; c < COLUMNS; c++)
                  cout << " " << MATRIX[0][c];
      }
      else {
            for (int c = 0; c < STRINGS; c++) {
                  if (c == 0) 
                        cout << '\x2f';
                  else if (c == STRINGS-1)
                        cout << '\x5c';
                  else
                        cout << '\x7c';
 
                  for (int d = 0; d < COLUMNS; d++)
                        cout << " " << MATRIX[c][d];
                  
                  if (c == 0) 
                        cout << " " << '\x5c';
                  else if (c == STRINGS-1)
                        cout << " " << '\x2f';
                  else
                        cout << " " << '\x7c';
 
                  cout << endl;
            }
            // cout << endl;
      }
}