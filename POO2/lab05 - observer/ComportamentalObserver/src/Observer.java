interface Observer {
    void update(int temperatura, int umidade, boolean chuva, int velocidadeVento);
}

interface Observable {
    void addObserver(Observer observer);
    void removeObserver(Observer observer);
    void notifyObservers();
}
