#include <bits/stdc++.h>

using namespace std;

ifstream fin ("scmax.in");
ofstream fout("scmax.out");

const int N_MAX = 100000 + 5;

int n, ndp, a[N_MAX], dp[N_MAX], dad[N_MAX];

bool cmp (int lo, int hi){
  return (a[lo] < a[hi]);
}

void afis (int poz){
  if(poz){
    afis(dad[poz]);
    fout << a[poz] << " ";
  }
}

int main(){
  fin >> n;
  for(int i = 1; i<=n; ++i){
    fin >> a[i];
    int poz = lower_bound(dp + 1, dp + ndp + 1, i, cmp) - dp;
    ndp = max(poz, ndp);
    dp[poz] = i;
    dad[i] = dp[poz-1];
  }

  fout << ndp << "\n";
  afis(dp[ndp]);

	return 0;
}

//Andrei Muntean, 2018
