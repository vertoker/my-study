#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N, C, sum = 0, result = 0;
	int A[100], B[100];
	cin >> N;
	
	//���� ������
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		cin >> B[i];
	}
	
	//���������� �������
	for(int i = 0; i < N; i++){
		sum += (B[i] - A[i]);
	}
	C = sum / N;
	
	//���������� ������� ���������
	for(int i = 0; i < N; i++){
		result += abs(A[i] + C - B[i]);
	}
	cout << C << endl;
	cout << result << endl;
}
