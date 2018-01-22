/***********
Modified code from GeeksForGeeks
***********/



bool run_check(int n, int source)
{
 
    // Assign first color to source
    colorArr[source] = 1;
 
    queue <int> q;
    q.push(source);
 
    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();
 
         
 
        // Find all non-colored adjacent vertices
       auto it = graph[u].begin();
        while(it != graph[u].end())
        {
            // An edge from u to v exists and destination v is not colored
            if (colorArr[*it] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[*it] = 1 - colorArr[u];
                q.push(*it);
            }
 
            else if (colorArr[*it] == colorArr[u])
                return false;

            it++;
        }
    }

    return true;	
} 
