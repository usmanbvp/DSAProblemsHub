//To find majority element in a 2d matrix
#include <iostream>
#include <vector>

int findMajorityElement(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return -1; // Return -1 to indicate no majority element.
    }

    int candidate = -1;
    int count = 0;

   
    for (int num : matrix[0]) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (candidate == num) {
            count++;
        } else {
            count--;
        }
    }

    //  Verify if the element is a majority element
    count = 0;
    for (int num : matrix[0]) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > matrix[0].size() / 2) {
        return candidate;
    }

    return -1; // Return -1 if there is no majority element.
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {2, 2, 1},
        {1, 1, 2},
        {2, 2, 2}
    };

    int result = findMajorityElement(matrix);

    if (result != -1) {
        std::cout << "The majority element in the matrix is " << result << std::endl;
    } else {
        std::cout << "There is no majority element in the matrix." << std::endl;
    }

    return 0;
}
