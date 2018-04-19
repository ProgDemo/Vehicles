#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

class Vehicle {

    public:
        enum VehicleException {VehicleCanNotStartException, VehicleCanNotStopException, VehicleInternalException};

        void virtual start() = 0;
        void virtual stop() = 0;
        virtual void run() = 0;
        virtual bool isRunning() = 0;
        std::string virtual getState() = 0;

};

#endif // VEHICLE_H_INCLUDED
