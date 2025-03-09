package michal.projects;

public class PercentageDiscount extends Discount{
    private double percentage;

    @Override
    public double calculateDiscount(double total) {
        if(isExpired() || total < minPrice) return total;
        
        return total - (total * percentage / 100);
    }

    @Override
    public void setDiscountValue(double value) {
        this.percentage = value;
    }
    
}
