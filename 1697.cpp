#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100005
using namespace std;

int bfs(int st, int ed)
{
    int res = 0;
    queue<int> q;
    int iVisit[MAX];
    memset(iVisit, 0, sizeof(iVisit));
    q.push(st);
    iVisit[st] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == ed) {
            res = iVisit[cur];
            break;
        }

        int nx1 = cur-1, nx2=cur+1, nx3 = cur*2;
        if(nx1 >= 0 && nx1 <= 100000){
            if(iVisit[nx1] == 0){
                iVisit[nx1] = max(iVisit[cur] + 1, iVisit[nx1]);
                q.push(nx1);
            }
        }
        if(nx2 >= 0 && nx2 <= 100000){
            if(iVisit[nx2] == 0){
                iVisit[nx2] = max(iVisit[cur] + 1, iVisit[nx2]);
                q.push(nx2);
            }
        }
        if(nx3 >= 0 && nx3 <= 100000){
            if(iVisit[nx3] == 0){
                iVisit[nx3] = max(iVisit[cur] + 1, iVisit[nx3]);
                q.push(nx3);
            }
        }
    }
    return res;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    cout << bfs(n,k) - 1;
}
