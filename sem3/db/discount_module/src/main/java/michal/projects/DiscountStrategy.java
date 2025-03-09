package michal.projects;

import java.util.List;

public interface DiscountStrategy {
    public double calculateTotal(List<Discount> discounts, double total);
}
