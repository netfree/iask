#include <bits/stdc++.h>

using namespace std;

ifstream fin ("spion.in");
ofstream fout("spion.out");

const long long MOD = 100003;

long long inv(long long a, long long b)
{
	long long b0 = b, t, q;
	long long x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

long long fact(int a){
  long long ans = 1;
  for(int i = 1; i<=a; ++i){
    ans *= i;
    if(ans > MOD-10)
      ans %= MOD;
  }
  return ans;
}

int main(){
  long long p; fin >> p;
  char c;
  long long n = 0, k = 0;
  while(fin >> c){
    n ++;
    if(c == 'E')
      k ++;
  }

  if(p == 1){
    fout << k + 1;
    exit(0);
  }

  long long top = fact(n);
  long long bottom = (fact(k) * fact(n-k)) % MOD;
  long long ans = top * inv(bottom, MOD);
  fout << ans % MOD;

	return 0;
}

//Andrei Muntean, 2018
