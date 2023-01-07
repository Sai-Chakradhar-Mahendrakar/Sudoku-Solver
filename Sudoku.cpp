#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int** mat,int i,int j,int no,int n)
{
	for(int k=0;k<n;k++)
	{
		if(mat[k][j]==no||mat[i][k]==no)
		{
			return false;
		}
	}
	int su = sqrt(n);
	int sx = (i/su)*su;
	int sy = (j/su)*su;

	for(int x=sx; x<sx + su;x++)
	{
		for(int y =sy;y<sy + su;y++)
		{
			if(mat[x][y]==no){
				return false;
			}
		}
	}
	return true;
}


bool solveSudoku(int** mat,int i,int j,int n){
	if(i==n)
	{
		cout<<"Sudoko AFTER solving: "<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
	}

	if(j==n)
	{
		return solveSudoku(mat,i+1,0,n);
	}

	if(mat[i][j]!=0)
	{
		return solveSudoku(mat,i,j+1,n);
	}

	for(int no=1;no<=n;no++)
	{
		if(isSafe(mat,i,j,no,n))
		{

			mat[i][j] = no;
			bool solveSubproblem = solveSudoku(mat,i,j+1,n);
			if(solveSubproblem==true)
			{
				return true;
			}
		}

	}
	mat[i][j] = 0;
	return false;
}


int main()
{
	int n;
	cout<<"Enter dimimsion(n*n): ";
	cin>>n;
	int** arr=new int*[n];
    for(int i=0; i<n; i++)
	{
        arr[i]=new int[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter value for i: "<<i+1<<" j: "<<j+1<<" : ";
            cin>>arr[i][j];
        }
    }
	cout<<endl;

	cout<<"Sudoko BEFORE solving: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	if(!solveSudoku(arr,0,0,n)){
		cout<<"No solution exists!";
	}
}