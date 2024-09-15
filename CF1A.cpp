#include <bits/stdc++.h>
using namespace std;
using uli = unsigned long long int;
int main(void) {
  uli n, m, a;
  cin >> n >> m >> a;
  cout << uli(ceil(double(n) / a) * ceil(double(m) / a));
  return 0;
}
