#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    /*
    Neka dp[i] oznacava maksimalne duzine nizova koji se zavrsavaju na
    i-tom elementu. S obzirom da mozemo da gradimo nizove na dva nacina:
        (1) <, >, <, > ... (manji - veci - manji - veci...)
        (2) >, <, >, < ... (veci - manji - veci - manji...),
    mozemo i da pamtimo 2 razlicita tipa niza koji se zavrsavaju na i-tom elementu.
    Shodno tome:
        (1) dp[i][0] - duzina najduzeg niza koji se zavrsava na i-tom elementu,
            takav da je a[i - 1] < a[i]
        (2) dp[i][1] - duzina najduzeg niza koji se zavrsava na i-tom elementu,
            takav da je a[i - 1] > a[i].
    S obzirom da se radi o podnizovima, u i-tom elementu poznajemo dvije opcije:
        (1) Nastaviti podniz iz posljednjeg elementa
        (2) Zapoceti novi podniz na trenutnom elementu.

    Ako nam dp[i - 1] oznacava najbolji moguci podniz koji smo mogli da konstruisemo,
    onda mozemo da njega iskoristimo i da na njegov kraj probamo dodati trenutni elementi,
    tj. l[i], i vidimo da li to kreira optimalno rjesenje.
    Relacija je veoma jednostavna:
        (1) dp[i][0] = dp[i - 1][1] + 1; ako je a[i - 1] < a[i]
        (1) dp[i][1] = dp[i - 1][0] + 1; ako je a[i - 1] > a[i]
    Jednostavno receno, ako gradimo niz u i-tom elementu, takav da je a[i - 1] < a[i],
    to znaci da i-ti element dodajemo na najbolji moguci podniz koji smo imali u (i - 1)-om elementu,
    ali takav da je znak izmedju (i - 1)-og i (i - 2)-og elementa ">" (jer ce sada znak biti "<",
    a mora se smjenjivati). Analogno tome, radimo istu stvar i za slucaj a[i - 1] > a[i].
    */
    vector<vector<int>> dp(n, {1, 1});
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (l[i - 1] < l[i]) {
            dp[i][0] = dp[i - 1][1] + 1;
        }
        else if (l[i - 1] > l[i]) {
            dp[i][1] = dp[i - 1][0] + 1;
        }

        // Za racunanje odgovora, jednostavno samo nadjemo najduzi
        // moguci podniz, bilo gdje u nizu.
        // Nije garantovano da ce najduzi podniz zavrsavati, recimo,
        // zadnjim elementom (tj. dp[n]), kao sto cesto zna biti slucaj
        // u nekim DP problemima, kada se odgovor "kopira" sa stanja
        // "i - 1", u stanje "i".
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }

    cout << ans << endl;
    return 0;
}
