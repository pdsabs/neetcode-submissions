class Solution {
public:
    map<pair<int,int>, int> subGridMap = {{{0,0},0}, {{0,1},1}, {{0,2},2},
                                          {{1,0},3}, {{1,1},4}, {{1,2},5},
                                          {{2,0},6}, {{2,1},7}, {{2,2},8}};

    int getSubgrid(int r, int c) {
        int row = 0, col = 0;
        if (r <= 2) {
            row = 0;
        } else if (r >= 3 && r <= 5) {
            row = 1;
        } else {
            row = 2;
        }

        if (c <= 2) {
            col = 0;
        } else if (c >= 3 && c <= 5) {
            col = 1;
        } else {
            col = 2;
        }

        return subGridMap[{row,col}];
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> subGridCnt(9);
        vector<unordered_set<int>> rowCnt (9);
        vector<unordered_set<int>> colCnt (9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                int currValue = board[i][j] - '0';
                if (currValue < 0 || currValue > 9) {
                    cout << "currValue" << endl;
                    return false;
                }
                
                if (rowCnt[i].count(currValue)) {
                    cout << "rowCnt" << endl;
                    return false;
                }
                rowCnt[i].insert(currValue);

                if (colCnt[j].count(currValue)) {
                    cout << "colCnt" << endl;
                    return false;
                }
                colCnt[j].insert(currValue);
                
                int subGrid = getSubgrid(i,j);
                if (subGridCnt[subGrid].count(currValue)) {
                    cout << "subGridCnt" << endl;
                    return false;
                }

                subGridCnt[subGrid].insert(currValue);
            }
        }

        return true;
    }
};
