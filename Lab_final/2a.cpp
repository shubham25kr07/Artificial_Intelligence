#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > pi;
int fin_cost=INT_MIN;
bool solve(vector<vector<int>> &grid,int n,int m,int ag_x1,int ag_y1,int ag_x2,int ag_y2,int step,int tot_ten)
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
    if(ag_x2-1>=0) 
    {
        if(grid[ag_x2-1][ag_y2]!=-1){
        if(grid[ag_x2-1][ag_y2]==10)
        {
            grid[ag_x2-1][ag_y2]=0;
            solve(grid,n,m,ag_x1,ag_y1,ag_x2-1,ag_y2,step-1,tot_ten+1);
            grid[ag_x2-1][ag_y2]=10;
            
        }
        else
        {
            solve(grid,n,m,ag_x1,ag_y1,ag_x2-1,ag_y2,step-1,tot_ten);
        }
        }
        
    }
    //check up
    if(ag_x1-1>=0) 
    {
        if(grid[ag_x1-1][ag_y1]!=-1){
        if(grid[ag_x1-1][ag_y1]==10)
        {
            grid[ag_x1-1][ag_y1]=0;
            solve(grid,n,m,ag_x1-1,ag_y1,ag_x2,ag_y2,step-1,tot_ten+1);
            grid[ag_x1-1][ag_y1]=10;
            
        }
        else
        {
            solve(grid,n,m,ag_x1-1,ag_y1,ag_x2,ag_y2,step-1,tot_ten);
        }
        }
        
    }
    // check down
    if(ag_x1+1<n) 
    {
        if( grid[ag_x1+1][ag_y1]!=-1){
        if(grid[ag_x1+1][ag_y1]==10)
        {
            grid[ag_x1+1][ag_y1]=0;
            solve(grid,n,m,ag_x1+1,ag_y1,ag_x2,ag_y2,step-1,tot_ten+1);
            grid[ag_x1+1][ag_y1]=10;
            
        }
        else
        {
            solve(grid,n,m,ag_x1+1,ag_y1,ag_x2,ag_y2,step-1,tot_ten);
        }
        }
        
    }
    // check right
    if(ag_y1+1<m )
    {
        if(grid[ag_x1][ag_y1+1]!=-1){
        if(grid[ag_x1][ag_y1+1]==10)
        {
            grid[ag_x1][ag_y1+1]=0;
            solve(grid,n,m,ag_x1,ag_y1+1,ag_x2,ag_y2,step-1,tot_ten+1);
            grid[ag_x1][ag_y1+1]=10;
        }
        else{
            solve(grid,n,m,ag_x1,ag_y1+1,ag_x2,ag_y2,step-1,tot_ten);
        }
        }
        
    }
    // check left
    if(ag_y1-1>=0)
    {
        if(grid[ag_x1][ag_y1-1]!=-1){
        if(grid[ag_x1][ag_y1-1]==10)
        {
            grid[ag_x1][ag_y1-1]=0;
            solve(grid,n,m,ag_x1,ag_y1-1,ag_x2,ag_y2,step-1,tot_ten+1);
            grid[ag_x1][ag_y1-1]=10;
        }
        else
        {
            solve(grid,n,m,ag_x1,ag_y1-1,ag_x2,ag_y2,step-1,tot_ten);
        }
        }
    }

    // check left
    if(ag_y2-1>=0)
    {
        if(grid[ag_x2][ag_y2-1]!=-1){
        if(grid[ag_x2][ag_y2-1]==10)
        {
            grid[ag_x2][ag_y2-1]=0;
            solve(grid,n,m,ag_x1,ag_x2,ag_x2,ag_y2-1,step-1,tot_ten+1);
            grid[ag_x2][ag_y2-1]=10;
        }
        else
        {
            solve(grid,n,m,ag_x1,ag_y1,ag_x2,ag_y2-1,step-1,tot_ten);
        }
        }
    }
    

    // check down
    if(ag_x2+1<n) 
    {
        if( grid[ag_x2+1][ag_y2]!=-1){
        if(grid[ag_x2+1][ag_y2]==10)
        {
            grid[ag_x2+1][ag_y2]=0;
            solve(grid,n,m,ag_x1,ag_y1,ag_x2+1,ag_y2,step-1,tot_ten+1);
            grid[ag_x2+1][ag_y2]=10;
            
        }
        else
        {
            solve(grid,n,m,ag_x1,ag_y1,ag_x2+1,ag_y2,step-1,tot_ten);
        }
        }
        
    }
    // check right
    if(ag_y2+1<m )
    {
        if(grid[ag_x2][ag_y2+1]!=-1){
        if(grid[ag_x2][ag_y2+1]==10)
        {
            grid[ag_x2][ag_y2+1]=0;
            solve(grid,n,m,ag_x1,ag_y1,ag_x2,ag_y2+1,step-1,tot_ten+1);
            grid[ag_x2][ag_y2+1]=10;
        }
        else{
            solve(grid,n,m,ag_x1,ag_y1,ag_x2,ag_y2+1,step-1,tot_ten);
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
        int ag_x1,ag_y1,ag_x2,ag_y2;
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                if(x==1)
                {
                    ag_x1=i;
                    ag_y1=j;
                }
                if(x==2)
                {
                    ag_x2=i;
                    ag_y2=j;
                }
                v.push_back(x);
            }
            grid.push_back(v);
        }
        int tot_ten=0;
        solve(grid,n,m,ag_x1,ag_y1,ag_x2,ag_y2,step,tot_ten);
        cout<<fin_cost<<"\n";
        fin_cost=0;

    }
    

    
}
