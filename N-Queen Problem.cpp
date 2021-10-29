/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/

#include<bits/stdc++.h>
using  namespace std;
bool isSafeToPut(int sol[][10],int i,int j,int n)
{
	for(int k=0;k<n;k++)
	{
		if(sol[k][j] || sol[i][k])
		{
			return false;
		}
	}

	int row=i,col=j;
	while(row>=0 && col>=0)
	{
		if(sol[row][col])
		{
			return false;
		}
		row--;
		col--;
	}

	row=i,col=j;

	while(row>=0 && col<n)
	{
		if(sol[row][col])
		{
			return false;
		}
		row--;
		col++;
	}

	return true;

}


bool nqueen(int sol[][10],int i,int n)
{
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<sol[i][j]<<" ";
			}
		}
		cout<<endl;
		return false;
	}

	for(int j=0;j<n;j++)
	{
		if(isSafeToPut(sol,i,j,n))
		{
			sol[i][j]=1;
			bool kyaAageRakhPaye=nqueen(sol,i+1,n);
			if(kyaAageRakhPaye)
			{
				return true;
			}
			sol[i][j]=0;
		}
	}

	return false;

}

void placeNQueens(int n){
	int sol[10][10]={0};
    nqueen(sol,0,n);
}