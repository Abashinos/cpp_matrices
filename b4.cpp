// Дана матрица А(N,M), N,M<= 10, с элементами вещественного типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу, определяет минимальный элемент в столбце, 
// содержащем максимальный элемент матрицы. Вывести на экран исходную 
// матрицу, номер столбца и найденный минимальный элемент. Считать 
// максимальный в матрице и минимальный элемент в указанном столбце единственными.


#include <iostream>
#include <cfloat>
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
	
	pair<int, double> p = pair<int, double>(0, DBL_MIN); 
	double min_elem = DBL_MAX;
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j){
			if (matrix[i][j] > p.second) {
				p.first = j;
				p.second = matrix[i][j];
			} 
		}
	}
	for (int i=0; i<a; ++i) {
		if (matrix[i][p.first] < min_elem) {
			min_elem = matrix[i][p.first];
		}
	}
	
	for (int i=0; i<a; ++i){
		for (int j=0; j<b; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Столбец: " << p.first << endl << "Минимальный элемент: " << min_elem;
	return 0;
}