// Дана матрица D(N,N), N<=10,  с элементами целого типа. 
// Написать программу на языке Паскаль или Си (консольный режим), 
// которая вводит матрицу и два числа k, l <=10. Определить суммы элементов матрицы, 
// находящихся выше и ниже диагонали, которая проведена через элемент с индексами k и l 
// параллельно главной диагонали. (Элементы диагонали в суммы не входят.) 
// Вывести на экран исходную матрицу и полученные суммы.


#include <iostream>
#include <climits>
using namespace std;

int main() {
	
	int a,k,l;
	cin >> a >> k >> l;
	
	int** matrix = new int*[a];
	for (int i=0; i<a; ++i) {
		matrix[i] = new int[a];
	}
	pair<int, int> sums = make_pair(0, 0);
	
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
	
	// расстояние от главной диагонали
	int distance = k - l;
	
	for (int i=0; i<a; ++i) {
		for (int j=0; j<a; ++j) {
			if (i < j + distance) {
				sums.first += matrix[i][j];
			}
			else if (i > j + distance) {
				sums.second += matrix[i][j];
			}
		}	
	}
	cout << sums.first << " " << sums.second;
	
	return 0;
}