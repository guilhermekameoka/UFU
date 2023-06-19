package factory;

public class FabricaChevrolet implements FabricaDeCarros {
    public Motor criarMotor() {
        return new MotorChevrolet();
    }

    public Acessorios criarAcessorios() {
        return new AcessoriosChevrolet();
    }
}
