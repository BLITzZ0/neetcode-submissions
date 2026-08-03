class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //for rows
        for(int i = 0; i<9; i++){
            unordered_map<char, int>mp;
            for(int j = 0;j<9; j++){
                if(board[i][j] == '.')continue;
                mp[board[i][j]]++;
                if(mp[board[i][j]] > 1)return false;
            }
        }

        //for cols
        for(int i = 0;i<9;i++){
            unordered_map<char, int>mp;
            for(int j = 0;j<9;j++){
                if(board[j][i] == '.')continue;
                mp[board[j][i]]++;
                if(mp[board[j][i]] > 1)return false;
            }
        }

        //for 3 X 3
        for(int row = 0;row<9;row+=3){
            for(int col = 0;col<9;col+=3){
                unordered_map<char, int>mp;
                for(int i = row;i<row+3;i++){
                    for(int j = col; j<col+3;j++){
                        if(board[i][j] == '.')continue;
                        mp[board[i][j]]++;
                        if(mp[board[i][j]] > 1)return false;
                    }
                }
            }
        }

        return true;
    }
};
