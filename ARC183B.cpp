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
  size_t T;
  fin >> T;
  while (T--) {
    size_t n, k;
    fin >> n >> k;
    vector<ui> a(n), b(n);
    for (ui &i : a) fin >> i, --i;
    for (ui &i : b) fin >> i, --i;
    if (a == b) {
      fout << "Yes\n";
      continue;
    }
    {
      unordered_set<ui> s;
      for (ui i : b) s.emplace(i);
      for (ui i : a) s.erase(i);
      if (!s.empty()) {
        fout << "No\n";
        continue;
      }
    }
    if (k == 1) {
      vector<ui>::iterator it = a.begin();
      for (ui i : b) {
        it = find(it, a.end(), i);
        if (it == a.end()) {
          fout << "No\n";
          goto end;
        }
      }
      fout << "Yes\n";
    } else {
      vector<vector<size_t>> posB(n);
      for (size_t i = 0; i < n; ++i) {
        if (!posB[b[i]].empty() && i - posB[b[i]].back() <= k) {
          fout << "Yes\n";
          goto end;
        }
        posB[b[i]].emplace_back(i);
      }
      fout << "No\n";
    }
  end:;
  }
  return 0;
}