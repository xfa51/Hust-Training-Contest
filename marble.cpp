#include <bits/stdc++.h>
using namespace std;
const int N = 605;
int m, n, k;
int dp[N][N], ans = 2e9;
int x[205], y[205];
void solve()
{
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = i * j;
            for (int t = 0; t <= i; ++ t)
            {
                dp[i][j] = min(dp[i][j], dp[t][j] + dp[i - t][j]);
            }
        }
        for (int j = 1; j <= n; ++j)
        {
            for (int t = 1; t <= k; ++t)
            {
                if (x[t] > i || y[t] > j) continue;
                dp[i][j] = min(dp[i][j], dp[i][j - y[t]] + dp[i - x[t]][y[t]]);
            }
        }
    }
    ans = min(ans, dp[m][n]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> y[i] >> x[i];
    }
    solve();
    swap(m, n);
    for (int i = 1; i <= k; ++i)
    {
        swap(x[i], y[i]);
    }
    solve();
    cout << ans;
}
