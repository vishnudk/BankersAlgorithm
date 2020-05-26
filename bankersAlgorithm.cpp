#include<iostream>
#include<stdlib.h>
#include <sstream>
#include<vector>
#include <list> 
#include <iterator> 
#include<stdio.h>
#include <bits/stdc++.h> 
int noOfProc,noOfReso=0;
using namespace std;
int compareProcessAndAvailableResourcess(int **procR,int *rem){
	list <int> :: iterator it; 
	list<int> procList; 
	list<int> allProc;
	for(int i=0;i<noOfProc;i++)
	allProc.push_back(i);
	int count=0;
	while(count<=noOfProc){
	for(int i=0;i<noOfProc;i++)
	{
		int flag=0;
		it = find(procList.begin(), procList.end(), i);
		// Check if iterator points to end or not
		if(it == procList.end()){
		for(int j=0;j<noOfReso;j++)
		{
			if (procR[i][j]<=rem[j])
			{
				flag++;
				if(flag==noOfReso)
				{
					procList.push_back(i);
					for(int k=0;k<noOfReso;k++)
					{
						rem[k]=rem[k]+procR[i][k];
						//procR[i][k]=-1;
					}
				}
			}
		}}
		if(i+1==noOfProc)
		{
			if(noOfProc==procList.size())
			break;
			else{
				count++;
			}
		}
	}
	if(noOfProc==procList.size())
			break;
	}
	if(noOfProc==procList.size())
    {
	for ( it = procList.begin(); it != procList.end(); ++it) 
        cout << ' ' << *it;
    cout<<endl;    
	return procList.size();}
	else
	return -1;
}
int **procRemain(int **arr1,int **arr)
{
	int** procRem=new int*[noOfProc];
	  for( int i=0;i<noOfProc;i++)
	   {
		procRem[i]=new int[noOfReso];
	   }
	for(int i=0;i<noOfProc;i++)
	{
		for(int j=0;j<noOfReso;j++)
		{
			procRem[i][j]=arr1[i][j]-arr[i][j];
		}
	}
	return procRem;
}
int* remainRes(int *arr1,int *arr)
{
		int* remain = new int[noOfReso]; 
	for(int i=0;i<noOfReso;i++)
	{
		remain[i]=arr1[i]-arr[i];
	}
	return remain;
}	
void disp(int **arr)
{
	cout<<"================================="<<endl;
	for (int i=0;i<noOfProc;i++)
	{
		for (int j=0;j<noOfReso;j++)
		{
			cout<<arr[i][j]<<" " ;
		}
		cout<<endl;
		}
	cout<<"================================="<<endl;
}
int* totalUse(int **arr)
{
	int* total = new int[noOfReso]; 
	for(int i=0;i<noOfReso;i++)
	{
		total[i]=0;
		for(int j=0;j<noOfProc;j++)
		{
			
			total[i]=total[i]+arr[j][i];
		}
		
	}
	return total;
}

int main()
{   
	cout<<"Enter the no of resources : ";
	cin>>noOfReso;
	cout<<"enter the no of process : ";
	cin>>noOfProc;
	
	int** procR=new int*[noOfProc];
	  for( int i=0;i<noOfProc;i++)
	   {
		procR[i]=new int[noOfReso];
	   }
	int** proc=new int*[noOfProc];
	  for( int i=0;i<noOfProc;i++)
	   {
		proc[i]=new int[noOfReso];
	   }
     int** aloc=new int*[noOfProc];
     for (int i=0;i<noOfProc;i++)
     {
		 aloc[i]=new int[noOfReso];
	 }
	 int* avail=new int[noOfReso];
	 cout<<"Enter process requirements : "<<endl;
	for (int i=0;i<noOfProc;i++)
	{
		for(int j=0;j<noOfReso;j++)
		{
			cin>>proc[i][j];
		}
	}
	cout<<"================================="<<endl;
	//system("cls");
	cout<<"Enter the allocation for process :"<<endl;
	for (int i=0;i<noOfProc;i++)
	{
		for(int j=0;j<noOfReso;j++)
		{
			cin>>aloc[i][j];
		}
	}
	cout<<"================================="<<endl;
    int* tot=totalUse(aloc);
    cout<<"total resource usage :"<<endl;
    for(int i=0;i<noOfReso;i++)
    {
		cout<<tot[i]<<" ";
	}
	cout<<endl;
	cout<<"enter the available number of resourcess in total"<<endl;
	for (int i=0;i<noOfReso;i++)
	{
		cin>>avail[i];
}
	int* t=remainRes(avail,tot);
    cout<<"resources remaining :"<<endl;
    for(int i=0;i<noOfReso;i++)
    cout<<t[i]<<" ";
    cout<<endl;
    procR=procRemain(proc,aloc);
    cout<<"No of resources required for each process to complete :"<<endl;
    disp(procR);
    int val=compareProcessAndAvailableResourcess(procR,t);
    if(val==-1)
    cout<<"dead lock"<<endl;
    	return 0;
    
}
