#include<bits/stdc++.h>
#define max 100
using namespace std;
class Sjf{
	public:
	int n,i;
	float b[max],at=0,tat=0.0,wt=0.0,stat=0.0,swt=0.0,atat,awt;
	void getdata(){
		cout<<"Enter number of processes= ";
		cin>>n;
		cout<<"Enter Bust time of the process\n";
		for(i=0;i<n;i++)
			cin>>b[i];
	}
	void time_cal(){
		sort(b,b+n);
		for(i=0;i<n;i++){
			tat+=b[i];
			wt=tat-b[i];
			cout<<"Turn around time= "<<tat<<"   "<<"Waiting time= "<<wt<<endl;
			stat+=tat;
			swt+=wt;
		}
	atat=stat/n;
	awt=swt/n;
	cout<<"\nAverage turn around time= "<<atat<<endl;
	cout<<"Average waiting time= "<<awt<<endl;		
	}
};
int main(){
	Sjf obj;
	obj.getdata();
	obj.time_cal();
	return 0;
}
