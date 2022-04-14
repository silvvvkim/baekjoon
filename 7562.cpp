#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include <cstring>
#define MAX 305
//#define DEBUG
using namespace std;

int map[MAX][MAX];
int dir[8][2] = {
    {-1,-2}, {-2,-1},
    {-1,2},{-2,1},
    {1,-2},{2,-1},
    {1,2},{2,1}
};

int bfs(int sx, int sy, int ex, int ey, int line)
{
    queue<pair<int, int> > q; 
    pair<int, int> start;
    start.first = sx;
    start.second = sy;
    q.push(start);
    map[sx][sy] = 1;
#ifdef DEBUG  
    cout << "x : " << sx <<  ", y : " << sy << endl;
    cout << "ex : " << ex <<  ", ey : " << ey << endl;
#endif
    int cur_x, cur_y, nx, ny;
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        cur_x = cur.first, cur_y = cur.second;
#ifdef DEBUG
        cout << "x : " << cur_x <<  ", y : " << cur_y << endl;
#endif
        if(cur_x == ex && cur_y == ey) return map[cur_x][cur_y];

        for(int i=0;i<8;i++)
        {
            nx = cur_x + dir[i][0], ny = cur_y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= line | ny >= line) continue;
            if(map[nx][ny] > 0) continue;
            map[nx][ny] = max(map[cur_x][cur_y] + 1, map[nx][ny]);
            pair<int, int> newPoint;
            newPoint.first = nx;
            newPoint.second = ny;
            q.push(newPoint);
        }
    }
    return 0;
}

int main(void)
{
    int tc, l, start_x, start_y, end_x, end_y;
    cin >> tc;
    for(int i=0;i<tc;i++)
    {
        memset(map, 0, sizeof(map));
        cin >> l >> start_x >> start_y >> end_x >> end_y;
        cout << bfs(start_x, start_y, end_x, end_y, l) - 1 << endl;
    }
}
