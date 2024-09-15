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
      bool get(unsigned char p) const { return (bit >> p) & 1; }
      value_type set(unsigned char p) const { return bit & (size_t(1) << p); }
      value_type reset(unsigned char p) const {
        return bit & ~(size_t(1) << p);
      }
      value_type flip(unsigned char p) const { return bit ^ (size_t(1) << p); }
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
  size_t n;
  cin >> n;
  vector<pair<ui, ui>> a(n);
  for (pair<ui, ui> &i : a) cin >> i.first >> i.second;
  BitDPid const id(n);
  vector<bool> f(id.size());
  for (auto const p : id) {
    for (size_t i = 0; i < n; ++i)
      for (size_t j = i + 1; j < n; ++j)
        if (p.get(i) && p.get(j) &&
            ((a[i].first == a[j].first) || (a[i].second == a[j].second)))
          f[p] = f[p] | !f[p.reset(i).reset(j)];
  }
  cout << (f.back() ? "Takahashi" : "Aoki");
  return 0;
}