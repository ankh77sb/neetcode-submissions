class Solution {
public:
    bool dfs(int i, int j, int m, int n, string word, int k, vector<vector<char>>& board) {
        if(k >= word.size())  return true;
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(board[i][j] == '0') return false;
        if(board[i][j] != word[k]) return false;
        char c = board[i][j];
        board[i][j] = '0';
        bool res =  dfs(i+1, j, m, n, word, k + 1, board) ||
                dfs(i, j + 1, m, n, word, k + 1, board) ||
                dfs(i-1, j, m, n, word, k + 1, board) ||
                dfs(i, j - 1, m, n, word, k + 1, board); 
        board[i][j] = c;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                if(dfs(i, j, m, n, word, 0, board))
                    return true;
            }
        }  
        return false; 
    }
};
