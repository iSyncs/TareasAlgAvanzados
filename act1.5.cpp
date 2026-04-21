#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// esta funcion verifica si una posicion es valida en el laberinto
bool esValida(int x, int y, int M, int N, vector<vector<int>>& lab, vector<vector<int>>& visitado) {
    return (x >= 0 && x < M && y >= 0 && y < N && lab[x][y] == 1 && visitado[x][y] == 0);
}

// etsa funcion resuelve el laberinto usando bfs
bool resolver(vector<vector<int>>& lab, vector<vector<int>>& path, int M, int N) {

    vector<vector<int>> visitado(M, vector<int>(N, 0));
    vector<vector<pair<int,int>>> parent(M, vector<pair<int,int>>(N, {-1,-1}));

    queue<pair<int,int>> q;

    q.push({0,0});
    visitado[0][0] = 1;

    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};

    while(!q.empty()) {

        auto [x,y] = q.front();
        q.pop();

        if(x == M-1 && y == N-1) {

            while(x != -1 && y != -1) {
                path[x][y] = 1;
                auto p = parent[x][y];
                x = p.first;
                y = p.second;
            }

            return true;
        }

        for(int d = 0; d < 4; d++) {

            int nx = x + dx[d];
            int ny = y + dy[d];

            if(esValida(nx, ny, M, N, lab, visitado)) {

                visitado[nx][ny] = 1;
                parent[nx][ny] = {x,y};
                q.push({nx,ny});
            }
        }
    }

    return false;
}

int main() {

    int M, N;
    cin >> M >> N;

    vector<vector<int>> lab(M, vector<int>(N));
    vector<vector<int>> path(M, vector<int>(N,0));

    // leer el laberinto desde la entrada
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> lab[i][j];
        }
    }

    if(lab[0][0] == 1 && resolver(lab, path, M, N)) {

        // imprimir el camino encontrado
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                cout << path[i][j];
                if(j < N-1) cout << " ";
            }
            cout << endl;
        }

    } else {

        // si no hay camino, imprimir todo ceros
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                cout << 0;
                if(j < N-1) cout << " ";
            }
            cout << endl;
        }

    }

    return 0;
}