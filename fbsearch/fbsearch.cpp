#define MAX_CHR 5000
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("fbsearch.in");
ofstream fout("fbsearch.out");

struct trie{
    int cnt, maxim;
    trie *fiu[28];
    string end_here; // cuvantul care e termina aici
    trie(){
        cnt = 0;
        maxim = 0;
        end_here = "";
        memset(fiu, 0, sizeof(fiu));
    }
};

trie *root = new trie();

int t, n, m;
char type, cuv[MAX_CHR];

int hashh(char *c){
    if(*c >= 'a' and *c <= 'z')
        return *c - 'a';
    if(*c >= 'A' and *c <= 'z')
        return *c - 'A';
    if(*c == ' ')
        return 'z' - 'a' + 1;

}

void adaugare(trie *nod, char *p, string search_item){
    if(*p == NULL){
        nod->end_here = search_item;
        return;
    }
    int delta = hashh(p);
    if(nod->fiu[delta] == NULL)
        nod->fiu[delta] = new trie();
    adaugare(nod->fiu[delta], p+1, search_item);
}

int nr;

void update(trie *nod, char *p, int &u){
    if(*p == NULL){
        nod->cnt += u;
        u = nod->cnt;
        nod->maxim = max(nod->maxim, u);
    } else{
      int delta = hashh(p);
      update(nod->fiu[delta], p+1, u);
        if(nod != root)
          nod->maxim = max(nod->maxim, u);
  }
}

string search(trie *nod, char *p, string search_item){
    if(*p == NULL){
        if(nod->end_here.size() and nod->cnt == nod->maxim)
          return nod->end_here;
        for(int i = 0; i<27; ++i)
          if(nod->fiu[i] != NULL)
            if(nod->fiu[i]->maxim == nod->maxim)
              return search(nod->fiu[i], p, search_item);
    }else {
        int delta = hashh(p);
        if(nod->fiu[delta] != NULL)
            return search(nod->fiu[delta], p+1, search_item);
        else
            return "Search Bing for " + search_item;
    }

}


int main(){
    fin >> t;

    while(t--){
        /// reinit trie
        fin >> n >> m;
        for(int i = 1; i<=n; ++i){
            fin >> cuv;
            adaugare(root, cuv, (string)cuv);
        }
        while(m--){
            fin >> type >> cuv;
            if(type == 'U'){
                fin >> nr;
                update(root, cuv, nr);
            }
            else
                fout << search(root, cuv, (string) cuv) << endl;
        }

    }
    return 0;
}
