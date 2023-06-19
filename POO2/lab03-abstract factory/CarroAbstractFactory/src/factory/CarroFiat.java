package factory;

public class CarroFiat extends Carro {
    public CarroFiat(FabricaDeCarros fabrica) {
        super(fabrica);
    }

    public String getDescricao() {
        return "Carro Fiat com " + super.getMotor().getDescricao() + " e " + super.getAcessorios().getDescricao();
    }
}

