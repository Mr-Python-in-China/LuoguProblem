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
  ui a, b, c;
  fin >> a >> b >> c;
  fout << ((b < c ? a < b || a > c : c < a && a < b) ? "Yes" : "No");
  return 0;
}