import java.util.*;

public abstract class Atleta implements Comparable<Atleta> {
    private String nome;
    private int idade;
    private float peso;
    private float altura;

    public Atleta(String nome, int idade, float peso, float altura) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
        this.altura = altura;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    public void aquecer(float minutos) {
        System.out.println("aquecendo por " + minutos + " minutos");
    }

    public abstract void jogar();

    @Override
    public String toString() {
        return ("nome: " + nome + " idade: " + idade + " peso: " + peso + " altura: " + altura);
    }

    @Override
    public int compareTo(Atleta atleta) {
        return nome.compareTo(atleta.nome);
    }

    public static Calendar calcularProximaOlimpiada() {
        // pega a data atual
        Calendar c = Calendar.getInstance();
        Calendar olimpiada = Calendar.getInstance();
        // data pra proxima olimpiada : 26/03/2023
        olimpiada.set(2023, 2, 26, 12, 0, 0);
        // diminui o tempo(em milissegundos) da data da olimpiada pela data atual e converte em dias
        long x = olimpiada.getTimeInMillis();
        long z = c.getTimeInMillis();
        long dias = (x - z) / 86400000;
        System.out.println("Dias ate a proxima olimpiada: " + dias);
        // retorna a data da olimpiada
        return olimpiada;

    }
}
