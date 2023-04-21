#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int main(){
	
	speed;
	boost;
	
	int T;
	cin>>T;
	
	while(T--){
		lld n;
		cin>>n;
		
		priority_queue<lld,vector<lld>,greater<lld>> queue;//syntax for min priority queue
		
		for(lld i=0;i<n;i++){
			lld x;
			cin>>x;
			queue.push(x);
		}
		
		lld sum=0;
		while(queue.size()>1){
			lld a= queue.top();
			queue.pop();
			lld b= queue.top();
			queue.pop();
			
			sum+= (a+b);
			queue.push((a+b));
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}
