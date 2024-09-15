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
    size_t n, m;
    cin >> n >> m;
    vector<char> a(n), b(m);
    vector<size_t> t(m);
    for (char &i : a) cin >> i;
    for (size_t &i : t) cin >> i, --i;
    for (char &i : b) cin >> i;
    sort(b.begin(), b.end());
    sort(t.begin(), t.end()), t.erase(unique(t.begin(), t.end()), t.end());
    for (size_t i = 0; i < t.size(); ++i) a[t[i]] = b[i];
    for (char i : a) cout.put(i);
    cout.put('\n');
  }
  return 0;
}