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
    size_t n;
    fin >> n;
    deque<ui> a(n);
    for (ui &i : a) fin >> i;
    sort(a.begin(), a.end());
    bool flag = false;
    while (a.size() > 1) (flag = !flag) ? a.pop_front() : a.pop_back();
    fout << a[0] << '\n';
  }
  return 0;
}