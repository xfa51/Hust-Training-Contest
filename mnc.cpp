#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
long long res = 0;
int n, d1[N], d2[N];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        res += d1[i];
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        res += d2[i];
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    cout << res;
}
