#include <iostream>
using namespace std;
typedef struct {
    int zeroCall, oneCall;
}Count;

Count memo[41];

int main(void)
{
    memo[0].zeroCall = 1;
    memo[0].oneCall = 0;
    memo[1].zeroCall = 0;
    memo[1].oneCall = 1;

    for(int i=2;i<41;i++){
        memo[i].zeroCall = memo[i-1].zeroCall + memo[i-2].zeroCall;
        memo[i].oneCall = memo[i-1].oneCall + memo[i-2].oneCall;
    }

    int tc, n;
    cin >> tc;
    for(int i=0; i<tc; i++){
        cin >> n;
        cout << memo[n].zeroCall << " " << memo[n].oneCall << endl;
    }
}
