#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
void permute(vector<int> &numeros, int inicio, vector<vector<int>> &resultado, set<vector<int>> &usadas) {
    int inicio2=0;
    if (inicio == numeros.size() - 1) {
        if (usadas.count(numeros) == 0) {
            if(numeros[inicio2]!=0)
            {
                resultado.push_back(numeros);
                usadas.insert(numeros);
            }
        }
        return;
    }
 
    for (int i = inicio; i < numeros.size(); i++) {
        swap(numeros[inicio], numeros[i]);
        permute(numeros, inicio + 1, resultado, usadas);
        swap(numeros[inicio], numeros[i]);
    }
}
 
vector<vector<int>> permute(vector<int> &numeros) {
    vector<vector<int>> resultado;
    set<vector<int>> usadas;
    permute(numeros, 0, resultado, usadas);
    return resultado;
}
 
int main() {
    vector<int> numeros = {1, 1, 4, 4, 5, 5, 0};
    vector<vector<int>> permutaciones = permute(numeros);
 
    for (auto &p : permutaciones) {
        for (int i : p) {
            cout << i;
        }
        cout << endl;
    }
 
    cout << "Total permutaciones: " << permutaciones.size() << endl;
    return 0;
}