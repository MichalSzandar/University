package michal.projects;

import java.time.Instant;

public abstract class Discount {
    protected double minPrice;
    protected Instant expieryDate;

    public void setMinPrice(double minPrice){
        this.minPrice = minPrice;
    }

    public double getMinPrice(){
        return minPrice;
    }

    public void setExpieryDate(Instant date){
        expieryDate = date;
    }

    public boolean isExpired(){
        if(expieryDate == null) return false;
        return Instant.now().isAfter(expieryDate);
    }

    public abstract double calculateDiscount(double total);
    public abstract void setDiscountValue(double value);
}
