import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Scanner;

public class userInput{
    public static void main(String[] args) throws IOException{
        System.out.print("Enter the first number: ");

        // Scanner sc = new Scanner(System.in);

        // Scanner method:
        // int num = sc.nextInt();
        // System.out.println("You've Entered: " + num);
        // sc.close();

        // int num = System.in.read();
        // System.out.println(num);

        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader bf = new BufferedReader(in);

        // // readLine() returns a String not integer
        int userInput = Integer.parseInt(bf.readLine());

        System.out.println("You've Entered: " + userInput);
        bf.close();
    }
}