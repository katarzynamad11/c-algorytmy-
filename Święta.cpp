#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <chrono>
using namespace std;

vector<vector<int>> readGraphFromFile(const string& filename) {
    vector<vector<int>> graph;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    int maxNode = -1; 

    int u, v;
    while (file >> u >> v) {
        maxNode = max(maxNode, max(u, v));
    }

   
    graph.resize(maxNode + 1);

    
    file.clear();
    file.seekg(0, ios::beg);

    while (file >> u >> v) {
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    file.close();

    return graph;
}



void bfsQueue(const vector<vector<int>>& graph, int startNode) {
    queue<int> q;
    unordered_set<int> visited;

    q.push(startNode);
    visited.insert(startNode);

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}


void bfsStack(const std::vector<std::vector<int>>& graph, int startNode) {
    std::stack<int> s;
    std::unordered_set<int> visited;

    s.push(startNode);
    visited.emplace(startNode);

    while (!s.empty()) {
        int current = s.top();
        std::cout << current << " ";
        s.pop();

        // Dodajemy sąsiadów do stosu w odwrotnej kolejności
        for (auto it = graph[current].rbegin(); it != graph[current].rend(); ++it) {
            int neighbor = *it;
            if (visited.find(neighbor) == visited.end()) {
                s.push(neighbor);
                visited.emplace(neighbor);
            }
        }
    }
}

void dfsStack(const vector<vector<int>>& graph, int startNode) {
    stack<int> s;
    unordered_set<int> visited;

    s.push(startNode);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (visited.find(current) == visited.end()) {
            cout << current << " ";
            visited.insert(current);
        }

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                s.push(neighbor);
            }
        }
    }
}

void dfsQueue(const std::vector<std::vector<int>>& graph, int startNode) {
    std::queue<int> q;
    std::unordered_set<int> visited;

    q.push(startNode);
    visited.emplace(startNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        std::cout << current << " ";

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.emplace(neighbor);
            }
        }
    }
}

int main() {
   
   vector<vector<int>> graph = readGraphFromFile("email-Eu-core.txt");


   auto start_time = std::chrono::high_resolution_clock::now();
    cout << "BFS starting from node 0: ";
    dfsQueue(graph, 0);
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate the duration (in milliseconds by default)
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Output the duration
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;


   //auto start_time_dfs = std::chrono::high_resolution_clock::now();
   //cout << "DFS starting from node 0: ";
   //dfsStack(graph, 0);  
   //auto end_time_dfs = std::chrono::high_resolution_clock::now();

   //// Calculate the duration (in milliseconds by default)
   //auto duration_dfs = std::chrono::duration_cast<std::chrono::milliseconds>(end_time_dfs - start_time_dfs);

   //// Output the duration
   //std::cout << "DFS Execution time: " << duration_dfs.count() << " milliseconds" << std::endl;


    return 0;
}