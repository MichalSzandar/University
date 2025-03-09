import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class MaxLoadTest {
   public static void main(String[] args) {
        Random random = new Random();

        try {
            FileWriter writerL1 = new FileWriter("L(1)_values.csv");
            FileWriter writerL2 = new FileWriter("L(2)_values.csv");

            //headers
            writerL1.write("n,L(1)\n");
            writerL2.write("n,L(2)\n");
  
            for (int n = 1000; n <= 100000; n += 1000) {
                for (int k = 0; k < 50; k++) {
                    int result = startSimulation(n, 1, random);
                    int result2 = startSimulation(n, 2, random);
                    // saving results
                    writerL1.write(n + "," + result + "\n");
                    writerL2.write(n + "," + result2 + "\n");
                }
            }

            // closing files
            writerL1.close();
            writerL2.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static int startSimulation(int n, int d, Random random) {
        int binId, l  = 0;

        int[] ballCount = new int[n]; // save number of balls in bins

        for(int i = 0; i < n; i++) {
            binId = getRandomBinId(n, ballCount, d, random);

            ballCount[binId]++;
           
            l = Math.max(ballCount[binId], l);
        }

        return l;
    }

    /**
     * draws d random elements and from array and chooses the one with lowest value
     * @param n - size of the array
     * @param bins - array from which we're choosing elements
     * @param d - number of elements to draw
     * @param rand - random number generator
     * @return lowest value among d random values from bins
     */
    private static int getRandomBinId(int n, int[] bins, int d, Random rand){
        int binId = rand.nextInt(n);
        int result = binId;

        for(int i = 1; i<d; i++){
            binId = rand.nextInt(n);
            if(bins[binId] < bins[result]){
                result = binId;
            }
        }
        return result;
    }
}
