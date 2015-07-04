// Дана матрица А(N,M), N,M<=12, с элементами целого типа. Написать программу 
// на языке Паскаль или Си (консольный режим), которая вводит матрицу, определяет 
// суммы элементов строк до первого отрицательного элемента и заносит их в новый 
// одномерный массив. Вывести на экран исходную матрицу и рядом с ней массив сумм. 
// Если отрицательных элементов в строке нет, то занести в массив сумм ноль.

#include <iostream>
#include <climits>
using namespace std;


int main() {
	
	int a,b;
	cin >> a >> b;
	
	int** matrix = new int*[a];
	for (int i=0; i<a; ++i) {
		matrix[i] = new int[b];
	}
	int* sums = new int[a];
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cin >> matrix[i][j];
		}
	}
	
	for (int i=0; i<a; ++i){
		int sum = 0;
		bool neg = false;
		for (int j=0; j<b; ++j){
			if (matrix[i][j] >= 0) {
				sum += matrix[i][j];
			}
			else {
				neg = true;
				break;
			}
		}
		if (neg) {
			sums[i] = sum;
		}
		else {
			sums[i] = 0;
		}
	}
	
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << "\t" << sums[i] << endl;
	}
	cout << endl;
	return 0;
}
