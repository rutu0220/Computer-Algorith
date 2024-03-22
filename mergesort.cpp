#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high)
{
    //two temporary array
    int n1=mid-low+1;
    int n2=high-mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++)
    {
        a[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++)
    {
        b[j]=arr[mid+1+j];
    }

    int i=0;
    int j=0;
    int k=low;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=b[j];
            //k++;
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[],int low,int high)
{
    if(low<high)     //when low=high only one element is left in array
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        //now merge
        merge(arr,low,mid,high);

    }
}

int main()
{
    int arr[]={5,6,3,2,1};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}