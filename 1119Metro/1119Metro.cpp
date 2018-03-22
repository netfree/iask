#include <bits/stdc++.h>
#define sqrt2 141.421356237
using namespace std;

ifstream fin ("1119Metro.in");
ofstream fout("1119Metro.out");

const int N_MAX = 1000 + 5;
long double dp[N_MAX][N_MAX];
bool urc[N_MAX][N_MAX];
int n, m, k;

int main(){
  cin >> m >> n;
  cin >> k;
  while(k--){
    int a, b; cin >> a >> b;
    urc[b][a] = true;
  }

  for(int i = 1; i<=n; ++i)
    dp[i][0] = 100*i;

  for(int i = 1; i<=n; ++i)
    for(int j = 1; j<=m; ++j)
      if(urc[i][j])
        dp[i][j] = min(dp[i-1][j-1] + 141.421356237, dp[i][j-1] + 100.00);
      else
        dp[i][j] = dp[i][j-1] + 100.00;

  cout << (int)dp[n][m];
	return 0;
}

//Andrei Muntean, 2018
