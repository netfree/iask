#include <bits/stdc++.h>

using namespace std;

ifstream fin ("aib.in");
ofstream fout("aib.out");

const int N_MAX = 100005;

int n, m, aib[2*N_MAX], a[N_MAX], b[N_MAX];

void update(int poz, int val) {
    for (int i = poz; i <= n; i += (i & (-i))) {
        aib[i] += val;
    }
}

int query(int a, int b){
  int s = 0;

  for (int i = b; i; i -= (i & (-i)))
     s += aib[i];

  for (int i = a - 1; i; i -= (i & (-i)))
     s -= aib[i];

  return s;
}

int get_ans(int val) {
    int st, dr, mij, s;
    st=1; dr=n;
    while(st<=dr) {
        mij=(st+dr)/2;
        s=query(1, mij);
        if(val==s)
            return mij;
        else if(val<s)
            dr=mij-1;
        else
            st=mij+1;
    }
    return -1;
}

int main(){

  fin >> n >> m;
  for(int i = 1; i<=n; ++i){
    fin >> a[i]; b[i] = i;
    update(i, a[i]);
  }
  while(m--){
    int type; fin >> type;
    if(type == 0){
      int a, b;
      fin >> a >> b;
      update(a, b);
    }
    if(type == 1){
      int lo, hi;
      fin >> lo >> hi;
      fout << query(lo, hi) << "\n";
    }
    if(type == 2){
      int k; fin >> k;
      fout << get_ans(k) << "\n";
    }
  }
	return 0;
}

//Andrei Muntean, 2018
