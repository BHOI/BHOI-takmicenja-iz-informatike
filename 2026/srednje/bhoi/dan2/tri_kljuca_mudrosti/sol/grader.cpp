#include "grader.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

namespace {

const int MAX_N = 2000;
const int MAX_CALLS = 100000;

void wrongAnswer() {
    printf("0\nwrong answer\n");
    exit(0);
}

int N, num_calls;
std::vector<int> graph[MAX_N];
std::set<std::pair<int, int>> edges, edges_reported;
int weight[MAX_N];

bool traverse(int p, int e, int rt = -1) {
    if (p == e) {
        ++weight[p];
        return true;
    }
    for (int q : graph[p]) {
        if (q != rt) {
            if (traverse(q, e, p)) {
                ++weight[p];
                return true;
            }
        }
    }
    return false;
}

}

int meetingPlace(int u, int v, int w) {
    if (!(0 <= u && u <= N - 1 && 0 <= v && v <= N - 1 && 0 <= w && w <= N - 1 &&
          u != v && u != w && v != w))
        wrongAnswer();
    if (++num_calls > MAX_CALLS)
        wrongAnswer();
    std::fill(weight, weight + N, 0);
    traverse(u, v);
    traverse(u, w);
    traverse(v, w);
    for (int x = 0; x < N; ++x)
        if (weight[x] == 3) return x;
    printf("0\nError: the input may be invalid\n");
    exit(0);
}

void mapPath(int u, int v) {
    if (!(0 <= u && u < v && v <= N - 1))
        wrongAnswer();
    if (!(edges.count(std::make_pair(u, v)) >= 1))
        wrongAnswer();
    if (!(edges_reported.count(std::make_pair(u, v)) == 0))
        wrongAnswer();
    edges_reported.insert(std::make_pair(u, v));
}

int main() {
    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "0\nError while reading input\n");
        exit(1);
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        if (scanf("%d%d", &u, &v) != 2) {
            fprintf(stderr, "0\nError while reading input\n");
            exit(1);
        }
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.insert(std::make_pair(u, v));
    }
    num_calls = 0;
    solve(N);
    if (edges_reported.size() != static_cast<size_t>(N - 1))
        wrongAnswer();
    
    printf("1\n%d\n", edges_reported.size());
    for (auto [f, t] : edges_reported) {
        printf("%d %d\n", f, t);
    }
    return 0;
}

/*
we assume that we have the right number of calls
this is the format
    - starts with 0 if incorrect, second line is error msg
    - starts with 1 if correct, second line is number of edges and then outputs the number of edges

*/
