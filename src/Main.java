import Vehicle.Vehicle;
import Vehicle.Car;

public class Main {

    public static void main (String[] args) {

        Vehicle car = new Car(4, 10);

        car.start();
        car.brake();
        car.stop();
    }
}
