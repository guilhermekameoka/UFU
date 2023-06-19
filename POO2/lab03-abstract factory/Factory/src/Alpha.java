public class Alpha implements CarroFactory {
    @Override
    public Motor cMotor() {
        return new Motor("6 cilindros");
    }

    @Override
    public Acessorios cAcessorios() {
        return new Acessorios("Ar-condicionado");
    }
}