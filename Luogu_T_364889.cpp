#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, l;
  cin >> n >> m >> l;
  set<string> st;
  while (n--) {
    string s;
    cin >> s;
    st.insert(s);
  }
  while (m--) {
    string s;
    cin >> s;
    st.erase(s);
  }
  while (l--) {
    string s;
    cin >> s;
    st.insert(s);
  }
  for (string const& i : st) cout << i << '\n';
  return 0;
}