#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr uli P = (uli)1e17 + 3;
constexpr ui BASE = 26;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  vector<vector<pair<size_t, uli>>> h(n);
  for (auto& i : h) {
    string s;
    fin >> s;
    for (string::iterator it = s.begin(); it < s.end(); ++it) {
      uli x = 0;
      for (string::iterator jt = it; jt < s.end(); ++jt)
        i.emplace_back(jt - it + 1, x = (x * BASE + *jt - 'a') % P);
    }
    i.emplace_back(0, 0);
  }
  for (vector<pair<size_t, uli>>& i : h)
    sort(i.begin(), i.end()), i.erase(unique(i.begin(), i.end()), i.end());
  vector<pair<size_t, uli>> dat(h.front());
  for_each(next(h.begin()), h.end(),
           [&dat](vector<pair<size_t, uli>> const& d) {
             vector<pair<size_t, uli>> r;
             set_intersection(dat.begin(), dat.end(), d.begin(), d.end(),
                              back_inserter(r));
             dat = r;
           });
  fout << dat.back().first;
  return 0;
}