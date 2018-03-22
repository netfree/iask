#include <bits/stdc++.h>

using namespace std;

ifstream fin ("trie.in");
ofstream fout("trie.out");

struct trie {
    int cnt, nFii;
    trie *fiu[26];
    trie() {
        cnt = 0; nFii = 0;
        memset(fiu, 0, sizeof(fiu));
    }
};

trie *root = new trie();
char T[25];

void adauga(trie *node, char *s) {
    if (*s == 0) {
        node->cnt++;
        return;
    }

    int delta = *s - 'a';

    if (node->fiu[delta] == 0) {
        node->nFii++;
        node->fiu[delta] = new trie();
    }

    adauga(node->fiu[delta], s + 1);
}

bool sterge(trie *node, char *s) {
    if (*s == 0) {
        node->cnt--;

        if (node->cnt == 0 and node->nFii == 0 and node != root) {
            delete node;
            return true;
        }
        return false;
    }

    int delta = *s - 'a';

    if (sterge(node->fiu[delta], s + 1)) {
        node->fiu[delta] = 0;
        node->nFii--;

        if (node->nFii == 0 and node->cnt == 0 and node != root) {
            delete node;
            return true;
        }
    }
    return false;
}

int query1(trie *node, char *s) {
    if (*s == 0)
        return node->cnt;

    int delta = *s - 'a';

    if (node->fiu[delta] == 0)
        return 0;

    return query1(node->fiu[delta], s + 1);
}

int query2(trie *node, char *s) {
    if (*s == 0)
        return 0;

    int delta = *s - 'a';

    if (node->fiu[delta] != 0)
        return query2(node->fiu[delta], s + 1) + 1;

    return 0;
}

int type;

int main () {

  while (fin >> type >> T) {
      if (type == 0)
          adauga(root, T);
      else if (type == 1)
          int aux = sterge(root, T);
      else if (type == 2)
          fout << query1(root, T) << "\n";
      else if (type == 3)
          fout << query2(root, T) << "\n";
  }

  return 0;
}

//Andrei Muntean, 2018
