#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

struct Point {
    int id;
    double x, y;

    Point(int i, double px, double py) : id(i), x(px), y(py) {}
};

struct Node {
    Point point;
    Node* left;
    Node* right;

    Node(Point p) : point(p), left(nullptr), right(nullptr) {}
};

class KDTree {
public:
    KDTree(vector<Point>& points) {
        root = buildTree(points, 0, points.size() - 1, 0);
    }

    vector<Point> rangeSearch(Point& center, double radius) {
        vector<Point> pointsInRadius;
        rangeSearch(root, center, radius, 0, pointsInRadius);
        return pointsInRadius;
    }

private:
    Node* root;

    Node* buildTree(vector<Point>& points, int start, int end, int depth) {
        if (start > end) {
            return nullptr;
        }

        int axis = depth % 2;
        int median = (start + end) / 2;

        nth_element(points.begin() + start, points.begin() + median, points.begin() + end + 1,
            [axis](const Point& a, const Point& b) {
                return axis == 0 ? a.x < b.x : a.y < b.y;
            });

        Node* node = new Node(points[median]);
        node->left = buildTree(points, start, median - 1, depth + 1);
        node->right = buildTree(points, median + 1, end, depth + 1);

        return node;
    }

    void rangeSearch(Node* node, Point& center, double radius, int depth, vector<Point>& result) {
        if (node == nullptr) {
            return;
        }

        int axis = depth % 2;
        double dist = calculateDistance(center, node->point);

        if (dist <= radius) {
            result.push_back(node->point);
        }

        if (axis == 0 ? (center.x - radius) < node->point.x : (center.y - radius) < node->point.y) {
            rangeSearch(node->left, center, radius, depth + 1, result);
        }

        if (axis == 0 ? (center.x + radius) > node->point.x : (center.y + radius) > node->point.y) {
            rangeSearch(node->right, center, radius, depth + 1, result);
        }
    }

    double calculateDistance(const Point& p1, const Point& p2) {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
};

int main() {
    const double maxX = 10.0;
    const double maxY = 10.0;
    const int numArtifacts = 1000;
    const double maxDisplacement = 0.5;
    const double searchRadius = 1.0;
    const int numSteps = 20;

    vector<Point> artifacts;
    for (int i = 0; i < numArtifacts; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX * maxX;
        double y = static_cast<double>(rand()) / RAND_MAX * maxY;
        artifacts.emplace_back(i + 1, x, y);
    }

    KDTree kdTree(artifacts);

    for (int step = 1; step <= numSteps; ++step) {
        string displacementFile = "przemieszczenia_" + to_string(step) + ".txt";
        ifstream file(displacementFile);
        if (!file.is_open()) {
            cerr << "Error opening file: " << displacementFile << endl;
            exit(EXIT_FAILURE);
        }

        vector<Point> currentPositions = artifacts;
        int id;
        double dx, dy;
        while (file >> id >> dx >> dy) {
            Point& currentPoint = currentPositions[id - 1];
            currentPoint.x = min(max(currentPoint.x + dx, 0.0), maxX);
            currentPoint.y = min(max(currentPoint.y + dy, 0.0), maxY);
        }

        file.close();

        // Random Jedi
        double jediX = static_cast<double>(rand()) / RAND_MAX * maxX;
        double jediY = static_cast<double>(rand()) / RAND_MAX * maxY;
        Point jedi(0, jediX, jediY);

        vector<Point> pointsInRadius = kdTree.rangeSearch(jedi, searchRadius);

        cout << "Step " << step << ": Jedi at (" << jediX << ", " << jediY << ") - Artifacts in radius:" << endl;
        for (const Point& point : pointsInRadius) {
            cout << "Artifact " << point.id << " at (" << point.x << ", " << point.y << ")" << endl;
        }
        cout << "-------------------------" << endl;
    }

    return 0;
}
