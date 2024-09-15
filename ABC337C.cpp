#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<size_t> a(n);
  vector<bool> vis(n);
  for (size_t i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i] = x;
    if (x != -1) vis[--a[i]] = true;
  }
  size_t srt = 0;
  for (size_t i = 0; i < n; ++i)
    if (!vis[i]) srt = i;
  vector<size_t> ans;
  for (size_t i = srt; i != -1; i = a[i]) ans.push_back(i);
  for_each(ans.rbegin(), ans.rend(), [](size_t p) { cout << p + 1 << ' '; });
  return 0;
}