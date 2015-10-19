
struct Item {
    int weight, cost;
};

struct Idxes {
    Idxes(double ratio, int index):ratio(ratio),index(index){};
    double ratio;
    int index;
};

struct sort_indexes{
    bool operator() (const Idxes* struct1, const Idxes* struct2) {
        return (struct1->ratio > struct2->ratio);
    };
};
