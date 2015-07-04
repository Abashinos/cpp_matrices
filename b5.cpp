// Дана матрица А (N,M), N,M<=10, с элементами целого типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, в каждом столбце матрицы находит минимальный 
// элемент и заносит его в новый одномерный массив С(N). 
// Вывести на экран исходную матрицу и под ней сформированный одномерный массив. 
// Если столбец содержит несколько одинаковых минимальных элементов, то в массив занести первый из них.


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
	int* mins = new int[b];
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cin >> matrix[i][j];
		}
	}
	
	for (int j=0; j<b; ++j){
		int min_elem = INT_MAX;
		for (int i=0; i<a; ++i){
			if (matrix[i][j] < min_elem) {
				min_elem = matrix[i][j];
			}
		}
		mins[j] = min_elem;
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int j=0; j<b; ++j) {
		cout << mins[j] << " ";
	}
	return 0;
}