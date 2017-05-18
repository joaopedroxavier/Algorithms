//
//	(Ada and Queue)
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/ADAQUEUE/
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e5;
const int INF=0x3f3f3f3f;

int key=0;
int main(){
	ios_base::sync_with_stdio(false);
	int q;
	deque<int> d[2];
	cin >> q;
	for(int i=0;i<q;++i){
		string s;
		cin >> s;
		if(s == "toFront"){
			int n;
			cin >> n;
			d[key].push_front(n);
			d[(key+1)%2].push_back(n);
		}
		if(s == "push_back"){
			int n;
			cin >> n;
			d[key].push_back(n);
			d[(key+1)%2].push_front(n);
		}
		else if(s == "front"){
			if(d[key].empty()) cout << "No job for Ada?" << endl;
			else{
				cout << d[key].front() << endl;
				d[key].pop_front();
				d[(key+1)%2].pop_back();
			}
		}
		else if(s == "back"){
			if(d[key].empty()) cout << "No job for Ada?" << endl;
			else{
				cout << d[key].back() << endl;
				d[key].pop_back();
				d[(key+1)%2].pop_front();
			}
		}
		else if(s == "reverse"){
			key = (key+1)%2;
		}
	}
	return 0;
}

