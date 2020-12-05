#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > pi;
int fin_cost=INT_MIN;
vector<string> final_path;
bool solve(vector<vector<int>> &grid,int n,int m,int ag_x,int ag_y,int step,int tot_ten,vector<string> &path)
{

    if(step==0)
    {
        if(fin_cost<tot_ten)
        {
            final_path=path;
            fin_cost=tot_ten;
        }
        return false;
    }
    if(fin_cost==tot_ten)
    {
        if(final_path.size()>path.size())
        {
            final_path=path;
        }
    }

    //check up
    if(ag_x-1>=0) 
    {
        if(grid[ag_x-1][ag_y]!=-1){
        if(grid[ag_x-1][ag_y]==10)
        {
            grid[ag_x-1][ag_y]=0;
            path.push_back("up");
            solve(grid,n,m,ag_x-1,ag_y,step-1,tot_ten+1,path);
            grid[ag_x-1][ag_y]=10;
            path.pop_back();
            
        }
        else
        {
            path.push_back("up");
            solve(grid,n,m,ag_x-1,ag_y,step-1,tot_ten,path);
            path.pop_back();
            
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
            path.push_back("down");
            solve(grid,n,m,ag_x+1,ag_y,step-1,tot_ten+1,path);
            grid[ag_x+1][ag_y]=10;
            path.pop_back();
            
        }
        else
        {
            path.push_back("down");
            solve(grid,n,m,ag_x+1,ag_y,step-1,tot_ten,path);
            path.pop_back();
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
            path.push_back("right");
            solve(grid,n,m,ag_x,ag_y+1,step-1,tot_ten+1,path);
            grid[ag_x][ag_y+1]=10;
            path.pop_back();
        }
        else{
            path.push_back("right");
            solve(grid,n,m,ag_x,ag_y+1,step-1,tot_ten,path);
            path.pop_back();
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
            path.push_back("left");
            solve(grid,n,m,ag_x,ag_y-1,step-1,tot_ten+1,path);
            grid[ag_x][ag_y-1]=10;
            path.pop_back();
        }
        else
        {
            path.push_back("left");
            solve(grid,n,m,ag_x,ag_y-1,step-1,tot_ten,path);
            path.pop_back();
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
        vector<string> path;
        solve(grid,n,m,ag_x,ag_y,step,tot_ten,path);
        if(final_path.size()==0)
        {
            cout<<"NIL\n";
        }
        else{
        for(auto it=final_path.begin();it!=final_path.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<"\n";
        }
        // cout<<fin_cost<<"\n";
        fin_cost=0;
        final_path.clear();

    }
    
}
