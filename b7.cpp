// Дана матрица А(N,N), N<= 12, с элементами целого типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, для каждого столбца этой матрицы определяет 
// среднее арифметическое элементов, расположенных до первого нулевого элемента, 
// и помещает полученное значение на место элемента побочной диагонали того же столбца. 
// Вывести на экран исходную матрицу и полученную после перестановки. 


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
	
	for (int j=0; j<a; ++j){
		int avg = 0, count = 0;
		for (int i=0; i<a; ++i){
			if (matrix[i][j] == 0) {
				break;
			}
			else {
				++count;
				avg += matrix[i][j];
			}
		}
		if (count > 0) {
			avg /= count;
		}
		matrix[a-j-1][j] = avg;
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<a; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}