class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {

                        if (x == i && y == j)
                            continue;

                        if (x >= 0 && x < m &&
                            y >= 0 && y < n &&
                            (board[x][y] == 1 || board[x][y] == 2)) {
                            live++;
                        }
                    }
                }

                if (board[i][j] == 1 && (live < 2 || live > 3))
                    board[i][j] = 2;

                if (board[i][j] == 0 && live == 3)
                    board[i][j] = 3;
            }
        }

        for (auto& row : board) {
            for (int& cell : row) {
                if (cell == 2) cell = 0;
                else if (cell == 3) cell = 1;
            }
        }
    }
};