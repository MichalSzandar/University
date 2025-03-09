
import javafx.scene.layout.VBox;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Cursor;
import javafx.scene.Node;

public class GUIVBox extends VBox
{
    public GUIVBox(Node listView, Node rowInputArea, Node indexInputArea,Node button)
    {
        super(listView, rowInputArea, indexInputArea,button);
        setAlignment(Pos.CENTER);
        setPadding(new Insets(20));
        setSpacing(20);
        setPrefSize(600, 600);
        setCache(true);
        setCursor(Cursor.OPEN_HAND);
    }
}