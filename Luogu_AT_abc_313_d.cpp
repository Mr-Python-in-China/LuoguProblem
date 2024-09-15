#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
istream& operator>>(istream& in, typename vector<bool>::reference b) {
  bool r;
  in >> r;
  b = r;
  return in;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  vector<bool> b(n);
  if (k == 1) {
    for (size_t i = 0; i < n; ++i) cout << "? " << i + 1 << endl, cin >> b[i];
  } else {
    b[0] = 1;
    bool beginner;
    cout << "? ";
    for (size_t i = 1; i <= k; ++i) cout << i << ' ';
    cout << endl, cin >> beginner;
    for (size_t i = k; i < n; i++) {
      bool res;
      cout << "? ";
      for (size_t i = 1; i < k; ++i) cout << i + 1 << ' ';
      cout << i + 1 << endl, cin >> res;
      b[i] = res == beginner;
    }
    for (size_t i = 1; i < k; i++) {
      bool res;
      cout << "? ";
      for (size_t j = 0; j < i; j++) cout << j + 1 << ' ';
      for (size_t j = i + 1; j <= k; j++) cout << j + 1 << ' ';
      cout << endl, cin >> res;
      b[i] = (res != beginner) ^ b[k];
    }
    bool turly = false;
    for (size_t i = 0; i < k; i++) turly ^= b[i];
    if (turly != beginner)
      for (vector<bool>::reference i : b) i = !i;
  }
  cout << "! ";
  for (vector<bool>::reference const& i : b) cout << i << ' ';
  return 0;
}