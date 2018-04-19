package Vehicle;

public abstract class Vehicle {

    private int wheels;
    protected float fuel;
    private int passengers;

    public Vehicle(int wheels, float fuel) {
        this.fuel = fuel;
        this.wheels = wheels;
    }

    public abstract void start();
    public abstract void stop();

    public void brake() {
        System.out.println("Vehicle brakes!\n");
    }
}
