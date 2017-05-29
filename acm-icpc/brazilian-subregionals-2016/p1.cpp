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

vi adj[3];

int main(){
	ios_base::sync_with_stdio(false);
	ll mach[3];
	bool ans=false;
	cin >> mach[0] >> mach[1] >> mach[2];
	for(int i=1;i<8;++i){
		int aux = i, sum=0, k=0;
		int aux2, sum2;
		while(aux){
			sum += (aux%2)*mach[k];
			aux /= 2;
			k++;
		}
		for(int j=1;j<7;++j){
			aux2 = j, sum2=0, k=0;
			while(aux2){
				sum2 += (aux2%2)*mach[k];
				aux2 /= 2;
				k++;
			}
			if(sum == sum2 and !(i&j)) {
				ans = true;
			}
		}
	}
	cout << ((ans) ? "S" : "N") << endl;
	return 0;
}

