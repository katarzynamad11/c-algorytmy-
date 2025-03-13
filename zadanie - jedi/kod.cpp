#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
using namespace std;

// Struktura przechowująca pozycje artefaktów
struct Artifact {
    int id;
    double x, y;
};

// Funkcja wczytująca pozycje początkowe z pliku
vector<Artifact> readInitialPositions(const string& filePath) {
    ifstream file(filePath);
    vector<Artifact> initialPositions;
    Artifact artifact;

    while (file >> artifact.id >> artifact.x >> artifact.y) {
        initialPositions.push_back(artifact);
    }

    return initialPositions;
}

// Funkcja aktualizująca pozycje artefaktów na podstawie przemieszczeń
void updatePositions(vector<Artifact>& positions, const string& displacementFile, double d) {
    ifstream file(displacementFile);
    int artifactId;
    double dx, dy;

    while (file >> artifactId >> dx >> dy) {
        //  Aktualizacja pozycji z uwzględnieniem ograniczenia d
        if (sqrt(pow(dx, 2) + pow(dy, 2)) <= 0.5)
        {
            positions[artifactId - 1].x += dx;
            positions[artifactId - 1].y += dy;
        }
    }
}

//void updatePositionsRecursive(vector<Artifact>& positions, ifstream& file, double d) {
//    int artifactId;
//    double dx, dy;
//
//    while (file >> artifactId >> dx >> dy) {
//        // Aktualizacja pozycji z uwzględnieniem ograniczenia d
//        if (sqrt(pow(dx, 2) + pow(dy, 2)) <= 0.5)
//        {
//            positions[artifactId - 1].x += dx;
//            positions[artifactId - 1].y += dy;
//        }
//        // Wywołanie rekurencyjne dla następnego rekordu w pliku
//        updatePositionsRecursive(positions, file, d);
//    }
//}
//
//void updatePositions(vector<Artifact>& positions, const string& displacementFile, double d) {
//    ifstream file(displacementFile);
//    updatePositionsRecursive(positions, file, d);
//    file.close();
//}

// Struktura reprezentująca obszar AxB
struct Area {
    double ax, ay, bx, by;
};

// Funkcja generująca losowe pozycje Jedi w zadanym obszarze
vector<Artifact> generateJediPositions(int numPositions, const Area& area) {
    vector<Artifact> jediPositions;
    srand(time(NULL));

    for (int i = 0; i < numPositions; ++i) {
        Artifact jedi;
        jedi.id = i;
        jedi.x = area.ax + static_cast<double>(rand()) / RAND_MAX * (area.bx - area.ax);
        jedi.y = area.ay + static_cast<double>(rand()) / RAND_MAX * (area.by - area.ay);
        jediPositions.push_back(jedi);
    }

    return jediPositions;
}

// Funkcja znajdująca artefakty w odległości nie większej niż h od danej pozycji Jedi
//vector<int> findArtifactsNearJedi(const Artifact& jediPosition, const vector<Artifact>& artifactPositions, double h) {
//    vector<int> nearArtifacts;
//
//    for (const Artifact& artifact : artifactPositions) {
//        double distance = sqrt(pow(artifact.x - jediPosition.x, 2) + pow(artifact.y - jediPosition.y, 2));
//        if (distance <= h) {
//            nearArtifacts.push_back(artifact.id - 1);
//        }
//    }
//
//    return nearArtifacts;
//}

vector<int> findArtifactsNearJedi(const Artifact& jediPosition, const vector<Artifact>& artifactPositions, double h) {
    vector<int> nearArtifacts;
    double hSquared = h * h;
    for (const Artifact& artifact : artifactPositions) {
        double distanceSquared = (artifact.x - jediPosition.x) * (artifact.x - jediPosition.x) +
            (artifact.y - jediPosition.y) * (artifact.y - jediPosition.y);

        if (distanceSquared <= hSquared) {
            nearArtifacts.push_back(artifact.id);
        }
    }

    return nearArtifacts;
}


int main() {
    // Parametry testowe
    Area area = { 0, 0, 10, 10 };
    int numArtifacts = 1000;
    double d = 0.5;
    double h = 1.0;
    int numSteps = 20;

    // Inicjalizacja pozycji artefaktów
    vector<Artifact> initialPositions = readInitialPositions("pozycje_poczatkowe.txt");
    auto start_time = std::chrono::high_resolution_clock::now();
    // Symulacja przemieszczeń i poszukiwań
    for (int step = 1; step <= numSteps; ++step) {
        string displacementFile = "dane_testowe_1/przemieszczenia_" + to_string(step) + ".txt";
        updatePositions(initialPositions, displacementFile, d);

        // Dla uproszczenia przyjmujemy f=5
        vector<Artifact> jediPositions = generateJediPositions(5, area);

        for (const Artifact& jediPosition : jediPositions) {
            vector<int> nearArtifacts = findArtifactsNearJedi(jediPosition, initialPositions, h);
            // cout << "Step: " << step << ", Jedi position: (" << jediPosition.x << ", " << jediPosition.y << "), Nearby artifacts: ";

           // for (int id : nearArtifacts) {
          //      cout << id << "(" << initialPositions[id].x << initialPositions[id].y << ")" << " ";
           //  }
          //   cout << endl;
        }

    }
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate the duration (in milliseconds by default)
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Output the duration
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;


    return 0;
}



