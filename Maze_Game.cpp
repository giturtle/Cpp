

//广度优先算法
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
 
struct pos { int x, y, level; };
 
int bfs(vector<vector<char> > & map){
   //四个方向
    const int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
 
    queue<pos> que;
 
    int m = map.size();  //行
    int n = map[0].size();  //列
 
    vector<vector<bool> > visit(m, vector<bool>(n, false));  /初始化为false，标记，避免无限递归
 
    pos start{ 0,1,0 }, end{ 9,8,0 };
    que.push(start);
    visit[start.x][start.y] = true;
    while (!que.empty()){
        pos cur = que.front(), next;
        que.pop();
        for (int i = 0; i < 4; ++i){
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            next.level = cur.level + 1;
            if (next.x == end.x && next.y == end.y) return next.level;
            if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
                !visit[next.x][next.y] && map[next.x][next.y] == '.'){
                que.push(next);
                visit[next.x][next.y] = true;
            }
        }
    }
 
    return 0;
}
 
int main(){
    vector<vector<char> > map(10, vector<char>(10));
    while (cin >> map[0][0]){
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j){
                if (i == 0 && j == 0) continue;
                cin >> map[i][j];
            }
        cout << bfs(map) << endl;
    }
    return 0;
}
