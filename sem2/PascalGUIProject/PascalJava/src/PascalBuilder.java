import java.util.ArrayList;

import javafx.scene.control.ListView;

public class PascalBuilder 
{
    PascalBuilder(int n, ListView<ArrayList<Integer>> listView)
    {
        ArrayList<ArrayList<Integer>> pascalTriangle = buildPascalTriangle(n);
        listView.getItems().clear();
        for (ArrayList<Integer> row : pascalTriangle) {
            listView.getItems().add(row);
        }
    }

    private ArrayList<ArrayList<Integer>> buildPascalTriangle(int n)
    {
        if(n<=0)
            throw new IndexOutOfBoundsException("Your input must be an integer greater than 0. \nYour input: "+n+".");

        ArrayList<ArrayList<Integer>> pascalTriangle = new ArrayList<ArrayList<Integer>>(n);
        
        for (int line = 1; line <= n; line++)
        {
            int c = 1;
            ArrayList<Integer> row = new ArrayList<Integer>();

            for (int i = 1; i <= line; i++) 
            {
                row.add(c);
                c = (int)((long)c * (long)(line - i) / (long)i);

                if(c<0)
                    throw new IndexOutOfBoundsException("Values in " + n + "th row exceed the maximum integer value. \nYour input should be a smaller number.");
            }
           pascalTriangle.add(row);
        }
        return pascalTriangle;
    }
}
