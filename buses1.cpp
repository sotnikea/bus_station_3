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
            �������������, ��� ������� bus �����������, ���������� ��������� ������ 0, 
            � ����� ����� stop_count ������� ������ ����� ���������� �������� ���������, 
            ������ ��� �������� � ������ ������ ��������
            */
            string busNumber;   //����� ��������
            int stationAmount;  //���������� ���������
            vector<string> busStation;   //�������� ���������
            string station;
            
            //��������� ����� ��������
            cin >> busNumber;

            //��������� ���������� �������
            cin >> stationAmount;
                        
            //��������� ��������� ��������� � ��������� � ������
            for (int i = 0; i < stationAmount; i++) {
                cin >> station;
                busStation.push_back(station);
            }
                  
            //��������� ��������� ������ � �������
            bus[busNumber] = busStation;
            mapKey.push_back(busNumber);

        }
        else if (operation_code == "BUSES_FOR_STOP") {
            /*
            �� ������ BUSES_FOR_STOP stop �������� ����� ������ ������ ���������, 
            ����������� ����� ��� ���������, � ��� �������, � ������� ��� ����������� ��������� NEW_BUS. 
            ���� ��������� stop �� ����������, �������� No stop.
            */

            string stop;    //�������� ���������
            cin >> stop;    //���� �������� ���������
            vector<string> route;       //������ ������ ��������� ���������� ����� �������

            for (auto busKey : mapKey) {
                for (auto s : bus[busKey]) {
                    if (s == stop) {
                        route.push_back(busKey);
                        continue;
                    }
                }
            }

            /*
            //���� ����� �������� ��������� �� �������
            for (auto curBus : bus)
            {
                for (int i = 0; i < curBus.second.size(); i++) {
                    if (curBus.second[i] == stop) {
                        route.push_back(curBus.first);
                    }
                }
            }
            */


            //��������� ���� �� ���� �� ���� �������. ���� ���, ������� �� ����������
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
            �� ������ STOPS_FOR_BUS bus �������� �������� ��������� �������� bus � ��������� ������� � ��� �������, 
            � ������� ��� ���� ������ � ��������������� ������� NEW_BUS. �������� ������ ��������� stop ������ 
            ����� ��� Stop stop: bus1 bus2 ..., ��� bus1 bus2 ... � ������ ���������, ����������� ����� ��������� stop, 
            � �������, � ������� ��� ����������� ��������� NEW_BUS, �� ����������� ��������� �������� bus. 
            ���� ����� ��������� stop �� ��������� �� ���� �������, ����� bus, ������ ������ ��������� ��� �� �������� 
            no interchange. ���� ������� bus �� ����������, �������� No bus.
            */

            string busNumber;   //����� �������� ��� ������
            cin >> busNumber;
            

            //���������, ��� ������� ����������
            if (bus.count(busNumber) == 0) {
                cout << "No bus" << endl;
                continue;
            }

            //��������� ������ ������� ��������
            for (auto curStation : bus[busNumber]) {
                vector<string>busses;

                //������� ������� ������� �� �����
                cout << "Stop " << curStation << ": ";

                //�������� �� ���������
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
            �� ������ ALL_BUSES �������� �������� ���� ��������� � ���������� �������. 
            �������� ������� �������� bus ������ ����� ��� Bus bus: stop1 stop2 ..., ��� stop1 stop2 ...
            � ������ ��������� �������� bus � �������, � ������� ��� ���� ������ � ��������������� ������� NEW_BUS. 
            ���� �������� �����������, �������� No buses.
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
