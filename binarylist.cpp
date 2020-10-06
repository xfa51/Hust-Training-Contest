#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector <int> dp[10005], f[10005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    m = min(n + 1, m);
    for (int i = 0; i <= n; ++i)
    {
        dp[i].resize(m);
        f[i].resize(m);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][0];
        f[i][0] = 0;
        for (int j = 1; j < m; ++j)
        {
            dp[i][j] = dp[i - 1][j - 1];
            dp[i][0] += dp[i - 1][j];
            if (dp[i][0] > k) dp[i][0] = k + 1;
            f[i][j] = f[i][j - 1] + dp[i][j];
            if (f[i][j] > k) f[i][j] = k + 1;
        }
    }
    if (k > dp[n][0] + f[n][m - 1])
    {
        cout << -1;
        return 0;
    }
    int cur = 0;
    while (k > 0)
    {
        if (n == 0) break;
        if (cur == m - 1)
        {
            cout << "1 ";
            n--;
            cur = 0;
            continue;
        }
        if (k <= f[n][m - cur - 1])
        {
            cout <<"0 ";
            n--;
            cur++;
        }
        else
        {
            cout << "1 ";
            k -= f[n][m - cur - 1];
            cur = 0;
            n--;
        }
    }
}
