package factory;

public class CarroFord extends Carro {
    public CarroFord(FabricaDeCarros fabrica) {
        super(fabrica);
    }

    public String getDescricao() {
        return "Carro Ford com " + super.getMotor().getDescricao() + " e " + super.getAcessorios().getDescricao();
    }
}
