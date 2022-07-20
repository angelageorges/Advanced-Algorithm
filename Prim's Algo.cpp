#include<iostream>
using namespace std;
#include<climits>
class List;
class Node
{
int vertice;
Node *next;
public:
Node(int v , Node *no=NULL)
{
vertice = v;
next = no;
}
friend class List;
};
class List
{
int n;
int **cost;
Node **list;
int mincost;
int minKey(int[], bool[]);
void print_MST(int[]);
public:
List(int no=0)
{
mincost =0;
n=no;
list = new Node *[n];
for (int j=0; j<n; j++)
{
list[j]=NULL;
}
cost = new int*[n];
for (int i=0;i<n; ++i)
{
cost[i] = new int [n];
}
}
void Create();
void Display();
void Prim();
int get_vertices();
void Display_cost_matrix();
};
int List :: get_vertices()
{
return n;
}
void List :: Display_cost_matrix()
{
cout<<"\n COST MATRIX: \n";
for (int i=0; i<n; i++)
{
cout<<"\t "<<i;
}
cout<<"\n -----------------------------------------------------------------------------";
cout<<"\n";
for (int i=0; i<n; i++)
{
cout<<i<<" |";
for (int j=0; j<n; j++)
{
if (cost[i][j] == INT_MAX)
{
cout<<"\tInfi";
}
else
{
cout<<"\t"<<cost[i][j];
}
}
cout<<"\n";
}
}
// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int List :: minKey(int key[], bool mstSet[])
{
 // Initialize min value
 int min = INT_MAX;
int min_index;

 for (int v = 0; v<n; v++)
 {
 if (mstSet[v] == false && key[v] < min) // visit
 {
 min = key[v];
min_index = v;
 }
 }
 return min_index;

// if(visited[v]==false && key[v]<min)
}

void List :: print_MST(int parent[]) // A utility function to print the constructed MST stored in parent[]
{
 cout<<"Edge \tWeight\n";
 for (int i = 1; i<n; i++)
 {
 cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";
 mincost+=cost[i][parent[i]];
 }
 cout<<"\n Total cost: "<<mincost;
}
void List :: Prim()
{
int *parent=new int[n]; // to store
 int *key = new int[n];
 bool *visit = new bool[n];
 for(int i=0;i<n;i++)
 {
 key[i]=INT_MAX;
 visit[i]=false;
 parent[i]=-1;
 }

 key[0]=0;
 parent[0]=-1;
 for(int i=0;i<n-1;i++)
 {
 int u = minKey(key,visit); // u will store min_index Next vertex consider for cost to be min
 visit[u]=true;
 for(int v=0;v<n;v++) // node to connect with u
 {
 if(cost[u][v]!=0 && visit[v] == false && cost[u][v]<key[v]) //
 {
 parent[v]=u;
 key[v]=cost[u][v];
 }
 }
 }
 print_MST(parent);

}
void List :: Create()
{
char ans;
Node *temp = NULL;
for (int i=0; i<n; i++)
{
for (int j=0; j<n; j++)
{
if (i!=j)
{
 cout<<" Is edge present between "<<i<<" and "<<j<<" (y/n) : ";
 cin>>ans;
 if (ans == 'y')
 {
 cout<<" \n Enter cost between "<<i<<" and "<<j<<" : ";
 cin>>cost[i][j];
 Node *newnode = new Node(j);
 if (list[i] == NULL)
 {
 temp = newnode; // temp will point to newnode
 list[i] = newnode; // and list will store newnode
 }
 else
 {
 temp->next = newnode;
 temp = newnode; // temp will point at the end of the list
 }
 }
 else
 {
 cost[i][j]=INT_MAX;
 }
 }
 else
 {
 cost[i][j] = 0;
}
}
}
}
void List :: Display()
{
Node *temp;
 for(int i=0;i<n;i++)
 {
 cout<<"\nVertex "<<i<<" => ";
 temp=list[i];
 while(temp!=NULL)
 {
 cout<<" V "<<temp->vertice<<" -> ";
 temp=temp->next;
 }
 cout<<" NULL";
 }
}
// Driver code
int main()
{
 int num;
 cout<<"\n ENTER THE NUMBER OF VERTICES OF GRAPH: ";
 cin>>num;
 List L(num);
 L.Create();

 cout<<"\n Adjacency list for entered graph: ";
 L.Display();

 L.Display_cost_matrix();
 L.Prim();

 return 0;
}


