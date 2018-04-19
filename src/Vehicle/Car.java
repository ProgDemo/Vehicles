package Vehicle;

public class Car extends Vehicle {

    public Car(int wheels, float fuel) {
        super(wheels, fuel);
    }

    @Override
    public void start() {
        System.out.println("Car starts, fuel level: " + super.fuel);
    }

    @Override
    public void stop() {
        System.out.println("Car stops, fuel level: " + super.fuel);
    }

    @Override
    public void brake() {
        System.out.println("Car brakes!\n");
    }
}
