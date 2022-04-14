#include <iostream>
using namespace std;

int memo[21][21][21];
//#define DEBUG
int find(int a, int b, int c)
{
#ifdef DEBUG
    cout << "a : " << a << ", b : " << b << ", c : " << c << endl;
#endif
    if(a <= 0 || b <= 0 || c <=0) return 1;
    else if(a > 20 || b > 20 || c > 20) return find(20,20,20);
    else if(memo[a][b][c] != 0) return memo[a][b][c];
    else if(a<b && b<c) memo[a][b][c] = find(a,b,c-1) + find(a,b-1,c-1) - find(a,b-1,c);
    else memo[a][b][c] = find(a-1,b,c) + find(a-1,b-1,c) + find(a-1,b,c-1) - find(a-1,b-1,c-1);
    return memo[a][b][c];
}

int main(void){
    int a,b,c;
    while(true){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1) break;
        cout << "w(" << a << ", " << b << ", " << c << ")" << " = " << find(a,b,c)  << endl;
    }
}
