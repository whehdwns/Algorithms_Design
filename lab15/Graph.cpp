//ENQUEUE	pg 235
//DEQUEUE	pg 235
//BFS		pg 595

//whehdwns

#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
    edges.insert(make_pair(make_pair(vert1, vert2), weight));
}

bool Graph::FindVertex(string vert1) {
    list<string>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++) 
	{
		if (*it == vert1) 
		{
			return true;
		}
	}
	return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
    map<pair<string, string>, int>::iterator it = edges.find(make_pair(vert1, vert2));

	if (it == edges.end()) 
	{
		return -1;
	}
	else 
	{
		return it->second;
	}
}

int Graph::IsReachable(string vert1, string vert2) {
    queue<string> q;
	string y, w;
	list<string>::iterator it;
	map<string, string> color;
	map<string, int> length;
	map<string, string>predecessor;
	map<pair<string, string>, int>::iterator maps;

	if (vert1 == vert2) 
	{
		return 0;
	}

	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		color[(*it)] = "WHITE";
		length[(*it)] = INT_MAX;
		predecessor[(*it)] = "NIL";
	}
	color[vert1] = "GRAY";
	length[vert1] = 0;
	predecessor[vert1] = "NIL";
	q.push(vert1);// INQUEUE

	while ( !q.empty()) 
	{
		y = q.front();
		q.pop();//DEQUEUE
		for (maps = edges.begin(); maps != edges.end(); maps++)
		{
			if (maps->first.first == y) 
			{
				if (color[maps->first.second] == "WHITE")
				{
					w = maps->first.second;
					color[w] = "GRAY";
					length[w] = length[y] + 1;
					predecessor[w] = y;
					q.push(w);//ENQUEUE
					if (w == vert2) 
					{
						return length[w];
					}
				}
			}
		}
		color[y] == "BLACK";
	}
	return -1;
}

int main() {
    Graph G;
    int weight, op;
	string parameter, A, B;

	cin >> parameter;
	while (parameter != "END") 
	{
		G.vertices.push_back(parameter);
		cin >> parameter;
	}

	cin >> parameter;
	while (parameter != "END") 
	{
		A = parameter;
		cin >> parameter;
		B = parameter;
		cin >> weight;
		if (G.FindVertex(A) && G.FindVertex(B)) {
			G.AddEdge(A, B, weight);
		}
		cin>>parameter;
	}

	G.PrintOut();

	cin >> op;
	while (op != 0) {
		switch (op)
		{
		case 1:
			cin >> A;
			cout << G.FindVertex(A) << endl;
			break;
		case 2:
			cin >> A;
			cin >> B;
			cout << G.FindEdgeCost(A, B) << endl;
			break;
		case 3:
			cin >> A;
			cin >> B;
			cout << G.IsReachable(A, B) << endl;
			break;
		}
		cin >> op;
	}
}
