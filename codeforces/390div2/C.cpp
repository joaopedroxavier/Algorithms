//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string users[N];
string msg[N];
string sender[N];
set<string> in_msg[N];
int pos[N];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int q=0;q<t;++q){
		int n, m;
		bool ans = true;
		cin >> n;
		for(int i=0;i<n;++i) cin >> users[i];
		cin >> m;
		for(int i=0;i<m;++i) in_msg[i].clear();
		getline(cin, msg[0]);
		for(int i=0;i<m;++i) getline(cin, msg[i]);
		for(int i=0;i<m;++i){
			pos[i] = msg[i].find(":");
			sender[i] = msg[i].substr(0,pos[i]);
			msg[i] = msg[i].substr(pos[i]);
		}
		for(int i=0;i<m;++i) for(int j=0;j<n;++j) in_msg[i].insert(users[j]);
		for(int i=0;i<m;++i){
			if(sender[i] != "?") in_msg[i].clear(), in_msg[i].insert(sender[i]);
			else{
				if(i>0 and sender[i-1] != "?") in_msg[i].erase(sender[i-1]);
				if(i<m-1 and sender[i+1] != "?") in_msg[i].erase(sender[i+1]);
				for(int j=0;j<n;++j){
					if(msg[i].find(users[j])!=string::npos){
						in_msg[i].erase(users[j]);
					}
				}
			}
			if(in_msg[i].size() == 1){
				sender[i] = *(in_msg[i].begin());
			}
		}
		for(int i=0;i<m;++i) if(in_msg[i].size() < 1) ans = false;
		for(int i=0;i<m;++i) if(sender[i] == "?") sender[i] = *(in_msg[i].begin());
		for(int k=0;k<m;++k){
			bool cont = false;
			for(int i=0;i<m;++i){
				auto it = in_msg[i].find(sender[i]);
				if(i>0 and sender[i] == sender[i-1]){
					it = next(it);
					if(it == in_msg[i].end()){
						ans = false;
						break;
					}
					sender[i] = *it, cont = true;
				}
				if(i<n-1 and sender[i] == sender[i+1]){
					it = next(it);
					if(it == in_msg[i].end()){
						ans = false;
						break;
					}
					sender[i] = *it, cont = true;
				}
			}
			if(!cont) break;
		}
		if(!ans) cout << "Impossible" << endl;
		else{
			for(int i=0;i<m;++i){
				cout << sender[i] << msg[i] << endl;
			}
		}
	}
	return 0;
}

