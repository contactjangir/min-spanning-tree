//Implement Prim's algorithm. 

#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair < int, int >iPair;

class Graph
{
  /* No. of vertices */
  int V;

  /* for weighted graph, we need to store vertex
     and weight pair for every edge */
    list < pair < int, int >>*adj;

public:
    Graph (int V);

  void addEdge (int u, int v, int w);

  /* Print MST using Prim's algorithm */
  void primMST ();
};

Graph::Graph (int V)
{
  this->V = V;
  adj = new list < iPair >[V];
}

void
Graph::addEdge (int u, int v, int w)
{
  adj[u].push_back (make_pair (v, w));
  adj[v].push_back (make_pair (u, w));
}

/* This function prints shortest paths from src vertex to all other vertices */
void
Graph::primMST ()
{
  // Create a priority queue to store vertices that are being primMST.
  priority_queue < iPair, vector < iPair >, greater < iPair > >pq;
  int min_weight = 0;

  // Take vertex 0 as source
  int src = 0;

  // Create a vector for keys and initialize all
  // keys as infinite (INF)
  vector < int >key (V, INF);

  // To store parent array which in turn store MST
  vector < int >parent (V, -1);

  // To keep track of vertices included in MST
  vector < bool > inMST (V, false);

  // Insert source itself in priority queue and initialize
  // its key as 0.
  pq.push (make_pair (0, src));
  key[src] = 0;

  /* Looping till priority queue becomes empty */
  while (!pq.empty ())
    {
      int u = pq.top ().second;
      pq.pop ();

      if (inMST[u] == true)
	{
	  continue;
	}

      inMST[u] = true;

      list < pair < int, int >>::iterator i;
      for (i = adj[u].begin (); i != adj[u].end (); ++i)
	{
	  int v = (*i).first;
	  int weight = (*i).second;

	  if (inMST[v] == false && key[v] > weight)
	    {
	      key[v] = weight;
	      min_weight += weight;
	      pq.push (make_pair (key[v], v));
	      parent[v] = u;
	    }
	}
    }

  printf ("Following are the edges in the constructed MST:\n");
  for (int i = 1; i < V; ++i)
    printf ("%d - %d\n", parent[i], i);
  printf ("Minimum Cost of the Spanning Tree: %d\n", min_weight);
}


int
main ()
{
  int V = 5;
  Graph g (V);

/*
 Let us create the following graph
         2        3
    (0)-----(1)------(2)
    |       / \      |
    |      /   \     |
    |     /     \    |
    6   8/       \5  |7
    |   /         \  |
    |  /           \ |
    | /             \|
    (3)-------------(4)
             9     
*/
  printf
    ("\nUsing Prim's algorithm to find a minimum spanning tree for the following Graph:\n");
  printf ("     2        3     \n");
  printf ("(0)-----(1)------(2)\n");
  printf ("|       / \\      |\n");
  printf ("|      /   \\     |\n");
  printf ("|     /     \\    |\n");
  printf ("6   8/       \\5  |7\n");
  printf ("|   /         \\  |\n");
  printf ("|  /           \\ |\n");
  printf ("| /             \\|\n");
  printf ("(3)-------------(4)\n");
  printf ("         9        \n");

  printf ("\n--------------------------------------------------\n");
  g.addEdge (0, 1, 2);
  g.addEdge (0, 3, 6);
  g.addEdge (1, 2, 3);
  g.addEdge (1, 3, 8);
  g.addEdge (1, 4, 5);
  g.addEdge (2, 4, 7);
  g.addEdge (3, 4, 9);

  g.primMST ();

  return 0;
}
