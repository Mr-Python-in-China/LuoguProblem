#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  vector<ui> a;
  copy(istream_iterator<ui>(cin), istream_iterator<ui>(), back_inserter(a));
  for_each(a.crbegin(), a.crend(), [](ui x) { cout << x << '\n'; });
  return 0;
}