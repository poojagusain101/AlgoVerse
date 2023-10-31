class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int count=-1;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty()){
            int s=q.size();
            count++;
            while(s--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(j>0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                    fresh--;
                }
                if(i>0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                    fresh--;
                }
                if(j<m-1 && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                    fresh--;
                }
                if(i<n-1 && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    fresh--;
                }
            }
        }
        if(fresh>0){
            return -1;
        }
        if(count==-1){
            return 0;
        }
        return count;        
    }
};
