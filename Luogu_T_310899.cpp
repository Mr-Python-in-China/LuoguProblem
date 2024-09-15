#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using graph = vector<pair<bool, vector<size_t>>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  graph mp(n);
  for (graph::reference i : mp) {
    char c;
    cin >> c;
    i.first = c == ')';
  }
  for (size_t i = 1; i < n; ++i) {
    size_t a, b;
    cin >> a >> b;
    --a, --b;
    mp[a].second.push_back(b), mp[b].second.push_back(a);
  }

  return 0;
}