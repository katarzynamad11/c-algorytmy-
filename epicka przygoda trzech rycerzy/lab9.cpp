#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>
#include <stack>
#include <ctime>
#include <cmath>

using namespace std;

struct Point {
    int row;
    int col;
    int distance;
};

int startRow, startCol, endRow, endCol;
vector<Point> path;
vector<vector<int>> distances;
const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };

struct ComparePoints {
    Point destination;

    ComparePoints(const Point& dest) : destination(dest) {}

    bool operator()(const Point& p1, const Point& p2) {
        double dist_p1 = sqrt(pow(p1.row - destination.row, 2) + pow(p1.col - destination.col, 2));
        double dist_p2 = sqrt(pow(p2.row - destination.row, 2) + pow(p2.col - destination.col, 2));

        return dist_p1 > dist_p2;
    }
};

vector<string> readLabyrinthFromFile(const string& filename) {
    vector<string> labyrinth;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(file, line)) {
        labyrinth.push_back(line);
    }

    file.close();
    return labyrinth;
}

void findShortestPathDijkstra(const vector<string>& labyrinth, vector<vector<int>>& distances) {
    // kolejka priorytetowa o nazwie pq, przechowuje punkty na podstawie ComparePoints

    priority_queue<Point, vector<Point>, ComparePoints> pq(ComparePoints({ endRow, endCol }));

    //punkt startowy
    pq.push({ startRow, startCol, 0 });
    distances[startRow][startCol] = 0;

    while (!pq.empty()) {
        Point current = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int new_row = current.row + dr[i];
            int new_col = current.col + dc[i];

            if (new_row >= 0 && new_row < labyrinth.size() &&
                new_col >= 0 && new_col < labyrinth[0].length() &&
                labyrinth[new_row][new_col] != 'x') {

                int new_distance = current.distance + 1;

                //sprawdzanie czy nowa odleglosc jest mniejsza niz akutalna 
                if (new_distance < distances[new_row][new_col] || distances[new_row][new_col] == -1) {
                    distances[new_row][new_col] = new_distance;
                    pq.push({ new_row, new_col, new_distance });
                }
            }
        }
    }
}

void findShortestPath(const vector<string>& labyrinth, vector<vector<int>>& distances) {
    queue<Point> q;
    q.push({ startRow, startCol });
    //macierz distances, punkt A na 0 
    distances[startRow][startCol] = 0;

    //przesuniecia pionowo i poziomo
    const int dr[] = { -1, 1, 0, 0 };
    const int dc[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_row = current.row + dr[i];
            int new_col = current.col + dc[i];

            if (new_row >= 0 && new_row < labyrinth.size() &&
                new_col >= 0 && new_col < labyrinth[0].length() &&
                labyrinth[new_row][new_col] != 'x' &&
                distances[new_row][new_col] == -1) {

                distances[new_row][new_col] = distances[current.row][current.col] + 1;
                q.push({ new_row, new_col });

                if (labyrinth[new_row][new_col] == 'B') {

                    Point currentPoint = { new_row, new_col };
                    path.push_back(currentPoint);

                    while (currentPoint.row != startRow || currentPoint.col != startCol) {
                        int currentDistance = distances[currentPoint.row][currentPoint.col];

                        for (int j = 0; j < 4; j++) {
                            int prev_row = currentPoint.row - dr[j];
                            int prev_col = currentPoint.col - dc[j];

                            if (prev_row >= 0 && prev_row < labyrinth.size() &&
                                prev_col >= 0 && prev_col < labyrinth[0].length() &&
                                distances[prev_row][prev_col] == currentDistance - 1) {

                                currentPoint = { prev_row, prev_col };
                                path.push_back(currentPoint);
                                break;
                            }
                        }
                    }

                    //odwracam wektor 

                    reverse(path.begin(), path.end());

                    return;
                }
            }
        }
    }
}

// w glab

//sprawdza czy punkt o podanych współrzędnych  znajduje się na aktualnej ścieżce.
bool isOnPath(int row, int col) {
    for (const Point& p : path) {
        if (p.row == row && p.col == col) {
            return true;
        }
    }
    return false;
}

bool findPathDFS(const vector<string>& labyrinth, int currentRow, int currentCol) {
    path.push_back({ currentRow, currentCol });

    if (currentRow == endRow && currentCol == endCol) {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int new_row = currentRow + dr[i];
        int new_col = currentCol + dc[i];

        if (new_row >= 0 && new_row < labyrinth.size() &&
            new_col >= 0 && new_col < labyrinth[0].length() &&
            labyrinth[new_row][new_col] != 'x' &&
            !isOnPath(new_row, new_col)) {

            if (findPathDFS(labyrinth, new_row, new_col)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

void visualizePath(vector<string>& labyrinth, const vector<Point>& path) {
    for (const Point& point : path) {
        labyrinth[point.row][point.col] = '+';
    }
}

void printLabyrinth(const vector<string>& labyrinth) {
    for (const string& row : labyrinth) {
        cout << row << endl;
    }
}

int main() {
    string filename = "labirynt_v2.txt";
    vector<string> labyrinth = readLabyrinthFromFile(filename);

    cout << "Initial Labyrinth:" << endl;
    printLabyrinth(labyrinth);
    cout << endl;

    for (int i = 0; i < labyrinth.size(); i++) {
        for (int j = 0; j < labyrinth[i].length(); j++) {
            if (labyrinth[i][j] == 'A') {
                startRow = i;
                startCol = j;
            }
            else if (labyrinth[i][j] == 'B') {
                endRow = i;
                endCol = j;
            }
        }
    }

    distances.assign(labyrinth.size(), vector<int>(labyrinth[0].length(), -1));

    // Find the shortest path from A to B using BFS
    cout << "Shortest Path using BFS:" << endl;
    findShortestPath(labyrinth, distances);

    // Wizualizacja i druk ścieżki
    visualizePath(labyrinth, path);
    printLabyrinth(labyrinth);

    // Wydruk liczby kroków
    if (!path.empty()) {
        int steps = path.size() - 1; // Number of steps is the length of the path minus 1
        cout << "Number of steps: " << steps << endl;
    }
    else {
        cout << "No path found." << endl;
    }

    // Resetowanie zmiennych dla kolejnego algorytmu
    path.clear();
    distances.assign(labyrinth.size(), vector<int>(labyrinth[0].length(), -1));

    cout << "Shortest Path using Dijkstra's Algorithm:" << endl;
    findShortestPathDijkstra(labyrinth, distances);

    Point currentPoint = { endRow, endCol, distances[endRow][endCol] };
    path.push_back(currentPoint);

    while (currentPoint.row != startRow || currentPoint.col != startCol) {
        for (int j = 0; j < 4; j++) {
            int prev_row = currentPoint.row - dr[j];
            int prev_col = currentPoint.col - dc[j];

            if (prev_row >= 0 && prev_row < labyrinth.size() &&
                prev_col >= 0 && prev_col < labyrinth[0].length() &&
                distances[prev_row][prev_col] == currentPoint.distance - 1) {

                currentPoint = { prev_row, prev_col, currentPoint.distance - 1 };
                path.push_back(currentPoint);
                break;
            }
        }
    }

    reverse(path.begin(), path.end());

    visualizePath(labyrinth, path);
    printLabyrinth(labyrinth);

    if (!path.empty()) {
        int steps = path.size() - 1;
        cout << "Number of steps: " << steps << endl;
    }
    else {
        cout << "No path found." << endl;
    }

    path.clear();
    distances.assign(labyrinth.size(), vector<int>(labyrinth[0].length(), -1));

    cout << "Path using Brute Force DFS:" << endl;
    findPathDFS(labyrinth, startRow, startCol);

    visualizePath(labyrinth, path);
    printLabyrinth(labyrinth);

    if (!path.empty()) {
        int steps = path.size() - 1;
        cout << "Number of steps: " << steps << endl;
    }
    else {
        cout << "No path found." << endl;
    }

    path.clear();

    distances.assign(labyrinth.size(), vector<int>(labyrinth[0].length(), -1));
    

    return 0;
}
