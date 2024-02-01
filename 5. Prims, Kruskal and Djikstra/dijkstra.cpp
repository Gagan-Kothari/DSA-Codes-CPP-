#include <iostream>

using namespace std;

class Dijkstra{
    private:
        int n;
        int** weight;

    public:
        Dijkstra(){
            cout << "Enter number of nodes: ";
            cin >> n;
            weight = new int*[n];
            for(int i=0;i<n;i++) {
                weight[i] = new int[n];
            }
        }

        void getval(){
            cout << "Enter the adjacency matrix:\n";
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    cout << "Enter weight at " << i << "," << j << " : ";
                    cin >> weight[i][j];
                }
            }
        }

        int min_dist(int* dist, bool* visited){
            int minDist = INT_MAX;
            int minIndex = -1;
            for(int i=0;i<n;i++){
                if(!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    minIndex = i;
                }
            }
            return minIndex;
        }

        void printpath(int* parent, int j){
            if(parent[j] == -1){
                cout << j;
                return;
            }
            printpath(parent,parent[j]);
            cout << " -> " << j;
        }

        void printSolution(int* dist,int* parent,int srce) {
            cout << "Vertex\tDistance\tPath\n";
            for (int i=0;i<n;i++){
                cout << srce << " -> " << i << "\t" << dist[i] << "\t\t";
                printpath(parent, i);
                cout << endl;
            }
        }

        void dijkstraSSSP(int srce) {
            int* dist = new int[n];
            bool* visited = new bool[n];
            int* parent = new int[n];
            for (int i = 0; i < n; i++) {
                dist[i] = INT_MAX;
                visited[i] = false;
                parent[i] = -1;
            }
            dist[srce] = 0;

            for (int count = 0; count < n - 1; count++) {
                int u = min_dist(dist, visited);
                visited[u] = true;
                for (int v = 0; v < n; v++) {
                    if (!visited[v] && weight[u][v] && dist[u] != INT_MAX && dist[u] + weight[u][v] < dist[v]) {
                        dist[v] = dist[u] + weight[u][v];
                        parent[v] = u;
                    }
                }
            }
            printSolution(dist,parent,srce);
        }
};

int main() {
    Dijkstra dijkstra;
    int x=1;
    int option;
    int source;

    do{
        cout << "MENU: " << endl;
        cout << "1.Shortest Path Algorithm" << endl;
        cout << "0.Exit" << endl << endl;
        cout << "Enter option: ";
        cin >> option;
        switch(option){
            default:
                cout << "Enter a valid option";
                break;
            
            case 1:
                dijkstra.getval();
                cout << "Enter the source node: ";
                cin >> source;
                dijkstra.dijkstraSSSP(source);
                break;

            case 0:
                cout << "Exited Successfully";
                x = 0;
                break;
        }
    }while(x);
}