#include<iostream>
#include<stdio.h>
using namespace std;

int Timmin(int A[]) {
	int m = A[0];
	for (int i = 0; i < 20; i++) {
		if (A[i] < m && A[i]!=-2) m = A[i];

	}
	return m;
}
void khoitao(int A[]) {
	for (int i = 0; i < 20; i++) {
		A[i] = -2;
	}

}


int main() {
	const int n = 8;
	char Point[n] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	int	 h[n] = { 14, 10, 10, 5, 5, 4, 4, 0 };
					//a, b, c, d, e, f, g, h
	int C[n][n] = { {0, 1, 1, 1, 0, 0, 0, 0},//a
					{1, 0, 0, 0, 0, 1, 0, 1},//b
					{1, 0, 0, 1, 1, 0, 0, 0},//c
					{1, 0, 1, 0, 1, 0, 0, 0},//d
					{0, 0, 1, 1, 0, 1, 1, 0},//e
					{0, 1, 0, 0, 1, 0, 1, 0},//f
					{0, 0, 0, 0, 1, 1, 0, 1},//g
					{0, 1, 0, 0, 0, 0, 1, 0,} };//h
	int Child[20];
	khoitao(Child);
	bool ktra[n] = {};
	char d, c;
	int a, b, m, lv = 1;
	int luuvet[10];
	//khoitao(luuvet);
	cout << endl << " Nhap gia tri nguon: "; cin >> d;
	cout << " Nhap gia tri dich: "; cin >> c;
	for (int i = 0; i < n; i++) {
		if (Point[i] == d) a = i;
		if (Point[i] == c)	b = i;
	}

	cout << "\nDuong di: " << Point[a]<< "-> ";
	ktra[a] = true;
	//luuvet[0] = a;
	while (a != b) {
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (C[a][i] == 1 && !ktra[i])
			{
				Child[j] = h[i];
				j++;
			}
		}
		m = Timmin(Child);
		khoitao(Child);
		/*for (int i = 0; i < n; i++) {
			int min = E[0];
			for (int i = 0; i < 6; i++) {
				if (E[i] < min) E[i]=min;
			}
		}*/
		for (int i = 0; i < n; i++)
		{
			if (h[i] == m && !ktra[i] && C[a][i] == 1)
			{
				ktra[i] = true;
				luuvet[lv] = i;
				a = i;
				lv++;
				break;
			}
		}
		cout << Point[a] << "-> ";
	}
	/*for (int i = 0; i < 10; i++){
		if (luuvet[i] != -2) {
			cout << luuvet[i] << ", ";
		}
	}*/
	return 0;
}
