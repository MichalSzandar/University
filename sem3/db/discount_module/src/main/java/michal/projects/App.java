package michal.projects;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        ShoppingBasket basket = new ShoppingBasket();
        basket.addProduct(new Product(20));
        basket.addProduct(new Product(30));

        PercentageDiscount d1 = new PercentageDiscount();
        d1.setDiscountValue(20);

        NominalDiscount d2 = new NominalDiscount();
        d2.setDiscountValue(20);

        basket.addDiscount(d1);
        basket.addDiscount(d2);

        System.out.println(basket.calculatePrice(new MaxDiscountStrategy()));
    }
}
