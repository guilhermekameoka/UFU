public class Main {
    public static void main(String[] args) {
        Carro voyage = new Carro(new Gama());
        Carro romeu = new Carro(new Alpha());
        Carro veloster = new Carro(new Beta());

        voyage.ligar();
        romeu.ligar();
        veloster.ligar();
    }
}