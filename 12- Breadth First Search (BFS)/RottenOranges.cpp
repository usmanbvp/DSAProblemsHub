
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution 
{
    public: 
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;

        int fresh=0;

        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++)
        {

            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                     fresh++;


            }
        }

        int time=-1;
        while(!q.empty())
        {
            int count=q.size();

                while(count--)
                {

                    pair<int,int> p=q.front();
                    q.pop();

                    int x=p.first;
                    int y=p.second;

                    if(x>=0 && x<m && y-1>=0 && y-1<n && grid[x][y-1]==1)
                    {
                        fresh--;
                         grid[x][y-1]=2;
                        q.push({x,y-1});
                    }

                     if(x>=0 && x<m && y+1>=0 && y+1<n && grid[x][y+1]==1)
                    {
                         fresh--;
                         grid[x][y+1]=2;
                        q.push({x,y+1});
                    }

                     if(x-1>=0 && x-1<m && y>=0 && y<n && grid[x-1][y]==1)
                    {
                         fresh--;
                         grid[x-1][y]=2;
                        q.push({x-1,y});
                    }

                     if(x+1>=0 && x+1<m && y>=0 && y<n && grid[x+1][y]==1)
                    {
                         fresh--;
                         grid[x+1][y]=2;
                        q.push({x+1,y});
                    }


                }

            time++;
        }

        if(fresh>0)
            return -1;
        if(time==-1)
            return 0;
        return time;
        
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  