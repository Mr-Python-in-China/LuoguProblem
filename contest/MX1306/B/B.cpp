#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    size_t n, k;
    fin >> n >> k;
    vector<vector<ui>> a(n, vector<ui>(n));
    for (vector<ui> &i : a)
        for (ui &j : i)
            fin >> j;
    vector<ui> f(1 << n, numeric_limits<ui>::max());
    f.back() = 0;
    for (ui b = (1u << n); b--;) {
        for (ui i = 0; i < n; ++i)
            if (!((1u << i) & b))
                for (ui j = 0; j < n; ++j)
                    if ((1u << j) & b)
                        f[b] = min(f[b], f[b | (1u << i)] + a[i][j]);
    }
    ui ans = numeric_limits<ui>::max();
    for (ui b = 0; b < (1u << n); ++b)
        if (__builtin_popcount(b) == k)
            ans = min(ans, f[b]);
    fout << ans;
    return 0;
}