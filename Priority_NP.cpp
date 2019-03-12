#include<iostream>
#define max 100
using namespace std;
class Priority{
	public:
		int n,i,j;
		float pr[max],b[max],a[max],ct=0,tat=0,wt=0,stat=0,atat=0,swt=0,awt=0;
		
		void getdata(){
			cout<<"Enter number of processes = ";
			cin>>n;
			cout<<"Enter arrival time of each process\n";
			for(i=0;i<n;i++)	
				cin>>a[i];
			cout<<"Enter burst time of each process\n";
			for(i=0;i<n;i++)
				cin>>b[i];
			cout<<"Enter priority of each process\n";
			for(i=0;i<n;i++)
				cin>>pr[i];	
		}
		
		void cal(){
			//sorting..................................
				for (j=i+1;j<n;j++) {
         			if (pr[i]<pr[j]) {
            			int temp=pr[j];
            			pr[j]=pr[i];
            			pr[i]=temp;
 
            			temp=b[j];
            			b[j]=b[i];
            			b[i]=temp;
            		}
         }			
         //Sorting....................................
		 	for(int i=0;i<n;i++){
				if(ct>a[i]){
					ct+=b[i];
					tat=ct-a[i];
					wt=tat-b[i];
				cout<<"Turn around time "<<tat<<"        "<<"Waiting time "<<wt<<endl;		
				}
				else{
					ct=0.0;
					ct=a[i]+b[i];
					tat=ct-a[i];
					wt=tat-b[i];
					cout<<"Turn around time "<<tat<<"        "<<"Waiting time "<<wt<<endl;			
				}
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
	Priority obj;
	obj.getdata();
	obj.cal();
	return 0;
}