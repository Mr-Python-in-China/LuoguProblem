#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n, m;
    fin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    size_t cnt = 0;
    for (vector<bool>& i : a)
      for (vector<bool>::reference j : i) {
        char c;
        fin >> c;
        j = c == 'W', cnt += c == 'W';
      }
    if (!a[0][0] || !a[n - 1][m - 1]) {
      fout << "J\n";
      continue;
    }
    queue<pair<size_t, size_t>> q({
        {0, 0}
    });
    size_t t = 0;
    while (!q.empty()) {
      ++t;
      for (size_t _ = q.size(); _; --_) {
        pair<size_t, size_t> p = q.front();
        q.pop();
        if (p.first == n - 1 && p.second == m - 1) goto end;
        for (auto d : array<pair<signed char, signed char>, 4>{
                 {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
        }) {
          pair<size_t, size_t> np(p.first + d.first, p.second + d.second);
          if (np.first < n && np.second < m && a[np.first][np.second])
            a[np.first][np.second] = false, q.emplace(np);
        }
      }
    }
  end:;
    if (a[n - 1][m - 1])
      fout << "J\n";
    else
      fout << ((cnt - t) % 2 == 0 ? "J\n" : "I\n");
  }
  return 0;
}