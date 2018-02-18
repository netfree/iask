#include <bits/stdc++.h>

using namespace std;

ifstream fin ("disjoint.in");
ofstream fout("disjoint.out");

const int N_MAX = 100000 + 5;

int n, m, p[N_MAX];

int parinte(int a){
  if(p[a] == a)
    return a;
  p[a] = parinte(p[a]);
  return p[a];
}

int main(){
  fin >> n >> m;
  for(int i = 1; i<=n; ++i)
    p[i] = i;
  while(m--){
    int type, a, b; fin >> type >> a >> b;
    if(type == 1)
      p[parinte(a)] = p[parinte(b)];
    else
      if(parinte(a) == parinte(b))
        fout << "DA\n";
      else fout << "NU\n";
  }
	return 0;
}

//Andrei Muntean, 2018
