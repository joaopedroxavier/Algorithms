#include <bits/stdc++.h>

using namespace std;

map<string, int> nvotes;
map<string, string> party;
vector<string> cand;

int n, m;

bool check(string s) {
	for(string t : cand) if(s != t and nvotes[t] >= nvotes[s]) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	string buf;
	getline(cin, buf);
	for(int i=0; i<n; i++) {
		string s, t;
		getline(cin, s);
		getline(cin, t);
		party[s] = t;
		cand.push_back(s);
	}
	scanf("%d", &m);
	getline(cin, buf);
	for(int i=0; i<m; i++) {
		string s;
		getline(cin, s);
		nvotes[s]++;
	}
	for(string s : cand) if(check(s)) return printf("%s\n", party[s].c_str()), 0;
	printf("tie\n");
	return 0;
}
