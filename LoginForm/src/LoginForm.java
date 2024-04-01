import javax.swing.*;

import com.formdev.flatlaf.FlatDarculaLaf;

import java.awt.*;
import java.awt.event.*;  
// import java.awt.event.ActionListener;
import java.sql.*;
// import java.text.Normalizer.Form;

public class LoginForm extends JFrame {
    final private Font mainFont = new Font("Noto Sans", Font.PLAIN, 18);

    JTextField InputEmail;
    JPasswordField InputPassword;


    public void initialize(){
        // ======Form Panel=====
        JLabel FormaLabel = new JLabel("Login Form", SwingConstants.CENTER);
        FormaLabel.setFont(mainFont);

        // For Email
        JLabel lbInputEmail = new JLabel("Email");
        lbInputEmail.setFont(mainFont);
        
        InputEmail = new JTextField();
        InputEmail.setFont(mainFont);
        
        // For Password
        JLabel lbPassword = new JLabel("Password");
        lbPassword.setFont(mainFont);

        InputPassword = new JPasswordField();
        InputPassword.setFont(mainFont);

        JPanel formPanel = new JPanel();
        formPanel.setLayout(new GridLayout(0, 1, 20, 20));
        formPanel.setBorder(BorderFactory.createEmptyBorder(30, 50, 30, 50));
        
        
        
        // Add Login Button to the Panel
        JButton btnLogin = new JButton("Login");
        btnLogin.setFont(mainFont);
        
        btnLogin.addActionListener(new ActionListener(){
            
            @Override
            public void actionPerformed(ActionEvent e){
                String email = InputEmail.getText();
                String password = String.valueOf(InputPassword.getPassword());
                
                // !!!!!!! Implement This Method !!!!!
                User user = getAuthenticatedUser(email, password);

                if(user !=null){
                    MainFrame mainFrame = new MainFrame();
                    mainFrame.initialize(user);
                    dispose();
                }
                else{
                    JOptionPane.showMessageDialog(LoginForm.this,
                    "Email or Password Invaild!!", "Try Again",
                    JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        
        // Add Cancel Button to the Panel
        JButton cancelBtn = new JButton("Cancel");
        cancelBtn.setFont(mainFont);
        
        cancelBtn.addActionListener(new ActionListener(){
            @Override
            
            public void actionPerformed(ActionEvent e){
                dispose();
            }
        });
        
        JPanel buttonPanel = new JPanel();
        buttonPanel.setBorder(BorderFactory.createEmptyBorder(30, 50, 30, 50));
        buttonPanel.add(btnLogin);
        buttonPanel.add(cancelBtn);

        // Add elements to JPanel
        formPanel.add(FormaLabel);
        formPanel.add(lbInputEmail);
        formPanel.add(InputEmail);
        formPanel.add(lbPassword);
        formPanel.add(InputPassword);

        add(formPanel, BorderLayout.NORTH);

        add(buttonPanel, BorderLayout.SOUTH);

        // JFrame Properties
        setTitle("Login Form !!");
        setSize(400, 500);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        setMinimumSize(new Dimension(350, 450));
        setVisible(true);
        setLocationRelativeTo(null);

    }

    private User getAuthenticatedUser(String email, String password){
        User user = null;

        final String DB_URL = "jdbc:mysql://localhost/mystore";
        final String USERNAME = "root";
        final String PASSWORD = "";

        try{
            Connection conn = DriverManager.getConnection(DB_URL, USERNAME, PASSWORD);

            String sql = "select * from users where email=? and password=?";

            PreparedStatement preparedStatement = conn.prepareStatement(sql);

            preparedStatement.setString(1, email);
            preparedStatement.setString(2, password);

            ResultSet rs = preparedStatement.executeQuery();

            if(rs.next()){
                user = new User();

                user.name = rs.getString("name");
                user.email = rs.getString("email");
                user.phone = rs.getString("phone");
                user.address = rs.getString("address");
                user.password = rs.getString("password");
            }

            preparedStatement.close();
            conn.close();
        }
        catch(Exception e){
            e.printStackTrace(); // Print the stack trace

            System.out.println("Database connection Failed!!");
        }

        return user;
    }


    public static void main(String args[]){

        // For Dark Mode
        try {
            UIManager.setLookAndFeel( new FlatDarculaLaf() );
        }
        catch( Exception ex ) {
            System.err.println( "Failed to initialize LaF" );
        }

        LoginForm loginForm = new LoginForm();
        loginForm.initialize();
    }
    
}
