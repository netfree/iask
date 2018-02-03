#include <bits/stdc++.h>

using namespace std;

ifstream fin ("rucsac.in");
ofstream fout("rucsac.out");

const int N_MAX = 5000 + 5, G_MAX = 10000 + 5;

int inherited, n, g, dp[G_MAX], wt[N_MAX], val[N_MAX];

int main(){
  fin >> n >> g;
  for(int i = 1; i<=n; ++i)
    fin >> wt[i] >> val[i];

  for(int j = 1; j<=g; ++j)
  if(j >= wt[1])
      dp[j] = val[1];
    else
      dp[j] = 0;

    for(int i = 2; i<=n; ++i)
      for(int j = g; j >= wt[i]; --j)
        dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);

  fout << dp[g];
	return 0;
}

//Andrei Muntean, 2018
