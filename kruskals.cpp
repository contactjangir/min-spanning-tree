#include <bits/stdc++.h>

using namespace std;

class DSU
{
  int *parent;
  int *rank;

public:
    DSU (int n)
  {
    parent = new int[n];
      rank = new int[n];

    for (int i = 0; i < n; i++)
      {
	parent[i] = -1;
	rank[i] = 1;
      }
  }

  // Find function
  int find (int i)
  {
    if (parent[i] == -1)
      return i;

    return parent[i] = find (parent[i]);
  }
  // union function
  void unite (int x, int y)
  {
    int s1 = find (x);
    int s2 = find (y);

    if (s1 != s2)
      {
	if (rank[s1] < rank[s2])
	  {
	    parent[s1] = s2;
	    rank[s2] += rank[s1];
	  }
	else
	  {
	    parent[s2] = s1;
	    rank[s1] += rank[s2];
	  }
      }
  }
};

class Graph
{
  vector < vector < int >>edgelist;
  int V;

public:
    Graph (int V)
  {
    this->V = V;
  }

  void addEdge (int x, int y, int w)
  {
    edgelist.push_back (
			 {
			 w, x, y});
  }

  void kruskals_mst ()
  {
    // Step 2. Sort all edges
    sort (edgelist.begin (), edgelist.end ());

    // Initialize the DSU
    DSU s (V);
    int ans = 0;
    cout << "--------------------------------------------------" << endl;
    cout << "\nFollowing are the edges in the " "constructed MST" << endl;
  for (auto edge:edgelist)
      {
	int w = edge[0];
	int x = edge[1];
	int y = edge[2];

	// take that edge in MST if it does form a cycle
	if (s.find (x) != s.find (y))
	  {
	    s.unite (x, y);
	    ans += w;
	    cout << x << " -- " << y << " == " << w << endl;
	  }
      }
    cout << "\nMinimum Cost Spanning Tree: " << ans << endl << endl;
  }
};

int
main ()
{
  /* Let us create following weighted graph
     10
     0--------1
     |  \     |
     6|   5\   |15
     |      \ |
     2--------3
     4       */
  cout <<
    "\nUsing Kruskal's algorithm to find a minimum spanning tree for the following Graph:"
    << endl;
  cout << "     10     " << endl;
  cout << " 0----------1" << endl;
  cout << " | \\        |" << endl;
  cout << " |  \\       |" << endl;
  cout << " |   \\      |" << endl;
  cout << "6|    \\ 5   |15" << endl;
  cout << " |     \\    |" << endl;
  cout << " |      \\   |" << endl;
  cout << " |       \\  |" << endl;
  cout << " 2----------3" << endl;
  cout << "      4     " << endl;

  Graph g (4);
  g.addEdge (0, 1, 10);
  g.addEdge (1, 3, 15);
  g.addEdge (2, 3, 4);
  g.addEdge (2, 0, 6);
  g.addEdge (0, 3, 5);

/*     int n, m;
     cout << "Enter number of vertices and Edges in G(V,E):";
     cin >> n >> m;
 
     Graph g(n);
     for (int i = 0; i < m; i++)
     {
         int x, y, w;
         cin >> x >> y >> w;
         g.addEdge(x, y, w);
     }
 */
  g.kruskals_mst ();
  return 0;
}
