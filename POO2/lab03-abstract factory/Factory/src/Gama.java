public class Gama implements CarroFactory {
    @Override
    public Motor cMotor() {
        return new Motor("1.2");
    }

    @Override
    public Acessorios cAcessorios() {
        return new Acessorios("Multimídia integrada");
    }
}
