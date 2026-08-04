class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            vector<bool> visited(9,false);
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if(visited[board[i][j]-1]) return false;
                visited[board[i][j]-1] = true;
            }
        }

        for(int i = 0; i < 9; i++) {
            vector<bool> visited(9,false);
            for(int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if(visited[board[j][i]-1]) return false;
                visited[board[j][i]-1] = true;
            }
        }

      for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
        
    }
};
