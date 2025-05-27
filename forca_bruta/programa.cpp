include <iostream>

using namespace std;

int main(){
    int lp, cp; cin >> lp >> cp;
    int lf1, cf1; cin >> lf1 >> cf1;
    int lf2, cf2; cin >> lf2 >> cf2;

    int area_p; area_p = lp * cp;
    int soma_areas_f; soma_areas_f = lf1 * cf1 + lf2 * cf2;
    if (soma_areas_f > area_p){
        cout << "N";
    }
    else {
        cout << "S";
    }

    return 0;
}