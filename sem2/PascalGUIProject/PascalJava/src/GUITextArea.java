import javafx.event.EventHandler;
import javafx.scene.control.TextArea;
import javafx.scene.input.MouseEvent;

public class GUITextArea extends TextArea 
{
    public GUITextArea()
    {
        super("Number of rows");
        setOnMouseClicked(new EventHandler<MouseEvent>(){
            @Override
            public void handle(MouseEvent e)
            {
                setText("");
            }
        });
        setPrefHeight(50);
        setMaxHeight(50);
        setMaxWidth(200);
        
    }
}
