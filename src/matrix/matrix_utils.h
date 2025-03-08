#pragma once
#include <string>

// Maximum dimensions for input matrix
#define MAX_ROW_COUNT 100
#define MAX_COL_COUNT 100

/**
 * Implements Kadane's algorithm to find maximum sum subarray
 * @param arr Input array
 * @param start Output parameter for start index of maximum sum subarray
 * @param finish Output parameter for end index of maximum sum subarray
 * @param n Length of input array
 * @return Maximum sum found
 */
int kadane(int* arr, int* start, int* finish, int n);

/**
 * Finds the maximum sum submatrix in the given matrix
 * @param mat Input matrix
 * @param row_count Number of rows
 * @param col_count Number of columns
 */
void findMaxSum(int** mat, int row_count, int col_count);

/**
 * Validates input string format
 * @param input Input string to validate
 * @return true if input format is valid, false otherwise
 */
bool validateInput(const std::string& input);