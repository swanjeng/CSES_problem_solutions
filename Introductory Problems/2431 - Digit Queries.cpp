#include <iostream>
#include <algorithm>
using namespace std;

// cumulative_position_limit[length] = the last position covered by all numbers
// with exactly 'length' digits, including the leading zero case for length 1.
long long cumulative_position_limit[18];

// first_number_with_length[length] = the smallest number that has exactly
// 'length' digits.
long long first_number_with_length[18];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    // Precompute the boundary positions for each digit length.
    for (int length = 1; length <= 17; ++length) {
        string boundary_string = to_string(length - 1);
        for (int repeat = 1; repeat < length; ++repeat) {
            boundary_string += '8';
        }
        boundary_string += '9';
        cumulative_position_limit[length] = stoll(boundary_string);

        string first_number_string = "1";
        for (int repeat = 1; repeat < length; ++repeat) {
            first_number_string += '0';
        }
        first_number_with_length[length] = stoll(first_number_string);
    }

    int query_count;
    cin >> query_count;

    while (query_count--) {
        long long target_position;
        cin >> target_position;

        // Find the digit length that contains the target position.
        int digit_length = lower_bound(cumulative_position_limit, cumulative_position_limit + 18, target_position) - cumulative_position_limit;

        // Convert the target position to an index inside the block of numbers
        // with this digit length.
        long long offset_from_previous_block = target_position - cumulative_position_limit[digit_length - 1] - 1;
        long long number_index = offset_from_previous_block / digit_length;
        long long digit_offset = offset_from_previous_block % digit_length;

        string number_string = to_string(number_index + first_number_with_length[digit_length]);
        cout << number_string[digit_offset] << "\n";
    }
    return 0;
}