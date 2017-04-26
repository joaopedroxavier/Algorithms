//
//	(C - Voting)
//	CodeForces Round #388 Div.2
//	source: http://codeforces.com/contest/749/problem/C
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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

queue<char> vote;
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		char c;
		cin >> c;
		vote.push(c);
	}
	int tam = 1;
	bool cnt = true;
	while(cnt){
		char u = vote.front();
		vote.push(vote.front());
		vote.pop();
		tam = 1;
		while(tam){
			char v = vote.front();
			if(v == u){
				tam++;
				vote.push(vote.front());
			}
			else tam--;
			vote.pop();
			if(tam >= (int)vote.size()){
				cnt = false;
				break;
			}
		}
	}
	cout << vote.front() << endl;
}	
