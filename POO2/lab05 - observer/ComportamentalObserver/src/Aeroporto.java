class Aeroporto implements Observer {
    private Observable observable;

    public Aeroporto(Observable observable) {
        this.observable = observable;
        this.observable.addObserver(this);
    }

    @Override
    public void update(int temperatura, int umidade, boolean chuva, int velocidadeVento) {
        System.out.println("Aeroporto - Condicoes do vento:");
        System.out.println("Velocidade do vento: " + velocidadeVento + " km/h\n");
        System.out.println("\n");
    }
}