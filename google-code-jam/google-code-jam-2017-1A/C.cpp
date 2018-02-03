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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int num_per_cycle(int hd, int ad, int ak, int hk){
	int cont=0;
	while(hd - ak > 0){
		hd -= ak;
		hk -= ad;
		cont++;
		if(hk < 0){
			cont--;
			break;
		}
	}
	cont++;
	return cont;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int q=0;q<t;++q){
		int hd, ad, hk, ak, b, d, m = INF;
		bool can = true;
		cin >> hd >> ad >> hk >> ak >> b >> d;
		if(ad > hk) m = 1;
		else if((hk <= 2*ad or hk <= ad+b) and (hd > ak)) m = 2;
		else if(hd <= 2*(ak-d)) can = false;
		else{
			int hd1 = hd, hk1 = hk;
			int ak1[] = {ak, ak, min(ak-d, 0), min(ak-d, 0)};
			int ad1[] = {ad, ad+b, ad, ad+b};
			int ans[] = {0, 1, 1, 2};
			for(int i=0;i<4;++i){
				if(hd1 - ak1[i] < 0) continue;
				while(hk1 > 0){
					while(hd1 - ak1[i] > 0){
						hd1 -= ak1[i];
						hk1 -= ad1[i];
						ans[i]++;
						if(hk1 <= 0){
							ans[i]--;
							break;
						}
					}
					ans[i]++;
					hd1 = hd;
				}
				m = min(m, ans[i]);
				hk1 = hk;
			}
		}
		cerr << m << endl;
		cout << "Case #" << q+1 << ": ";
		if(can) cout << m << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

