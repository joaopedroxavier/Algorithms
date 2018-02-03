#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int main(){
	ios_base::sync_with_stdio(false);
	int vl, va, candy=0;
	cin >> vl >> va;
	while((vl >= candy and candy%2) or (va >= candy and !(candy%2))){
		if(candy%2) vl -= candy;
		else va -= candy;
		candy++;
	}
	cout << ((candy%2) ? "Vladik" : "Valera") << endl;
	return 0;
}

