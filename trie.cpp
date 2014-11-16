/*
 * trie.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: Kareem
 */
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <queue>
using namespace std;

struct Node {
	Node* parent;
	Node* children[26];
	string word;

	Node() :
			children() {
	}
};

struct Trie {
	Node* root;

	Trie() {
		root = new Node;
	}

	void insert(string word) {
		Node* current = root;
		unsigned int length = word.length();
		for (unsigned int i = 0; i < length; i++) {
			int charIndex = word[i] - 'a';
			if (current->children[charIndex] == NULL) {
				current->children[charIndex] = new Node;
				current->children[charIndex]->parent = current;
			}
			current = current->children[charIndex];
		}
		current->word = word;
	}
};

list<string> findDoublet(Trie* trie, string word) {
	list<string> doublets;
	Node* current = trie->root;
	unsigned int length = word.length();
	for (unsigned int i = 0; i < length; i++) {
		for (unsigned int j = 0; j < 26; j++) {
//			cout << (current->children[(word[j] - 'a')] != NULL) << endl;
			if ((j != (word[i] - 'a')) && current->children[j] != NULL) {
				Node* searchNode = current->children[j];
				unsigned int k;
				for (k = i + 1; k < length; k++) {
					int charIndex = word[k] - 'a';
					if (searchNode->children[charIndex] == NULL) {
						break;
					}
					searchNode = searchNode->children[charIndex];
				}
				if (k == length) {
					doublets.insert(doublets.end(), searchNode->word);
				}
			}
		}
		current = current->children[word[i] - 'a'];
	}

	return doublets;
}

//list<string> bfs(Trie* dictionary, string start, string end) {
//
//	queue<string> fringe;
//	set<string> discovered;
//	set<string> processed;
//	map<string, string> parent;
//
//	discovered.insert(start);
//	fringe.push(start);
//	while (fringe.empty() == false) {
//		string front = fringe.front();
//		fringe.pop();
//		if (front.compare(end) == 0) {
//			break;
//		}
//		processed.insert(front);
//		list<string> neighbors = findDoublest(dictionary, front);
//		list<string>::iterator nIt = neighbors.begin();
//		while (nIt != neighbors.end()) {
//			string neighbor = (*nIt);
//			if (discovered.find(neighbor) == discovered.end()) {
//				fringe.push(neighbor);
//				discovered.insert(neighbor);
//				parent[neighbor] = front;
//			}
//			nIt++;
//		}
//	}
//
//	list<string> path;
//	if (parent.find(end) != parent.end()) {
//		string current = end;
//		while (current.compare(start) != 0) {
//			path.insert(path.begin(), current);
//			current = parent[current];
//		}
//		path.insert(path.begin(), current);
//	}
//
//	return path;
//
//}
