#include<iostream>
using namespace std;
int min,max;
int MinMax(int arr[],int i,int j,int &min, int &max);
int main()
{
    int i,j;
    int arr[6]={98,6,9,1,3,2};
    int max=arr[0];
    int min=arr[0];
    MinMax(arr,0,5,min,max);
    cout<<"Minimum and maximum number is ="<<endl<<min<<endl<<max<<endl;
    return 0;
}
int MinMax(int arr[],int i,int j,int &min,int &max)
{
    //int mid;
    //int min,max;
    //int min1,max1;
    if(i==j)  
    {
        min=arr[i];
		max=arr[i];
    }
    else if(i==j-1)
    {
        if(arr[i]<arr[j])
        {
          min=arr[i];
          max=arr[j];
        }
        else
        {
            min=arr[j];
            max=arr[i];
        }
    
    }
    else
    {
       int mid=(i+j)/2;
       int min1,max1;
        MinMax(arr,i,mid,min,max);
       // min1=min;
       // max1=max;
        MinMax(arr,mid+1,j,min1,max1);
        if(max<max1)
        {
            max=max1;
        }
        if(min>min1)
        {
            min=min1;
        }
    }
}


