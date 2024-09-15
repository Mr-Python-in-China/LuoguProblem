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
  size_t n, k;
  fin >> n >> k;
  vector<ui> a(n);
  for (ui &i : a) fin >> i;
  rotate(a.begin(), a.begin() + (n - k), a.end());
  for (ui i : a) fout << i << ' ';
  return 0;
}