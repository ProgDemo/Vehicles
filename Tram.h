#ifndef TRAM_H_INCLUDED
#define TRAM_H_INCLUDED

#include <sstream>

class Tram : public Vehicle {

    private:
        int numOfPassenger;
        int maxSpeed;
        bool running;
        bool doorOpen;

    public:
        static const bool TRAM_IS_RUNNING = true;
        static const bool DOOR_OPEN = true;

        Tram(int numOfPassenger = 0, int maxSpeed = 50, bool doorOpen = !DOOR_OPEN):
            numOfPassenger(numOfPassenger), maxSpeed(maxSpeed), doorOpen(doorOpen), running(!TRAM_IS_RUNNING) {}

        void openDoor() { doorOpen = DOOR_OPEN; }
        void closeDoor() { doorOpen = !DOOR_OPEN; }


        void start() {
            if (doorOpen || running) {
                throw VehicleCanNotStartException;
            }

            running = TRAM_IS_RUNNING;
        }

        void run() {
            if (!running) {
                throw VehicleInternalException;
            }
        }

        void stop() {
            if (!running) {
                throw VehicleCanNotStopException;
            }

            running = !TRAM_IS_RUNNING;
        }

        std::string getState() {
            std::stringstream tmp;
            tmp << "Tram: " << (running ? "RUNNING" : "NOT RUNNING");
            return tmp.str();
        }

        bool isRunning() { return running; }

};

#endif // TRAM_H_INCLUDED
