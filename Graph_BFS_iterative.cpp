#include<iostream>
#include<process.h>
#include<queue>
using namespace std;
class ListGraph;
class GraphNode{
    int vertex;
    GraphNode *next;
    public:
      GraphNode(int v=0,GraphNode *n = NULL)
        {
            vertex = v;
            next = n;
        }
       int getVertex()
         {
             return vertex;
         }
      friend class ListGraph;
};
class ListGraph{     
     int n;    //No of vertices
     GraphNode **list;  //double pointer because 'array' of graphnode pointers
     bool *visited;
     public:
         ListGraph(int no=0)
            {
                n=no;
                list = new GraphNode*[n];
                for(int j=0;j<n;j++)
                      list[j]=NULL;
                visited = new bool[n];
                for(int i=0;i<n;i++)
                   visited[i] = false;
            }
         void create();
         void display();
         void BFS(int startVertex);
         
};

void ListGraph::create()
{
   char ans;
   GraphNode *temp = NULL;
   for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
           {
              cout<<"Is there edge between "<<i<<" and "<<j<<"?(y or n)";
              cin>>ans;
              if(ans=='y')
                {
                  GraphNode *newnode = new GraphNode(j);
                  if(list[i]==NULL)      //no outgoing vertex from vertex 'i'
                     {
                       temp = newnode;
                       list[i] = newnode;
                     }
                  else    //temp will point to the last node in the list 
                  {
                    temp->next =  newnode;
                    temp = newnode;
                  }
                }
           }
      }
}

void ListGraph::display()
{
  GraphNode *temp;
  for(int i=0;i<n;i++)
     {
       cout<<"\nVertex "<<i<<"->";
       temp = list[i];
       while(temp!=NULL)
         {
           cout<<"\tV"<<temp->vertex<<"->";
           temp=temp->next;
         }
        cout<<"\tNULL";    
}
}

void ListGraph::BFS(int startVertex)
{
         	if(startVertex>=n || startVertex<0)
        {
        cout<<"\nVertex not existing!";
        return;
        } 
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex); 
        while(!q.empty())
          {
              startVertex = q.front();
              cout << startVertex << " ";
              q.pop();              
              GraphNode* temp = list[startVertex];              
              while(temp!=NULL)
               {
                   int w = temp->vertex;
                   if(!visited[w])
                      {
                          visited[w] = true;
                          q.push(w);
                      }
                    temp = temp->next;
               }
          }
		 }
     

int main()
{
    int n;
    cout<<"Enter no of vertex in the Graph: ";
    cin>>n;
    ListGraph LG(n);
    LG.create();
    cout<<"\nAdjacency list for entered graph : ";
    LG.display();
    int v;
    cout<<"\nEnter vertex to start BFS sequence: ";
    cin>>v;
    cout<<"\n\nBFS Sequence: ";
    LG.BFS(v);
    cout<<"\b\b\b\b\b\b  ";
}

