#include <bits/stdc++.h>

using namespace std;

ifstream fin ("inversmodular.in");
ofstream fout("inversmodular.out");

int inversmodular(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int x, y;

int main(){
  fin >> x >> y;
  fout << inversmodular(x, y);
	return 0;
}

//Andrei Muntean, 2018
