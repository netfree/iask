#include <bits/stdc++.h>

using namespace std;

ifstream fin ("arbint.in");
ofstream fout("arbint.out");

const int N_MAX = 100000 + 5;
const int inf = 0x3f3f3f3f;

int n, m, ait[4*N_MAX];

int query(int poz, int lo, int hi, int st, int dr){
  if(hi < st or lo > dr)
    return -inf;
  if(st >= lo and dr <= hi)
    return ait[poz];
  int mid = (st + dr)/2;
  return max(query(poz * 2, lo, hi, st, mid), query(poz * 2 + 1, lo, hi, mid + 1, dr));

}

void update(int poz, int poz_to_upd, int new_val, int st, int dr){
  if(poz_to_upd < st or poz_to_upd > dr)
    return;
  if(poz_to_upd == st and st == dr){
    ait[poz] = new_val;
    return;
  }
  int mid = (st+dr)/2;
  update(poz*2, poz_to_upd, new_val, st, mid);
  update(poz*2 + 1, poz_to_upd, new_val, mid+1, dr);
  ait[poz] = max(ait[poz*2+1], ait[poz*2]);
}

int main(){
  fin >> n >> m;
  for(int i = 1, nr; i<=n; ++i){
    fin >> nr;
    update(1, i, nr, 1, n);
  }
  while(m--){
    int type, a, b;
    fin >> type >> a >> b;
    if(type == 0)
      fout << query(1, a, b, 1, n) << '\n';
    else
      update(1, a, b, 1, n);
  }
	return 0;
}

//Andrei Muntean, 2018
