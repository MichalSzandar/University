import javafx.scene.layout.Pane;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;

import java.util.ArrayList;
import java.util.logging.*;

public class GUI
{
    public GUI(Stage stage)
    {

        ListView<ArrayList<Integer>> listView = new ListView<ArrayList<Integer>>();
        listView.setPrefHeight(860);
        
        GUITextArea txtArea = new GUITextArea();
        Button btn = new GUIButton("Generate Pascal Triangle", listView, txtArea);
        Pane root = new GUIVBox(listView, txtArea, btn);


        Scene scene = new Scene(root);
        scene.getStylesheets().add("styles.css");
        stage.setScene(scene);
        stage.setTitle("Pascal Triangle Generator");
        stage.show();
        MyLogger.logger.log(Level.INFO, "Scene has been inited");
    }
}
