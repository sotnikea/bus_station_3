#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, vector<string>> bus;
    vector<string> mapKey;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "NEW_BUS") {
            /*
            гарантируется, что маршрут bus отсутствует, количество остановок больше 0, 
            а после числа stop_count следует именно такое количество названий остановок, 
            причём все названия в каждом списке различны
            */
            string busNumber;   //Номер маршрута
            int stationAmount;  //Количество остановок
            vector<string> busStation;   //Названия остановок
            string station;
            
            //Считываем номер маршрута
            cin >> busNumber;

            //Считываем количество станций
            cin >> stationAmount;
                        
            //Считываем введенные остановки и добавляем в вектор
            for (int i = 0; i < stationAmount; i++) {
                cin >> station;
                busStation.push_back(station);
            }
                  
            //Переносим введенные данные в словарь
            bus[busNumber] = busStation;
            mapKey.push_back(busNumber);

        }
        else if (operation_code == "BUSES_FOR_STOP") {
            /*
            На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, 
            проезжающих через эту остановку, в том порядке, в котором они создавались командами NEW_BUS. 
            Если остановка stop не существует, выведите No stop.
            */

            string stop;    //Название остановки
            cin >> stop;    //Ввод названия остановки
            vector<string> route;       //Вектор списка маршрутов проходящих через станцию

            for (auto busKey : mapKey) {
                for (auto s : bus[busKey]) {
                    if (s == stop) {
                        route.push_back(busKey);
                        continue;
                    }
                }
            }

            /*
            //Ищем какие автобусы проходили по станции
            for (auto curBus : bus)
            {
                for (int i = 0; i < curBus.second.size(); i++) {
                    if (curBus.second[i] == stop) {
                        route.push_back(curBus.first);
                    }
                }
            }
            */


            //Проверяем есть ли хотя бы один автобус. Если нет, станции не существует
            if (route.size() == 0) {
                cout << "No stop" << endl;
            }
            else {
                for (int i = 0; i < route.size(); i++) {
                    cout << route[i] << " ";
                }
            }
            cout << endl;

        }
        else if (operation_code == "STOPS_FOR_BUS") {
            /*
            На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, 
            в котором они были заданы в соответствующей команде NEW_BUS. Описание каждой остановки stop должно 
            иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, проезжающих через остановку stop, 
            в порядке, в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus. 
            Если через остановку stop не проезжает ни один автобус, кроме bus, вместо списка автобусов для неё выведите 
            no interchange. Если маршрут bus не существует, выведите No bus.
            */

            string busNumber;   //Номер автобуса для поиска
            cin >> busNumber;
            

            //Проверяем, что автобус существует
            if (bus.count(busNumber) == 0) {
                cout << "No bus" << endl;
                continue;
            }

            //Проверяем каждую станцию маршрута
            for (auto curStation : bus[busNumber]) {
                vector<string>busses;

                //Выводим текущую станцию на экран
                cout << "Stop " << curStation << ": ";

                //Проверка по автобусам
                for (auto key : mapKey) {
                    if (key == busNumber) continue;
                    for (int i = 0; i < bus[key].size(); i++) {                         
                        if (bus[key][i] == curStation) {
                            busses.push_back(key);
                        }
                    }
                }
                
                if (busses.size() == 0) {
                    cout << "no interchange" << endl;
                }
                else {
                    for (auto b : busses) {
                        cout << b << " ";
                    }
                    cout << endl;
                }
            }

            

        }
        else if (operation_code == "ALL_BUSES") {
            /*
            На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке. 
            Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., где stop1 stop2 ...
            — список остановок автобуса bus в порядке, в котором они были заданы в соответствующей команде NEW_BUS. 
            Если автобусы отсутствуют, выведите No buses.
            */
            if (bus.size() == 0) {
                cout << "No buses" << endl;
                continue;
            }

            for (auto b : bus) {
                cout << "Bus " << b.first << ": ";
                for (auto s : b.second) {
                    cout << s << " ";
                }
                cout << endl;
            }
           

        }

    }

    return 0;
}
