package factory;

public abstract class Carro {
    private Motor motor;
    private Acessorios acessorios;

    public Carro(FabricaDeCarros fabrica) {
        this.motor = fabrica.criarMotor();
        this.acessorios = fabrica.criarAcessorios();
    }

    public Motor getMotor() {
        return motor;
    }

    public Acessorios getAcessorios() {
        return acessorios;
    }

    public abstract String getDescricao();
}
