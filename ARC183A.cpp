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
  ui n, k;
  fin >> n >> k;
  if (n % 2 == 0) {
    fout << n / 2 << ' ';
    for (ui i = n; i > n / 2; --i)
      for (ui j = 0; j < k; ++j) fout << i << ' ';
    for (ui j = 1; j < k; ++j) fout << n / 2 << ' ';
    for (ui i = n / 2 - 1; i >= 1; --i)
      for (ui j = 0; j < k; ++j) fout << i << ' ';
  } else {
    for (ui j = 0; j < k; ++j) fout << (n + 1) / 2 << ' ';
    if (n == 1) return 0;
    fout << n / 2 << ' ';
    for (ui i = n; i > (n + 1) / 2; --i)
      for (ui j = 0; j < k; ++j) fout << i << ' ';
    for (ui j = 1; j < k; ++j) fout << n / 2 << ' ';
    for (ui i = n / 2 - 1; i >= 1; --i)
      for (ui j = 0; j < k; ++j) fout << i << ' ';
  }
  return 0;
}