// This code is a solution to the HackerRank problem "Strong Password."
// The problem link: https://www.hackerrank.com/challenges/strong-password/problem
#include <bits/stdc++.h>

using namespace std;

// Function to check if the password has at least one lowercase letter
bool has_lower(string pass) {
    for (int i = 0; i < pass.size(); i++) {
        if (islower(pass[i]))
            return true;
    }
    return false;
}

// Function to check if the password has at least one uppercase letter
bool has_uppercase(string pass) {
    for (int i = 0; i < pass.size(); i++) {
        if (isupper(pass[i]))
            return true;
    }
    return false;
}

// Function to check if the password contains at least one special character
bool password_has_special_char(string pass) {
    for (int i = 0; i < pass.size(); i++) {
        if (pass[i] == '!' || pass[i] == '@' || pass[i] == '#' ||
            pass[i] == '$' || pass[i] == '%' || pass[i] == '^' ||
            pass[i] == '&' || pass[i] == '*' || pass[i] == '(' || pass[i] == ')' || pass[i] == '-' || pass[i] == '+')
            return true;
    }
    return false;
}

// Function to check if the password contains at least one digit
bool password_has_at_least_one_digit(string pass) {
    for (int i = 0; i < pass.size(); i++) {
        if (isdigit(pass[i]))
            return true;
    }
    return false;
}

// Function to determine the minimum number of changes required to make the password strong
int minimumNumber(int n, string password) {
    int solution = 0;

    // Check if the password meets various requirements and increment the solution count accordingly
    if (!password_has_at_least_one_digit(password))
        solution++;
    if (!password_has_special_char(password))
        solution++;
    if (!has_lower(password))
        solution++;
    if (!has_uppercase(password))
        solution++;

    int diff = 6 - password.size();

    // Return the maximum of solution count and the difference required to make the password of at least length 6
    return max(solution, diff);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
