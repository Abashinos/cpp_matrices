// Дана матрица D(N,M), N,M<=10,  с элементами вещественного типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, для каждой  строки матрицы определяет 
// максимальный элемент и перемещает его на место последнего 
// элемента этой строки.  Вывести на экран исходную и полученную 
// после перестановки матрицы. Максимальный элемент считать единственным. 

#include <iostream>
#include <climits>
using namespace std;

int main() {
	
	int a,b;
	cin >> a >> b;
	
	double** matrix = new double*[a];
	for (int i=0; i<a; ++i) {
		matrix[i] = new double[b];
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cin >> matrix[i][j];
		}
	}
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i=0; i<a; ++i){
		int max_elem = -INT_MAX;
		for (int j=0; j<b; ++j){
			if (matrix[i][max_elem] < matrix[i][j]) {
				max_elem = j;
			}
		}
		swap(matrix[i][max_elem], matrix[i][b-1]);
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
