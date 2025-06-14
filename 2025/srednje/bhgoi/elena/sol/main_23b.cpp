#include <iostream>
#include <vector>

using namespace std;

int main(){
    // U ovom podzadatku broj nacina da se dodje od X do cilja je
    // jednak broju nacina da se dodje od cilja do X
    int r, k, n;

    cin >> r >> k >> n;

    string s;
    cin >> s >> s >> s;
    cin >> s;

    int cilj;
    for(int i=0;i<k;i++){
        if(s[i] == 'C'){
            cilj = i;
        }
    }

    vector<int> br(k);
    vector<int> v(k), vc(k); // vc = kopija v

    v[cilj] = 1;
    br[cilj] = 1;

    while(n--){
        vc[0] = v[1];
        vc[k-1] = v[k-2];

        for(int i=1;i<k-1;i++){
            vc[i] = v[i-1] + v[i+1];
            vc[i] %= 1000000007;
        }

        v = vc;

        for(int i=0;i<k;i++){
            br[i] += v[i];
            br[i] %= 1000000007;
        }
    }

    int max_ind = 0;
    
    for(int i=0;i<k;i++){
        if(br[i] > br[max_ind]){
            max_ind = i;
        }
    }

    cout << 1 << ' ' << max_ind + 1 << endl;
    cout << br[max_ind] << endl;

    return 0;
}