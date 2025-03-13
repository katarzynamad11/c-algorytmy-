#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Point {
    int id;
    double x, y;

    Point(int i, double px, double py) : id(i), x(px), y(py) {}
};

double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void readPositions(const string& filename, vector<Point>& positions) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int id;
    double x, y;
    while (file >> id >> x >> y) {
        positions.emplace_back(id, x, y);
    }

    file.close();
}

void updatePositions(vector<Point>& currentPositions, const string& displacementFile, double maxDisplacement) {
    ifstream file(displacementFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << displacementFile << endl;
        exit(EXIT_FAILURE);
    }

    int id;
    double dx, dy;
    while (file >> id >> dx >> dy) {
        Point& currentPoint = currentPositions[id - 1];
        currentPoint.x = min(max(currentPoint.x + dx, 0.0), 10.0);
        currentPoint.y = min(max(currentPoint.y + dy, 0.0), 10.0);
    }

    file.close();
}

vector<Point> findPointsInRadius(const vector<Point>& artifacts, const Point& jedi, double radius) {
    vector<Point> pointsInRadius;
    for (const Point& artifact : artifacts) {
        if (calculateDistance(jedi, artifact) <= radius) {
            pointsInRadius.push_back(artifact);
        }
    }
    return pointsInRadius;
}

int main() {
    const double maxX = 10.0;
    const double maxY = 10.0;
    const int numArtifacts = 1000;
    const double maxDisplacement = 0.5;
    const double searchRadius = 1.0;
    const int numSteps = 20;

    // Wczytaj początkowe pozycje z pliku
    vector<Point> initialPositions;
    readPositions("pozycje_poczatkowe.txt", initialPositions);

    vector<Point> currentPositions = initialPositions;

    for (int step = 1; step <= numSteps; ++step) {
        string displacementFile = "przemieszczenia_" + to_string(step) + ".txt";
        updatePositions(currentPositions, displacementFile, maxDisplacement);

        // Random Jedi 
        double jediX = static_cast<double>(rand()) / RAND_MAX * maxX;
        double jediY = static_cast<double>(rand()) / RAND_MAX * maxY;
        Point jedi(0, jediX, jediY);

        vector<Point> pointsInRadius = findPointsInRadius(currentPositions, jedi, searchRadius);

        cout << "Step " << step << ": Jedi at (" << jediX << ", " << jediY << ") - Artifacts in radius:" << endl;
        for (const Point& point : pointsInRadius) {
            cout << "Artifact " << point.id << " at (" << point.x << ", " << point.y << ")" << endl;
        }
        cout << "-------------------------" << endl;
    }

    return 0;
}
