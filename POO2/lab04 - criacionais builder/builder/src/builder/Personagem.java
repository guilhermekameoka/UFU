package builder;

public class Personagem {
    private String nome;
    private String profissao;
    private String arma;
    private String item;
    
    public Personagem(String nome, String profissao, String arma, String item) {
        this.nome = nome;
        this.profissao = profissao;
        this.arma = arma;
        this.item = item;
    }
    
    public String getNome() {
        return nome;
    }
    
    public String getProfissao() {
        return profissao;
    }
    
    public String getArma() {
        return arma;
    }
    
    public String getItem() {
        return item;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public void setProfissao(String profissao) {
        this.profissao = profissao;
    }
    
    public void setArma(String arma) {
        this.arma = arma;
    }
    
    public void setItem(String item) {
        this.item = item;
    }
}


