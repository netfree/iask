#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

ifstream fin ("pm.in");
ofstream fout("pm.out");

const int N_MAX = 100 + 5;
const int inf = 0x3f3f3f3f;

vector<int> vec[N_MAX], rvec[N_MAX];

int n, lo[N_MAX], hi[N_MAX], t[N_MAX];

void get_lo(int nod, int val){
  lo[nod] = max(lo[nod], val);
  for(auto v : vec[nod])
    get_lo(v, val + t[nod]);
}

void get_hi(int nod, int val){
  hi[nod] = min(hi[nod], val - t[nod]);
  for(auto v : rvec[nod])
    get_hi(v, val - t[nod]);
}

int main(){
  fin >>  n;
  for(int i = 1; i<=n; ++i)
    fin >> t[i];
  for(int i = 1, mk; i<=n; ++i){
    fin >> mk;
    for(int j = 1, x; j<=mk; ++j){
      fin >> x;
      vec[x].push_back(i);
      rvec[i].push_back(x);
    }
  }

  n ++;

  for(int i = 1; i<n; ++i){
    if(vec[i].size() == 0){
      vec[i].push_back(n);
      rvec[n].push_back(i);
    }
    if(rvec[i].size()){
      rvec[i].push_back(0);
      vec[0].push_back(i);
    }
  }

  memset(hi, inf, sizeof(hi));

  //get_lo(0, 0);
  //get_hi(n, lo[n]);

  fout << lo[n] << "\n";
  for(int i = 1; i<n; ++i)
    fout << lo[i] << " " << hi[i] << "\n";

	return 0;
}

//Andrei Muntean, 2018
