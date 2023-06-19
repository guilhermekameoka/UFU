public class Carro {
    private Motor motor;
    private Acessorios acessorios;

    public Carro(CarroFactory factory) {
        this.motor = factory.cMotor();
        this.acessorios = factory.cAcessorios();
    }

    public void ligar() {
        System.out.println("Seu motor " + motor.getTipo() + " com os acessórios " + acessorios.getDescricao());
    }
}