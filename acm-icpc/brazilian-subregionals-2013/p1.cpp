#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	while(1){
		cin >> a >> b >> c;
		if(cin.eof()) break;
		if(a == b){
			cout << ((b == c) ? "*" : "C") << endl;
		}
		else if(b == c){
			cout << ((c == a) ? "*" : "A") << endl;
		}
		else if(c == a){
			cout << ((a == b) ? "*" : "B") << endl;
		}
	}
	return 0;
}
