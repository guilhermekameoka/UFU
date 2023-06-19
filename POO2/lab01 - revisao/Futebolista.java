public class Futebolista extends Atleta {
    Futebolista(String a, int b, float c, float d) {
        super(a, b, c, d);
    }

    public void jogar(){
        System.out.println("Jogando futebol");
    }

    @Override
    public int compareTo(Object o) {
        String n = ((Atleta) o).getNome();
        String n2 = getNome();
        return n2.compareTo(n);
    }
}
