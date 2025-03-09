
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;

import java.util.ArrayList;
import java.util.logging.*;


public class GUIButton extends Button
{

    public GUIButton(String name, ListView<String> listView, TextArea indexInputArea, TextArea rowInputArea)
    {
        super(name);
        setPrefSize(200, 50);
        
        setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent e)
            {
                MyLogger.logger.log(Level.INFO, "Button");
                listView.getItems().clear();

                ArrayList<String> output = CppRunner.getOutput("./src/cpp/programExec " + rowInputArea.getText().trim() + " " + indexInputArea.getText().trim());
                for (String line : output) {
                    listView.getItems().add(line);
                    System.out.println(line);
                }
                
            }
        });

    }
}