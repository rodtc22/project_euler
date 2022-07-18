#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;

template <typename T> ostream& operator << (ostream & os, const vector<T>& v){os <<"["; for(int i = 0 ;i < v.size() ;i++){if(i) os <<", "; os << v[i];} os <<"]"; return os;}
template <typename T> istream& operator >> (istream & is, vector<T>& v){ for(auto &x : v) is >> x; return is;}

void printe(){}
template <typename H, typename ...T>
void printe(H h, T ...t){
	cout << ", " << h;
	printe(t...);
}
#define er(args...) {cout <<"DBG: " << #args <<"= {"; printe(args); cout << "}\n";}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	#endif

	string nro;
	string s;
	while(cin >> s)
		nro.append(s);
	
	int k = 13,n = nro.size();
	ll ans = 0;
	for(int i = 0 ;i <= n-k ;i++){
		ll acu = 1;
		for(int j = 0 ;j < k ;j++)
			acu = acu * (nro[i+j]-'0');
		ans = max(ans,acu);
	}
	cout << ans << endl;
	return 0;
}