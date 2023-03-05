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

int main() {
    std::string input = "ababcbacadefegdehijhklij";

    std::vector<int> ans = partitionLabels(input);

    for (int val : ans) {
        std::cout << val << std::endl;
    }

    return 0;
}