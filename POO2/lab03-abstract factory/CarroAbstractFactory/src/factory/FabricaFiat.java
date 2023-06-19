package factory;

public class FabricaFiat implements FabricaDeCarros {
    public Motor criarMotor() {
        return new MotorFiat();
    }

    public Acessorios criarAcessorios() {
        return new AcessoriosFiat();
    }
}
