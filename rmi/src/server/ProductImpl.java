package server;

import java.rmi.RemoteException;

public class ProductImpl implements Product {
    
    // Attributes of product
    public String name;
    public Double price;
    public String description;

    // make a Constructor
    public ProductImpl(String newName, String newDescription, Double newPrice) throws RemoteException{
        this.name = newName;
        this.price = newPrice;
        this.description = newDescription;
    }
    public String getName() throws RemoteException{
        return this.name;
    }

    public Double getPrice() throws RemoteException{
        return this.price;
    }

    public String getDescription() throws RemoteException{
        return this.description;
    }
}
