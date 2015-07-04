// Дана матрица А(N,M), N,M<=10, с элементами целого типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, определяет среднее арифметическое 
// максимального и минимального элементов каждого столбца 
// и помещает полученное значение на место первого элемента столбца. 
// Вывести на экран исходную матрицу и полученную после перестановки.


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
	
	for (int j=0; j<b; ++j) {
		int min_elem = INT_MAX, max_elem = INT_MIN;
		for (int i=0; i<a; ++i) {
			if (matrix[i][j] < min_elem) {
				min_elem = matrix[i][j];
			}
			if (matrix[i][j] > max_elem) {
				max_elem = matrix[i][j];
			}
		}
		matrix[0][j] = (min_elem + max_elem) / 2;
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}