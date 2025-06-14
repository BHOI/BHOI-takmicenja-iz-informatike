import random
import os

import networkx as nx


# Configuration constants
FIRST_TESTCASE_NUM = 1  # Starting number for testcase files
NUM_TESTCASES = 1  # Number of testcase files to generate
MIN_NODES, MAX_NODES = 400, 500
MIN_EDGES, MAX_EDGES = 2, 1000
MIN_WEIGHT, MAX_WEIGHT = 1, 1
MIN_QUERIES, MAX_QUERIES = 10, 10
MAX_RATIO_OF_NEGATIVE_EDGES = 0
MAX_DIFFERENT_STARTS = 10

negative_cycle_checks = 0


def random_key():
    """Generate a random key for edges."""
    return random.randint(0, 1000000000)


def has_negative_weight_cycle_from_start(graph: nx.DiGraph, start: int) -> bool:
    """Check if the graph has a negative weight cycle reachable from the start node."""
    global negative_cycle_checks
    negative_cycle_checks += 1
    try:
        # Use Bellman-Ford algorithm to detect negative weight cycles
        nx.find_negative_cycle(graph, start, weight="weight")
        return True
    except Exception as e:
        if "No negative cycles detected." not in str(
            e
        ) and "Negative cycle is detected but not found" not in str(e):
            raise
        return False


# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)


def generate_test_case(case_num):
    n = random.randint(MIN_NODES, MAX_NODES)
    m = random.randint(MIN_EDGES, MAX_EDGES)
    q = random.randint(MIN_QUERIES, MAX_QUERIES)

    m = min(
        m, n * (n - 1)
    )  # Ensure m does not exceed the maximum possible edges in a directed graph
    q = min(q, n * (n - 1))  # Ensure q does not exceed the maximum possible queries

    print(f"Generating test case {case_num}: n = {n}, m = {m}, q = {q}")

    graph = nx.MultiDiGraph()

    # Generate edges with weights
    while graph.number_of_edges() < m:
        u = random.randint(0, n - 1)
        v = random.randint(0, n - 1)
        # print(f"Trying to add edge from {u} to {v}")
        while u == v or graph.has_edge(u, v):
            print(
                f"Edge from {u} to {v} already exists or is self-loop. Generating new edge."
            )
            u = random.randint(0, n - 1)
            v = random.randint(0, n - 1)

        new_weight = random.randint(MIN_WEIGHT, MAX_WEIGHT)

        graph.add_edge(u, v, weight=new_weight, key=random_key())

    print(f"Edges generated: {graph.number_of_edges()}")

    graph_copy = graph.copy()
    new_edges = []

    start = 0
    while start < n:
        # Add one more edge from each node to another
        end = random.randint(0, n - 1)
        while start == end:
            end = random.randint(0, n - 1)
        new_weight = random.randint(MIN_WEIGHT, MAX_WEIGHT)
        graph.add_edge(start, end, weight=new_weight, key=random_key())
        new_edges.append((end, new_weight))

        start += 1
    
    # Added all positive edges, now change some to negative weights
    # Take care not to create negative cycles
    negative_edge_attempts = int(
        MAX_RATIO_OF_NEGATIVE_EDGES * graph.number_of_edges()
    )

    print(f"Attempting to create {negative_edge_attempts} negative edges.")
    negative_edge_additions = 0
    for _ in range(negative_edge_attempts):    
        u, v, key, data = random.choice(list(graph.edges(data=True, keys=True)))
        if data['weight'] < 0:
            continue
        new_weight = -data['weight']
        graph.remove_edge(u, v, key=key)
        new_key = random_key()
        graph.add_edge(u, v, weight=new_weight, key=new_key)
        if has_negative_weight_cycle_from_start(graph, u):
            # If this creates a negative cycle, revert the change
            graph.remove_edge(u, v, key=new_key)
            graph.add_edge(u, v, weight=data['weight'], key=key)
        else:
            negative_edge_additions += 1
            
    print(f"Negative edges added: {negative_edge_additions}")

    queries = []
    starts = set()
    # Generate queries
    while len(queries) < q:
        start = (
            random.randint(0, n - 1)
            if len(starts) < MAX_DIFFERENT_STARTS
            else random.choice(list(starts))
        )
        end = random.randint(0, n - 1)

        while start == end:
            end = random.randint(0, n - 1)

        queries.append((start, end))
        starts.add(start)

    assert len(new_edges) == n
    assert len(queries) == q
    assert graph.number_of_nodes() == n
    assert graph.number_of_edges() == m + n

    # Write to file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n} {m} {q}\n")
        edges = list(graph_copy.edges(data=True))
        random.shuffle(edges)
        for u, v, data in edges:
            f.write(f"{u} {v} {data['weight']}\n")

        for end, new_weight in new_edges:
            f.write(f"{end} {new_weight}\n")

        for start, end in queries:
            f.write(f"{start} {end}\n")

    assert n == graph.number_of_nodes()
    assert m + n == graph.number_of_edges()
    assert q == len(queries)
    print(
        f"Created test case {case_num}: n = {n}, m = {m}, q = {q}, edges = {graph.number_of_edges()}"
    )
    print(f"Negative weight cycle checks: {negative_cycle_checks}")


# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
