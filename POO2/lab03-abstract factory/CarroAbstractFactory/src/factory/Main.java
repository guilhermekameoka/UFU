package factory;

public class Main {

    public static void main(String[] args) {
        // Cria fábricas
        FabricaDeCarros fabricaChevrolet = new FabricaChevrolet();
        FabricaDeCarros fabricaFiat = new FabricaFiat();
        FabricaDeCarros fabricaFord = new FabricaFord();
        
        // Cria carros usando as fábricas
        Carro carro1 = new CarroChevrolet(fabricaChevrolet);
        Carro carro2 = new CarroFiat(fabricaFiat);
        Carro carro3 = new CarroFord(fabricaFord);
        
        // Exibe descrição dos carros
        System.out.println(carro1.getDescricao());
        System.out.println(carro2.getDescricao());
        System.out.println(carro3.getDescricao());
    }

}

