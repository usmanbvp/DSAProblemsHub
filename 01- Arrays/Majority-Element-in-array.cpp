// Given an array nums of size n, we have to return the majority element.
#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (candidate == num) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

bool isMajorityElement(vector<int>& nums, int candidate) {
    int count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    return count > nums.size() / 2;
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int candidate = findMajorityElement(nums);

    if (isMajorityElement(nums, candidate)) {
        cout << "The majority element is: " << candidate << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    return 0;
}
