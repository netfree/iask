#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cezar.in");
ofstream fout("cezar.out");

const short int N_MAX = 10000 + 5;

vector<short int> vec[N_MAX];
queue<short int> q;
short int g[N_MAX], cst[N_MAX];
short int k, n;
int sol = 0;

int main(){
  fin >> n >> k;
  for(short int i = 1, x, y; i <= n-1; ++i){
    fin >> x >> y;
    vec[x].push_back(y);
    vec[y].push_back(x);
    g[x]++; g[y]++;
  }
  for(short int i = 1; i<=n; ++i){
    cst[i] = 1;
    if(g[i] == 1)
      q.push(i);
  }

  while(q.size()){
    short int frz = q.front();
    q.pop();
    g[frz]--;
    for(auto p : vec[frz])
      if(g[p] != 0){
        g[p]--;
        cst[p] += cst[frz];
        sol += cst[frz];
        if(g[p] == 1)
          q.push(p);
      }
  }

  sort(cst + 1, cst + n + 1);

  for(short int i = 1; i<=n; ++i)
    cout << i << " " << cst[i] << "\n";

  for(short int i = n - 1; i >= n - k; --i)
    sol -= cst[i];

  fout << sol;
	return 0;
}

//Andrei Muntean, 2018
