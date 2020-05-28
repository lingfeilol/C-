class Solution {
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
public:
    bool exist(vector<vector<char>>& board, string& word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(dfs(board,word,0,i,j))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board,string& word,int index,int n,int m)
    {
        if(index==word.size())
            return true; 
         if(n<0|| n>=board.size()|| m<0|| m>=board[0].size()||board[n][m]=='#'||board[n][m]!=word[index])
            return false;
        board[n][m]='#';//只会是匹配才会接着搜索  
        for(int i=0;i<4;i++)
        {
            int newx=n+dx[i],newy=m+dy[i];
            if(dfs(board,word,index+1,newx,newy))
                return true;
        }
        board[n][m]=word[index];//回溯
        return false;
    }
};