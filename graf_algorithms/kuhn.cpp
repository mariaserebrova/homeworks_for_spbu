#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#pragma
using namespace std;

const int maxn = 6;

vector<int> g[maxn];
int mt[maxn];
bool used[maxn];


bool dfs(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int u : g[v]) {

        if (mt[u] == -1 || dfs(mt[u])) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    int cnt = 0;


    int n = 6;

    g[1] = { 1, 0, 0, 1, 0, 0};
    g[2] = { 1, 1, 1, 0, 0, 1 };
    g[3] = { 1, 0, 1, 0, 1, 0 };
    g[4] = { 1, 1, 1, 0, 0, 1 };
    g[5] = { 1, 0, 1, 0, 1, 0 };
    g[6] = { 1, 1, 1, 0, 0, 1 };


    memset(mt, -1, sizeof mt);
    for (int i = 0; i < n; i++) {
        memset(used, 0, sizeof mt);
        if (dfs(i))
            cnt++;
    }

    cout << "the size of the maximum matching in a bipartite graph is " << cnt;
}
