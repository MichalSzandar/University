import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

// simulations of the distorted communication problem

public class DistortedCom{
    public static void main(String[] args){
        Random rand = new Random();

        try {
            FileWriter writer1 = new FileWriter("t1_values.csv");
            FileWriter writer2 = new FileWriter("t2_values.csv");

            writer1.write("n,T\n");
            writer2.write("n,T\n");

            for (int n = 1000; n <= 100000; n+=1000) {
                for (int k = 0; k<50; k++) {
                    int res1 = startSimulation(n, 0.5, rand);
                    int res2 = startSimulation(n, 0.1, rand);

                    writer1.write(n + "," + res1 + "\n");
                    writer2.write(n + "," + res2 + "\n");
                }
            }

            writer1.close();
            writer2.close();
        } catch (IOException e){
            e.printStackTrace();
        }
    }

    /**
     * sends signal to n stations with probability p that the signal will be recieved
     * @param n - number of stations to send signal to
     * @param p - probability for recieving the signal
     * @param rand - random number generator
     * @return t - number of rounds needed to transmit the signal to each station
     */
    public static int startSimulation(int n, double p, Random rand){
        int t = 0;
        boolean[] stations = new boolean[n];
        int recievedMessages = 0;

        while(recievedMessages < n){
            t++;
            for(int i = 0; i < n; i++){
                if(!stations[i]){
                    stations[i] = (rand.nextDouble() < p);
                    if(stations[i])
                        recievedMessages++;
                }
            }
        }

        return t;
    }
}