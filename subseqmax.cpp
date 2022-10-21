#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int n;
long long s[N], ans = -1e18, cur = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        s[i] += s[i - 1];
        ans = max(ans, s[i] - cur);
        cur = min(cur, s[i]);
    }
    cout << ans;
}
