#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> partitionLabels(std::string s) { // O(N) time, O(N) space
    std::unordered_map<char, int> active; // keeps track of active values
    std::unordered_map<char, int> map; // keeps track of all values
    int count = 0;
    std::vector<int> ans;

    for (char val : s) { // populate total map
        map[val]++;
    }

    for (char val : s) {
        active[val]++; // populate active
        count++;
        
        if (active[val] == map[val]) { // if active = map, meaning all occurrences of a single character have been counted
            map.erase(val); // erase from map
            active.erase(val); // erase from active

            if (active.size() == 0) { // if active is empty (meaning no values are current active, ie a partition can be made)
                ans.push_back(count); // add count to answer, reset count
                count = 0;
            }
        }
    }

    return ans;
}

std::vector<int> partitionLabelsOptimal(std::string s) { // O(N) time, O(1) space
    std::vector<int> active (26, 0); // vector we'll be checking if a value is active or not with
    std::vector<int> all (26, 0); // holds frequency of all vals
    std::vector<int> res;
    int count = 0;

    for (char val : s) { // populates frequency table
        all[val - 'a']++;
    }

    for (char val : s) {
        count++;
        active[val - 'a']++; // increments active frequency

        if (active[val - 'a'] == all[val - 'a']) { // if the frequencies match (meaning all occurrences of that letter have been seen)
            active[val - 'a'] = 0; // set active to 0

            for (int i = 0; i < active.size(); i++) {
                if (active[i] != 0) { // if a value in active is still active, break
                    break;
                }

                if (i == active.size() - 1) { // if you've reached the end of the vector without breaking, it means all values are 0's and you can push count to the answer vector
                    res.push_back(count);
                    count = 0;
                }
            }
        }
    }

    return res;
}

int main() {
    std::string input = "ababcbacadefegdehijhklij";

    std::vector<int> ans = partitionLabelsOptimal(input);

    for (int val : ans) {
        std::cout << val << std::endl;
    }

    return 0;
}