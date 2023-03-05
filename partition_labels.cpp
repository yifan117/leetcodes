#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> partitionLabels(std::string s) {
    std::unordered_map<char, int> active;
    std::unordered_map<char, int> map;
    int count = 0;
    std::vector<int> ans;

    for (char val : s) {
        map[val]++;
    }

    for (char val : s) {
        active[val]++;
        count++;
        
        if (active[val] == map[val]) {
            map.erase(val);
            active.erase(val);

            if (active.size() == 0) {
                ans.push_back(count);
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