#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s, t;
  cin >> s >> t;
  for (size_t w = 1; w < s.size(); ++w) {
    vector<string> substr;
    size_t i = 0;
    for (; i + w < s.size(); i += w) substr.push_back(s.substr(i, w));
    substr.push_back(s.substr(i));
    for (size_t c = 0; c < w; ++c) {
      string d;
      for (string const &i : substr)
        if (c < i.size()) d += i[c];
      if (t == d) cout << "Yes", exit(0);
    }
  }
  cout << "No";
  return 0;
}