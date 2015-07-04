// Дана матрица А (N,M), N,M<=10,  с элементами целого типа. 
// Написать программу на языке Паскаль или Си (консольный режим),  
// которая вводит матрицу, в каждом столбце матрицы удаляет минимальный элемент  
// и заносит его в новый одномерный массив С(N).  Вывести на экран исходную матрицу, 
// полученную матрицу A(N-1,M)  и под ней сформированный одномерный массив. 
// Если столбец содержит  несколько одинаковых минимальных элементов, 
// то удалить из столбца и занести в массив первый из них.


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
	int** new_matrix = new int*[a-1];
	for (int i=0; i<a-1; ++i) {
		new_matrix[i] = new int[b];
	}
	int* mins = new int[b];
	int* min_indices = new int[b];
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cin >> matrix[i][j];
		}
	}
		
	for (int j=0; j<b; ++j) {
		pair<int, int> min_elem = make_pair(0, INT_MAX);
		for (int i=0; i<a; ++i) {
			if (matrix[i][j] < min_elem.second) {
				min_elem.first = i;
				min_elem.second = matrix[i][j];
			}
		}
		min_indices[j] = min_elem.first;
		mins[j] = min_elem.second;
	}
	for (int j=0; j<b; ++j) {
		for (int i=0, k=0; i<a, k<a-1; ++i, ++k) {
			if (min_indices[j] != i) {
				new_matrix[k][j] = matrix[i][j]; 
			}
			else {
				--k;
			}
		}
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i=0; i<a-1; ++i){
		for (int j=0; j<b; ++j) {
			cout << new_matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int j=0; j<b; ++j){
		cout << mins[j] << " ";
	}
	return 0;
}