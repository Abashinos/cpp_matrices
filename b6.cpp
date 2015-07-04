// Дана квадратная матрица D(N,N), N<=10,  с элементами вещественного типа. 
// Написать программу на языке Паскаль или Си (консольный режим), которая 
// вводит матрицу, определяет максимальный элемент в каждой строке и перемещает его 
// на место элемента главной диагонали той же строки. Считать максимальный элемент 
// в каждой строке единственным. Вывести на экран исходную и полученную после перестановки матрицы.


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
	
	for (int i=0; i<a; ++i){
		int max_elem = INT_MIN;
		for (int j=0; j<a; ++j){
			if (matrix[i][max_elem] < matrix[i][j]) {
				max_elem = j;
			}
		}
		swap(matrix[i][max_elem], matrix[i][i]);
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<a; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}