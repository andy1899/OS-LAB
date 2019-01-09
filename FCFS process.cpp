#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,j,k;
	cout<<"Enter no of process"<<endl;
	cin>>n;
	int burst[n],wat[n],tat[n],pro[n];
	for(int i=0;i<n;i++)
	{
	cin>>burst[i];
    }
	sort(burst,burst+n);
	//*******************************
	for(int i=0;i<n;i++)
	{
		j=i;
	   if(i==0)
	    wat[0]=0;
	   else
	    while(j>=1)
	    {
	     wat[j]=wat[j-1]+burst[j-1];
	      --j;
	    }
	}
	for(int i=0;i<n;i++)
	{ k=i;
	  if(k==0)
	   tat[0]=burst[0];
        while(k>0)
	    {
	     tat[k]=burst[k]+tat[k-1];
         --k;
	    }
	}
	//*************************
	cout<<"Waiting"<<endl;
	for(int i=0;i<n;i++)
		cout<<wat[i]<<" ";
   //**************************
	cout<<endl<<"Turn Around"<<endl;
	for(int i=0;i<n;i++)
		cout<<tat[i]<<" ";
	
}
