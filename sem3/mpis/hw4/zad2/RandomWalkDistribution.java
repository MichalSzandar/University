import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class RandomWalkDistribution {

    public static void main(String[] args) throws IOException {
        int[] N_values = {5, 10, 15, 20, 25, 30, 100};

        // ilosc symulacji (im wieksza tym dokladniejsze przyblizenie)
        int simulations = 100000000;

        for (int N : N_values) {
            simulateAndSaveDistribution(N, simulations);
        }

        System.out.println("Simulation complete. Data saved to files.");
    }

    private static void simulateAndSaveDistribution(int N, int simulations) throws IOException {
        Random random = new Random();

        // do zliczania wartosci S_N
        //zakres od -N do N przesuniety o N
        int[] histogram = new int[2 * N + 1]; 

        for (int i = 0; i < simulations; i++) {
            int S_N = 0;
            for (int j = 0; j < N; j++) {
                S_N += random.nextBoolean() ? 1 : -1;
            }
            histogram[S_N + N]++;
        }

        // Zapisywanie do pliku
        String filename = "distribution_N_" + N + ".csv";
        try (FileWriter writer = new FileWriter(filename)) {
            writer.write("S_N,Probability\n");
            for (int i = -N; i <= N; i++) {
                double probability = (double) histogram[i + N] / simulations;
                writer.write(i + "," + probability + "\n");
            }
        }

        System.out.println("Data for N = " + N + " saved to " + filename);
    }
}
