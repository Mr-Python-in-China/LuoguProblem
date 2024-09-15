#include <bits/stdc++.h>

const int MAXN = 100010, MAXM = 700010;

struct Edge {
  int y, z;
  Edge *next;
} *a[MAXN], POOL[MAXM], *ptr, *back[MAXN];

void AddEdge(int x, int y, int z) {
  Edge *tmp = ptr++;
  tmp->y = y;
  tmp->z = z;
  tmp->next = a[x];
  a[x] = tmp;
}

int n, nodes[MAXN], k, s, t;
long long dis[MAXN];

long long dijkstra() {
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  std::priority_queue<std::pair<long long, int> > Q;
  Q.push(std::make_pair(0, s));
  for (int i = 1; i < n + 2; i++) {
    while (!Q.empty() && dis[Q.top().second] != -Q.top().first) Q.pop();
    if (Q.empty()) break;
    int now = Q.top().second;
    Q.pop();
    for (Edge *p = a[now]; p; p = p->next)
      if (dis[p->y] > dis[now] + p->z)
        Q.push(std::make_pair(-(dis[p->y] = dis[now] + p->z), p->y));
  }
  return dis[t];
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    ptr = POOL;
    memset(a, 0, sizeof a);
    int m;
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      AddEdge(x, y, z);
    }
    for (int i = 1; i <= k; i++) scanf("%d", nodes + i);

    long long Ans = ~0ull >> 1;
    s = n + 1, t = n + 2;
    for (int i = 0; (1 << i) <= k; i++) {
      Edge *backup = ptr;
      memcpy(back, a, (sizeof a[0]) * (n + 3));
      for (int j = 1; j <= k; j++)
        if (j & (1 << i)) {
          AddEdge(s, nodes[j], 0);
        } else {
          AddEdge(nodes[j], t, 0);
        }
      Ans = std::min(Ans, dijkstra());
      ptr = backup;
      memcpy(a, back, (sizeof a[0]) * (n + 3));
      for (int j = 1; j <= k; j++)
        if (j & (1 << i)) {
          AddEdge(nodes[j], t, 0);
        } else {
          AddEdge(s, nodes[j], 0);
        }
      Ans = std::min(Ans, dijkstra());
      ptr = backup;
      memcpy(a, back, (sizeof a[0]) * (n + 3));
    }
    printf("%lld\n", Ans);
  }
  return 0;
}
