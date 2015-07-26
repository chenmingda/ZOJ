#include <iostream>
#include <vector>
using namespace std;
//DFS
vector<int> winner; // 记录每种可能情况下的胜者

void swap(int* i, int* j){
	int t;
	t=*i;
	*i=*j;
	*j=t;
	return;
}

void CrashBallon(int lower,int upper, int startPoint){
	int ballon=0;
	if(lower==1 && upper ==1){
		winner.push_back(3);
		return;
	}
	else if(lower != 1 && startPoint > 100){
		winner.push_back(2);
		return;
	}
	else if(lower == 1 && upper !=1 && startPoint > 100){
		winner.push_back(1);
		return;
	}
	for(int i=startPoint;i<=100;i++){
		if(lower%i==0){
			CrashBallon(lower/i,upper,i+1);
			ballon++;
		}
		if(upper%i==0){
			CrashBallon(lower,upper/i,i+1);
			ballon++;
		}
	}
	if(ballon==0){
		if(lower!=1)
			winner.push_back(2);
		else if(upper!=1)
			winner.push_back(1);
		else
			winner.push_back(3);
	}
	return;
}

int main(){
	int upper,lower;
	while(cin>>upper>>lower){
		int flag=0;
		int exist2=0,exist1=0;
		if(upper<lower)
			swap(&upper,&lower);
		CrashBallon(lower,upper,2);
		for(int i=0;i<winner.size();i++){
			// cout<<"winner["<<i<<"]:"<<winner[i]<<",";
			if(winner[i]==3){
				cout<<upper<<endl;
				flag=1;
				winner.clear();
				break;
			}
			else if(winner[i]==2)
				exist2++;
			else if(winner[i]==1)
				exist1++;
		}
		// cout<<endl;
		if(exist1 && flag==0){
			cout<<lower<<endl;
			winner.clear();
			continue;
		}
		if(exist2 && flag==0){
			cout<<upper<<endl;
			winner.clear();
			continue;
		}
		if(flag==0){
			cout<<upper<<endl;
			winner.clear();
		}
	}
}