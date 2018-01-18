#include <bits/stdc++.h>
#define DN 50005
using namespace std;

ifstream fin("subsecvente2.in");
ofstream fout("subsecvente2.out");

typedef struct nod{struct nod *fiu[2];int lst;}NOD, *TRIE;
int lgmax, n, i;
char CUV[DN];
void adauga(TRIE &T, char *p, int lg)
{
    if((*p) == '\0' || lg == 61)return;
    if(T == NULL)
    {
        T = new NOD;
        for(int i = 0; i <= 1; i++)
            T -> fiu[i] = NULL;
        T -> lst = 1;
        adauga(T, p, lg);
    }
    else
        adauga(T -> fiu[*p - 'a'], p + 1, lg + 1);
}
void cauta(TRIE T, char *p, int lg)
{
    if(T == NULL)return;
    if(T -> lst == i - 1)T -> lst = i;
    if(T -> lst == n && lg > lgmax)lgmax = lg;
    if((*p) == '\0' || lg == 61)return;
    if((*p) != '\0')
        cauta(T -> fiu[*p - 'a'], p + 1, lg + 1);
}
TRIE T = NULL;
int main()
{
    fin >> n;

    for(i = 1; i <= n; i++)
    {
        fin >> CUV;
        int m=strlen(CUV);
        for(int j = 0 ; j < m; j++)
        {
            cout << CUV[j];
            if(i == 1)
                adauga(T, CUV + j, 0);
            else cauta(T, CUV + j, 0);
        }
        cout << endl;
    }
    fout << lgmax;
    return 0;
}
