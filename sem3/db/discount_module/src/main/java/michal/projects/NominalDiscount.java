package michal.projects;

public class NominalDiscount extends Discount{

    private double nominal;
    @Override
    public double calculateDiscount(double total) {
        if(isExpired() || total < minPrice) return total;
        
        return total - nominal;
    }

    @Override
    public void setDiscountValue(double value) {
        nominal = value;
    }  
}
