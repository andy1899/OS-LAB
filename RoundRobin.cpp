#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	cout<<"Enter the number of processes:";
	cin>>n;
	float BT[n],RBT[n],CT[n],TAT[n],WT[n],t=0,tq,avWT=0,avTAT=0,avCT=0;
	cout<<"Enter the details of "<<n<<" processes.\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter Burst time of process"<<i+1<<":";
		cin>>BT[i];
		RBT[i]=BT[i];
	}
	cout<<"Enter the time quantum:";
	cin>>tq;
	bool done;
	do
	{
	done=false;
	for(i=0;i<n;i++)
	{
	  if(RBT[i]>0)
	  {
	   done=true;
	   if(RBT[i]>tq)
	   { t+=tq;
	     RBT[i]-=tq;
	   }
	   else 
	   {
	     t+=RBT[i];
		 RBT[i]=0;
		 CT[i]=t;//Completion time is given its value
		 WT[i]=t-BT[i];//Waiting Time is calculated
      	 TAT[i]=t;//Turn Around Time is calculated
	   }
      }
   }
   }while(done);
	for(i=0;i<n;i++)
	{	avTAT+=TAT[i];
		avWT+=WT[i];
		avCT+=CT[i];
		cout<<"\nProcess "<<i+1;
		cout<<"\nCompletion time:   "<<CT[i];
		cout<<"\nTurn Around time:  "<<TAT[i];
		cout<<"\nWaiting time:      "<<WT[i]<<"\n";
	}
	cout<<"\nAverages:";
    cout<<"\nCompletion time:   "<<avCT/n;
	cout<<"\nTurn Around time:  "<<avTAT/n;
	cout<<"\nWaiting time:      "<<avWT/n;
}
    
