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
  size_t q;
  fin >> q;
  unordered_map<ui, size_t> mp;
  while (q--) {
    char c;
    fin >> c;
    if (c == '1') {
      ui x;
      fin >> x;
      ++mp[x];
    } else if (c == '2') {
      ui x;
      fin >> x;
      if (--mp[x] == 0) mp.erase(x);
    } else if (c == '3')
      fout << mp.size() << '\n';
  }

  return 0;
}