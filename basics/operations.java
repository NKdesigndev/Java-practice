import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class operations{
    public static void main(String[] args) throws IOException{
        
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader bf = new BufferedReader(in);
        
        // Take Input from user:
        System.out.print("Enter the first number: ");
        double num1 = Double.parseDouble(bf.readLine());

        System.out.print("Enter the Second number: ");
        double num2 = Double.parseDouble(bf.readLine());
        
        // Perform arithmetic operations
        double addition = num1 + num2;
        double sub = num1 - num2;
        double multiply = num1 * num2;
        double division = num1 / num2;

        // Print the results
        System.out.println("Addition: " + addition);
        System.out.println("Sub: " + sub);
        System.out.println("Multiply: " + multiply);
        System.out.println("Division: " + division);

        bf.close();
    }
}