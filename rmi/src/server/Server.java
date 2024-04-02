package server;
import java.rmi.server.*;
import java.rmi.registry.*;

public class Server {
    public static void main(String args[]){
        try{

            // Set hostname for the server using javaProperty
            System.setProperty("java.rmi.server.hostname","127.0.0.1");

            ProductImpl p1 = new ProductImpl("Laptop", "lenovo laptop", 58000.00);
            ProductImpl p2 = new ProductImpl("Mobile","Google Pixel",40000.00);
            ProductImpl p3 = new ProductImpl("Power Charger","Lenovo Charger",3000.00);
            ProductImpl p4 = new ProductImpl("MotorBike","Royal Enfield", 200000.00);


            // Export the objects p1,p2,p3 and p4 using UnicastRemoteObject.class
            Product stub1 = (Product) UnicastRemoteObject.exportObject(p1, 0);
            Product stub2 = (Product) UnicastRemoteObject.exportObject(p2, 0);
            Product stub3 = (Product) UnicastRemoteObject.exportObject(p3, 0);
            Product stub4 = (Product) UnicastRemoteObject.exportObject(p4, 0);
            
            // Register the exported class in RMI registry with some name
            // Client will use that name to get the reference of those exported object

            // Get the registry to register the object
            Registry registry = LocateRegistry.getRegistry("127.0.0.1", 9100);

            registry.rebind("l", stub1);
            registry.rebind("m", stub2);
            registry.rebind("c", stub3);
            registry.rebind("b", stub4);

        }
        catch(Exception e){
            System.out.println("Some server error..." + e);
        }
    }
}
