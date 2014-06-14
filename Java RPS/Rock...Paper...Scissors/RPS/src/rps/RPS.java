package rps;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class RPS {
    public static void main(String[] args) 
    {
        JFrame frame = new Buttons();

        //Set the title (I also put my instructions there)
        frame.setTitle("Sword Shield Mace!");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.setVisible(true);
    }
}
