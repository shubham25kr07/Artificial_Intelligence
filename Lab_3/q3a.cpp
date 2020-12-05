#include<bits/stdc++.h>
#define mv_ map<string,vector<string>>
#define m_ map<string,int> 
#define vp_ vector<vector<vector<pair<string,string>>>>
#define pp_ pair<int,pair<int,int> >
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void initialise_visited(mv_ &sdata,m_ &visited)
{
    for(auto it=sdata.begin();it!=sdata.end();it++)
    {
     // cout<<it->first<<" \n";
       vector<string> v=it->second;
        for(auto itt=v.begin();itt!=v.end();itt++)
        {
            string roll=*itt;
            visited[roll]=0; // not visited 
           //cout<<*itt<<" ";
        }
        cout<<"\n";
    }
}
void initialise_classroom(vp_ &classrooms,int k,int m,int n)
{
    for(int classes=0;classes<k;classes++)
    {
        vector<vector<pair<string,string>>> vvp;
        for(int row=0;row<m;row++)
        {
            vector<pair<string,string>> vp;
            for(int col=0;col<n;col++)
            {
                vp.push_back(make_pair("00","00"));
            }
            vvp.push_back(vp);
        }
        classrooms.push_back(vvp);
    }
    //cout<<classrooms[0][0][0].first<<" "<<classrooms[0][0][0].second;
} 
bool issafe(vp_ &classrooms,string batch,int k,int m,int n,int row,int col,int classes)
{
    if(classrooms[classes][row][col].first=="00")
    {
        if(row-1>=0 && classrooms[classes][row-1][col].first==batch)
            return false;
        if(row+1<m && classrooms[classes][row+1][col].first==batch)
            return false;
        if(col-1>=0 && classrooms[classes][row][col-1].first==batch)
            return false;
        if(col+1<n && classrooms[classes][row][col+1].first==batch)
            return false;
        if(row-1>=0 && col-1>=0 &&  classrooms[classes][row-1][col-1].first==batch )
            return false;
        if(row-1>=0 && col+1<n &&  classrooms[classes][row-1][col+1].first==batch )
            return false;
        if(row+1<m && col-1>=0 &&  classrooms[classes][row+1][col-1].first==batch )
            return false;
        if(row+1<m && col+1<n &&  classrooms[classes][row+1][col+1].first==batch )
            return false;
        return true;
    }
    else{
        return false;
    }
}
bool check_visited(m_ &visited,int sitted)
{    
    // for(auto it=visited.begin();it!=visited.end();it++)
    // {
    //     if(it->second==0)
    //     return false;
    // }
    // return true;
    if(visited.size()==sitted)
        return true;
    return false;

}
void print(vp_ &classrooms,int k,int m,int n)
{
    for(int classes=0;classes<k;classes++)
    {
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                string batch=classrooms[classes][row][col].first;
                string roll=classrooms[classes][row][col].second;
                if(batch=="00" && roll=="00")
                {
                cout<<"NIL"<<" "<<"NIL"<<" ";
                }
                else 
                {
                    cout<<batch<<" "<<roll<<" ";
                }
            }
            cout<<"\n";
        }
    }
}
int degree_heuristics(vp_ &classrooms,int k,int m,int n,int row,int col,int classes)
{
    int cnt=0;

    if(row-1>=0 && classrooms[classes][row-1][col].first=="00")
        cnt++;
    if(row+1<m && classrooms[classes][row+1][col].first=="00")
        cnt++;
    if(col-1>=0 && classrooms[classes][row][col-1].first=="00")
        cnt++;
    if(col+1<n && classrooms[classes][row][col+1].first=="00")
        cnt++;
    if(row-1>=0 && col-1>=0 &&  classrooms[classes][row-1][col-1].first=="00")
        cnt++;
    if(row-1>=0 && col+1<n &&  classrooms[classes][row-1][col+1].first=="00")
        cnt++;
    if(row+1<m && col-1>=0 &&  classrooms[classes][row+1][col-1].first=="00")
        cnt++;
    if(row+1<m && col+1<n &&  classrooms[classes][row+1][col+1].first=="00")
        cnt++;

    return cnt;
}
tuple<int,int,int>  min_remaining_value(vp_ &classrooms,mv_&sdata,m_ &visited,int k,int m,int n)
{
    int minn=100000;
    int rrow=-1,ccol=-1,cclass=-1;
    int prev_degree=-1;
    for(int classes=0;classes<k;classes++)
    {
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                
                if(classrooms[classes][row][col].first=="00")
                {
                    int cnt=0,curr_degree=0;
                    for(auto it=sdata.begin();it!=sdata.end();it++)
                    {
                        string batch=it->first;
                        if(issafe(classrooms,batch,k,m,n,row,col,classes))
                        {
                            vector<string> v=it->second;
                            for(auto itt=v.begin();itt!=v.end();itt++)
                            {
                                string roll=*itt;
                                if(visited[roll]==0)
                                {
                                    cnt++;
                                }
                            }

                        }
                    }
                    curr_degree = degree_heuristics(classrooms,k,m,n,row,col,classes);
                    if(cnt<minn )
                    {
                        minn=cnt;
                        rrow=row;
                        ccol=col;
                        cclass=classes;
                    }
                    else if(cnt==minn)
                    {
                        prev_degree = degree_heuristics(classrooms,k,m,n,rrow,ccol,cclass);
                        if(curr_degree > prev_degree )
                        {
                            prev_degree=curr_degree;
                            rrow=row;
                            ccol=col;
                            cclass=classes;
                        }
                    }

                }
            }
        }
    }
    tuple<int,int,int> index;
    index=make_tuple(rrow,ccol,cclass);
    return index;


}
bool solve(vp_ &classrooms,mv_&sdata,m_ &visited,int k,int m,int n,int sitted)
{
    if(check_visited(visited,sitted))
        return true;

    int row,col,classes;
    tie(row,col,classes)=min_remaining_value(classrooms,sdata,visited,k,m,n);
    
    if(row==-1)
    return false;

    for(auto it=sdata.begin();it!=sdata.end();it++)
    {
        string batch=it->first;
        if(issafe(classrooms,batch,k,m,n,row,col,classes))
        {
            vector<string> v=it->second;
            for(auto itt=v.begin();itt!=v.end();itt++)
            {
                string roll=*itt;
                if(visited[roll]==0)
                {
                    classrooms[classes][row][col].first=batch;
                    classrooms[classes][row][col].second=roll;
                    visited[roll]=1;
                    sitted++;
                    // cout<<batch<<" "<<roll<<" "<<"\n";
                   
                    if(solve(classrooms,sdata,visited,k,m,n,sitted))
                        return true;

                    classrooms[classes][row][col].first="00";
                    classrooms[classes][row][col].second="00";
                    visited[roll]=0;
                    sitted--;
                    break;
                
                }
            }
        }
    }
    classrooms[classes][row][col].first="NIL";
    classrooms[classes][row][col].second="NIL";

    if(solve(classrooms,sdata,visited,k,m,n,sitted))
        return true;

    classrooms[classes][row][col].first="00";
    classrooms[classes][row][col].second="00";

    return false;
    

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,m,n;
        cin>>k>>m>>n;
        int l;
        cin>>l;
        mv_ sdata;  // student record store
        while(l--)
        {
            string batch,roll;
            cin>>batch>>roll;
            sdata[batch].push_back(roll);
        }
        for(auto it=sdata.begin();it!=sdata.end();it++)
        {
            sort(it->second.begin(),it->second.end());
        }
        
        m_ visited;        
        initialise_visited(sdata,visited);

        vp_ classrooms;
        initialise_classroom(classrooms,k,m,n);
        // for(auto it=visited.begin();it!=visited.end();it++)
        // {
        //     cout<<it->first<<" "<<it->second<<"\n";
        // }
        
        int row=0,col=0,classes=0,sitted=0;
        if(solve(classrooms,sdata,visited,k,m,n,sitted))
        {
            print(classrooms,k,m,n);
        }
        else{
            cout<<"-1\n";
        } 
    }
}
