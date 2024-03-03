
# Shortest path in an DAG

## use topo sort
### One source to all vertices
```C++
typedef pair<int,int> Pair;

class Solution
{   
    void dfs(int& curr,vector<Pair> adj[],bool visited[],int& V,stack<int>& s)
    {   
        
        //make curr visited
        visited[curr]=true;

        for(auto i:adj[curr])
        {
           
            if(!visited[i.first])
            dfs(i.first,adj,visited,V,s);
            
        }
        s.push(curr);
        

    }     

    
    public:
	vector<int> shortestDistance(int V, vector<Pair> adj[],int src) 
	{   
        //first calculate topo sort from src and store in a stack
        // visited array
        
        bool visited[V]={false};

        // empty stack
        stack<int> s;

        //dfs traversal
      
        dfs(src,adj,visited,V,s);
        
        vector<int> ans(V,1e6); // or INT_MAX
        ans[src]=0;
      
        while(!s.empty())
        {   
            int top=s.top();
      
            s.pop();
            for(auto j:adj[top])
            {   
               
          
                if(ans[top]+j.second<ans[j.first])
                ans[j.first]=ans[top]+j.second;
            }

        }
        
        
    return ans;
    }
	
};



```
#### Time Complexity: O(V+E)
#### Auxiliary space:3*O(V)

### fixed destination

```C++
int shortestDistance(int V, vector<Pair> adj[],int src,int des) 
	{   
        if(src==des) return 0;
        //first calculate topo sort from src and store in a stack
        // visited array
        
        bool visited[V]={false};

        // empty stack
        stack<int> s;

        //dfs traversal
      
        dfs(src,adj,visited,V,s);
        
        vector<int> ans(V,1e6); // or INT_MAX
        ans[src]=0;
      
        while(!s.empty())
        {   
            int top=s.top();
            if(top==des)
                return  ans[top];
            s.pop();

            for(auto j:adj[top])
            {   
               
                if(ans[top]+j.second<ans[j.first])
                ans[j.first]=ans[top]+j.second;
                
            }

        }
       
        
    return -1; //inf - not exist
    }


```
#### Time Complexity: O(V+E)
#### Auxiliary space: 3*O(V)
