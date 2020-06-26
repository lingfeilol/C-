class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<int> ret;
        if(board.empty()) return ret;
        int row=board.size(), col=board[0].size(),mod=1e9+7;
        vector<vector<int>>dpScore (row+1,vector<int>(col+1));
        vector<vector<int>>dpCount (row+1,vector<int>(col+1));
        dpCount[row-1][col-1]=1; //初始化方案数为1
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                //有路障，或者无法到达此格
                if(board[i][j]!='X' && (dpCount[i+1][j]!=0 ||dpCount[i][j+1]!=0|| dpCount[i+1][j+1]!=0) )
                {
                    //更新路劲和
                    int maxscore=max({dpScore[i+1][j],dpScore[i][j+1],dpScore[i+1][j+1]});
                    dpScore[i][j] = maxscore+board[i][j]-'0';
                    //更新方案数 包含了最大路径和有多个的情况，则将其方案数累加起来
                    if(dpScore[i+1][j+1]==maxscore)
                        dpCount[i][j]=(dpCount[i][j]+dpCount[i+1][j+1])%mod;
                    if(dpScore[i+1][j]==maxscore)
                        dpCount[i][j]=(dpCount[i][j]+dpCount[i+1][j])%mod;
                    if(dpScore[i][j+1]==maxscore)
                        dpCount[i][j]=(dpCount[i][j]+dpCount[i][j+1])%mod;
                }
            }
        }
        int maxscore=dpScore[0][0]==0? 0:dpScore[0][0]-('E'-'0');
        int maxcount=dpCount[0][0];
        ret.push_back(maxscore);
        ret.push_back(maxcount);
        return ret;
    }
};