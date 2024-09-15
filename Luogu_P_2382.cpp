#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct UNKOWN {};
uli f(string::const_iterator& it, unordered_map<string, uli>& yz) {
  uli ans = 0;
  while (*it != ')') {
    uli m;
    if (*it == '(')
      m = f(++it, yz), ++it;
    else {
      string ns;
      ns.push_back(*(it++));
      while (islower(*it)) ns.push_back(*(it++));
      if (!yz.count(ns)) throw UNKOWN();
      m = yz[ns];
    }
    size_t times = 0;
    while (isdigit(*it)) (times *= 10) += *(it++) - '0';
    if (times == 0) times = 1;
    ans += m * times;
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  unordered_map<string, uli> yz;
  while (cin >> s && s != "END_OF_FIRST_PART") {
    uli sz;
    cin >> sz;
    yz[s] = sz;
  }
  while (cin >> s && s != "0") {
    s.push_back(')');
    string::const_iterator it = s.cbegin();
    try {
      cout << f(it, yz) << '\n';
    } catch (UNKOWN err) { cout << "UNKNOWN\n"; }
  }
  return 0;
}