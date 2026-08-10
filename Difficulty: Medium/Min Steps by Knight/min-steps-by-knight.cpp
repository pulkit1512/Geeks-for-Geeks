int drow[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dcol[] = {-1, 1, -2, 2, -2, 2, -1, 1};
class Solution {
	public:
	int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
		// Code here
		int posx = knightPos[0];
		int posy = knightPos[1];
		int targetx = targetPos[0];
		int targety = targetPos[1];
		vector<vector<bool>>visited(n+1,vector<bool>(n+1,0));
		queue<tuple<int, int, int>> q;
		q.push({posx, posy, 0});
		visited[posx][posy]=1;
		while (!q.empty()) {
			auto [x, y, steps] = q.front();
			q.pop();
			
			if(x==targetx&&y==targety) return steps;
			for (int i = 0; i < 8; i++) {
				int next_x = x + drow[i];
				int next_y = y + dcol[i];
				
		
				if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= n) {
				    if(!visited[next_x][next_y]){
				        q.push({next_x,next_y,steps+1});
				        visited[next_x][next_y]=1;
				    }
				}
			}
			visited[x][y]=1;
		}
		return -1;
	}
};
