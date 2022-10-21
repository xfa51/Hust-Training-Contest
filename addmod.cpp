#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
unsigned long long a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    cout << (a % mod + b % mod) % mod;
}
