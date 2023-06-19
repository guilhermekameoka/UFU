public class Tenista extends Atleta {

    public Tenista(String a, int b, float c, float d) {
        super(a, b, c, d);
    }

    @Override
    public void jogar() {
        System.out.println("Jogando tênis");
    }

    @Override
    public int compareTo(Object o) {
        String n = ((Atleta) o).getNome();
        String n2 = getNome();
        return n2.compareTo(n);
    }

}
