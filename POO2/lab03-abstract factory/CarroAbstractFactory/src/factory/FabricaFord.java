package factory;

public class FabricaFord implements FabricaDeCarros {
    public Motor criarMotor() {
        return new MotorFord();
    }

    public Acessorios criarAcessorios() {
        return new AcessoriosFord();
    }
}