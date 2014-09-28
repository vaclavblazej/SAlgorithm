#include <iostream>
#include <vector>
#include <string>
#define REP(i,a) for(int i = 0; i < a; i++)

using namespace std;

vector<int> find(string pattern, string text){
	vector<int> result;
	int patternLength = pattern.length();
	int textLength = text.length();
	int len = textLength - patternLength + 1;
	REP(i, len){
		bool flag = true;
		REP(j, patternLength){
			flag &= (pattern[j] == text[i + j]);
			if(!flag) break;
		}
		if(flag) result.push_back(i);
	}
	return result;
}

int main(){
	vector<int> res = find("alfa", "alalfalfaalfalfa");
	while(!res.empty()){
		cout << res[0] << endl;
		res.erase(res.begin());
	}
}
