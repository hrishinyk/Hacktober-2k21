#include<iostream>
using namespace std;
void warshal(int a[10][10],int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
int main()
{

    int a[10][10],n;
    cout<<"Enter the number of vertices:";
    cin>>n;
    cout<<"Enter the adjacency matrix:\n";
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {

            cin>>a[i][j];
        }
    }
    warshal(a,n);
    cout<<"All the shortest pairs for the given graph are:\n";
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
