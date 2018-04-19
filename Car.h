#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <sstream>

class Car : public Vehicle {

    private:
        double fuelLevel;
        int maxSpeed;
        int numOfPassengers;
        bool running;

    public:
        static const bool CAR_IS_RUNNING = true;

        Car(double fuelLevel = 0, int maxSpeed = 180, int numOfPassengers = 4):
            fuelLevel(fuelLevel), maxSpeed(maxSpeed), numOfPassengers(numOfPassengers), running(!CAR_IS_RUNNING) {}

        bool isEmpty() const { return fuelLevel <= 0; }

        double setFuel(double fuelLevel) { this->fuelLevel = fuelLevel; }
        double getFuel() const { return fuelLevel; }

        void start() {
            if (isEmpty() || numOfPassengers == 0 || running) {
                throw VehicleCanNotStartException;
            }

            running = CAR_IS_RUNNING;
        }

        void stop() {
            if (!running) {
                throw VehicleCanNotStopException;
            }

            running = !CAR_IS_RUNNING;
        }

        void run() {
            if (!running) {
                throw VehicleInternalException;
            }

            if (isEmpty()) {
                running = !CAR_IS_RUNNING;
                throw VehicleInternalException;
            }

            fuelLevel -= 0.5;
        }

        std::string getState() {
            std::stringstream tmp;

            tmp << "Car: " << (running ? "RUNNING" : "NOT RUNNING") << " - fuel: " << fuelLevel;
            return tmp.str();

        }

        bool isRunning() { return running; }
};

#endif // CAR_H_INCLUDED
