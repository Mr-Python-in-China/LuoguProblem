#include <bits/stdc++.h>
using namespace std;
vector<bool> safeWrite(vector<bool> const& a, vector<bool> const& c) {
  vector<bool> res(31);
  size_t p = 0;
  for (size_t i = 0; i < 31; ++i) res[i] = (!c[i] ? a[p++] : 0);
  return res;
}
vector<bool> safeRead(vector<bool> const& a, vector<bool> const& c) {
  vector<bool> res;
  for (size_t i = 0; i < 31; ++i)
    if (!c[i]) res.emplace_back(a[i]);
  return res;
}
vector<bool> send_packet(vector<bool> A);
void send_message(vector<bool> a, vector<bool> c) {
  vector<bool> s(31), t(31);
  for (size_t i = 1; i < 31; ++i) s[i - 1] = c[i];
  for (size_t i = 1; i < 31; ++i) t[i] = c[i - 1];
  s[30] = c[0], t[0] = c[30];
  send_packet(s), send_packet(t);
  vector<bool>::iterator it = a.begin(), jt = it + 16;
  for (; jt < a.end(); it += 16, jt += 16)
    send_packet(safeWrite(vector<bool>(it, jt), c));
  vector<bool> tmp(it, a.end());
  tmp.resize(16);
  send_packet(safeWrite(tmp, c));
}
std::vector<bool> receive_message(std::vector<std::vector<bool>> r) {
  vector<bool> s = r[0], t = r[1];
  array<size_t, 31 * 2> fa = {};
  for (size_t i = 1; i < 31; ++i) fa[i - 1 + 0] = s[i - 1] ? i + 0 : i - 1 + 31;
  for (size_t i = 1; i < 31; ++i) fa[i + 31] = t[i] ? i - 1 + 31 : i + 0;
  fa[30] = s[30] ? 0 + 0 : 30 + 31, fa[0 + 31] = t[0] ? 30 + 0 : 0;
  array<signed char, fa.size()> color = {};
  {
    array<unsigned char, fa.size()> indeg = {};
    for (size_t i = 0; i < fa.size(); ++i) ++indeg[fa[i]];
    queue<size_t> q;
    for (size_t i = 0; i < fa.size(); ++i)
      if (!indeg[fa[i]]) q.emplace(i);
    while (!q.empty()) {
      size_t p = q.front();
      q.pop();
      color[p] = -1;
      if (!--indeg[fa[p]]) q.emplace(fa[p]);
    }
  }
}

#ifndef ONLINE_JUDGE
vector<vector<bool>> packets;
vector<bool> d(31);
mt19937 rd((random_device())());
uniform_int_distribution<unsigned short int> rdb(0, 1);
vector<bool> send_packet(vector<bool> A) {
  assert(A.size() == 31);
  for (size_t i = 0; i < 31; ++i)
    if (d[i]) A[i] = rdb(rd);
  packets.emplace_back(A);
  return A;
}
int main(void) {
  size_t n;
  cin >> n;
  vector<bool> dat(n);
  for (auto i : dat) {
    char c;
    cin >> c;
    i = c == '1';
  }
  for (auto i : d) {
    char c;
    cin >> c;
    i = c == '1';
  }
  send_message(dat, d);
  vector<bool> res = receive_message(packets);
  assert(res == dat);
  cerr << packets.size();
}
#endif
