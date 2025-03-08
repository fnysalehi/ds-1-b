#include <iostream>

// Test function declarations
void runMatrixTests();
void runLoopTests();

int main() {
    std::cout << "Running all tests...\n" << std::endl;
    
    std::cout << "Running Matrix Tests:" << std::endl;
    runMatrixTests();
    
    std::cout << "\nRunning Loop Detector Tests:" << std::endl;
    runLoopTests();
    
    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}