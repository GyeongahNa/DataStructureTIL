#include <stack>
#include <vector>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int R, C;
int board[100][100];
bool visited[100][100];

bool dfs(int sx, int sy, int ex, int ey) {

    stack<ii> st;
    st.push({sx, sy});
    visited[sx][sy] = true;

    while (!st.empty()) {

        ii cur = st.top();
        if (cur.X == ex && cur.Y == ey) return true;
        st.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (board[nx][ny] || visited[nx][ny]) continue;

            st.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return false;
} 

int main() {

    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) cin >> board[i][j];
    }

    if (dfs(0, 0, R-1, C-1)) cout<<"yes";
    else cout<<"no";
    return 0;
}