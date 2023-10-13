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
    return 0;
}