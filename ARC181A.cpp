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
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<size_t> a(n);
    bool flag0 = true, flag1 = false;
    set<size_t> s;
    for (size_t i = 0; i < n; ++i) s.insert(i);
    cin >> a[0];
    --a[0];
    if (a[0] == 0) flag1 = true;
    s.erase(a[0]);
    for (size_t i = 1; i < n; ++i) {
      cin >> a[i];
      --a[i];
      if (a[i - 1] > a[i]) flag0 = false;
      if (i == a[i] && *s.begin() == i) flag1 = true;
      s.erase(a[i]);
    }
    cout << (flag0                            ? '0'
             : flag1                          ? '1'
             : a[0] != n - 1 || a[n - 1] != 0 ? '2'
                                              : '3')
         << '\n';
  }
  return 0;
}