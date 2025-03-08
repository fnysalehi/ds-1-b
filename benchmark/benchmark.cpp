#include <chrono>
#include <random>
#include <iostream>
#include "matrix_utils.h"

void runBenchmarks() {
    const int SIZES[] = {10, 50, 100};
    
    for (int size : SIZES) {
        // Create random matrix
        int** mat = new int*[size];
        for(int i = 0; i < size; i++) {
            mat[i] = new int[size];
            for(int j = 0; j < size; j++) {
                mat[i][j] = rand() % 201 - 100; // Random numbers between -100 and 100
            }
        }

        // Measure time
        auto start = std::chrono::high_resolution_clock::now();
        findMaxSum(mat, size, size);
        auto end = std::chrono::high_resolution_clock::now();
        
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Matrix size " << size << "x" << size << ": " 
                  << duration.count() << "ms" << std::endl;

        // Cleanup
        for(int i = 0; i < size; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
}