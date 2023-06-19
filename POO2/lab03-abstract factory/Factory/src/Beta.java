public class Beta implements CarroFactory {
    @Override
    public Motor cMotor() {
        return new Motor("1.2");
    }

    @Override
    public Acessorios cAcessorios() {
        return new Acessorios("Alto falante e câmera de ré");
    }
}