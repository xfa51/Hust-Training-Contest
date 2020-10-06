#include<bits/stdc++.h>
using namespace std;
int n, m, cnt[20], best = 2e9, l[20], vis[20];
vector <int> br[20], vt;
void Try(int cursub, int curres, int cntsub)
{
    if (cntsub == n)
    {
        best = min(best, curres);
        return;
    }
    if (curres >= best) return;
    for (int i = 1; i <= m; ++i)
    {
        bool ok = true;
        for (int j : br[i])
        {
            if (vis[j] != 0 && vis[j] < i)
            {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        vis[cursub] = i;
        cnt[i] += l[cursub];
        Try(cursub + 1, max(curres, cnt[i]), cntsub + 1);
        cnt[i] -= l[cursub];
        vis[cursub] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("input.txt", "r"))
        assert(freopen("input.txt", "r", stdin));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x; cin >> x;
            if (x == 1)
            {
                br[i].push_back(j);
            }
        }
    }
    Try(1, 0, 0);
    if (best == 2e9) best = -1;
    cout << best;
}