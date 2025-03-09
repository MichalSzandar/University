import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

/**
 * Class to test insertion sort algorithm
 */
public class InsertionSort {
    public static void main(String[] args){
        Random rand = new Random();
        List<Integer> list = new ArrayList<>();
        long start = System.currentTimeMillis();

        try{
            FileWriter writerCmp = new FileWriter("Cmp_values.csv");
            FileWriter writerS = new FileWriter("S_values.csv");

            //headers
            writerCmp.write("n,cmp\n");
            writerS.write("n,s\n");

            for(int n = 100; n <= 10000; n+=100){
                addNextHundredElements(list);

                for(int k = 0; k<50; k++){
                    //shuffle(list, rand);
                    //for better optimization I'll use shuffle method from Collections class instead of my own (mine still works)
                    Collections.shuffle(list);

                    int[] results = insertionSort(list);
                    writerCmp.write(n + "," + results[0] + "\n");
                    writerS.write(n + "," + results[1] + "\n");
                }
            }

            writerCmp.close();
            writerS.close();

        } catch (IOException e){
            e.printStackTrace();
        }

        System.out.println(System.currentTimeMillis() - start);
    }

    /**
     * sorts list and returns number of comparisons and key swaps
     * @param perm - list to sort
     * @return - int res[] where res[0] is #comparisons and res[1] is #key swaps
     */
    public static int[] insertionSort(List<Integer> perm) {
        int size = perm.size();
        int cmp = 0;
        int s = 0;
        for(int j = 1; j < size; j++) {
            int key = perm.get(j);
            int i = j-1;
            while (i >= 0 ) {
                cmp++;
                if (perm.get(i) > key) {
                    perm.set(i + 1, perm.get(i));
                    s++;
                } else {
                    break;
                }
                i--;
            }

            perm.set(i+1, key);
        }

        return new int[]{cmp, s};
    }

    /**
     * shuffles elements of the list
     * @param perm - list 
     * @param rand - random numbers generator
     */
    public static void shuffle(List<Integer> perm, Random rand){
        int size = perm.size();
        for(int i = size; i>1; i--){
            swap(perm, i-1, rand.nextInt(i));
        }
    }

    /**
     * swaps two elements in the list
     * @param list - list to swap elements
     * @param i - index of the first element
     * @param j - index of the second element
     */
    private static void swap(List<Integer> list, int i, int j){
        int temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    }

    /**
     * adds another hundred elements to the list
     * @param perm - list to which we're adding new elements
     */
    private static void addNextHundredElements(List<Integer> perm){
        int size = perm.size();

        for(int i = size; i <= size+100; i++){
            perm.add(i);
        }
    }
}