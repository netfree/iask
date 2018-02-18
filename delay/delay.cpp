#include <bits/stdc++.h>

using namespace std;

ifstream fin ("delay.in");
ofstream fout("delay.out");

const int N_MAX = 16000 + 5;

int n, m, a, b, c, niv[N_MAX], t[N_MAX], eu[10 * N_MAX], ne, fst[N_MAX], lst[N_MAX], ait[20*N_MAX], dp[20][10*N_MAX];

vector<int> vec[N_MAX];

void euler(int nod, int parinte, int nivel){
  eu[++ne] = nod;
  niv[ne] = nivel;
  fst[nod] = ne;
  lst[nod] = ne;
  for(auto v : vec[nod])
    if(v != parinte){
      euler(v, nod, nivel + 1);
      eu[++ne] = nod;
      niv[ne] = nivel;
      lst[nod] = ne;
    }
}

int query (int poz, int lo, int hi, int st, int dr){
    if(dr <= hi and st >=lo){
        return ait[poz];
    }

    if(st > hi or dr < lo)
        return 0;

    int mid = st + (dr-st)/2;

    return query(poz*2, lo, hi, st, mid) + query(poz*2+1, lo, hi, mid+1, dr);
}

void update(int poz, int to_update, int val, int st, int dr){

    if(to_update > dr or to_update < st)
        return;
    if(st == dr and st == to_update){
        ait[poz] = val;
        return;
    }

    int mid = st + (dr-st)/2;

    update(poz * 2, to_update, val, st, mid);
    update(poz * 2 + 1, to_update, val, mid+1, dr);
    ait[poz] = ait[2*poz] + ait[2*poz + 1];
}

void init(){
  for(int i = 1; i<=ne; ++i)
    dp[0][i] = i;
  for(int power = 1; (1 << power) <= ne; ++power)
    for(int i = 1; i + (1 <<power) - 1 <= ne; ++i)
      if(niv[dp[power-1][i]] < niv[dp[power-1][i + (1<<(power-1))]])
        dp[power][i] = dp[power-1][i];
      else
        dp[power][i] = dp[power-1][i + (1<<(power-1))];
}

int rmq(int lo, int hi){
  int power = log2(hi - lo + 1);
  if(niv[dp[power][lo]] < niv[dp[power][hi - (1 << power) + 1]])
    return dp[power][lo];
  return dp[power][hi - (1 << power) + 1];
}

int lca(int a, int b){
  int lo = min(a,b);
  int hi = max(a,b);
  return eu[rmq(lo, hi)];
}


int get_ans(int nod1, int nod2){
  int nodlca = lca(fst[nod1], fst[nod2]);
  //cout << nod1 << " " << nod2 << " " << nodlca << "\n";
  return query(1, fst[nodlca], fst[nod1], 1, ne) + query(1, fst[nodlca], fst[nod2], 1, ne) - t[nodlca];
}


int main(){
  fin >> n;
  for(int i = 1; i<=n; ++i)
    fin >> t[i];
  for(int i = 2; i<=n; ++i){
    fin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  euler(1,0,0);
  init();

  for(int i = 1; i<=n; ++i){
    update(1, fst[i], t[i],  1, ne);
    update(1, lst[i] + 1, -t[i], 1, ne);
  }



  fin >> m;
  while(m--){
    fin >> a >> b >> c;
    if(a == 1){
      t[b] = c;
      update(1, fst[b], c, 1, ne);
      update(1, lst[b] + 1, -c, 1, ne);
    }
    else fout << get_ans(b, c) << "\n";
  }



	return 0;
}

//Andrei Muntean, 2018
