import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.logging.Level;

public class CppRunner {
    public static ArrayList<String> getOutput(String command) 
    {
        ArrayList<String> output = new ArrayList<String>();
        try {
            String[] input = command.split(" ");

            ProcessBuilder pb = new ProcessBuilder(input);

            Process process = pb.start();

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                MyLogger.logger.log(Level.INFO, "program reutrned: " + line);
                output.add(line);
            }
            while ((line = errorReader.readLine()) != null) {
                MyLogger.logger.log(Level.SEVERE, "ERROR: " + line);
                AlertPopups.displayError(line);
            }

            int exitCode = process.waitFor();
            MyLogger.logger.log(Level.INFO, "Program exited with code: " + exitCode);
        
        } catch (IOException | InterruptedException e) {
            MyLogger.logger.log(Level.SEVERE, e.getMessage());
        }
        return output;
    }

}
