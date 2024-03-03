# Topological Sorting
## Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.
### Method-1
#### We can use DFS. We can store vertices in a stack according to dfs calls and in last reverse a stack and return it.
```C++
class Solution
{                                                                                                                                                                                                                                                                                                                                                                                                                                                    
void dfs(int& curr,vector<int> adj[],bool visited[],int& V,stack<int>& s)
    {   
        // make curr visited
        visited[curr]=true;

        for(auto i:adj[curr])
        {
            if(!visited[i])
            dfs(i,adj,visited,V,s);
        }
        s.push(curr);

    }                                                                                                                                                                                                                                                                                                                                                                                                                                   
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   
        // visited array
        bool visited[V]={false};

        // empty stack
        stack<int> s;

        // dfs traversal
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            dfs(i,adj,visited,V,s);
        }
        // topo vector
    vector<int> topo;
    while (!s.empty())
    {
        topo.push_back(s.top());
        s.pop();
    }
    return topo;
	}


    
};
```

#### Time Complexity: O(V+E). The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS
#### Auxiliary space: O(V)-stack+2*O(V)-visited array and answer vector


### Method -2 ( Kahn Algo)


```C++
int Indegree[V]={0};
        for (int i=0;i<V;i++)
        {   
            for(auto j:adj[i])
            Indegree[j]++;
        }
     
        
        stack<int> s;
       
        
        for(int i=0;i<V;i++)
        {
            if(Indegree[i]==0)
            s.push(i);
        }

        // s.size() ==0 Not a DAG
        
        vector<int> topo;
        
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            topo.push_back(top);
            for(auto i: adj[top])
            {
                Indegree[i]--;
                if (Indegree[i]==0)
                s.push(i);
            }
        }
        //if (s.size()!=v.size()) Not a DAG - cycle exists
      
        return topo;

```
