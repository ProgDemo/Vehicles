#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Tram.h"
#include <windows.h>

using namespace std;

int main()
{
    //Vehicle v;
    Car c(25, 200, 5);

    //vector<Vehicle> vehicles;
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Car(25, 200, 5));
    vehicles.push_back(new Tram(200, 70));
    vehicles.push_back(new Car(5, 185, 4));

    for (int i = 0; i < 3; ++i) {
        try {
            vehicles[i]->start();
        } catch (Vehicle::VehicleException e) {
            if (e == Vehicle::VehicleCanNotStartException) {
                cerr << "Vehicle can not start!\n";
            } else if (e == Vehicle::VehicleInternalException) {
                cerr << "Vehicle error! :( \n";
            } else if (e == Vehicle::VehicleCanNotStopException) {
                cerr << "Vehicle can not be stopped!\n";
            }
        }
    }

    while (true) {
        for (int i = 0; i < 3; ++i) {
            try {
                if (vehicles[i]->isRunning()) {
                    vehicles[i]->run();
                }
            } catch (Vehicle::VehicleException e) {
                if (e == Vehicle::VehicleCanNotStartException) {
                    cerr << "Vehicle can not start!\n";
                } else if (e == Vehicle::VehicleInternalException) {
                    cerr << "Vehicle error! :( \n";
                } else if (e == Vehicle::VehicleCanNotStopException) {
                    cerr << "Vehicle can not be stopped!\n";
                }
            }

            cout << vehicles[i]->getState() << endl;
            Sleep(1000);
        }
        cout << "\n---------------\n";
    }

    return 0;
}
