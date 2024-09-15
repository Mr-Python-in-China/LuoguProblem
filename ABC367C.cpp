#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
void f(size_t p, vector<ui> &arr, vector<ui> const &r, ui k) {
  if (p == arr.size()) {
    if (accumulate(arr.begin(), arr.end(), ui(0)) % k == 0) {
      for (ui i : arr) fout << i << ' ';
      fout << '\n';
    }
    return;
  }
  for (arr[p] = 1; arr[p] <= r[p]; ++arr[p]) f(p + 1, arr, r, k);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui k;
  fin >> n >> k;
  vector<ui> arr(n), r(n);
  for (ui &i : r) fin >> i;
  f(0, arr, r, k);
  return 0;
}