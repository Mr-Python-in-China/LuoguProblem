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
    ui a, b;
    fin >> a >> b;
    fout << ((a % 2 == 0 && b % 2 == 0) || (b % 2 == 1 && a >= 2 && a % 2 == 0)
                 ? "YES\n"
                 : "NO\n");
  }
  return 0;
}