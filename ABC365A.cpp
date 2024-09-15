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
  ui x;
  cin >> x;
  if (x % 400 == 0)
    cout << "366";
  else if (x % 100 == 0)
    cout << "365";
  else if (x % 4 == 0)
    cout << "366";
  else
    cout << "365";
  return 0;
}