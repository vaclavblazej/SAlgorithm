#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void solveRatio(vector<Item *> & items, int maxWeight, ostream & os){
	long long bestCase = 0;
	vector<Idxes*> ratios;
	int size = items.size();
	for (int i = 0; i < size; ++i) {
		double ratio = items[i]->cost / (double) items[i]->weight;
		ratios.push_back(new Idxes(ratio, i));
	}
	sort(ratios.begin(), ratios.end(), sort_indexes());
	int cumulativeWeight = 0;
	int bestCost = 0;
	for (int i = 0; i < size; ++i) {
		if (cumulativeWeight + items[ratios[i]->index]->weight <= maxWeight){
			cumulativeWeight += items[ratios[i]->index]->weight;
			bestCost += items[ratios[i]->index]->cost;
			bestCase |= 1 << (ratios[i]->index);
		}
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

int approx(istream & is, ostream & os){
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
		solveRatio(items, maxWeight, os);
		os << endl;
		for (uint i = 0; i < items.size(); ++i) {
			delete items[i];
		}
	}

	return EXIT_SUCCESS;
}
