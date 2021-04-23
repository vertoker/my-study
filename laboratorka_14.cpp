#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void calculateAverage(double *averages, int **array, int row, int column){
	for (int x = 0; x < row; x++){
		double sum = 0;
		for (int y = 0; y < column; y++){
			sum += array[x][y];
		}
		averages[x] = sum / column;
	}
}

int calculateCounter(int *numbers, double *averages, double num, int row){
	int counter = 0;
	for (int x = 0; x < row; x++){
		if (averages[x] < num){
			numbers[counter] = x;
			counter += 1;
		}
	}
	return counter;
}

int main() {
	//��������� � ����
	setlocale(LC_ALL, "Russian");
	int row, column, **array;
	double num;
	cout << "������� ����������� ��������: ";
	cin >> num;
	cout << "������� ���������� �����: ";
	cin >> row;
	cout << "������� ���������� ��������: ";
	cin >> column;
	
	array = new int *[row];
	double *averages = (double *) new double[row];
	int *numbers = (int *) new int[row];
	
	for (int x = 0; x < row; x++){
		array[x] = new int[column];
		cout << "������� �������� ��� " << x + 1 << "-� ������ (" << column << " ��������): ";
		for (int y = 0; y < column; y++){
			cin >> array[x][y];
		}
	}
	//����� �������
	cout << endl << "������� �������" << endl;
	for (int x = 0; x < row; x++){
		for (int y = 0; y < column; y++){
			cout << array[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	//������������
	calculateAverage(averages, array, row, column);
	int counter = calculateCounter(numbers, averages, num, row);
	
	//�����
	if (counter == 0){
		cout << "� ������� ���� �����, ������� ������������� ������� ������ " << num;
	}
	else{
		cout << "���������� �����, ������� ������������� ������� ������ " << num << " ����� " << counter << endl;
		cout << "������ ��� �������: ";
		for (int x = 0; x < row; x++){
			if (averages[x] < num){
				cout << x << " ";
			}
		}
	}
	
	//�������
	for (int x = 0; x < row; x++){
		delete[] array[x];
	}
	delete[] array;
	delete[] numbers;
	delete[] averages;
	
	return 0;
}
