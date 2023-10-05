// algorithm to find elements that appear more than N/3 times in an array.
#include <iostream>
#include <vector>

using namespace std;

vector<int> findMajorityElements(vector<int>& nums) {
    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;

    for (int num : nums) {
        if (candidate1 == num) {
            count1++;
        } else if (candidate2 == num) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        }
    }

    vector<int> result;

    if (count1 > nums.size() / 3) {
        result.push_back(candidate1);
    }
    if (count2 > nums.size() / 3) {
        result.push_back(candidate2);
    }

    return result;
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    vector<int> majorityElements = findMajorityElements(nums);

    if (!majorityElements.empty()) {
        cout << "The majority elements are: ";
        for (int element : majorityElements) {
            cout << element << " ";
        }
        cout << endl;
    } else {
        cout << "No majority elements found." << endl;
    }

    return 0;
}
