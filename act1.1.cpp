// A00840096 - Carlos Baranda - Act 1.1
// Implementacion de la búsqueda binaria en C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funcion de búsqueda binaria
int BusquedaBinaria(const vector<double>& a, int i, int l, double x) {
    //Caso base, si el indice de inicio es mayor que el indice de fin el elemento no se encuentra en el array
    if (i > l) return -1;
    // Se calcula el indice del elemento del medio
    int m = (i + l) / 2;
// Si el elemento del medio es igual al valor a buscar se retorna el indice 
    if (a[m] == x) return m;
// Si el elemento del medio es mayor que el valor a buscar, se busca en la mitad izq del array
    if (a[m] > x) return BusquedaBinaria(a, i, m - 1, x);
// Si el elemento del medio es menor que el valor a buscar se bucsa en la mitad derecha del array
    return BusquedaBinaria(a, m + 1, l, x);
}

int main() {
    // Se solicita el numero de elementos del array
    int n;
    cout << "Ingrese el numero de elementos: ";
    cin >> n;
// Se crea un vector double para almacenar los elementos del array
    vector<double> a(n);
    cout << "Ingrese los elementos(Separar con espacio no con comas): ";
    // S leen los elementos del array del anterior vector
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Se ordena el array y se imprime
    cout << "\nArreglo ordenado: ";
    sort(a.begin(), a.end());
    for (double val : a) {
        cout << val << " ";
    }
    cout << endl;

    // Se solicita el valor que se buscara
    double x;
    cout << "\nIngrese el valor a buscar: ";
    cin >> x;

    // Se llama a la funcion de bb y se almacena el resultado
    int resultado = BusquedaBinaria(a, 0, n - 1, x);
    // Se imprime el resultado de la busqueda
    if (resultado != -1)
        cout << "Valor encontrado en el indice: " << resultado << endl;
        // Si el resultado es -1 se imprime que el valor no se encuentra
    else
        cout << "Valor no encontrado. Resultado: -1" << endl;
    
        // Return para terminar el programa
    return 0;
}