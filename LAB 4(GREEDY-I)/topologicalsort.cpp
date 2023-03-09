#include <iostream>
#include <stack>

using namespace std;

const int MAX_NODES = 100005; // maximum number of nodes

int n, m; // number of nodes and edges
int adj[MAX_NODES]; // adjacency list
int head[MAX_NODES]; // head of the adjacency list
int nxt[MAX_NODES]; // next of the adjacency list
int to[MAX_NODES]; // to of the adjacency list
int vis[MAX_NODES]; // visited array
int ans[MAX_NODES]; // answer array
int cnt; // counter for the answer array

// function to add edge to the adjacency list
void addEdge(int u, int v) {
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

// function to perform DFS
void dfs(int u, stack<int>& s) {
    vis[u] = 1; // mark node as visited

    for (int i = head[u]; i != -1; i = nxt[i]) { // loop through all neighbors of the node
        int v = to[i];

        if (!vis[v]) { // if neighbor is not visited, perform DFS on it
            dfs(v, s);
        }
    }

    s.push(u); // add node to the topological sort stack
}

// function to perform topological sort
void topoSort() {
    stack<int> s; // stack for topological sort

    // perform DFS on all nodes
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, s);
        }
    }

    // retrieve the nodes in the topological order
    while (!s.empty()) {
        ans[cnt++] = s.top();
        s.pop();
    }
}

int main() {
    cin >> n >> m; // read input

    // initialize arrays
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));

    // read input and add edges to the adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    topoSort(); // perform topological sort

    // output the nodes in the topological order
    for (int i = cnt - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
