// MINIMUM SPANNING TREE		Chapter 23	
//Priority Queues				pg 162
//		a min-priority queue supports the operations INSERT ,MINIMUM , EXTRACT-MIN ,and DECREASE-KEY .
//PRIM's Algorithm				pg 634

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> Graph;

class CreateGraph	
{
public:
	int Vertex;
		
	list<pair<int, int> > *adjacencyList;

	CreateGraph(int Vertex)
	{
		adjacencyList = new list<pair<int, int>>[Vertex];
	}

	void PRIMS(int Vertex)
	{
		priority_queue<Graph, vector<Graph>, greater<Graph> > PQ;
		vector<int> key(Vertex, numeric_limits<int>::max());
		vector<int> parent(Vertex);
		vector<int> visited(Vertex);

		PQ.push(pair<int, int>(0, 0));
		while (!PQ.empty())
		{
			int u = PQ.top().second;
			PQ.pop();
			visited[u]=1;
			list<pair<int, int> >::iterator i;
			for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); i++)
			{
				int v = (*i).first;
				if (key[v] > (*i).second && !visited[v])
				{
					key[v] = (*i).second;
					PQ.push(pair<int, int>(key[v], v));
					parent[v] = u;
				} 
			}
		}
		for (int i = 1; i < Vertex; i++)
		{
			cout << parent[i] << endl;
		}
	}
};

int main()
{
	int V, E, u, v, w;
	cin >> V >> E;
	CreateGraph G(V);
	for (int i = 1; i <= E; i++)
	{
		cin >> u >> v >> w;
		G.adjacencyList[v].push_back(make_pair(u, w));
		G.adjacencyList[u].push_back(make_pair(v, w));
	}
	G.PRIMS(V);

	return 0;
}
