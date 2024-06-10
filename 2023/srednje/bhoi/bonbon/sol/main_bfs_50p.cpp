#include <iostream>
#include <set>
#include <queue>
#include <tuple>
#include <assert.h>
using namespace std;

typedef tuple<int, int> VisitedState;
// first number is current bonbons in A
// second number is current bonbons in B
// last number is number of steps required to get to this state
typedef tuple<int, int, int, VisitedState> StateWithStep;

inline VisitedState extractVisitedState(const StateWithStep& state) {
  return make_tuple(get<0>(state), get<1>(state));
}

inline bool canEmpty(int currentState) {
  return currentState > 0;
}

inline bool canFill(int currentState, int maxBonbons) {
  return currentState < maxBonbons;
}

inline bool canPour(int fromCurrentBonbons, int toCurrentBonbons, int maxBonbonsDest) {
  return canFill(toCurrentBonbons, maxBonbonsDest) && canEmpty(fromCurrentBonbons);
}

inline void pour(int& fromCurrentBonbons, int& toCurrentBonbons, int maxBonbonsDest) {
  int capacityLeftInDestination = maxBonbonsDest - toCurrentBonbons;
  int toPour = min(fromCurrentBonbons, capacityLeftInDestination);
  assert(toPour > 0);
  fromCurrentBonbons = fromCurrentBonbons - toPour;
  toCurrentBonbons = toCurrentBonbons + toPour;
}

#define ADD_IF_NOT_VISITED(s) {\
  StateWithStep tmp = s;\
  VisitedState tmp2 = extractVisitedState(tmp);\
  if (visited.find(tmp2) == visited.end()) {\
    q.push(tmp);\
    visited.insert(tmp2);\
  }\
}

void addAllPossiblePathsFromState(
    StateWithStep currentState,
    queue<StateWithStep>& q,
    set<VisitedState>& visited,
    int a, int b
) {
  int nextNumberOfSteps = get<2>(currentState) + 1;
  VisitedState visitedState = extractVisitedState(currentState);
  int& currA = get<0>(currentState);
  int& currB = get<1>(currentState);
  if (canEmpty(currA)) {
    ADD_IF_NOT_VISITED(make_tuple(0, currB, nextNumberOfSteps, visitedState));
  }
  if (canFill(currA, a)) {
    ADD_IF_NOT_VISITED(make_tuple(a, currB, nextNumberOfSteps, visitedState));
  }
  if (canEmpty(currB)) {
    ADD_IF_NOT_VISITED(make_tuple(currA, 0, nextNumberOfSteps, visitedState));
  }
  if (canFill(currB, a)) {
    ADD_IF_NOT_VISITED(make_tuple(currA, b, nextNumberOfSteps, visitedState));
  }
  if (canPour(currA, currB, b)) {
    int aCP = currA, bCP = currB;
    pour(aCP, bCP, b);
    ADD_IF_NOT_VISITED(make_tuple(aCP, bCP, nextNumberOfSteps, visitedState));
  }
  if (canPour(currB, currA, a)) {
    int aCP = currA, bCP = currB;
    pour(bCP, aCP, a);
    ADD_IF_NOT_VISITED(make_tuple(aCP, bCP, nextNumberOfSteps, visitedState));
  }
}

// A bonbons, B bonbons, we try to get C bonbons in total
int solve(int a, int b, int c) {
  // which states we visited
  set<VisitedState> visited;
  // queue of states
  queue<StateWithStep> q;
  // we start with both bags empty
  q.push({0, 0, 0, {0, 0}});
  visited.insert({0, 0});

  // we try to solve this by BFS search of all possible states
  while (!q.empty()) {
    auto current = q.front();
    q.pop();
    assert(visited.find({get<0>(current), get<1>(current)}) != visited.end());
    // if bonbons in first + bonbons in second == c, we are done
    int aa = get<0>(current);
    int bb = get<1>(current);
    if (aa + bb == c) {
      return get<2>(current);
    }
    addAllPossiblePathsFromState(current, q, visited, a, b);
  }
  return -1;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << solve(a, b, c) << endl;
  return 0;
}