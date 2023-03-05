#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

// https://leetcode.com/problems/jump-game-iv/solutions/1690813/best-explanation-ever-possible-for-this-question/

int minJumps(std::vector<int>& arr) {
    int n = arr.size(); // get size of vec
    if (n == 1) return 0; // base case

    std::unordered_map<int, std::vector<int>> mp;
    int step = 0;

    for (int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i); // sets key of map to arr[i], and the value is a vector of indexes
    }

    std::queue<int> q;

    q.push(0);

    while (!q.empty()) {
        step++; // increments number of steps to reach end
        int size = q.size(); // gets size of queue
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();

            if ((current - 1 >= 0) && (mp.find(arr[current-1]) != mp.end())) { // if index - 1 is not outside of vector and the value is in the map, push the value to queue
                q.push(current - 1);
            }

            if ((current + 1 < n) && (mp.find(arr[current + 1]) != mp.end())) { // if index + 1 is not outside of vector, and value is in the map, push the value to queue
                if (current + 1 == n - 1) return step;
                q.push(current + 1);
            }

            if (mp.find(arr[current]) != mp.end()) { // if the map contains the current value:
                for (int k : mp[arr[current]]) { // iterates through the vector of current's value
                    if (k != current) { // if the value in the vec is not equal to current (skips current index)
                        if (k == n - 1) return step; // if the index is equal to the end (meaning you can jump from current index to the end), return steps taken
                        q.push(k); // if not, add k to the queue
                    }
                }
            }

            mp.erase(arr[current]); // deletes current value so you don't backtrack, and at most, it iterates over the vector once
        }
    }

    return step;
}

int main() {
    std::vector<int> input = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    std::cout << minJumps(input) << std::endl; 
}