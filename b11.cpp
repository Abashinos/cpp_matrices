// Дана матрица D(N,N), N<=10,  с элементами вещественного типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, находит средние арифметические элементов  
// четырех частей матрицы, на которые делят ее главная и побочная диагонали  
// (без диагональных элементов). Полученные значения поместить в одномерный  
// массив в любом порядке.  Вывести на экран исходную матрицу и одномерный массив.


#include <iostream>
#include <climits>
using namespace std;

int main() {
	
	int a;
	cin >> a;
	
	double** matrix = new double*[a];
	for (int i=0; i<a; ++i) {
		matrix[i] = new double[a];
	}
	double avgs[4] = {0, 0, 0, 0};
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<a; ++j) {
			cin >> matrix[i][j];
		}
	}
		
	// количество элементов в каждой ячейке
	int elems_number = ((a % 2 == 0) ? (a*a - 2*a) : (a*a - 2*a + 1))/4;
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<a; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i=0; i<a; ++i) {
		for (int j=0; j<a; ++j) {
			if (i<j) {
				if (j<a-i-1) {
					avgs[0] += matrix[i][j];
				}
				else if (j>a-i-1) {
					avgs[1] += matrix[i][j];
				}
			}
			else if (i>j) {
				if (j>a-i-1) {
					avgs[2] += matrix[i][j];
				}
				else if (j<a-i-1) {
					avgs[3] += matrix[i][j];
				}
			}
		}	
	}
	for (int i=0; i<4; ++i) {
		avgs[i] /= elems_number;
		cout << avgs[i] << " ";
	}
	
	return 0;
}