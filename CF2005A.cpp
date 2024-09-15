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
    for (size_t i = 0; i < n; i += 5) fout << 'a';
    for (size_t i = 1; i < n; i += 5) fout << 'e';
    for (size_t i = 2; i < n; i += 5) fout << 'i';
    for (size_t i = 3; i < n; i += 5) fout << 'o';
    for (size_t i = 4; i < n; i += 5) fout << 'u';
    fout << '\n';
  }
  return 0;
}