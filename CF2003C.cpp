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
    deque<char> sorted(n);
    for (char &i : sorted) fin >> i;
    sort(sorted.begin(), sorted.end());
    bool flag = true;
    while (sorted.size())
      if (flag = !flag) {
        fout << sorted.front();
        sorted.pop_front();
      } else {
        fout << sorted.back();
        sorted.pop_back();
      }
    fout << '\n';
  }
  return 0;
}