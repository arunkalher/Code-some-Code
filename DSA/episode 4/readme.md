
# Shortest path in an unweighted graph


### One source to all vertices
```C++
class Solution
{   public:
	vector<int> shortestDistance(int V, vector<int> adj[],int src) 
	{   
        vector<int> pathLength(V,-1); 
        pathLength[src]=0;
        queue<int> q;
        q.push(src);
        int answer=0;
        while(!q.empty())
        {
            answer+=1;
            int size=q.size();
            while(size--)
            {
                int front=q.front();
                q.pop();
                for(auto j:adj[front])
                {
                    if(pathLength[j]==-1)
                    {
                        pathLength[j]=answer;
                        q.push(j);
                    }
                }
            }

        }
        return pathLength;

	}
};


```
#### Time Complexity: O(V+E)
#### Auxiliary space: O(V)-queue+)(V)-answer array

### fixed destination

```C++
class Solution
{   public:
	int shortestDistance(int V, vector<int> adj[],int src,int des) 
	{       
        if(src==des)
        return 0;
        vector<int> pathLength(V,-1); 
        pathLength[src]=0;
        queue<int> q;
        q.push(src);
        int answer=0;
        while(!q.empty())
        {
            answer+=1;
            int size=q.size();
            while(size--)
            {
                int front=q.front();
                q.pop();
                for(auto j:adj[front])
                {
                    if(pathLength[j]==-1)
                    {   if(j==des)
                        return answer;
                        pathLength[j]=answer;
                        q.push(j);
                    }
                }
            }

        }
        return -1;

	}
};


```
#### Time Complexity: O(V+E)
#### Auxiliary space: O(V)-queue+)(V)-answer array

