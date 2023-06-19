package factory;

public class CarroChevrolet extends Carro {
    public CarroChevrolet(FabricaDeCarros fabrica) {
        super(fabrica);
    }

    public String getDescricao() {
        return "Carro Chevrolet com " + super.getMotor().getDescricao() + " e " + super.getAcessorios().getDescricao();
    }
}

