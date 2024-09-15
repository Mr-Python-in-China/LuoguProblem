#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n);
    vector<size_t> cnt(n);
    for (ui& i : a) cin >> i, ++cnt[i];
    ui mex = find(cnt.cbegin(), cnt.cend(), 0) - cnt.cbegin();
    vector<bool> f(mex);
    size_t c = 0;
    vector<pair<size_t, size_t>> ans({
        {0, 0}
    });
    for (; ans.back().second < n; ++ans.back().second) {
      if (a[ans.back().second] < mex && !f[a[ans.back().second]])
        f[a[ans.back().second]] = true, ++c;
      if (c == mex)
        ans.emplace_back(ans.back().second + 1, ans.back().second),
            fill(f.begin(), f.end(), false), c = 0;
    }
    ans.pop_back();
    ans.back().second = n - 1;
    if (ans.size() < 2)
      cout << "-1\n";
    else {
      cout << ans.size() << '\n';
      for (pair<size_t, size_t> i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
  }
  return 0;
}