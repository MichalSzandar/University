import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

/*
 * Program do obliczaniaonej wartości całek dla podanych przedziałów
 */

public class Main {
    //interfejs funkcji żeby moc przekazac pozniej funkcje jako argument
    private interface Func {
        public double eval(double x);
    }

    //f(x) = x^(1/3)
    private static class F1 implements Func{
        @Override
        public double eval(double x){
            return Math.pow(x, 1.0/3.0);
        }
    }

    //f(x) = sin(x)
    private static class F2 implements Func{
        @Override
        public double eval(double x){
            return Math.sin(x);
        }
    }

    //f(x) = 4x(1-x)^3
    private static class F3 implements Func{
        @Override
        public double eval(double x){
            return 4*x*Math.pow(1-x,3);
        }
    }

    public static void main(String[] args){
        //testowanie dla f(x) = pow(x, 1/3) na przedziale [0;8] dla k1 = 5
        test(0, 8, 2, new F1(), new File("test1_1.txt"), 5);
        test(0, 8, 2, new F1(), new File("test1_2.txt"), 50);

        //testowanie f(x) = sin(x) na przedziale [0; pi]
        test(0, Math.PI, 1, new F2(), new File("test2_1.txt"), 5);
        test(0, Math.PI, 1, new F2(), new File("test2_2.txt"), 50);

        //testowanie f(x) = 4x(1-x)^3 na przedziale [0;1]
        test(0, 1, 4, new F3(), new File("test3_1.txt"), 5);
        test(0, 1, 4, new F3(), new File("test3_2.txt"), 50);
    }

    //glowna funkcja do estymacji calek
    private static double estimateValue(double a, double b, double sup, int n, Func f){
        Random rand = new Random();
        double x, y;
        int c = 0;
        for(int i =0; i<n; i++){
            x = rand.nextDouble(a, b);
            y = rand.nextDouble(0, sup);
            if(f.eval(x)>y)
                c++;
        }
        return ((double)c/(double)n)*(b-a)*sup;
    }

    //funkcja zapisujaca wyniki testow do pliku txt
    private static void test(double a, double b, double sup, Func f, File file, int k){
        double val;
        double sum;

        try (PrintWriter writer = new PrintWriter(new FileWriter(file))) {
            writer.print(createHeader(k));

            for(int i = 50; i <= 5000; i += 50){
                sum = 0;
                writer.print(i);  
                for(int j = 0; j < k; j++){
                    val = estimateValue(a, b, sup, i, f);
                    sum += val;
                    writer.print(";" + val);  
                }
                writer.println(";" + sum / (double)k);  
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // pomocnicza funkcja do generowania naglowkow w pliku
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
