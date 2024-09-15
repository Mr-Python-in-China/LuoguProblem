#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct BitDPid {
  unsigned char const w;
  struct iterator {
    using difference_type = ptrdiff_t;
    struct value_type {
      size_t bit;
      value_type(size_t _bit): bit(_bit) {}
      operator size_t const &() const { return bit; }
      operator size_t &() { return bit; }
      value_type intersection(value_type d) { return *this & d; }
      bool intersection_is_empty(value_type d) { return intersection(d) == 0; }
      bool get(unsigned char p) const { return (bit >> p) & 1; }
      value_type set(unsigned char p) const { return bit & (size_t(1) << p); }
      value_type reset(unsigned char p) const {
        return bit & ~(size_t(1) << p);
      }
      value_type flip(unsigned char p) const { return bit ^ (size_t(1) << p); }
      unsigned char popcount() { return __builtin_popcount(bit); }
    };
    using reference = value_type &;
    using pointer = value_type *;
    iterator(ui _bit): v(_bit) {}
    virtual iterator &operator++() {
      ++v;
      return *this;
    }
    virtual iterator operator++(int) {
      auto old = *this;
      ++v;
      return old;
    }
    friend bool operator==(iterator a, iterator b) { return a.v == b.v; }
    friend bool operator!=(iterator a, iterator b) { return a.v != b.v; }
    reference operator*() { return v; }
    pointer operator->() { return &v; }

   protected:
    value_type v;
  };
  BitDPid(unsigned char _s): w(_s) {}
  iterator begin() const { return 0; }
  iterator end() const { return size_t(1) << w; }
  size_t size() const { return size_t(1) << w; }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  BitDPid id(n);
  vector<vector<uli>> f(id.size(), vector<uli>(k + 1));
  f[0][0] = 1;
  for (size_t t = 0; t < n; ++t) {
    vector<vector<uli>> g(id.size(), vector<uli>(k + 1));
    for (auto i : id)
      for (auto j : id)
        if (j.popcount() <= k)
          if (i.intersection_is_empty(j) && i.intersection_is_empty(j << 1) &&
              i.intersection_is_empty(j >> 1) &&
              j.intersection_is_empty(j >> 1) &&
              j.intersection_is_empty(j << 1)) {
            for (size_t d = 0; d <= (k - j.popcount()); ++d)
              g[j][d + j.popcount()] += f[i][d];
          }
    f = g;
  }
  cout << accumulate(f.begin(), f.end(), uli(0),
                     [](uli x, auto const &v) { return x + v.back(); });
  return 0;
}