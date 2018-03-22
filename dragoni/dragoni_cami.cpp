#include <fstream>
#include <climits>
#include <vector>
#include <queue>

#define MAXN 802

using namespace std;

ifstream fin("dragoni.in");
ofstream fout("dragoni.out");

struct elem{
    int nod, c;
};

int n, m, maxim, dragon[MAXN], cost[MAXN][MAXN], nn, z, drago, drago2, viz[MAXN];
vector <elem> G[MAXN];

struct two{
    int node, d;
};

queue <two> Q;

inline void Solve1(int nod, int dr) {
    viz[nod] = 1;

    for (vector <elem> :: iterator i = G[nod].begin(); i != G[nod].end(); i++) {
        if (dr >= (*i).c && viz[(*i).nod] == 0) {
            viz[(*i).nod] = 1;
            if (dragon[(*i).nod] > dr) {
                if (dragon[(*i).nod] > maxim)
                    maxim = dragon[(*i).nod];
            }
                Solve1((*i).nod, dr);
        }
    }
}

inline void Init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INT_MAX;
        }
    }
}

inline void Bellman_Ford(int start, int draggo) {
    Init();
    Q.push({start, draggo});
    cost[start][draggo] = 0;

    while (!Q.empty()) {
        z = Q.front().node;
        drago = Q.front().d;
        Q.pop();

        if (z == n)
            continue;

        for (vector <elem> :: iterator i = G[z].begin(); i != G[z].end(); i++) {
            if (dragon[drago] < dragon[(*i).nod])
                drago2 = (*i).nod;
            else
                drago2 = drago;

            if (cost[(*i).nod][drago2] > cost[z][drago] + (*i).c && (*i).c <= dragon[drago]) {
                cost[(*i).nod][drago2] = cost[z][drago] + (*i).c;

                Q.push({(*i).nod, drago2});
            }
        }
       // Q.pop();
    }
}

inline void Solve2() {
    Bellman_Ford(1, 1);

    int minim = INT_MAX;

    for (int i = 1; i <= n; i++) {
        if (cost[n][i] < minim)
            minim = cost[n][i];
    }

    fout << minim;
}

inline void Read() {
    int p;

    fin >> p;
    fin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fin >> dragon[i];
    }

    int x, y, z;

    for (int i = 1; i <= m; i++) {
        fin >> x >> y >> z;

        G[x].push_back({y, z});
        G[y].push_back({x, z});
    }

    if (p == 1) {
        maxim = dragon[1];
        Solve1(1, dragon[1]);
        fout << maxim;
    }
    else
        Solve2();
}

int main () {
    Read();

    fin.close(); fout.close(); return 0;
}

/// Camelia Lazar 2018
