#define x first
#define y second
#define pldld pair<double, double>
#define ld double

#include <bits/stdc++.h>

using namespace std;

ifstream fin ("infasuratoare.in");
ofstream fout("infasuratoare.out");

const int N_MAX = 120000 + 5;

int n, k = 1;
pldld v[N_MAX], st[N_MAX];

bool cmp(pldld a, pldld b){
  return (a < b);
}

ld deter (pldld a, pldld b, pldld c){
  return (a.x*b.y + b.x*c.y + a.y*c.x - c.x*b.y - a.x*c.y - b.x*a.y);
}

int main(){
  fin >> n;
  for(int i = 1; i<=n; ++i)
    fin >> v[i].x >> v[i].y;

  sort(v+1,v+n+1,cmp);

  st[1].x = v[1].x;
  st[1].y = v[1].y;
  k = 1;

  for(int i = 2; i<=n; ++i){
    while(k > 1 and deter(st[k-1], st[k], v[i]) > 0)
      k --;
    k ++;
    st[k].x = v[i].x;
    st[k].y = v[i].y;
  }

  for(int i = n-1; i>=1; --i){
    while(k > 1 and deter(st[k-1], st[k], v[i]) > 0)
      k --;
    k ++;
    st[k].x = v[i].x;
    st[k].y = v[i].y;
  }
  k--;
  fout << k << "\n";
  for(int i = k; i>=1; --i)
    fout << fixed << setprecision(6) << st[i].x << " " << st[i].y << '\n';


	return 0;
}

//Andrei Muntean, 2018
