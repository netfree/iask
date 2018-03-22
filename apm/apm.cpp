#include <bits/stdc++.h>

using namespace std;

ifstream fin ("apm.in");
ofstream fout("apm.out");

const int N_MAX = 200000 + 5;
const int M_MAX = 400000 + 5;

struct eee{
  int x, y, cost;
  bool operator <(const eee& other) const{
    return cost < other.cost;
  }
};

int parinte(int a){
  if(p[a] == a)
    return p[a];
  return p[a] = parinte(a);
}

vector<eee> muchii;
int n, m, p[N_MAX];

int main(){
  fin >> n >> m;
  while(m--){
    int a, b, c;
    fin >> a >> b >> c;
    muchii.push_back({a,b,c});
  }
  sort(muchii.begin(), muchii.end());

  for(int i = 1; i<=m; ++i)
      p[i] = i;

  for(auto muchie : muchii){
    px = parinte(muchie.x);
    py = parinte(muchie.y);
    if(px != py){
      p[parinte(px)] = p[parinte(py)];
      nr_ans += muchie.cost;

    }
  }

	return 0;
}

//Andrei Muntean, 2018
