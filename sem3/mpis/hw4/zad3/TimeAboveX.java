import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class TimeAboveX{

    public static void main(String[] args) throws IOException {
        int[] N_values = {100, 1000, 10000};

        // ilosc wykonan
        int realizations = 5000;

        for (int N : N_values) {
            simulateAndSaveFractionAboveOX(N, realizations);
        }

        System.out.println("Simulation complete. Data saved to files.");
    }

    private static void simulateAndSaveFractionAboveOX(int N, int realizations) throws IOException {
        Random random = new Random();

        double[] fractions = new double[realizations];

        for (int i = 0; i < realizations; i++) {
            int S[] = new int[N+1];
            S[0] = 0;
            //liczy ile czasu spedzamy nad X
            int L_N = 0;

            for (int n = 1; n <= N; n++) {
                S[n] = S[n-1] + (random.nextBoolean() ? 1 : -1);
                if (S[n] > 0 || (S[n] == 0 &&  S[n-1] > 0)) {
                    L_N++;
                }
            }

            fractions[i] = (double) L_N / N;
        }

        String filename = "fraction_above_OX_N_" + N + ".csv";
        try (FileWriter writer = new FileWriter(filename)) {
            writer.write("P_N\n");
            for (double fraction : fractions) {
                writer.write(fraction + "\n");
            }
        }

        System.out.println("Data for N = " + N + " saved to " + filename);
    }
}
