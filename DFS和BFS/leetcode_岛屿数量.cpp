/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围


示例1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
*/

class Solution {
public: 

    bool vst[301][301];   //访问标记
    int sum=0;
    int dir[4][2]={0,1,0,-1,1,0,-1,0}; //方向向量

    //检查边界
    bool CheckEdge(int x,int y, vector<vector<char>>&  grid) 
    {
        if( x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && vst[x][y]==0 && grid[x][y]=='1') //满足条件
            return 1;
        else
            return 0;
    }

    // 方法1 DFS
    void dfs(int x,int y, vector<vector<char>>& grid)
    {
        printf("%d %dno end\n",x,y);
        for(int i=0;i<4;i++) 
        {
            if( CheckEdge(x+dir[i][0],y+dir[i][1],grid) )
            {
                printf("%d %d\n",x+dir[i][0],y+dir[i][1]);
                vst[x+dir[i][0]][y+dir[i][1]]=1;
                dfs(x+dir[i][0],y+dir[i][1],grid);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid){
        //先dfs找到完一个岛 再for循环找vst别的点
        int num=0;
        for(int m=0; m<grid.size(); m++)
        {
            for(int n=0; n<grid[0].size(); n++)
            {
                if(grid[m][n]=='1' && vst[m][n]==0)
                {
                    vst[m][n]=1;
                    dfs(m,n,grid);
                    num++;
                }
            }
        }
        return num;
    }

    //方法2 BFS
    void bfs(int x,int y, vector<vector<char>>& grid)
    {
        queue<int> q;
        q.push(grid[x][y]);
        q.push(x);
        q.push(y);
        while(!q.empty())
        {
            int o = q.size()/3;
            for(int k=0; k<o; k++)
            {
                q.pop();
                x = q.front();
                q.pop();
                y = q.front();
                q.pop();
                vst[x][y]=1;

                if( CheckEdge(x,y+1,grid) )
                {
                    vst[x][y+1]=1;
                    q.push(grid[x][y+1]);
                    q.push(x);
                    q.push(y+1);
                }
                if( CheckEdge(x,y-1,grid) )
                {
                    vst[x][y-1]=1;
                    q.push(grid[x][y-1]);
                    q.push(x);
                    q.push(y-1);
                }
                if( CheckEdge(x+1,y,grid) )
                {
                    vst[x+1][y]=1;
                    q.push(grid[x+1][y]);
                    q.push(x+1);
                    q.push(y);
                }
                if( CheckEdge(x-1,y,grid) )
                {
                    vst[x-1][y]=1;
                    q.push(grid[x-1][y]);
                    q.push(x-1);
                    q.push(y);
                }
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size(),n=grid[0].size(),num=0;
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
            {
                if(vst[i][j]==0 && grid[i][j]=='1')
                {
                    bfs(i,j,grid);
                    num++;
                }
            }
        return num;
    }
};
