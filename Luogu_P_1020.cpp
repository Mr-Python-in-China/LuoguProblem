#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  vector<usi> a;
  stack<usi> stk;
  {
    usi x;
    while (cin >> x) a.push_back(x);
  }
  vector<usi> f;
  for (usi i : a) {
    vector<usi>::iterator it =
        upper_bound(f.begin(), f.end(), i, greater<usi>());
    if (it == f.end())
      f.push_back(i);
    else
      *it = i;
  }
  set<usi, greater<usi>> ss({numeric_limits<usi>::max()});
  for (usi i : a) {
    if (*ss.begin() < i) ss.insert(numeric_limits<usi>::max());
    ss.erase(prev(ss.upper_bound(i))), ss.insert(i);
  }
  cout << f.size() << '\n' << ss.size();
  return 0;
}