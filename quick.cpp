#include<iostream>
using namespace std;

int quick(int arr[],int low,int high);
int partition(int arr[],int low,int high);

int main()
{
 int arr[]={10,5,3,2,8,9};
 int size=6;
 int i;
 int low=arr[0];
 int high=size-1;
 cout<<"after sorting"<<endl;
 quick(arr,0,size-1);
 for(i=0;i<size;i++)
 {
 	cout<<arr[i]<<" ";
 	//cout<<endl;
 }
 cout<<endl;
 return 0;
}

int quick(int arr[],int low,int high)
{
 if(low<high)
 {
  int loc=partition(arr,low,high);
  quick(arr,low,loc-1);
  quick(arr,loc+1,high);
 }
}

int partition(int arr[],int low,int high)
{
int size=6,temp,loc;
 int i,j;
 i=low+1;
 j=size-1;
 int pivot=arr[low];
 while(i<=j)
 {
  while(arr[i]<=pivot)
  {
   i++;
  }
   while(arr[j]>pivot)
   {
    j--;
   }
   if(i<j)
   {
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
   }
    arr[low]=arr[j];
    arr[j]=pivot;
    return j;
 }
}


