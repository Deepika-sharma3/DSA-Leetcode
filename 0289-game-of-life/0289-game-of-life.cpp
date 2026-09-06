class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

       
        vector<vector<int>> original = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {

                        if (x == i && y == j)
                            continue;

                       
                        if (x >= 0 && x < m &&
                            y >= 0 && y < n) {

                           
                            if (original[x][y] == 1)
                                live++;
                        }
                    }
                }

              
                if (original[i][j] == 1) {

                    if (live < 2 || live > 3)
                        board[i][j] = 0;
                }

                else {

                    if (live == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};