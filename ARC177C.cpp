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
  vector<vector<bool>> mp(n, vector<bool>(n));
  for (vector<bool> &i : mp)
    for (vector<bool>::reference j : i) {
      char c;
      cin >> c;
      j = c == 'B';
    }
  vector<vector<ui>> cntr(n, vector<ui>(n, numeric_limits<ui>::max())),
      cntb(n, vector<ui>(n, numeric_limits<ui>::max()));
  {
    deque<pair<size_t, size_t>> q{{{0, 0}}};
    cntr[0][0] = mp[0][0] != 0;
    while (!q.empty()) {
      pair<size_t, size_t> p = q.front();
      q.pop_front();
      for (pair<size_t, size_t> np : array<pair<size_t, size_t>, 4>{
               {{p.first - 1, p.second},
                {p.first, p.second - 1},
                {p.first + 1, p.second},
                {p.first, p.second + 1}}
      })
        if (np.first < n && np.second < n &&
            cntr[np.first][np.second] >
                cntr[p.first][p.second] + (mp[p.first][p.second] != 0))
          cntr[np.first][np.second] =
              cntr[p.first][p.second] + (mp[np.first][np.second] != 0),
          mp[p.first][p.second] != 0 ? q.push_back(np) : q.push_front(np);
    }
  }
  {
    deque<pair<size_t, size_t>> q{{{n - 1, 0}}};
    cntb[n - 1][0] = mp[n - 1][0] != 1;
    while (!q.empty()) {
      pair<size_t, size_t> p = q.front();
      q.pop_front();
      for (pair<size_t, size_t> np : array<pair<size_t, size_t>, 4>{
               {{p.first - 1, p.second},
                {p.first, p.second - 1},
                {p.first + 1, p.second},
                {p.first, p.second + 1}}
      })
        if (np.first < n && np.second < n &&
            cntb[np.first][np.second] >
                cntb[p.first][p.second] + (mp[p.first][p.second] != 1))
          cntb[np.first][np.second] =
              cntb[p.first][p.second] + (mp[np.first][np.second] != 1),
          mp[p.first][p.second] != 1 ? q.push_back(np) : q.push_front(np);
    }
  }
  cout << cntr[n - 1][n - 1] + cntb[0][n - 1];
  return 0;
}