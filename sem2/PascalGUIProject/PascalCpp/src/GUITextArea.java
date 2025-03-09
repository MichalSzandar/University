import javafx.event.EventHandler;
import javafx.scene.control.TextArea;
import javafx.scene.input.MouseEvent;

public class GUITextArea extends TextArea 
{
    public GUITextArea(String defaultText)
    {
        super(defaultText);
        setOnMouseClicked(new EventHandler<MouseEvent>(){
            @Override
            public void handle(MouseEvent e)
            {
                setText("");
            }
        });
        setPrefHeight(40);
        setMaxHeight(40);
        setMaxWidth(300);
        
    }
}
