#include <bits/stdc++.h>

using namespace std;

ifstream fin ("lca.in");
ofstream fout("lca.out");

const int N_MAX = 100000 + 5;

vector<int> vec[N_MAX];
int n,m,x,nr, y;
int deep[N_MAX], dad[N_MAX];

void dfs(int nod){
  for(auto v : vec[nod]){
    deep[v] = deep[nod] + 1;
    dfs(v);
  }
}

int lca(int x, int y){
  while(deep[x] > deep[y])
    x = dad[x];
  while(deep[y] > deep[x])
    y = dad[y];
  while(x != y){
    x = dad[x];
    y = dad[y];
  }
  return x;
}

int main(){

  fin >> n >>  m;
  for(int i = 2; i<=n; ++i){
    fin >> dad[i];
    vec[dad[i]].push_back(i);
  }

  deep[1] = 1;
  dfs(1);

  while(m--){
    fin >> x >> y;
    fout << lca(x,y) << "\n";
  }

	return 0;
}

//Andrei Muntean, 2018
