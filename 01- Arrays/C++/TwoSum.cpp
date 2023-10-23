#include <iostream>

using namespace std;

void findTwoSumPairs(int nums[], int lengthOfArray, int target, int result[][2], int &pairCount) {
    pairCount = 0; // Initialize the pair count to 0
    
    for (int i = 0; i < lengthOfArray; i++) {
        for (int j = i + 1; j < lengthOfArray; j++) {
            if (nums[i] + nums[j] == target) {
                result[pairCount][0] = nums[i];
                result[pairCount][1] = nums[j];
                pairCount++;
            }
        }
    }
}

int main() {
    int lengthOfArray, target;

    cout << "Enter size of array: ";
    cin >> lengthOfArray;

    // Declare an array with the specified size
    int nums[lengthOfArray];

    // Declare elements of the array
    cout << "Enter elements of the array: ";
    for (int i = 0; i < lengthOfArray; i++) {
        cin >> nums[i];
    }

    // Declare target value
    cout << "Enter target value: ";
    cin >> target;

    int result[lengthOfArray][2];
    int pairCount;

    findTwoSumPairs(nums, lengthOfArray, target, result, pairCount);

    if (pairCount > 0) {
        cout << "Resultant pairs:" << endl;
        for (int i = 0; i < pairCount; i++) {
            cout << "(" << result[i][0] << ", " << result[i][1] << ")" << endl;
        }
    } else {
        cout << "No such pairs found." << endl;
    }

    return 0;
}
