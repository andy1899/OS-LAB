
#include<bits/stdc++.h>
using namespace std;
main()
{
	cout<<"Enter the no memory spaces available intially"<<endl;
	int mem_no,no;
	cin>>mem_no;
	cout<<"Enter size of memory spaces"<<endl;
	int size[mem_no];
	for(int i=0;i<mem_no;i++)
	cin>>size[i];
	cout<<"Enter number of process"<<endl;
	cin>>no;
	int pro[no];
	cout<<"Enter size of process"<<endl;
    for(int i=0;i<no;i++)
	cin>>pro[i];
	for(int i=0;i<no;i++)
	{bool flag=true;
	 for(int j=0;j<mem_no;j++)
	  {
	   if(pro[i]<=size[j])
	   {
	   	flag=false;
	   	cout<<"Space allocated in partition number="<<j+1<<" process no="<<i+1<<endl;
		size[j]-=pro[i];		
		break;
		}	
	  }
	  if(flag==true)
	  	cout<<"Sorry not enough space is availabel for process no="<<i+1<<"to allocate"<<endl;
	
	}
	cout<<"Size of memory left="<<endl;
	for(int i=0;i<mem_no;i++)
	cout<<size[i]<<" ";
		
}
