#include <bits/stdc++.h>

using namespace std;

ifstream fin ("hamilton.in");
ofstream fout("hamilton.out");

const int N_MAX = 20;
const int inf = 0x3f3f3f3f;

int n, m;
int drum[N_MAX][N_MAX];
int dp[(1<<18) + 5][N_MAX];

int isbit(int nr, int ind){
  return (nr & (1<<ind));
}

int main(){
  fin >>  n >> m;
  memset(drum, inf, sizeof(drum));
  while(m--){
    int a, b, c;
    fin >> a >> b >> c;
    drum[a][b] = c;
  }
  memset(dp, inf, sizeof(dp));

  /// Se poate pune cu graf transpus fiinca nu are sens sa gasi

  /// La dinamica inainte pornim dintr-o stare in care stim ce e si incarcam sa ajunge la o stare in care nu stim ce e
  /// La dinamica inapoi, pornim dintr-o stare in care nu stim e se afla si incercam sa gasim o solutie la starea curenta pe care nu o stim

  dp[1][0] = 0;
  for(int mask = 1; mask < (1<<n); ++mask)
    for(int i = 0; i<n; ++i)
      if(isbit(mask, i))
        for(int j = 0; j<n; ++j)
          if(!isbit(mask, j) and drum[i][j] != inf)
            dp[mask + (1<<j)][j] = min(dp[mask + (1<<j)][j], dp[mask][i] + drum[i][j]);

  int ans = inf;
  for(int i = 1; i<n; ++i)
    ans = min(ans, dp[(1<<n)-1][i] + drum[i][0]);
  if(ans == inf)
    fout << "Nu exista solutie\n";
  else
    fout << ans;
  return 0;
}

//Andrei Muntean, 2018
