#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
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
    ui cN = 0, cS = 0, cE = 0, cW = 0;
    vector<char> s(n);
    for (char &i : s)
      cin >> i, (i == 'N'   ? ++cN
                 : i == 'S' ? ++cS
                 : i == 'E' ? ++cE
                 : i == 'W' ? ++cW
                            : throw);
    if ((cN == 1 && cS == 1 && cE == 0 && cW == 0) ||
        (cN == 0 && cS == 0 && cE == 1 && cW == 1) || ((cE ^ cW) & 1) ||
        ((cS ^ cN) & 1)) {
      cout << "NO\n";
      continue;
    }
    ui needN = max<int>(cN - cS, 0) / 2, needS = max<int>(cS - cN, 0) / 2,
       needE = max<int>(cE - cW, 0) / 2, needW = max<int>(cW - cE, 0) / 2;
    if (!(needN || needS || needE || needW))
      cN ? (needN = needS = 1, needE = needW = 0)
         : (needN = needS = 0, needE = needW = 1);
    for (char i : s) {
      ui &q = i == 'N' ? needN : i == 'S' ? needS : i == 'E' ? needE : needW;
      if (q)
        --q, cout.put('H');
      else
        cout.put('R');
    }
    cout << '\n';
  }
  return 0;
}