//
//	(B - Mamooth's Genome Decoding)
//	CodeForces Round #387 Div.2
//	source: http://codeforces.com/contest/747/problem/B
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << ",  " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int a, g, c, t;
int main(){
	ios::sync_with_stdio(false);
	string gen;
	int n;
	cin >> n;
	cin >> gen;
	for(char u : gen){
		if(u == 'A') a++;
		else if(u == 'G') g++;
		else if(u == 'C') c++;
		else if(u == 'T') t++;
	}
	if(n%4!=0){
		cout << "===" << endl;
		return 0;
	}
	else if(a>n/4 or g>n/4 or c>n/4 or t>n/4){
		cout << "===" << endl;
		return 0;
	}
	else{
		for(int i=0;i<(int)gen.size();++i){
			if(gen[i] == '?'){
				if(a<n/4) a++, gen[i] = 'A';
				else if(g<n/4) g++, gen[i] = 'G';
				else if(c<n/4) c++, gen[i] = 'C';
				else t++, gen[i] = 'T';
			}
		}
		cout << gen << endl;
	}
	return 0;
}

