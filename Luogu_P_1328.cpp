#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using usi = unsigned short int;
char WIN_TABLE[5][5] = {
    { 0, -1,  1,  1, -1},
    { 1,  0, -1,  1, -1},
    {-1,  1,  0, -1,  1},
    {-1, -1,  1,  0,  1},
    { 1,  1, -1, -1,  0}
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  usi n, na, nb, ansa = 0, ansb = 0, cnta = 0, cntb = 0;
  cin >> n >> na >> nb;
  vector<ui> a(na), b(nb);
  for (vector<ui>::reference i : a) cin >> i;
  for (vector<ui>::reference i : b) cin >> i;
  while (n--)
    ansa += (WIN_TABLE[a[cnta]][b[cntb]] == 1),
        ansb += (WIN_TABLE[a[cnta]][b[cntb]] == -1),
        // cout<<int(WIN_TABLE[a[cnta]][b[cntb]])<<' ',
        cnta = (cnta + 1) % na, cntb = (cntb + 1) % nb;
  cout << ansa << ' ' << ansb;
  return 0;
}