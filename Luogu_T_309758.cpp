#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
struct ins {
  ui id, pos, light;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n;
  cin >> n;
  ui leave = n;
  list<ins> a(n);
  vector<ui> ans(n);
  {
    list<ins>::iterator it = a.begin();
    for (ui i = 0; i < n; i++, it++) it->id = i;
  }
  for (list<ins>::iterator it = a.begin(); it != a.end(); it++) cin >> it->pos;
  list<ins>::iterator l = a.begin(), m = l, r = l, top = l;
  ui cnt = 0;
  for (list<ins>::iterator it = a.begin(); it != a.end(); it++) {
    cin >> it->light;
    l = m, m = r, r = it;
    if (top->light < it->light) top = it;
    if (m->light > l->light && m->light > r->light) cnt++;
  }
  if (cnt == 0 && top == r) {
    for (ui i = 1; i < n; i++) cout << a.back().pos << ' ';
    cout << "0 ";
    return 0;
  }
  if (cnt == 1) {
    for (list<ins>::iterator it = a.begin(); it != top; it++)
      cout << top->pos << ' ';
    cout << "0 ";
    for (list<ins>::iterator it = next(top); it != a.end(); it++) {
      cout << top->pos << ' ';
    }
    return 0;
  }
  while (leave != 1) {
    list<ins>::iterator lt = a.begin(), mt = next(lt), rt = next(mt);
    if (lt->light < mt->light) lt->pos++;
    for (; rt != a.end(); lt++, mt++, rt++) {
      if (lt->light > mt->light && lt->light > rt->light) mt->pos--;
      if (lt->light < rt->light && mt->light < rt->light) mt->pos++;
    }
    if (mt->light < lt->light) mt->pos--;
    for (list<ins>::iterator it = a.begin(), jt = next(it); jt != a.end();) {
      if (it->pos != jt->pos)
        it++, jt++;
      else {
        leave--;
        if (it->light < jt->light)
          ans[it->id] = it->pos, a.erase(it++), jt++;
        else
          ans[jt->id] = jt->pos, a.erase(jt++), jt++, it++;
      }
    }
  }
  for (vector<ui>::const_reference i : ans) cout << i << ' ';
  return 0;
}