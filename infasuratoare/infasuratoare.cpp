#define x first
#define y second
#define ld double
#define pii pair<double, double>
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("infasuratoare.in");
ofstream fout("infasuratoare.out");

const int N_MAX = 120000 + 5;

int n, stsz;
pii pct[N_MAX];
pii st[N_MAX];

ld deter(pii a, pii b, pii c){
  return ((a.x - c.x)*(b.y - c.y) + (b.x - c.x)*(c.y - a.y));
}

int main(){

pii a; a.x = 1; a.y = 1;
pii b; b.x = 1; b.y = 2;
pii c; c.x = 0; c.y = 0;

cout << deter(b, a, c);

/*
  fin >> n;
  for(int i = 1; i<=n; ++i)
    fin >> pct[i].x >> pct[i].y;

  sort(pct + 1, pct + n + 1);

  for(int i = 1; i<=n; ++i){
    while(stsz >= 2 and deter(st[stsz-1], st[stsz], pct[i]) > 0)
      stsz --;
    st[++stsz] = pct[i];
  }

  for(int i = n-1; i>=1; --i){
    while(stsz >= 2 and deter(st[stsz-1], st[stsz], pct[i]) > 0)
      stsz --;
    st[++stsz] = pct[i];
  }

  stsz--;

  fout << stsz << '\n';
  for(int i = stsz; i>=1; --i)
    fout << fixed << setprecision(12) << st[i].x << " " << st[i].y << '\n';
*/
  return 0;
}

//Andrei Muntean, 2018
