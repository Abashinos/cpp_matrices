// Дана матрица D(N,M), N,M<=10,  с элементами целого типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу и два числа k,l<=10. Определить суммы элементов 
// четырех частей матрицы, на которые делят ее строка k и столбец l 
// (элементы строки k и столбца l не учитывать). Полученные значения 
// поместить в одномерный массив в любом порядке. Вывести на экран 
// исходную матрицу и одномерный массив.


#include <iostream>
#include <climits>
using namespace std;

int main() {
	
	int a,b,k,l;
	cin >> a >> b >> k >> l;
	
	int** matrix = new int*[a];
	for (int i=0; i<a; ++i) {
		matrix[i] = new int[b];
	}
	int sums[4] = {0, 0, 0, 0};
	
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
	
	for (int i=0; i<a; ++i) {
		for (int j=0; j<b; ++j) {
			if (i<k) {
				if (j<l) {
					sums[0] += matrix[i][j];
				}
				else if (j>l) {
					sums[1] += matrix[i][j];
				}
			}
			else if (i>k) {
				if (j>l) {
					sums[2] += matrix[i][j];
				}
				else if (j<l) {
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