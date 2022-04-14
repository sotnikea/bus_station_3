#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>


using namespace std;


int main(void) {
    int q;
    cin >> q;

    map <set<string>, int> routes;
    int num = 0;

    for (int i = 0; i < q; ++i) {
        
        int stops;
        cin >> stops;
        set<string> route;
        string s;
        
        for (int i = 0; i < stops; i++) {
            cin >> s;
            route.insert(s);
        }
                

        //Проверяем наличие в словаре такого же набора остановок
        if (routes.count(route) == 0) {
            num++;
            cout << "New bus " << num << endl;
            routes[route] = num;
        }
        else {
            cout << "Already exists for " << routes[route] << endl;
        }

    }
}