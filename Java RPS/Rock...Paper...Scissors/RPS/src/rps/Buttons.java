package rps;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
 
public class Buttons extends JFrame
{ 
    private static final int FRAME_WIDTH = 700;
    private static final int FRAME_HEIGHT = 75;
    
    public Buttons()
    { 
        createComponents();
        setSize(FRAME_WIDTH, FRAME_HEIGHT);
    }

    private void createComponents()
    {
        
        //make buttons
        JButton button1 = new JButton("Sword");
        JButton button2 = new JButton("Shield");
        JButton button3 = new JButton("Mace");
        
        //add them to the panel grid
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(1, 3));
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);

        //add the buttonPanel to the frame
        add(buttonPanel);

        //listener for clicks
        ActionListener listener = new ClickListener();
        
        //check each button for a click
        button1.addActionListener(listener);
        button2.addActionListener(listener);
        button3.addActionListener(listener);
    }
}