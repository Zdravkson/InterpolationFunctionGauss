#include <bits/stdc++.h>
#define MAX_N 1000 // MAKSIMALAN BROJ KOORDINATA

using namespace std;

double coefficientMatrix[MAX_N][MAX_N + 1];
double ans[MAX_N];
pair<double, double> coordinates[MAX_N];

int main() {
    int n;
    cout << "Unesite broj koordinata: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Unesite x koordinatu " << i + 1 << ". tacke: ";
        cin >> coordinates[i].first;
        cout << "Unesite y koordinatu " << i + 1 << ". tacke: ";
        cin >> coordinates[i].second;
    }
    // popunjavamo matricu sa koeficijentima jednacina sistema sa n jednacina i n nepoznatih
    for(int i = 0; i < n; i++) {
        coefficientMatrix[i][n] = coordinates[i].second;
        double exponentation = 1;
        for(int j = n - 1; j >= 0; j--) {
            coefficientMatrix[i][j] = exponentation;
            exponentation *= coordinates[i].first;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double tmpcoef = coefficientMatrix[j][i] / coefficientMatrix[i][i];
            for(int k = 0; k <= n; k++) {
                coefficientMatrix[j][k] -= (tmpcoef * coefficientMatrix[i][k]);
            }
        }
    }
    ans[n - 1] = coefficientMatrix[n - 1][n] / coefficientMatrix[n - 1][n - 1]; // resenje za poslednju promenljivu, desne strana podeljena sa koeficijentom ispred poslednje promenljive
    for(int i = n - 2; i >= 0; i--) {
        double tmpsum = 0;
        for(int j = n - 1; j > i; j--) { // izracunavamo sumu svih poznatih u i-toj jednacini
            tmpsum += coefficientMatrix[i][j] * ans[j];
        }
        ans[i] = (coefficientMatrix[i][n] - tmpsum) / coefficientMatrix[i][i]; // oduzimamo sumu poznatih od desne strane i podelimo to sa koeficijentom ispred promenljive koju izracunavamo
    }
    cout << "Interpolirani polinom je: ";
    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            cout << ans[i];
        } else {
            cout << ans[i] << " * x^" << n - 1 - i << " + ";
        }
    }
    return 0;
}