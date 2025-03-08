#include <cassert>
#include <sstream>
#include <iostream>
#include "../src/matrix/matrix_utils.h"

// Test function declarations
void testKadane();
void testFindMaxSum();
void testInputValidation();
void testNegativeMatrix();
void testSingleElementMatrix();
void testEmptyMatrix();

// Redirect cout for testing
class CoutRedirect {
    std::streambuf* old;
    std::stringstream ss;
public:
    CoutRedirect() : old(std::cout.rdbuf(ss.rdbuf())) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
    std::string str() { return ss.str(); }
};

void runMatrixTests() {
    testKadane();
    testFindMaxSum();
    testInputValidation();
    testNegativeMatrix();
    testSingleElementMatrix();
    testEmptyMatrix();
    std::cout << "All matrix tests passed!" << std::endl;
}

void testKadane() {
    int arr[] = {1, -2, 3, 4, -5, 6};
    int start, finish;
    int result = kadane(arr, &start, &finish, 6);
    assert(result == 8); // Maximum sum should be 8 (3 + 4 + (-5) + 6)
    assert(start == 2); // Starting index
    assert(finish == 5); // Ending index
}

void testFindMaxSum() {
    int** mat = new int*[3];
    for(int i = 0; i < 3; i++) {
        mat[i] = new int[3];
    }
    
    // Test matrix:
    // 1  2  3
    // 4  5  6
    // 7  8  9
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;

    CoutRedirect redirect;
    findMaxSum(mat, 3, 3);
    assert(redirect.str() == "1,2,3;4,5,6;7,8,9");

    for(int i = 0; i < 3; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

void testNegativeMatrix() {
    int** mat = new int*[2];
    for(int i = 0; i < 2; i++) {
        mat[i] = new int[2];
    }
    
    // Test matrix:
    // -1  -2
    // -3  4
    mat[0][0] = -1; mat[0][1] = -2;
    mat[1][0] = -3; mat[1][1] = 4;

    CoutRedirect redirect;
    findMaxSum(mat, 2, 2);
    assert(redirect.str() == "4");

    for(int i = 0; i < 2; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

void testSingleElementMatrix() {
    int** mat = new int*[1];
    mat[0] = new int[1];
    mat[0][0] = 5;

    CoutRedirect redirect;
    findMaxSum(mat, 1, 1);
    assert(redirect.str() == "5");

    delete[] mat[0];
    delete[] mat;
}

void testEmptyMatrix() {
    CoutRedirect redirect;
    findMaxSum(nullptr, 0, 0);
    assert(redirect.str().empty());
}

void testInputValidation() {
    assert(validateInput("1,2,3;4,5,6") == true);
    assert(validateInput("") == false);
    assert(validateInput("abc") == false);
    assert(validateInput("1,2;3,4;") == true);
    assert(validateInput("1,-2,3;-4,5,-6") == true);
}