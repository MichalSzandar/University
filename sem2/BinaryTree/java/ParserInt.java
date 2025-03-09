public class ParserInt implements Parser<Integer> {

    @Override
    public Integer parse(String s) {
        return Integer.parseInt(s);
    }
    
}
