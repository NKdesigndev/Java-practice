import java.awt.*;
import javax.swing.*;

public class MainWrapper extends JFrame{

    JTextField tfEmail;
    JTextField tfPassword;

    public void initialize(){

        // Forma Panel
        JLabel formTitle = new JLabel("Login Form", SwingConstants.CENTER);

        JLabel lbEmail = new JLabel("Email");
        tfEmail = new JTextField();

        JLabel lbPassword = new JLabel("Password");
        tfPassword = new JTextField();
        

        JPanel formPanel = new JPanel();
        formPanel.setLayout(new GridLayout(0, 1, 10, 10));

        setTitle("Login !!");
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

        setSize(300, 400);
        setMinimumSize(new Dimension(350, 450));
        setLocationRelativeTo(null);
        setVisible(true);
   
    }
}
