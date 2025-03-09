
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;

import java.util.ArrayList;
import java.util.logging.*;


public class GUIButton extends Button
{

    public GUIButton(String name, ListView<ArrayList<Integer>> listView, TextArea textArea)
    {
        super(name);
        setPrefSize(200, 50);
        
        setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent e)
            {
                MyLogger.logger.log(Level.INFO, "Button");
    
                try{
                    int input = Integer.parseInt(textArea.getText());
                    new PascalBuilder(input, listView);
                }catch(IndexOutOfBoundsException ex)
                {
                    MyLogger.logger.log(Level.SEVERE, ex.getMessage());
                    AlertPopups.displayError(ex.getMessage());
                }catch(Exception ex)
                {
                    MyLogger.logger.log(Level.SEVERE, "input should be an integer greater than 0.");
                    AlertPopups.displayError("input should be an integer greater than 0.");
                }
            }
        });

    }
}
