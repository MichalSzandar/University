public class ParserDouble implements Parser<Double>{

    @Override
    public Double parse(String s) {
        return Double.parseDouble(s);
    }
    
}
