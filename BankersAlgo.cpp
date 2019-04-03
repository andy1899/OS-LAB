//Bankers
#include<bits/stdc++.h>
using namespace std;
main()
{
    int res,pro;
	cout<<"Enter number of resources"<<endl;
	cin>>res;
	cout<<"Enter number of process"<<endl;
	cin>>pro;
	int alloc[pro][res],max[pro][res],need[pro][res],avail[res],count=0,exe[pro],rem[pro],z,check=0;
	cout<<"Enter allocation details"<<endl;
	for(int i=0;i<pro;i++)
	 {
	  cout<<"Enter resource allocation for process="<<i+1<<endl;
	  for(int j=0;j<res;j++)
	   {
	   cout<<"Enter allocation of resource="<<j+1<<endl; 	
		cin>>alloc[i][j];
		}	
	 }
    cout<<"Enter max instances"<<endl;
	for(int i=0;i<pro;i++)
	 {
	  cout<<"Enter max instances for process="<<i+1<<endl;
	  for(int j=0;j<res;j++)
	   {
	   cout<<"Enter max instances of resource="<<j+1<<endl; 	
		cin>>max[i][j];
		}	
	 }
	cout<<"Enter no of instances availabel"<<endl;
	  for(int j=0;j<res;j++)
	   cin>>avail[j];
     cout<<"Need matrix="<<endl;
	  
    for(int i=0;i<pro;i++)
	 {
	  for(int j=0;j<res;j++)
	  {
	   need[i][j]=max[i][j]-alloc[i][j];	
	   cout<<need[i][j]<<" ";
	  }
	  cout<<endl;
     }
     for(int i=0;i<pro;i++)
	  {
	  exe[i]=-1;
	  rem[i]=-1;
      }
	while(z!=0&&check<=pro)
	{ z=0;
	   ++check;
		for(int i=0;i<pro;i++)
	 { 
	  count=0;
	  for(int j=0;j<res;j++)
	   { 
	   	if((avail[j]-need[i][j])>=0)
	   	  ++count;
	   	if(count==res)
	     { exe[i]=i+1;
	      for(int j=0;j<res;j++)
           avail[j]+=alloc[i][j];
		 }	 
	   }
		 if(exe[i]==-1)
	       rem[z++]=i+1;
     }
      cout<<"Process that are executed"<<endl;
	    for(int i=0;i<pro;i++)
	     cout<<exe[i]<<" ";
	   cout<<endl;
	cout<<"Process that are remaining"<<endl;
	   
 	    for(int m=0;m<z;m++)
		 cout<<rem[m]<<" "; 
		cout<<endl;
		 if(z==0)
		 cout<<"Safe state"<<endl;

     }
	 if(z>0)   
     cout<<"Unsafe State"<<endl;
   }
