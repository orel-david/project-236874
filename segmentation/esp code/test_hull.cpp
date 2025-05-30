#include <vector>
#include <iostream>
#include "hull.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to generate a random set of points
vector<pair<int, int>> generateRandomPoints(int numPoints, int xRange, int yRange) {
    vector<pair<int, int>> points;
    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < numPoints; ++i) {
        int x = rand() % xRange;   // Random x-coordinate within range
        int y = rand() % yRange;   // Random y-coordinate within range
        points.push_back({x, y});
    }

    return points;
}

int main() {
    // int n;
    // cin >> n;

    // vector<pair<int,int>> points;
    // for (int i = 0; i < n; i++) {
    //     int x, y;
    //     cin >> x >> y;
    //     points.push_back({x, y});
    // }

    // int numPoints = 500;
    // int xRange = 100;
    // int yRange = 100;

    // std::vector<Point> rect = {{0, 0}, {1, 1}, {0, 2}, {-1, 1}};


    // vector<pair<int, int>> randp = generateRandomPoints(numPoints, xRange, yRange);

    // auto start = high_resolution_clock::now();
    // Circle mec = minCircle({ { 5, -2 }, {-3,-2}, {-2,5}, {1, 6}, {0,2}});
    // cout << mec.center.x << " " << mec.center.y <<" "<< mec.r<< std::endl;
    // // double minArea = minBoundingRectangleArea(rect);
    // // std::cout << "Minimum Area Bounding Rectangle: " << minArea << "\n";
    // // // Compute the convex hullS
    // // Hull hull = Hull(randp);
    // auto end = high_resolution_clock::now();

    // // Calculate the elapsed time
    // auto duration = duration_cast<microseconds>(end - start);

    // // Output the time in microseconds
    // cout << "Elapsed time: " << duration.count() << " microseconds" << endl;

    int m1[4] = {1,2,3,4};
    int m2[4] = {5,6,7,8};
    int* res = (int*)malloc(2*2*2*sizeof(int));
    
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 2; x++) {
            res[y * 4 + x] = m1[y * 2 + x];      // First two columns
            res[y * 4 + x + 2] = m2[y * 2 + x];  // Next two columns
        }
    }

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 4; x++) {
            std::cout << res[y * 4 + x] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}