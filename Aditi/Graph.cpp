
#include <iostream>
using namespace std;

class Graph {
private:
    int graph[10][10];
    int members;

    void dfsHelper(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < members; i++) {
            if (graph[node][i] > 0 && !visited[i]) {
                dfsHelper(i, visited);
            }
        }
    }

public:
    Graph(int n) {
        members = n;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                graph[i][j] = 0;
            }
        }
    }

    void addDebt(int from, int to, int amount) {
        if (from < 0 || from >= members ||
            to < 0 || to >= members ||
            from == to || amount <= 0) {
            cout << "Invalid debt!\n";
            return;
        }

        graph[from][to] += amount;
        cout << "Debt added successfully!\n";
    }

    void displayGraph() {
        cout << "\n===== DEBT GRAPH =====\n";

        for (int i = 0; i < members; i++) {
            for (int j = 0; j < members; j++) {
                if (graph[i][j] > 0) {
                    cout << "Member " << i
                         << " owes Member " << j
                         << ": Rs. " << graph[i][j]
                         << endl;
                }
            }
        }
    }

    void BFS(int start) {
        if (start < 0 || start >= members) return;

        bool visited[10] = {false};
        int queue[10];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "\nBFS Traversal: ";

        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            for (int i = 0; i < members; i++) {
                if (graph[current][i] > 0 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }

        cout << endl;
    }

    void DFS(int start) {
        if (start < 0 || start >= members) return;

        bool visited[10] = {false};

        cout << "DFS Traversal: ";
        dfsHelper(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(4);

    // 0 = Aditi
    // 1 = Iti
    // 2 = Priyal
    // 3 = Riddhisha

    g.addDebt(1, 0, 300);
    g.addDebt(2, 0, 200);
    g.addDebt(3, 2, 100);

    g.displayGraph();

    g.BFS(3);
    g.DFS(3);

    return 0;
}