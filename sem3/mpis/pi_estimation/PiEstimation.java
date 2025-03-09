import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

// Class to estimate the value of Pi using the Monte Carlo method

public class PiEstimation {
    public static void main(String[] args){
        test(new File("pi_1.txt"), 5);
        test(new File("pi_2.txt"), 50);
    }

    private static double estimatePi(double r, int n){
        Random random = new Random();
        double x, y;
        int c = 0;
        for(int i = 0; i < n; i++){
            x = random.nextDouble(0, r);
            y = random.nextDouble(0, r);
            if(Math.pow(x, 2) + Math.pow(y, 2) <= Math.pow(r, 2)){
                c++;
            }
        }
        return 4*((double)c/(double)n);
    }

     private static void test(File file, int k){
        double val;
        double sum;

        try (PrintWriter writer = new PrintWriter(new FileWriter(file))) {
            writer.print(createHeader(k));

            for(int i = 50; i <= 5000; i += 50){
                sum = 0;
                writer.print(i);  
                for(int j = 0; j < k; j++){
                    val = estimatePi(1, i);
                    sum += val;
                    writer.print(";" + val); 
                }
                writer.println(";" + sum / (double)k);  
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String createHeader(int numRuns) {
        StringBuilder header = new StringBuilder();
        header.append("n");
        for (int i = 1; i <= numRuns; i++) {
            header.append(";run_").append(i);
        }
        header.append(";average\n");
        return header.toString();
    }
}