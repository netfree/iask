#include <bits/stdc++.h>

using namespace std;

ifstream fin ("sub.in");
ofstream fout("sub.out");

struct trie{
  int occur;
  trie *son[26];
  trie(){
    occur = 0;
    memset(son, 0, sizeof(son));
  }
};

trie *root = new trie();

int na, nb, ans;
char cuv[400];

void add_cuv(trie *nod, char *p, int i){
  if(*p == NULL) return;
  int delta = *p - 'a';
  if(nod->son[delta] == NULL)
    nod->son[delta] = new trie();

  if(nod->son[delta]->occur < i-1)
    return;

  else if(nod->son[delta]->occur == i-1 and i == na)
    ans ++;

  nod->son[delta]->occur = i;
  add_cuv(nod->son[delta], p + 1, i);
}

void delete_cuv(trie *nod, char *p, int i){
  if(*p == NULL) return;
  int delta = *p - 'a';

  if(nod->son[delta] == NULL) return;

  if(nod->son[delta]->occur == na){
    //cout << "Am invins!";
    nod->son[delta]->occur = 0;
    ans --;
  }
  delete_cuv(nod->son[delta], p + 1, i);
}

int main(){
  fin >> na;
  for(int i = 1; i<=na; ++i){
    fin >> cuv;
    int m = strlen(cuv);
    for(int j = 0; j<m; ++j)
      add_cuv(root, cuv+j, i);
  }

  fin >> nb;
  for(int i = 1; i<=nb; ++i){
    fin >> cuv;

    int m = strlen(cuv);
    for(int j = 0; j<m; ++j)
      delete_cuv(root, cuv+j, i);
  }

  fout << ans;

	return 0;
}

//Andrei Muntean, 2018
