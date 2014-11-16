#include <vector>
#include <map>
#include <limits.h>
using namespace std;

/**
 * Converts a graph into an adjacency matrix. The graph is a map where the key of each element is a vertex of type T and the value is a vector of the neighbor vertices.
 */
template<class T>
int** convertGraphToAdjacencyMatrix(map<T, vector<T> > graph) {
	map<T, int> indexMap;
	map<int, T> reverseIndexMap;
	generateIndexMap(graph, indexMap, reverseIndexMap);
	int numVertices = graph.size();
	int** adjacencyMatrix = new int*[numVertices];
	typename map<T, vector<T> >::iterator it = graph.begin();
	int index = 0;
	while (it != graph.end()) {
		adjacencyMatrix[index] = new int[numVertices];
		for (int i = 0; i < numVertices; i++) {
			if (i == index) {
				adjacencyMatrix[index][i] = 0;
			} else {
				adjacencyMatrix[index][i] = SHRT_MAX;
			}
		}

		for (unsigned int i = 0; i < it->second.size(); i++) {
			adjacencyMatrix[index][indexMap[it->second[i]]] = 1;
		}
		index++;
		it++;
	}

	return adjacencyMatrix;
}

/**
 * This utility function is used by some graph related functions. It generates a map between the actual graph vertices and integer indices.
 * Doing this facilitates using different graph algorithms that represent vertices using integer values.
 */
template<class T>
void generateIndexMap(map<T, vector<T> > graph, map<T, int>& indexMap,
		map<int, T>& reverIndexMap) {
//	map<T, int> indexMap;
	int index = 0;
	typename map<T, vector<T> >::iterator it = graph.begin();
	while (it != graph.end()) {
		indexMap[it->first] = index;
		reverIndexMap[index] = it->first;
		index++;
		it++;
	}
}
