// A00840096
#include <iostream>
#include <vector>

using namespace std;

// funcion para resolver el laberinto usando backtracking
bool solve(vector<vector<int>>& lab, vector<vector<int>>& path, int x, int y, int m, int n) {
    // si llegamos a la salida
    if (x == m - 1 && y == n - 1) {
        path[x][y] = 1;
        return true;
    }
    
    // marcar la casilla actual como parte del camino
    path[x][y] = 1;
    
    // derecha, abajo, izquierda, arriba
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    // intentar cada direccion
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        // verificar si es valido
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && lab[nx][ny] == 1 && path[nx][ny] == 0) {
            if (solve(lab, path, nx, ny, m, n)) {
                return true;
            }
        }
    }
    
    // si no hay camino, desmarcar
    path[x][y] = 0;
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    // leer el laberinto
    vector<vector<int>> lab(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lab[i][j];
        }
    }
    
    // matriz para el camino, inicializada a 0
    vector<vector<int>> path(m, vector<int>(n, 0));
    
    // intentar resolver desde (0,0)
    if (solve(lab, path, 0, 0, m, n)) {
        // imprimir el camino
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << path[i][j];
                if (j < n - 1) cout << " ";
            }
            cout << endl;
        }
    } else {
        // si no hay camino, imprimir todo
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << 0;
                if (j < n - 1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}