#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cout << "solution-";
  char c;
  while (cin >> c) cout.put(tolower(c) == '_' ? '-' : tolower(c));
  return 0;
}