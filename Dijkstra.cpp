#include <bits/stdc++.h>
using namespace std;

template<typename T>//Template with which we can add any data type 
class Graph {//class graph 
	map<T, list<pair<T, int>>> l;//declaration of nested map  l with T and list of pairs

public://public object
	void addEdge(T x, T y, int wt) {//function addEdge will add anew edge in the graph
		l[x].push_back({y, wt});
		l[y].push_back({x, wt});//to make the graph unidirectional just remove this line
//These line will make the graph directional 
	}

	void print() {
		for (auto p : l) {
			T node = p.first;
			cout << node << " -> ";

			for (auto nbr : l[node]) {
				cout << "(" << nbr.first << "," << nbr.second << ") ";
			} cout << endl;
		}
	}

	void djikstraSSSP(T src) {

		map<T, int> dist;

		// Initialising dist to inf
		for (auto p : l) {
			T node = p.first;
			dist[node] = INT_MAX;
		}
		dist[src] = 0;

		// set created to get the min dist element at the beginning
		// 		dist, node
		set<pair<int, T>> s;
		s.insert({dist[src], src});

		while (!s.empty()) {

			pair<int, T> p = *s.begin();//defining pair T of int and T
			s.erase(s.begin());
			T currNode = p.second;
			int currNodeDist = p.first;

			// visit all nbrs of node
			for (auto nbr : l[currNode]) {//range based loop
				T nbrNode = nbr.first;
				int distInBetween = nbr.second;
				int nbrNodeDist = dist[nbrNode];

				// Potential new distance = currNodeDist + distInBetween
				if (currNodeDist + distInBetween < nbrNodeDist) {

					// Update dist in both set and map
					// If node not present in set then add it
					auto pr = s.find({dist[nbrNode], nbrNode});
					if (pr != s.end()) {
						s.erase(pr);
					}
					dist[nbrNode] = currNodeDist + distInBetween;
					s.insert({dist[nbrNode], nbrNode});
				}
			}

		}

		for (auto x : dist) {
			cout << x.first << " is at distance " << x.second << " from source" << endl;
		}



	}

};

int main() {

	Graph<string> g;

	g.addEdge("Amritsar", "Delhi", 1);//Adding some edges in the graph
	g.addEdge("Amritsar", "Jaipur", 4);
	g.addEdge("Delhi", "Jaipur", 2);
	g.addEdge("Mumbai", "Jaipur", 8);
	g.addEdge("Bhopal", "Agra", 2);
	g.addEdge("Mumbai", "Bhopal", 3);
	g.addEdge("Agra", "Delhi", 1);

	g.print();
	cout << endl;
	g.djikstraSSSP("Amritsar");
	cout << endl;
	g.djikstraSSSP("Delhi");
}
