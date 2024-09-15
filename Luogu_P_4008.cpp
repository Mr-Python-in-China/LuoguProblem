#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr size_t W = sizeof(size_t) * 8;
template <typename T, typename RandomEngine => struct jumplist {
  using value_type = T;
  using reference = value_type &;
  using const_reference = const reference;
  using difference_type = ptrdiff_t;
  using size_type = size_t;

 protected:
  static size_t rand_height(void) {
    size_t i = 0;
    while (++i <= w) {
      bool b = distrib(rand);
      if (b == 0) break;
    }
    return i;
  }

  struct node {
    size_t height;
    struct _ptr {
      node *prev, *next;
    } *ptrs;
    node(size_t n)
        : height(n),
          ptrs(static_cast<_ptr *>(operator new[](sizeof(_ptr) * n))) {}
    node(node const &that): node(that.height) {
      copy(that.ptrs, that.ptrs + height, ptrs);
    }
    node(node &&that): height(that.height), ptrs(that.ptrs) {
      that.ptrs = nullptr;
    }
    virtual ~node() { operator delete[](ptrs); }
    node &operator=(node &) = delete;
  } header;
  struct val_node: node {
    value_type val;
    template <typename... Args>
    val_node(size_t n, Args... args): node(n), val(forward(args)...) {}
    val_node(val_node const &that): node(that), val(that.val) {}
    val_node(val_node &&that): node(that), val(that.val) {}
  };
  size_type sz;
  RandomEngine rand;
  uniform_int_distribution<short> distrib;
  static RandomEngine gen_new_RandomEngine(void) {
    return RandomEngine(random_device()());
  }

 public:
  jumplist(RandomEngine const _rand = gen_new_RandomEngine())
      : header(W), RandomEngine(_rand), distrib(0, 1) {
    for (size_t i = 0; i < header.height; ++i)
      header.ptrs[i].prev = header.ptrs[i].next = &header.ptrs[i];
  }
  jumplist(jumplist const &that,
           RandomEngine const _rand = gen_new_RandomEngine())
      : jumplist(_rand) {
    copy(that.begin(), that.end(), back_inserter(*this));
  }
  jumplist(jumplist &&that, RandomEngine const _rand = gen_new_RandomEngine())
      : header(move(that.header)), jumplist(_rand) {}
  jumplist(size_type n, value_type const &d) { assign(n, d); }
  template <typename LegacyInputIterator>
  jumplist(LegacyInputIterator first, LegacyInputIterator last) {}
  jumplist(initializer_list<value_type> const &il)
      : jumplist(il.begin(), il.end()) {}
  jumplist &operator=(jumplist const &that) {
    assign(that.begin(), that.end());
  }
  jumplist &operator=(jumplist &&that) {}
  jumplist &operator=(initializer_list<value_type> const &il) {
    assign(il.begin(), il.end());
  }
  ~jumplist() { clear(); }

  template <typename D> struct iterator_template {
    using difference_type = jumplist::difference_type;
    using value_type = D;
    using pointer = value_type *;
    using reference = value_type &;
    using iterator_category = bidirectional_iterator_tag;

    iterator_template(node *_p): p(_p) {}
    iterator_template operator++(void) {
      p = p->ptrs->next;
      return *this;
    }
    iterator_template operator--(void) {
      p = p->ptrs->prev;
      return *this;
    }
    iterator_template operator++(int) {
      auto t = *this;
      ++*this;
      return t;
    }
    iterator_template operator--(int) {
      auto t = *this;
      --*this;
      return t;
    }
    reference operator*(void) const { return *p; }
    pointer operator->(void) const { return p; }
    friend bool operator==(iterator_template const &a,
                           iterator_template const &b) {
      return a.p == b.p;
    }
    friend bool operator!=(iterator_template const &a,
                           iterator_template const &b) {
      return a.p != b.p;
    }

   protected:
    node *p;
  };
  using iterator = iterator_template<value_type>;
  using const_iterator = iterator_template<value_type const>;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  iterator begin() { return header.ptrs->next; }
  iterator end() { return header; }
  const_iterator cbegin() { return begin(); }
  const_iterator cend() { return end(); }
  reverse_iterator rbegin() { return end(); }
  reverse_iterator rend() { return begin(); }
  const_reverse_iterator crbegin() { return cbegin(); }
  const_reverse_iterator crend() { return cend(); }

  friend bool operator==(jumplist const &a, jumplist const &b) {
    return equal(a.cbegin(), a.cend(), b.cbegin(), b.cend());
  }
  friend bool operator!=(jumplist const &a, jumplist const &b) {
    return !(a == b);
  }
  void swap(jumplist const &a) { std::swap(*this, a); }
  size_type size(void) { return sz; }
  bool empty(void) { return !sz; }
  template <typename... Args>
  iterator emplace(const_iterator it, Args... args) {
    val_node *nd = new val_node(rand_height(), forward(args)...);
    node p = nd;
    for (size_t i = 0; i < nd->val; ++i) {
      while (p->height < i) p = ptr->height[i].next;
      nd->ptrs[i].prev = it.p->ptrs[i].prev, nd->ptrs[i].next = it.p;
      nd->ptrs[i].prev->ptrs[i].next = nd, nd->ptrs[i].next->ptrs[i].prev = nd;
    }
  }
  iterator insert(const_iterator it, value_type const &d) { emplace(it, d); }
  iterator insert(const_iterator it, value_type &&d) { emplace(it, d); }
  iterator insert(const_iterator it, size_type n, value_type const &d) {
    emplace(it, d);
  }
  template <typename LegacyInputIterator>
  iterator insert(const_iterator it, LegacyInputIterator first,
                  LegacyInputIterator last) {
    if (first == last) return it;
    iterator res = insert(it, *(first++));
    while (first != last) insert(it, *(first++));
  }
  iterator insert(const_iterator it, initializer_list<value_type> const &il) {
    return insert(it, il.begin(), il.end());
  }
  iterator erase(const_iterator it);
  iterator erase(const_iterator first, const_iterator last) {
    while (first != last) erase(first++);
    return first;
  }
  void clear(void) { erase(begin(), end()); }
  template <typename LegacyInputIterator>
  void assign(LegacyInputIterator first, LegacyInputIterator last) {
    clear();
    insert(first, last);
  }
  void assign(initializer_list<value_type> const &il) {
    assign(il.begin(), il.end());
  }
  void assign(size_type n, value_type const &v) {
    clear();
    for (size_type i = 0; i < n; ++i) push_back(v);
  }
  reference front(void) { return *begin(); }
  reference back(void) { return *prev(end()); }
  template <typename... Args> void emplace_front(Args... args) {
    emplace(begin(), forward<args>...);
  }
  template <typename... Args> void emplace_back(Args... args) {
    emplace(end(), forward<args>...);
  }
  void push_front(value_type const &v) { emplace_front(v); }
  void push_back(value_type const &v) { emplace_back(v); }
  void pop_front(void) { erase(begin()); }
  void pop_back(void) { erase(prev(end())); }
  reference operator[](size_type p);
  reference at(size_type p) {
    if (p >= size()) throw out_of_range("Out of range in jumplist.");
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  return 0;
}