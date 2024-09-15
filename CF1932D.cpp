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
    char w;
    cin >> n >> w;
    unsigned char p = w == 'C'   ? 0
                      : w == 'D' ? 1
                      : w == 'H' ? 2
                      : w == 'S' ? 3
                                 : throw;
    array<vector<unsigned char>, 4> c;
    for (size_t i = 0; i < 2 * n; ++i) {
      char s[3];
      cin >> s;
      c[s[1] == 'C'   ? 0
        : s[1] == 'D' ? 1
        : s[1] == 'H' ? 2
        : s[1] == 'S' ? 3
                      : throw]
          .push_back(s[0] - '2');
    }
    for (vector<unsigned char>& i : c)
      sort(i.begin(), i.end(), greater<unsigned char>());
    ostringstream ans;
    for (size_t i = 0; i < n; ++i) {
      for (size_t i = 0; i < 4; ++i)
        if (i != p && c[i].size() > 1) {
          unsigned char s1 = c[i].back();
          c[i].pop_back();
          unsigned char s2 = c[i].back();
          c[i].pop_back();
          ans.put(s1 + '2')
              .put(i == 0   ? 'C'
                   : i == 1 ? 'D'
                   : i == 2 ? 'H'
                   : i == 3 ? 'S'
                            : throw)
              .put(' ')
              .put(s2 + '2')
              .put(i == 0   ? 'C'
                   : i == 1 ? 'D'
                   : i == 2 ? 'H'
                   : i == 3 ? 'S'
                            : throw)
              .put('\n');
          goto successful;
        }
      if (c[p].empty()) {
        cout << "IMPOSSIBLE\n";
        goto failed;
      }
      for (size_t i = 0; i < 4; ++i)
        if (i != p && c[i].size() > 0) {
          unsigned char s1 = c[i].back();
          c[i].pop_back();
          unsigned char s2 = c[p].back();
          c[p].pop_back();
          ans.put(s1 + '2')
              .put(i == 0   ? 'C'
                   : i == 1 ? 'D'
                   : i == 2 ? 'H'
                   : i == 3 ? 'S'
                            : throw)
              .put(' ')
              .put(s2 + '2')
              .put(w)
              .put('\n');
          goto successful;
        }
      if (c[p].size() <= 1) {
        cout << "IMPOSSIBLE\n";
        goto failed;
      }
      {
        unsigned char s1 = c[p].back();
        c[p].pop_back();
        unsigned char s2 = c[p].back();
        c[p].pop_back();
        ans.put(s1 + '2').put(w).put(' ').put(s2 + '2').put(w).put('\n');
        goto successful;
      }
      cout << "IMPOSSIBLE\n";
      goto failed;
    successful:;
    }
    cout << ans.str();
  failed:;
  }
  return 0;
}