import random
import os

import networkx as nx

# Configuration constants
FIRST_TESTCASE_NUM = 22   # Starting number for testcase files
NUM_TESTCASES = 0      # Number of testcase files to generate

MIN_N, MAX_N = 1, 2_000
MIN_Q, MAX_Q = 1, 500_000

MAX_CHILDREN_PER_NODE = 100
PRUNE_PROBABILITY = 0.9
OVERDEPTH_FACTOR = 0.1

# Create input directory if it doesn't exist
os.makedirs("input", exist_ok=True)

def generate_test_case(case_num):
    n = random.randint(MIN_N, MAX_N)
    q = random.randint(MIN_Q, MAX_Q)

    G = nx.Graph()
    G.add_node(0)  # Start with the first node

    curr_node = 0
    while G.number_of_nodes() < n:
        if curr_node >= G.number_of_nodes():
            print("Warning: Current node exceeds number of nodes in the graph. Stopping.")
            return
        
        # Randomly choose the number of children for the current node
        num_children = random.randint(1, MAX_CHILDREN_PER_NODE)

        # Ensure we don't exceed the number of nodes
        num_children = min(num_children, n - G.number_of_nodes())
        if curr_node > 0 and random.random() < PRUNE_PROBABILITY:
            num_children = 0

        for _ in range(num_children):
            new_node = G.number_of_nodes()
            G.add_node(new_node)
            G.add_edge(curr_node, new_node)

        curr_node += 1


    # Assert that the graph has exactly n nodes and n-1 edges
    assert G.number_of_nodes() == n, f"Generated graph has {G.number_of_nodes()} nodes, expected {n}."
    assert G.number_of_edges() == n - 1, f"Generated graph has {G.number_of_edges()} edges, expected {n-1}."
    
    # Ensure the graph is connected
    assert nx.is_connected(G), "Generated graph is not connected."
    
    # Ensure graph is a tree
    assert nx.is_tree(G), "Generated graph is not a tree."

    # Get list of distances from the root node (0) to all other nodes
    distances = nx.single_source_shortest_path_length(G, 0)
    distances_list = list(distances.values())
    
    # Ensure distances list is non-descreasing
    assert distances_list == sorted(distances_list), "Distances from root node are not non-decreasing."

    # Calculate the maximum depth of the tree
    tree_depth = nx.diameter(G)

    edges = list(G.edges())
    random.shuffle(edges)

    queries = []
    for _ in range(q):
        a = random.randint(0, n - 1)
        b = random.randint(0, n - 1)
        while a == b:
            b = random.randint(0, n - 1)
        d = random.randint(0, round(tree_depth*(1 + OVERDEPTH_FACTOR)))
        d = min(d, n-1)
        queries.append((a, b, d))

    # Create the input file
    with open(f"input/input{case_num}.txt", "w") as f:
        f.write(f"{n} {q}\n")
        for edge in edges:
            f.write(f"{edge[0]+1} {edge[1]+1}\n")
        for query in queries:
            f.write(f"{query[0]+1} {query[1]+1} {query[2]}\n")

    
    print(f"Created test case {case_num}: n = {n}, q = {q}, max_depth = {tree_depth}, edges = {len(edges)}")

# Generate the test cases
for i in range(FIRST_TESTCASE_NUM, FIRST_TESTCASE_NUM + NUM_TESTCASES):
    generate_test_case(i)

print(f"Successfully created {NUM_TESTCASES} test cases in the 'input' folder.")
