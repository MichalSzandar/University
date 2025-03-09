import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

public class AlertPopups {
    public static void displayError(String message)
    {
        Alert alert = new Alert(AlertType.ERROR);
        alert.setResizable(false);
        alert.getDialogPane().setPrefSize(450, 100);
        alert.setTitle("Wrong Input");
        alert.setHeaderText(null);
        alert.setGraphic(null);
        alert.setContentText(message);

        alert.showAndWait();
    }
    
}
