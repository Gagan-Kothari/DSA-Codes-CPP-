#include <iostream>
using namespace std;

class Prims {
private:
    int n;
    int* parent;
    bool* MST;
    int* key;
    int** weight;

public:
    Prims() {
        cout << "Enter number of nodes: ";
        cin >> n;
        parent = new int[n];
        MST = new bool[n];
        key = new int[n];
        weight = new int*[n];
        for (int i = 0; i < n; i++) {
            weight[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            key[i] = 100000;
        }
        for (int i = 0; i < n; i++) {
            MST[i] = false;
        }
        key[0] = 0;
        parent[0] = -1;
    }

    void getGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "Enter weight at " << i << "," << j << ": ";
                cin >> weight[i][j];
            }
        }
    }

    int minKey() {
        int min = 100000;
        int minimumIndex = -1;

        for (int i=0;i<n;i++) {
            if (!MST[i] && key[i] < min) {
                min = key[i];
                minimumIndex = i;
            }
        }

        return minimumIndex;
    }

    void minimumSearchTree() {
        for (int i=0;i<n-1;i++){
            int j = minKey();
            MST[j] = true;

            for (int i=0;i<n;i++) {
                if (weight[j][i] && !MST[i] && weight[j][i] < key[i]) {
                    parent[i] = j;
                    key[i] = weight[j][i];
                }
            }
        }

        cout << "Edge \tWeight" << endl;
        for (int i = 1;i<n;i++) {
            cout << parent[i] << "-" << i << "\t" << weight[i][parent[i]] << endl;
        }
    }

};

int main() {
    Prims prims;
    prims.getGraph();
    prims.minimumSearchTree();
}
