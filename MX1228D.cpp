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
    ui P;
    fin >> n >> P;
    vector<ui> a(n);
    iota(a.begin(), a.end(), 0);
    ui ans = 0;
    do {
      stack<ui, vector<ui>> p, q;
      ui except = n - 1;
      for (ui i : a) {
        while (!p.empty() && p.top() < i) q.push(p.top()), p.pop();
        p.push(i);
        while (true) {
          if (!p.empty() && p.top() == except)
            --except, p.pop();
          else if (!q.empty() && q.top() == except)
            --except, q.pop();
          else
            break;
        }
      }
      ans += except != -1;
    } while (next_permutation(a.begin(), a.end()));
    fout << ans % P << '\n';
  }
  return 0;
}