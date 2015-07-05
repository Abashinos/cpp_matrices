// Дана матрица D(N,N), N<=10,  с элементами целого типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, находит суммы элементов четырех частей матрицы, 
// на которые делят ее главная и побочная диагонали (без диагональных элементов). 
// Полученные значения поместить в одномерный массив в любом порядке. 
// Вывести на экран исходную матрицу и одномерный массив.


#include <iostream>
#include <climits>
using namespace std;

int main() {
	
	int a;
	cin >> a;
	
	int** matrix = new int*[a];
	for (int i=0; i<a; ++i) {
		matrix[i] = new int[a];
	}
	int sums[4] = {0, 0, 0, 0};
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<a; ++j) {
			cin >> matrix[i][j];
		}
	}
	
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
					sums[0] += matrix[i][j];
				}
				else if (j>a-i-1) {
					sums[1] += matrix[i][j];
				}
			}
			else if (i>j) {
				if (j>a-i-1) {
					sums[2] += matrix[i][j];
				}
				else if (j<a-i-1) {
					sums[3] += matrix[i][j];
				}
			}
		}	
	}
	for (int i=0; i<4; ++i) {
		cout << sums[i] << " ";
	}
	
	return 0;
}