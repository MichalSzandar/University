package michal.projects;

import java.util.ArrayList;
import java.util.List;

public class ShoppingBasket {
    private List<Product> products;
    private List<Discount> discounts;

    private double sumProductPrice(){
        double sum = 0;
        for(Product product: products){
            sum += product.getPrice();
        }
        return sum;
    }

    public void addProduct(Product product){
        products.add(product);
    }

    public void addDiscount(Discount discount){
        discounts.add(discount);
    }

    public void removeDiscount(Discount discount){
        discounts.remove(discount);
    }

    public double calculatePrice(DiscountStrategy strategy){
        return strategy.calculateTotal(discounts, sumProductPrice());
    }

    public ShoppingBasket(){
        products = new ArrayList<>();
        discounts = new ArrayList<>();
    }
}
