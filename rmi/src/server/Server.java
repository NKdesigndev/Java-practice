package server;
// import java.rmi.server.*;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server extends ProductImpl {
    public Server(String newName, String newDescription, double newPrice) throws RemoteException {
        super(newName, newDescription, newPrice);
        //TODO Auto-generated constructor stub
    }

    public static void main(String args[]){
        try{

            // Set hostname for the server using javaProperty
            System.setProperty("java.rmi.server.hostname","localhost");
            System.out.println("Server has been started...");

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
            Registry registry = LocateRegistry.getRegistry("localhost", 9100);

            registry.rebind("l", stub1);
            registry.rebind("m", stub2);
            registry.rebind("c", stub3);
            registry.rebind("b", stub4);

            System.out.println("Exporting and Binding of objects has been completed..");
        }
        catch(Exception e){
            System.out.println("Some server error..." + e);
        }
    }
}
