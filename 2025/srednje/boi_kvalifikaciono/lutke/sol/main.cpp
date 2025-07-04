#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
  int x, y;
  ll max_till;
  shared_ptr<Node> left, right;
  Node(int a, int b, ll max_till) : x(a), y(b), max_till(max_till) {}
  bool leaf() const { return x == y; }
  void combine() { max_till = max(left->max_till, right->max_till); }
  int len() { return y - x + 1; }
};

shared_ptr<Node> construct(int a, int b, const vector<ll>& d) {
  if (a == b) {
    return make_shared<Node>(a, a, d[a]);
  }
  int mid = a + (b - a) / 2;
  auto curr = make_shared<Node>(a, b, -1);
  curr->left = construct(a, mid, d);
  curr->right = construct(mid + 1, b, d);
  curr->combine();
  return curr;
}

struct SegTree {
  int n;
  shared_ptr<Node> root;
  SegTree(const vector<ll>& d) {
    if (d.size() == 0) {
      root = nullptr;
    } else {
      root = construct(0, d.size() - 1, d);
    }
  }

  void internal_update(shared_ptr<Node> curr, int inx, ll k) {
    if (curr->leaf()) {
      if (curr->x == inx) {
        curr->max_till = k;
      }
      return;
    }
    if (inx <= curr->left->y) {
      internal_update(curr->left, inx, k);
    } else {
      internal_update(curr->right, inx, k);
    }
    curr->combine();
  }
  void update(int inx, ll k) { internal_update(root, inx, k); }

  ll internal_max_till_inx(shared_ptr<Node> curr, int inx) const {
    if (curr->leaf()) {
      if (curr->x <= inx) {
        return curr->max_till;
      }
      return -1;
    }
    if (inx <= curr->left->y) {
      return internal_max_till_inx(curr->left, inx);
    } else {
      return max(curr->left->max_till, internal_max_till_inx(curr->right, inx));
    }
  }

  ll max_till_inx(int inx) const {
    if (root == nullptr) {
      return -1;
    }
    return internal_max_till_inx(root, inx);
  }

  int internal_len_until_val(shared_ptr<Node> curr, ll val) const {
    if (curr->leaf()) {
      if (curr->max_till < val) {
        return 1;
      } else {
        return 0;
      }
    }
    if (curr->left->max_till < val) {
      return curr->left->len() + internal_len_until_val(curr->right, val);
    } else {
      return internal_len_until_val(curr->left, val);
    }
  }

  int len_until_val(ll val) const {
    if (root == nullptr) {
      return 0;
    }
    return internal_len_until_val(root, val);
  }
};

void enhance(int e, priority_queue<pair<ll, size_t>>& d_sorted, vector<ll>& d,
             int p, auto update_func) {
  vector<pair<ll, int>> top_e;
  top_e.reserve(e);
  int seen = 0;
  for (; seen < e;) {
    auto top = d_sorted.top();
    d_sorted.pop();
    if (top.first != d[top.second]) {
      // just pop out stale values from the queue
      continue;
    }
    seen++;
    top_e.push_back(top);
  }
  auto last_iter = top_e.rbegin();
  // Take the value of the current e'th one an increase by 1 for our number.
  ll last_value = last_iter->first + 1;
  d_sorted.push(*last_iter);
  // Push our now enhanced doll, the old value will be ignored if ever accessed.
  d_sorted.push({last_value, p});
  d[p] = last_value;
  update_func(p, d[p]);
  while (++last_iter != top_e.rend()) {
    int i = last_iter->second;
    d[i] = ++last_value;
    update_func(i, d[i]);
    d_sorted.push({d[i], i});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a;
  cin >> n >> a;
  a--;
  vector<ll> d(n);
  priority_queue<pair<ll, size_t>> d_sorted;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    d_sorted.push({d[i], i});
  }
  vector<ll> left_d(d.rbegin() + (d.size() - a), d.rend());
  vector<ll> right_d(d.begin() + a + 1, d.end());
  SegTree left(left_d), right(right_d);
  auto update_seg_tree = [&left, &right, a](int b, ll k) {
    int diff = b - a;
    if (diff == 0) {
      return;
    } else if (diff < 0) {
      // important to have -1 as the tree is 0 indexed
      left.update(-diff - 1, k);
    } else {
      right.update(diff - 1, k);
    }
  };
  int q;
  cin >> q;
  while (q--) {
    char c;
    cin >> c;
    if (c == 'F') {
      int b, result = 0;
      cin >> b;
      b--;
      int diff = b - a;
      if (diff < 0) {
        // get the biggest number in the left side up to our doll at |b|
        // important to have -1 as the tree is 0 indexed
        ll max_till_b = left.max_till_inx(-diff - 1);
        // get how many we would consume on the right side
        // now we know max beauty we encounter until b
        int len_until = right.len_until_val(max_till_b);
        result = len_until + (-diff);
      } else {
        ll max_till_b = right.max_till_inx(diff - 1);
        int len_until = left.len_until_val(max_till_b);
        result = len_until + diff;
      }
      cout << result << endl;
    } else if (c == 'E') {
      int p, e;
      cin >> p >> e;
      p--;
      enhance(e, d_sorted, d, p, update_seg_tree);
    } else {
      throw;
    }
  }
}