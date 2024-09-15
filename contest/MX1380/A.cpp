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
  size_t n;
  fin >> n;
  vector<ui> a(n);
  for (ui& i : a) fin >> i;
  ui addon = 0;
  vector<char> revans;
  for_each(a.rbegin(), a.rend(), [&](ui x) {
    x += addon;
    for (ui i = x; i > 1; i /= 2) {
      auto d =
          i & 1 ? vector<char>{'c', '+', '1', '+'} : vector<char>{'c', '+'};
      addon += (i & 1) + 1;
      revans.insert(revans.end(), make_reverse_iterator(d.end()),
                    make_reverse_iterator(d.begin()));
    }
    revans.emplace_back('1');
  });
  for_each(revans.rbegin(), revans.rend(), [](char x) { fout << x; });
  return 0;
}