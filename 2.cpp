// Author : Sarthak Sharma
// Date: 2021-12-04 19:11

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define lb lower_bound
#define up upper_bound
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)
#define fbo find_by_order
#define oof order_of_key
#define all(a) a.begin(), a.end()

using namespace std;
using namespace __gnu_pbds;

// <------------------------------------- Templates ------------------------------------->
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> void _print(T arg) { cerr << arg << endl; }

template <class T> void _print(vector<T> &a) { for(auto &it: a) { cerr << it << tab1; }cerr << endl; }

// <------------------------------------- Code ------------------------------------->

const int N = 1e5 + 10;
const int mod = 1e9;
vi a;

bool subset_sum(int n, int sum, int k, int sz) {
	cerr << sum << tab1 << sz << endl;
	if(sz > 1 && sum % k == 0) {
		return true;
	}
	if(n <= 0) {
		return false;
	}
	if(subset_sum(n - 1, sum + a[n - 1], k, sz + 1) || subset_sum(n - 1, 0, k, 0)) {
		return true;
	}
	return false;
}

	vector<vector<bool>> isP;
	vector<vector<string>> ans;
	void solve(string s, int st, vector<string> tmp) {
		if(st == s.size()) {
			ans.push_back(tmp);
			return;
		}
		for(int i = st; i < s.size(); i++) {
			if(isP[st][i]) {
				tmp.push_back(s.substr(st, i - st + 1));
				solve(s, i + 1, tmp);
				tmp.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		int n = s.size();
		isP = vector<vector<bool>>(n, vector<bool>(n, 0));
		for(int k = 0; k < n; k++) {
			int i = 0, j = k;
			while(i < n && j < n) {
				if(i == j) isP[i][j] = 1;
				else if(i + 1 == j && s[i] == s[j]) isP[i][j] = 1;
				else if(s[i] == s[j] && isP[i + 1][j - 1]) isP[i][j] = 1;
				i++, j++;
			}
		}
		solve(s, 0, {});
		return ans;
	}

int main() {
	clock_t begin_69 = clock();
	fast_io;
	int n, k;
	// cin >> n >> k;
	// a = vi();
	// rep(i, 0, n) {
	// 	cin >> a[i];
	// }
	// char a = '9', b = '9';
	// int rem = 0;
	// string currProd = to_string((a - '0') * (b - '0') + rem);
	// _print((a - '0') * (b - '0') + rem);
	// _print((a - '0'));
	// _print((b - '0'));
	// ll l = 1;
	// ll p = ((123456789 * l) * (80000000 * 1)) + 944977892635269;
	// cout << fixed << p;

	vector<vector<string>> ans = partition("aab");
	for(auto i: ans) {
		for(auto j: i) {
			cout << j << tab1;
		}cout << endl;
	}
	
	// cout << currProd << tab1 << currProd.size();
	// cout << subset_sum(n, 0, k, 0) << endl;
	#ifndef ONLINE_JUDGE
		clock_t terminator_69 = clock();
		cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	#endif 
	return 0;
}
