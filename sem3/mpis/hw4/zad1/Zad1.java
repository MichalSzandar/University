public class Zad1 {
    public static void main(String[] args) {
        System.out.println("n  Markov   Czebyszew  real");
        for(int i = 100; i <= 10000; i*=10) {
            double a1 = (6.0/5.0) * E(i, 1.0/2.0);
            double a2 = (1.0/5.0) * E(i, 1.0/2.0);
            System.out.println(i + ": " + szacowanieMarkova(i, 1.0/2.0, a1) + " : " + szacowanieCzebyszewa(i, 1.0/2.0, a2) + " : " );
        }

        System.out.println("n  Markov   Czebyszew  real");
        for(int i = 100; i <= 10000; i*=10) {
            double a1 = (11.0/10.0) * E(i, 1.0/2.0);
            double a2 = (1.0/10.0) * E(i, 1.0/2.0);
            System.out.println(i + ": " + szacowanieMarkova(i, 1.0/2.0, a1) + " : " + szacowanieCzebyszewa(i, 1.0/2.0, a2) +  " : " );
        }
    }

    /**
     * metoda do liczenia wartości oczekiwanej zmiennej losowej o rozkładzie Bin(n, p)
     * @param n - ilosc prob
     * @param p - preawdopodobienstwo pojedynczego sukcesu
     * @return oczekiwana wartość
     */
    public static double E(int n, double p) {
        return n * p;
    }

    /**
     * metoda do liczenia wariancji zmiennej losowej o rozkladzien Bin(n, p)
     * @param n - ilosc prob
     * @param p - prawdopodobienstwo pojedynczego sukcesu
     * @return wariancja 
     */
    public static double var(int n, double p){
        return n * p * (1 - p);
    }

    /**
     * metoda do wyznaczania górnej granicy P(X >= a), 
     * gdzie X to zmienna losowa o rozkładzie Bin(n, p),
     * a to liczba rzeczywista dodatnia za pomocą 
     * nierówności Markova
     * @param n - ilość prób
     * @param p - prawdopodobieństwo sukcesu w pojedynczej próbie 
     * @param a - dodatnia liczba rzeczywista
     * @return górna granica wyrażenia P(X >= a)
     */
    public static double szacowanieMarkova(int n, double p, double a) {
        return E(n, p) / a;
    }

    /**
     * metoda do wyznaczania górnej granicy P(X >= a), 
     * gdzie X to zmienna losowa o rozkładzie Bin(n, p),
     * a to liczba rzeczywista dodatnia za pomocą 
     * nierówności Czebyszewa
     * @param n - ilość prób
     * @param p - prawdopodobieństwo sukcesu w pojedynczej próbie 
     * @param a - dodatnia liczba rzeczywista
     * @return górna granica wyrażenia P(X >= a)
     */
    public static double szacowanieCzebyszewa(int n, double p, double a) {
        return var(n, p) / Math.pow(a, 2);
    }

    public static long fact(int i) {
        if(i <= 1) {
           return 1;
        }
        return i * fact(i - 1);
     }

    public static long binomial(int  n, int k){
        return fact(n)/(fact(k) * fact(n-k));
    }

    public static double ppbWiekszeOdK(int n, int k, double p){
        double res = 0;
        for(int i = k; i <= n; i++){
            res += binomial(n, k) * Math.pow(p, n);
        }

        return res;
    }
}