#include <bits/stdc++.h>
using namespace std;
using li = long long int;
ifstream fin;
ostream& fout = cout;
char bufArray[1 << 20];
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  fin.rdbuf()->pubsetbuf(bufArray, sizeof(bufArray));
  fin.open("/dev/stdin");
  size_t n;
  fin >> n;
  li ans = 0;
  while (n--) {
    li x;
    fin >> x;
    ans += x;
  }
  fout << ans;
  return 0;
}