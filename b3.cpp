// Дана матрица А(N,M), N,M<=10, с элементами целого типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, считает количество различных квадратов 
// со стороной k, содержащих только нулевые элементы, которые можно 
// выделить в матрице. Вывести на экран исходную матрицу и 
// количество квадратов или сообщение о том, что таких квадратов 
// в матрице нет.

#include <iostream>
#include <climits>
using namespace std;


int main() {
	
	int a,b,k;
	cin >> a >> b >> k;
	
	int** matrix = new int*[a];
	for (int i=0; i<a; ++i) {
		matrix[i] = new int[b];
	}
	int squares = 0;
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cin >> matrix[i][j];
		}
	}
	
	for (int i=0; i<a-k+1; ++i){
		for (int j=0; j<b-k+1; ++j){
			if (matrix[i][j] == 0) {
				bool sq = true;
				for (int l=i; l<a && l<i+k; ++l) {
					for (int m=j; m<b && m<j+k; ++m) {
						if (!matrix[l][m] == 0) {
							sq = false;
							break;
						}
					}
					if (!sq) {
						break;
					}
				}
				if (sq) {
					++squares;
				}
			}
		}
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	if (squares != 0) {
		cout << "Количество квадратов: " << squares;
	}
	else {
		cout << "Квадратов нет.";
	}
	return 0;
}