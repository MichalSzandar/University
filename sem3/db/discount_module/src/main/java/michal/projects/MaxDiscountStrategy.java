package michal.projects;

import java.util.List;

public class MaxDiscountStrategy implements DiscountStrategy {

    @Override
    public double calculateTotal(List<Discount> discounts, double total) {
        double result = total;
   
        for(Discount discount : discounts) {
            if(discount instanceof PercentageDiscount) {
                result = discount.calculateDiscount(result);
            }
        }

        for(Discount discount : discounts){
            if(discount instanceof NominalDiscount) {
                result = discount.calculateDiscount(result);
            }
        }
  
        return result; 
    }
    
}
