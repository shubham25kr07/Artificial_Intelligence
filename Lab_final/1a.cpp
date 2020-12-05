#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > pi;
int fin_cost=INT_MIN;
bool solve(vector<vector<int>> &grid,int n,int m,int ag_x,int ag_y,int step,int tot_ten)
{
    if(step==0)
    {
        if(fin_cost<tot_ten)
        {
            fin_cost=tot_ten;
        }
         return true;
    }
    //check up
    if(ag_x-1>=0) 
    {
        if(grid[ag_x-1][ag_y]!=-1){
        if(grid[ag_x-1][ag_y]==10)
        {
            grid[ag_x-1][ag_y]=0;
            solve(grid,n,m,ag_x-1,ag_y,step-1,tot_ten+1);
            grid[ag_x-1][ag_y]=10;
            
        }
        else
        {
            solve(grid,n,m,ag_x-1,ag_y,step-1,tot_ten);
        }
        }
        
    }
    // check down
    if(ag_x+1<n) 
    {
        if( grid[ag_x+1][ag_y]!=-1){
        if(grid[ag_x+1][ag_y]==10)
        {
            grid[ag_x+1][ag_y]=0;
            solve(grid,n,m,ag_x+1,ag_y,step-1,tot_ten+1);
            grid[ag_x+1][ag_y]=10;
            
        }
        else
        {
            solve(grid,n,m,ag_x+1,ag_y,step-1,tot_ten);
        }
        }
        
    }
    // check right
    if(ag_y+1<m )
    {
        if(grid[ag_x][ag_y+1]!=-1){
        if(grid[ag_x][ag_y+1]==10)
        {
            grid[ag_x][ag_y+1]=0;
            solve(grid,n,m,ag_x,ag_y+1,step-1,tot_ten+1);
            grid[ag_x][ag_y+1]=10;
        }
        else{
            solve(grid,n,m,ag_x,ag_y+1,step-1,tot_ten);
        }
        }
        
    }
    // check left
    if(ag_y-1>=0)
    {
        if(grid[ag_x][ag_y-1]!=-1){
        if(grid[ag_x][ag_y-1]==10)
        {
            grid[ag_x][ag_y-1]=0;
            solve(grid,n,m,ag_x,ag_y-1,step-1,tot_ten+1);
            grid[ag_x][ag_y-1]=10;
        }
        else
        {
            solve(grid,n,m,ag_x,ag_y-1,step-1,tot_ten);
        }
        }
    }


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,step;
        cin>>n>>m>>step;
        vector<vector<int>> grid;
        int ag_x,ag_y;
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                if(x==1)
                {
                    ag_x=i;
                    ag_y=j;
                }
                v.push_back(x);
            }
            grid.push_back(v);
        }
        int tot_ten=0;
        solve(grid,n,m,ag_x,ag_y,step,tot_ten);
        cout<<fin_cost<<"\n";
        fin_cost=0;

    }
    

    
}
