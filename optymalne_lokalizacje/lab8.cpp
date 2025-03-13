#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <limits>

struct Point {
    int id;
    double x;
    double y;
};

double distanceBetweenPoints(const Point& point1, const Point& point2) {
    return std::hypot(point1.x - point2.x, point1.y - point2.y);
}

std::vector<Point> readExistingLocationsFromFile(const std::string& filename) {
    std::vector<Point> existingLocations;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Point location;
            char comma;
            iss >> location.id >> comma >> location.x >> comma >> location.y;
            existingLocations.push_back(location);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return existingLocations;
}

std::vector<Point> findAvailableLocations(const std::vector<Point>& existingLocations) {
    const double gridResolution = 0.01;
    std::vector<Point> availableLocations;

    for (double x = 0.0; x <= 1.0; x += gridResolution) {
        for (double y = 0.0; y <= 1.0; y += gridResolution) {
            Point newLocation = { -1, x, y };

            bool skipLocation = false;
            for (const auto& existingLocation : existingLocations) {
                if (distanceBetweenPoints(newLocation, existingLocation) < gridResolution) {
                    skipLocation = true;
                    break;
                }
            }

            if (!skipLocation) {
                availableLocations.push_back(newLocation);
            }
        }
    }

    return availableLocations;
}

Point findBestLocation(const std::vector<Point>& existingLocations) {
    double bestDistance = -1.0;  
    Point bestLocation;

    for (double x = 0.0; x <= 1.0; x += 0.01) {
        for (double y = 0.0; y <= 1.0; y += 0.01) {
            Point newLocation = { -1, x, y };

            bool skipLocation = false;
            for (const auto& existingLocation : existingLocations) {
                if (distanceBetweenPoints(newLocation, existingLocation) < 0.01) {
                    skipLocation = true;
                    break;
                }
            }

            if (skipLocation) {
                continue;
            }

            double minDistance = std::numeric_limits<double>::max();
            for (const auto& existingLocation : existingLocations) {
                double d = distanceBetweenPoints(newLocation, existingLocation);
                if (d < minDistance) {
                    minDistance = d;
                }
            }

            if (minDistance > bestDistance) {
                bestDistance = minDistance;
                bestLocation = newLocation;
            }
        }
    }

    return bestLocation;
}

int main() {
    std::string filename = "points.csv";
    std::vector<Point> existingLocations = readExistingLocationsFromFile(filename);
    auto start_time = std::chrono::high_resolution_clock::now();

    // znajdz wszystkie mozliwe lokacje 
    std::vector<Point> availableLocations = findAvailableLocations(existingLocations);
    std::cout << "All available locations for new shops:" << std::endl;
    for (const auto& location : availableLocations) {
        std::cout << "(" << location.x << ", " << location.y << ")" << std::endl;
    }




    // najlepsze miejsce na nowy sklep 
    Point bestLocation = findBestLocation(existingLocations);
    std::cout << "Best location for a new shop: (" << bestLocation.x << ", " << bestLocation.y << ")" << std::endl;

    // Stop the clock
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate the duration (in milliseconds by default)
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Output the duration
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
