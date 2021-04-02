#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//������� �22
int main() {
	const int N = 20;
	int maxAverage = 0;
	int minCount = 0;
	int array[N];
	srand(time(NULL));
	
	//������������ ������
	cout << "Unsorted array elements: " << endl;
	for(int i = 0; i < N; i++){
		array[i] = rand() % 24 - 12;
		cout << setw(5) << array[i];
	}
	cout << endl;
	
	//���������� �� ������ ������
	for(int x = 0; x < N; x++){
		if(abs(array[x]) < 3){
			for(int y = x + 1; y < N; y++){
				array[y - 1] = array[y];
			}
			array[N - 1] = 22;
		}
	}
	
	//���������� ��� �������� � ����� �������������� �������
	cout << "Sorted array elements: " << endl;
	for(int i = 0; i < N; i++){
		cout << setw(5) << array[i];
	}
	cout << endl;
	return 0;
}
