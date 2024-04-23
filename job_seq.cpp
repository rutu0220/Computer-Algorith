#include<iostream>
using namespace std;
int dline[5];
int profit[5];

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int profit[],int deadline[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(profit[j]<profit[j+1])
            {
                swap(&profit[j],&profit[j+1]);
                swap(&deadline[j],&deadline[j+1]);
            }
        }
    }
}

int main()
{
    int i=0,j=1;
    int maxdead=0;
    int cnt=0,pr=0,r=0;
    int slot[5]={-1};
    for(i=0;i<5;i++)
    {
        cout<<"Enter profit "<<i+1<<endl;
        cin>>profit[i];
        cout<<"Enter deadline "<<i+1<<endl;
        cin>>dline[i];
    }
    int n=sizeof(profit)/sizeof(profit[0]);
    bubble(profit,dline,n);
    cout<<"Sorted profit and deadline "<<endl;
    cout<<"profit\tdeadline\n";

    for(i=0;i<n;i++)
    {
        cout << profit[i] << "\t" << dline[i] << "\n";
    }
    for(i=0;i<n;i++)
    {
        if(dline[i]>maxdead)
        {
            maxdead=dline[i];
        }
    }
    for(i=1;i<=maxdead;i++)
    {
        slot[i]=-1;
    }
    for(i=0;i<5;i++)
    {
    for(r=dline[i];r>=1;r--)
    {
        if(slot[r]==-1)
        {
            slot[r]=i;
            pr+=profit[i];
            cnt++;
            break;
        }
    }
    if(cnt==maxdead)
    {
        break;
    }
    }
    cout<<"total profit "<<pr<<"\t";
    cout<<"maximum deadline "<<maxdead;
    return 0;
}