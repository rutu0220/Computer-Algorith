#include<iostream>
using namespace std;
int binary(int arr[],int low,int high,int sdata);
int linear(int arr[],int lpos,int sdata);
int main()
{
    int arr[6]={2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int low=0;
    int high=size-1;
    int sdata;
    int index;
    int lpos;
    int i;
    for(i=0;i<size-1;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"ENter data to search";
    cin>>sdata;
    // func call for binary search
   index=binary(arr,low,high,sdata);
    if(index==-1)
    {
        cout<<"Data not found";
    }
    else
    {
       cout<<"Data found at "<<index;
    }
// function call for linear search
index=linear(arr,lpos,sdata);
if(index==-1)
    {
        cout<<"Data not found";
    }
    else
    {
       cout<<"Data found at "<<index;
    }

}
int binary(int arr[],int low,int high,int sdata)
{
    int mid;
    while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==sdata)
    {
        return mid;
    }
    if(sdata>arr[mid])
    {
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    }
    return -1;
}
int linear(int arr[],int lpos,int sdata)
{
    int cur_pos=0;
    while(cur_pos<=lpos)
    {
        if(sdata==arr[cur_pos])
        {
            return cur_pos;
        }
        else
        {
            cur_pos++;
        }
    }
    return -1;
}