package server;

import java.rmi.RemoteException;

public class ProductImpl implements Product {
    
    // Attributes of product
    public String name;
    public String description;
    public double price;

    // make a Constructor
    public ProductImpl(String newName, String newDescription, double newPrice) throws RemoteException{
        this.name = newName;
        this.description = newDescription;
        this.price = newPrice;
    }
    public String getName() throws RemoteException{
        return this.name;
    }

    
    public String getDescription() throws RemoteException{
        return this.description;
    }
    
    public double getPrice() throws RemoteException{
        return this.price;
    }
}
