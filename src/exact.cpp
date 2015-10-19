#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void solveExact(vector<Item *> & items, int maxWeight, ostream & os){
	int size = items.size();
	long long bit = 0;
	long long end = 1 << size;

	long long bestCase = 0;
	int bestCost = 0;

	// test every possible combination
	while (bit < end) {
		int weight = 0;
		int cost = 0;
		for (int i = 0; i < size; ++i) {
			if ((bit & (1 << i)) != 0) {
				weight += items[i]->weight;
				cost += items[i]->cost;
			}
		}
		if (weight <= maxWeight && cost > bestCost) {
			bestCase = bit;
			bestCost = cost;
		}
		++bit;
	}

	os << bestCost << ' ';
	int weight = 0;
	for (int i = 0; i < size; ++i) {
		if ((bestCase & (1 << i)) != 0) {
			weight += items[i]->weight;
			os << ' ' << 1;
		} else {
			os << ' ' << 0;
		}
	}

	return;
}


int exact(istream & is, ostream & os){
	srand(time(NULL));

	int id, itemNumber, maxWeight;
	for (int i = 0; i < 50; ++i) {
		vector<Item *> items;
		is >> id >> itemNumber >> maxWeight;
		for (int i = 0; i < itemNumber; ++i) {
			items.push_back(new Item());
			is >> items[i]->weight >> items[i]->cost;
		}
		os << id << ' ' << itemNumber << ' ';
		solveExact(items, maxWeight, os);
		os << endl;
		for (uint i = 0; i < items.size(); ++i) {
			delete items[i];
		}
	}

	return EXIT_SUCCESS;
}
