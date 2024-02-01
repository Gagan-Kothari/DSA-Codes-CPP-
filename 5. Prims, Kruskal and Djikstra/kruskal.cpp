#include <iostream>
using namespace std;

class Kruskal{
    private:
        int n;
        int** weight;
        struct Edge{
            int source;
            int dest;
            int wgt;
        };

    public:
        Kruskal(){
            cout << "Enter number of nodes: ";
            cin >> n;
            weight = new int*[n];
            for(int i=0;i<n;i++){
                weight[i] = new int[n];
            }
        }

        void getval(){
            cout << "Enter the adjacency matrix:\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << "Enter weight at " << i << "," << j << " : ";
                    cin >> weight[i][j];
                }
            }
        }

        int parentsearch(int* parent, int node) {
            if(parent[node] == node){
                return node;
            }
            return parentsearch(parent,parent[node]);
        }

        void join(int* parent, int x, int y) {
            int xset = parentsearch(parent,x);
            int yset = parentsearch(parent,y);
            parent[yset] = xset;
        }

        void sortEdges(Edge* edges, int numEdges) {
            for (int i=0;i<numEdges;i++) {
                for (int j=i+1;j<numEdges;j++) {
                    if (edges[i].wgt>edges[j].wgt) {
                        Edge temp = edges[i];
                        edges[i] = edges[j];
                        edges[j] = temp;
                    }
                }
            }
        }

        void kruskalMST(){
            int* parent = new int[n];
            for (int i = 0; i < n; i++){
                parent[i] = i;
            }

            Edge* edges = new Edge[n*n];
            int num = 0;

            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(weight[i][j]>0){
                        edges[num].source = i;
                        edges[num].dest = j;
                        edges[num].wgt = weight[i][j];
                        num++;
                    }
                }
            }

            sortEdges(edges,num);

            cout << "Minimum Spanning Tree Edges:\n";
            cout << "Edge \tWeight" << endl;
            int MSTedge = 0;
            int index = 0;

            while(MSTedge<n-1 && index<num){
                Edge current = edges[index++];
                int x = parentsearch(parent,current.source);
                int y = parentsearch(parent,current.dest);

                if(x!=y){
                    cout << current.source << " - " << current.dest << "\t" << current.wgt << endl;
                    join(parent,x,y);
                    MSTedge++;
                }
            }
        }
};

int main() {
    Kruskal kruskal;
    kruskal.getval();
    kruskal.kruskalMST();
}
// title
// aim
// algo
// program
// output

// do it in word