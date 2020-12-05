#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;
typedef pair<int,pp> pi;
typedef vector<vector<vector<int>>> vovov;
bool isvalid(int i,int j,int n, int m)
{
    if(i>=0 && i<n && j>=0 && j<m)
    return true;
    return false;
}
int heuristic(pp &state,pp &goal)
{
    int fs,is,js;
    int fg,ig,jg;
    fs=state.first;
    is=state.second.first;
    js=state.second.second;

    fg=goal.first;
    ig=goal.second.first;
    jg=goal.second.second;

    int count=0;
    if(fs>=fg)
    {
        count = abs(fs-fg) + abs(ig-is) + abs(js-jg);
    }
    else
    {
        count= (2*abs(fg-fs) + abs(ig-is) + abs(js-jg));
    }
    //cout<<count<<"\n";
     return count;
}
void bfs(vovov &v,pp &psrc,pp &pgoal,int n,int m,int h)
{
    priority_queue<pi, vector<pi>, greater<pi> > open; 

   set<pp> closed;
    map<pp,int> g_fun;
    map<pp,int> f_fun;
    map<pp,int> h_fun;

    g_fun[psrc]=0;
    h_fun[psrc]=heuristic(psrc,pgoal);
    f_fun[psrc]=g_fun[psrc]+h_fun[psrc];

    open.push(make_pair(f_fun[psrc],psrc));
    int flag=0;
    while(!open.empty())
    {
        pp state=open.top().second;
        // int fval=open.top().first;
        open.pop();
        int floor=state.first;
        int srow=state.second.first;
        int scol=state.second.second;
        if(state==pgoal)
        {
            cout<<g_fun[pgoal]<<"\n";
            flag=1;
            break;
        }
        closed.insert(state);

        vector<vector<int>> f=v[floor];

        if(f[srow][scol]==1 || f[srow][scol]==2)
        {
            if(isvalid(srow+1,scol,n,m) && f[srow+1][scol]!=0)
            {

                pp nextstate;
                nextstate=make_pair(floor,make_pair(srow+1,scol));
                if(closed.find(nextstate)==closed.end())
                {
                    int g,h,f;
                    g=g_fun[state]+1;
                    h=heuristic(nextstate,pgoal);
                    f=g+h;
                   
                   if( (f_fun.find(nextstate)==f_fun.end()) || f_fun[nextstate]>f)
                   {
                       g_fun[nextstate]=g;
                       f_fun[nextstate]=f;
                       h_fun[nextstate]=h;
                       open.push(make_pair(f_fun[nextstate],nextstate));
                   }
                    
                }
            }
            if(isvalid(srow-1,scol,n,m) && f[srow-1][scol]!=0)
            {
                pp nextstate;
                nextstate=make_pair(floor,make_pair(srow-1,scol));
                if(closed.find(nextstate)==closed.end())
                {
                    int g,h,f;
                    g=g_fun[state]+1;
                    h=heuristic(nextstate,pgoal);
                    f=g+h;
                   
                   if( (f_fun.find(nextstate)==f_fun.end()) || f_fun[nextstate]>f)
                   {
                       g_fun[nextstate]=g;
                       f_fun[nextstate]=f;
                       h_fun[nextstate]=h;
                       open.push(make_pair(f_fun[nextstate],nextstate));
                   }
                    
                }
            }
            if(isvalid(srow,scol+1,n,m) && f[srow][scol+1]!=0)
            {
                pp nextstate;
                nextstate=make_pair(floor,make_pair(srow,scol+1));
                if(closed.find(nextstate)==closed.end())
                {
                    int g,h,f;
                    g=g_fun[state]+1;
                    h=heuristic(nextstate,pgoal);
                    f=g+h;
                   
                   if( (f_fun.find(nextstate)==f_fun.end()) || f_fun[nextstate]>f)
                   {
                       g_fun[nextstate]=g;
                       f_fun[nextstate]=f;
                       h_fun[nextstate]=h;
                       open.push(make_pair(f_fun[nextstate],nextstate));
                   }
                    
                }
            }
            if(isvalid(srow,scol-1,n,m) && f[srow][scol-1]!=0)
            {
                pp nextstate;
                nextstate=make_pair(floor,make_pair(srow,scol-1));
                if(closed.find(nextstate)==closed.end())
                {
                    int g,h,f;
                    g=g_fun[state]+1;
                    h=heuristic(nextstate,pgoal);
                    f=g+h;
                   
                   if( (f_fun.find(nextstate)==f_fun.end()) || f_fun[nextstate]>f)
                   {
                       g_fun[nextstate]=g;
                       f_fun[nextstate]=f;
                       h_fun[nextstate]=h;
                       open.push(make_pair(f_fun[nextstate],nextstate));
                   }
                    
                }
            }

            if(f[srow][scol]==2)
            {
                
                if(floor-1>=0 && floor-1<h)
                { 
                    pp nextstate;
                    nextstate=make_pair(floor-1,make_pair(srow,scol));
                    if(closed.find(nextstate)==closed.end())
                    {
                        int g,h,f;
                        g=g_fun[state]+1;
                        h=heuristic(nextstate,pgoal);
                        f=g+h;
                   
                        if( (f_fun.find(nextstate)==f_fun.end()) || f_fun[nextstate]>f)
                        {
                            g_fun[nextstate]=g;
                            f_fun[nextstate]=f;
                            h_fun[nextstate]=h;
                            open.push(make_pair(f_fun[nextstate],nextstate));
                        }
                    
                    }
                }
                if(floor+1>=0 && floor+1<h)
                {
                    pp nextstate;
                    nextstate=make_pair(floor+1,make_pair(srow,scol));
                    if(closed.find(nextstate)==closed.end())
                    {
                        int g,h,f;
                        g=g_fun[state]+2;
                        h=heuristic(nextstate,pgoal);
                        f=g+h;
                   
                        if( (f_fun.find(nextstate)==f_fun.end()) || f_fun[nextstate]>f)
                        {
                            g_fun[nextstate]=g;
                            f_fun[nextstate]=f;
                            h_fun[nextstate]=h;
                            open.push(make_pair(f_fun[nextstate],nextstate));
                        }
                    
                    }
                }
            }
        }    
    }
    if(flag==0) cout<<"-1\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,h;
        cin>>n>>m>>h;
        vector<vector<vector<int>>> vvv;
        for(int i=0;i<h;i++)
        {
            vector<vector<int>> vv;
            for(int j=0;j<n;j++)
            {
                vector<int> v;
                for(int k=0;k<m;k++)
                {
                    int x;
                    cin>>x;
                    v.push_back(x);
                }
                vv.push_back(v);
            }
            vvv.push_back(vv);
        }
        int q;
        cin>>q;
        while(q--)
        {
            pp psrc;
            pp pgoal;
            int srcflo,isrc,jsrc;
            int goalflo,igoal,jgoal;
            cin>>srcflo>>isrc>>jsrc;
            cin>>goalflo>>igoal>>jgoal;
            psrc=make_pair(srcflo,make_pair(isrc,jsrc));
            pgoal=make_pair(goalflo,make_pair(igoal,jgoal));
            //cout<<"!";
            bfs(vvv,psrc,pgoal,n,m,h);
        }
    }
}
