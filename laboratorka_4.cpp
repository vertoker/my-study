#include <iostream>
#include <cmath>
using namespace std;

//������� �22
int main() {
	//���� �������� ����������
	double e = 0.0001, a0, a1, fact = 2;
	int n = 2;
	
	//���������� ����� do while
	a1 = pow(2, n) * fact / pow(n, n);
	do{
		n++;
		a0 = a1;
		fact *= n;
		a1 = pow(2, n) * fact / pow(n, n);
		//cout << abs(a1 - a0) << "\n";
	}
	while(abs(a1 - a0) > e);
	
	//����� ����� do while
	cout << "a in n = " << a1 << "\n";
	cout << "a in (n-1) = " << a0 << "\n";
	cout << "n = " << n << "\n";
	
	//���������� ����� while
	n = 2; fact = 2;
	a1 = pow(2, n) * fact / pow(n, n);
	while(abs(a1 - a0) > e){
		n++;
		a0 = a1;
		fact *= n;
		a1 = pow(2, n) * fact / pow(n, n);
		//cout << abs(a1 - a0) << "\n";
	}
	
	//����� ����� while
	cout << "a in n = " << a1 << "\n";
	cout << "a in (n-1) = " << a0 << "\n";
	cout << "n = " << n << "\n";
	return 0;
}
