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
  ui n, t, a;
  cin >> n >> t >> a;
  cout << (n - (a + t) + a < t || n - (a + t) + t < a ? "Yes" : "No");
  return 0;
}