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
    size_t n;
    fin >> n;
    vector<bool> a(n);
    for (auto i : a) {
      char c;
      fin >> c;
      i = c == '1';
    }
    size_t c = sqrt(n);
    if (c * c != n) {
      fout << "No\n";
      continue;
    }
    bool flag = true;
    for (size_t i = 0; i < c; ++i)
      if (a[c * 0 + i] == false || a[c * (c - 1) + i] == false) flag = false;
    for (size_t i = 1; i < c - 1; ++i) {
      if (a[c * i + 0] == false || a[c * i + (c - 1)] == false) flag = false;
      for (size_t j = 1; j < c - 1; ++j)
        if (a[c * i + j] == true) flag = false;
    }
    fout << (flag ? "Yes\n" : "No\n");
  }
  return 0;
}