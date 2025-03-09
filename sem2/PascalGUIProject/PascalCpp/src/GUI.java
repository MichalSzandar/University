import javafx.scene.layout.Pane;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import java.util.logging.*;

public class GUI
{
    public GUI(Stage stage)
    {

        ListView<String> listView = new ListView<String>();
        listView.setPrefHeight(860);
        
        GUITextArea indexInputArea = new GUITextArea("enter indexes of values");
        GUITextArea rowInputArea = new GUITextArea("enter row of Pascal's triangle");
        Button btn = new GUIButton("Generate values", listView, indexInputArea, rowInputArea);
        Pane root = new GUIVBox(listView, indexInputArea, rowInputArea, btn);


        Scene scene = new Scene(root);
        scene.getStylesheets().add("styles.css");
        stage.setScene(scene);
        stage.setTitle("Pascal Triangle Generator");
        stage.show();
        MyLogger.logger.log(Level.INFO, "Scene has been inited");
    }
}
