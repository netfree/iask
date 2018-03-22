#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N_MAX = 20 + 5;
const int M_MAX = 50 + 5;

ifstream fin ("boom.in");
ofstream fout("boom.out");

int srjcost[M_MAX], srjconf[M_MAX];
pii dad[(1<<20) + 5]; //dad_node, sarja aplicata ca sa ajung la conf curenta
int cost[(1<<20) + 5];
priority_queue<pii, vector<pii>, greater<pii> > q; // cost, nod
int n, m;

int main(){
  fin >> n >> m;
  for(int i = 1, srjlen; i<=m; ++i){
    fin >> srjcost[i] >> srjlen;
      for(int j = 1, x; j<=srjlen; ++j){
        fin >> x;
        srjconf[i] |= (1<<(x-1));
      }
  }

  cout << "works so far";

  cost[0] = 0;
  q.push({0, 0});
  while(!q.empty()){
    int nod = q.top().y;
    int act = q.top().x;
    q.pop();

    if(act != cost[nod])
      continue;

    for(int i = 1; i<=m; ++i){
      int step1 = nod |= srjconf[i];
      int newnod = ((step1 << 1) | 1)&((step1 >> 1) | (1 << (n-1)));
      if(cost[newnod] < cost[nod] + srjcost[i]){
        cost[newnod] = cost[nod] + srjcost[i];
        dad[newnod] = {nod, i};
        q.push({cost[newnod], newnod});
      }
    }
  }

  fout << cost[(1<<n)-1];

}
