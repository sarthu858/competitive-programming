#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void subset(char *a, int n){
	for(int i=0; i<(1<<n); i++){
		cout<<"{ ";
		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				cout<<a[j]<<" ";
			}
		}cout<<"}"<<endl;
	}
}

int main() {
	int n;
	cin>>n;
	char a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	subset(a,n);
	return 0;

}
