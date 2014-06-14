package rps;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class ClickListener implements ActionListener
{
    private static final int OUTPUT_WIDTH = 250;
    private static final int OUTPUT_HEIGHT = 75;
    
    public void actionPerformed(ActionEvent event)
    {
        //do a random int from 0-2 to simulate enemy AI
        Random randomGen = new Random();
        int randomChoice = randomGen.nextInt(3);
        /**
            0 = sword
            1 = shield
            2 = mace
        */
        
        String playerChoice = event.getActionCommand(); //Text on the button
        
        String outMessage = ""; //message to be displayed at end
        
        //Find out if the player lost, if they won, or it is a tie
        if (playerChoice.equals("Sword"))
        {
            if (randomChoice == 0)
            {
                outMessage = "Swords clang off each other!";
            }
            else if (randomChoice == 1)
            {
                outMessage = "Shield blocks Sword!";
            }
            else if (randomChoice == 2)
            {
                outMessage = "Sword parries Mace!";
            }
        }
        else if (playerChoice.equals("Shield"))
        {
            if (randomChoice == 0)
            {
                outMessage = "Shield blocks Sword!";
            }
            else if (randomChoice == 1)
            {
                outMessage = "Shields deflect each other!";
            }
            else if (randomChoice == 2)
            {
                outMessage = "Mace Dents Shield!";
            }
        }
        else if (playerChoice.equals("Mace"))     
        {
            if (randomChoice == 0)
            {
                outMessage = "Sword parries Mace!";
            }
            else if (randomChoice == 1)
            {
                outMessage = "Mace Dents Shield!";
            }
            else if (randomChoice == 2)
            {
                outMessage = "Maces bounce off each other!";
            }
        }
        
        JFrame outFrame = new JFrame();
        
        JLabel output = new JLabel(outMessage);
        
        JPanel outPanel = new JPanel();
        outPanel.add(output);
        outFrame.add(outPanel);
        
        outFrame.setSize(OUTPUT_WIDTH, OUTPUT_HEIGHT);
        outFrame.setTitle("Drumroll...");
        //no close operation so you can close out output and keep going
        
        outFrame.setVisible(true);
    }
}