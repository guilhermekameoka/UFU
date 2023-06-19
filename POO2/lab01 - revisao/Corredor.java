public class Corredor extends Atleta {

    public Corredor(String nome, int idade, float peso, float altura) {
        super(nome, idade, peso, altura);
    }

    @Override
    public void jogar(){
        System.out.println("Correndo");
    }

    @Override
    public int compareTo(Object o) {
        String n = ((Atleta) o).getNome();
        String n2 = getNome();
        return n2.compareTo(n);
    }
}
