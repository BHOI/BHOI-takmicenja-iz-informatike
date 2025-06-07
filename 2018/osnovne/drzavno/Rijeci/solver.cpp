#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solve(const vector<string> &needles, const vector<string> &haystack) {
  unordered_map<string, int> m;
  vector<int> occurrences;
  for (const auto &str : haystack) {
    m[str]++;
  }
  occurrences.reserve(needles.size());
  for (const auto &str : needles) {
    occurrences.push_back(m[str]);
  }
  return occurrences;
}

int main() {

  size_t n, m;
  cin >> n;
  vector<string> needles(n);

  needles.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> needles[i];
  }
  cin >> m;
  vector<string> haystack(m);
  for (size_t i = 0; i < m; i++) {
    cin >> haystack[i];
  }

  vector<int> sol = solve(needles, haystack);


  for (size_t i = 0; i < n; i++) {
    cout << sol[i] << ' ';
  }
  cout << '\n';

}