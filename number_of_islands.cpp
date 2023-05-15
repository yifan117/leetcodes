#include <queue>
#include <vector>

int main() {

}

int solve(std::vector<std::vector<int>> grid) {
    int count = 0;
    std::queue<std::pair<int, int>> q;
    std::pair<int, int> curr;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                count++;
                q.push({i, j});

                while (!q.empty()) {
                    curr = q.front();
                    q.pop();

                    grid[curr.first][curr.second] = '0';

                    if (curr.first + 1 < grid.size()) {
                        if (grid[curr.first + 1][curr.second] == '1') {
                            q.push({curr.first + 1, curr.second});
                            grid[curr.first + 1][curr.second] = '0';
                        }
                    }

                    if (curr.first - 1 >= 0) {
                        if (grid[curr.first - 1][curr.second] == '1') {
                            q.push({curr.first - 1, curr.second});
                            grid[curr.first - 1][curr.second] = '0';
                        }
                    }

                    if (curr.second + 1 < grid[i].size()) {
                        if (grid[curr.first][curr.second + 1] == '1') {
                            q.push({curr.first, curr.second + 1});
                            grid[curr.first][curr.second + 1] = '0';
                        }
                    }

                    if (curr.second - 1>= 0) {
                        if (grid[curr.first][curr.second - 1] == '1') {
                            q.push({curr.first, curr.second - 1});
                            grid[curr.first][curr.second - 1] = '0';
                        }
                    }
                }
            }
        }
    }

    return count;
}