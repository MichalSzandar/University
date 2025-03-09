import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

//simulations of the balls and bins problem

class Main {
    public static void main(String[] args) {
        Random random = new Random();

        try {
            // Tworzymy pliki wyjściowe
            FileWriter writerB = new FileWriter("B_values.csv");
            FileWriter writerU = new FileWriter("U_values.csv");
            FileWriter writerC = new FileWriter("C_values.csv");
            FileWriter writerD = new FileWriter("D_values.csv");
            FileWriter writerD_C = new FileWriter("D-C_values.csv");

            // Nagłówki
            writerB.write("n,B\n");
            writerU.write("n,U\n");
            writerC.write("n,C\n");
            writerD.write("n,D\n");
            writerD_C.write("n,D-C\n");

            // Pętla przez wartości n
            for (int n = 1000; n <= 100000; n += 1000) {
                for (int k = 0; k < 50; k++) {
                    int[] results = startSimulation(n, random);

                    // Zapis wyników do plików
                    writerB.write(n + "," + results[0] + "\n");
                    writerU.write(n + "," + results[1] + "\n");
                    writerC.write(n + "," + results[2] + "\n");
                    writerD.write(n + "," + results[3] + "\n");
                    writerD_C.write(n + "," + results[4] + "\n");
                }
            }

            // Zamykamy pliki
            writerB.close();
            writerU.close();
            writerC.close();
            writerD.close();
            writerD_C.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static int[] startSimulation(int n, Random random) {
        /*
         * B - moment pierwszej kolizji
         * U - liczba pustych urn
         * C - minimalna liczba rzutów, po której jest co najmniej jedna kula wszędzie
         * D - minimalna liczba rzutów, po której wszędzie są co najmniej 2 kule
         */
        int B = 0, U = 0, C = 0, D = 0, binId, ballId = 1;

        int[] ballCount = new int[n]; // Przechowuje liczbę kul w każdym koszyku
        int binsWithOneBallCount = 0;
        int binsWithTwoBallsCount = 0;

        while (D == 0) {
            binId = random.nextInt(n);

            // Sprawdzamy, czy koszyk ma już co najmniej jedną kulę
            if (ballCount[binId] == 1) {
                if (B == 0) {
                    B = ballId; 
                }
                binsWithTwoBallsCount++;
            }

            // Jeśli koszyk był wcześniej pusty
            if (ballCount[binId] == 0) {
                binsWithOneBallCount++;
            }

            ballCount[binId]++;

            // Ustawiamy wartość C, gdy wszystkie koszyki mają przynajmniej 1 kulę
            if (C == 0 && binsWithOneBallCount == n) {
                C = ballId;
            }

            // Rejestrujemy liczbę pustych koszyków w momencie n-tym rzucie
            if (ballId == n) {
                U = n - binsWithOneBallCount;
            }

            // Ustawiamy D, gdy wszystkie koszyki mają przynajmniej 2 kule
            if (D == 0 && binsWithTwoBallsCount == n) {
                D = ballId;
            }

            ballId++;
        }

        return new int[]{B, U, C, D, D-C};
    }
}
