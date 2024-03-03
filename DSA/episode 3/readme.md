# Detect cycle in a directed graph
## Method 1
```C++
class Solution {
  public:
   bool check(int& curr,vector<int> adj[],bool* visited,bool* cycle)
  {
       if(cycle[curr])
       return true;
         if(visited[curr])
         return false;
         
       
       visited[curr]=true;
       cycle[curr]=true;
      
       for(auto j:adj[curr])
       {
            if(check(j,adj,visited,cycle))
            return true;
       }
       cycle[curr]=false;
       return false;
   }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        bool visited[V]={false};
        
        
        for(int i=0;i<V;i++)
        {   
            if(!visited[i]){
         
         bool cycle[V]={false};
            if(check(i,adj,visited,cycle))
            return true;
            }
            
        }
        return false;
    }
    
};
```

#### Time Complexity: O(V+E)
#### Auxiliary space: 2*O(V)-visited array and check array

## Method 2 - can use a unordered set also

```C++
class Solution {
  public:
   bool check(int& curr,vector<int> adj[],bool* visited,unordered_set<int>& cycle)
  {
       if(cycle.find(curr)!=cycle.end())
       return true;
         if(visited[curr])
         return false;
         
       
       visited[curr]=true;
       cycle.insert(curr);
      
       for(auto j:adj[curr])
       {
            if(check(j,adj,visited,cycle))
            return true;
       }
       cycle.erase(curr);
       return false;
   }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        bool visited[V]={false};
        
        
        for(int i=0;i<V;i++)
        {   
            if(!visited[i]){
         
            unordered_set<int> cycle;
            if(check(i,adj,visited,cycle))
            return true;
            }
            
        }
        return false;
    }
    
};

```

#### Time Complexity: O(V+E)
#### Auxiliary space: 2*O(V)-visited array and unordered_set