// Дана матрица А(N,N), N<=10, с элементами вещественного типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, определяет минимальный элемент 
// выше главной диагонали и помещает его на место максимального значения ниже главной диагонали. 
// Вывести на экран исходную матрицу и полученную после перестановки.


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
	
	pair<int, int> min_elem = make_pair(0, 0), max_elem = make_pair(0, 0);
	int min_val = INT_MAX, max_val = INT_MIN;
		
	for (int i=0; i<a; ++i) {
		for (int j=i+1; j<a; ++j) {
			if (matrix[i][j] < min_val) {
				min_val = matrix[i][j];
				min_elem = make_pair(i, j);
			}
		}
		for (int j=0; j<i; ++j) {
			if (matrix[i][j] > max_val) {
				max_val = matrix[i][j];
				max_elem = make_pair(i, j);
			}
		}
	}
	
	swap(matrix[max_elem.first][max_elem.second], matrix[min_elem.first][min_elem.second]);
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<a; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}