#include<bits/stdc++.h>
#define vv vector<vector<int>> 
#define pvi pair<vector<vector<int>> ,int> 
#define vec vector<int> 
#define pii pair<int,int>
#define prio_que priority_queue <pii, vector<pii>, greater<pii> >
using namespace std;
// heuristics function which will give the column number which has minimum number of row occupied except zero
// if any two column  have same value then  take the minimum column number 
int minimum_remaining_value(vec &domain,int n)
{
	int col_index=-1;
	int mx=100000;
	for(int col=0;col<n;col++)
	{
		if(domain[col]!=0){

			if(domain[col]<mx)
			{
				mx=domain[col];
				col_index=col;
			}
		}
	}
	return col_index;
}
// heuristics function which will return the row_no and number of cell which can be affected 
// by placing the queen for a particular column 
prio_que least_constraining_value(vv &board, int n ,int col)
{
	prio_que pq;

	for(int row=0;row<n;row++)
	{
		if(board[row][col]==0)
		{
			int cnt=0;
			int i,j;
			for(i=0;i<col;i++)
			{
				if(board[row][i]==0)
					cnt++;
			}
			for(i=col+1;i<n;i++)
			{
				if(board[row][i]==0)
					cnt++;
			}
			for(i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
			{
				if(board[i][j]==0)
					cnt++;
			}
			for(i=row+1,j=col-1;i<n && j>=0 ;i++,j--)
			{
				if(board[i][j]==0)
					cnt++;
			}
			for(i=row-1,j=col+1;i>=0 && j<n;i--,j++)
			{
				if(board[i][j]==0)
					cnt++;
			}
			for(i=row+1,j=col+1;i<n && j<n ;i++,j++)
			{
				if(board[i][j]==0)
					cnt++;
			}

			pq.push(make_pair(cnt,row));
			//cout<<cnt<<"\n";
		}
	}
	return pq;

}
bool check_goal(int tot_queen,int n)
{
	if(tot_queen>=n)
		return true;
	return false;
}
void print(vv &board,int n)
{
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	cout<<"After Modifications\n";
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==-1)
				cout<<"_"<<" ";
			else
				cout<<"Q"<<" ";
			//cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void mark(vv &board,vv &visited,int row,int col)
{
	if(board[row][col]!=-1)
	{
		visited[row][col]=1;
		board[row][col]=-1;
	}
}
bool check_affected_cells(int roww,int coll,int row,int col)
{
	if(roww==row && coll==col)
		return false;
	if(roww==row) return true;
	if(coll==col) return true;
	if((coll-roww)==(col-row)) return true;
	if((coll+roww)==(col+row)) return true;
	return false;
}
bool solve(vector<vector<int>> &board,int n,vec &domain,int tot_queen)
{
	int col=minimum_remaining_value(domain,n);
	if(check_goal(tot_queen,n))
	{
		return true;
	}
	if(col==-1)
	{
		return false;
	}

	prio_que pq;
	pq=least_constraining_value(board,n,col);

	while(!pq.empty())
	{
		int  val=pq.top().first;
		int row=pq.top().second;
		board[row][col]=1;
		pq.pop();
		tot_queen++;
		//cout<<row<<"\n";
		//print(board,n);

		if(check_goal(tot_queen,n))
		{
			print(board,n);
			return true;
		}
		vv visited;
		for(int i=0;i<n;i++)
		{
			vector<int> v;
			for(int j=0;j<n;j++)
			{
				v.push_back(0);
			}
			visited.push_back(v);
		}

		for(int roww=0;roww<n;roww++)
		{
			for(int coll=0;coll<n;coll++)
			{
				if(check_affected_cells(roww,coll,row,col))
				{
					mark(board,visited,roww,coll);
				}
			}
		}

		for(int coll=0;coll<n;coll++)
		{
			int cnt=0;
			for(int roww=0;roww<n;roww++)
			{
				if(board[roww][coll]==0)
					cnt++;
			}
			domain[coll]=cnt;
		}
		if(solve(board, n, domain,tot_queen))
			return true;

		board[row][col]=0;
		for(int roww=0;roww<n;roww++)
		{
			for(int coll=0;coll<n;coll++)
			{
				if(check_affected_cells(roww,coll,row,col) && visited[roww][coll]==1)
				{
					board[roww][coll]=0;
				}
			}
		}
		for(int coll=0;coll<n;coll++)
		{
			int cnt=0;
			for(int roww=0;roww<n;roww++)
			{
				if(board[roww][coll]==0)
					cnt++;
			}
			domain[coll]=cnt;
		}
		tot_queen--;
	}
	return false;

}
void initialise(vv &board, vec &domain,int n)
{
	for(int i=0;i<n;i++)
	{
		vector<int> v;
		for(int j=0;j<n;j++)
		{
			v.push_back(0);
		}
		board.push_back(v);
	}
	for(int i=0;i<n;i++)
	{
		domain.push_back(n);
	}
}
int main()
{
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	vv board;
	vec domain;
	int tot_queen=0;
	initialise(board,domain,n);
	solve(board,n,domain,tot_queen);
}