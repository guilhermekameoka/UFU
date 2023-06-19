package clinica;

import java.io.Serializable;

public class Exame implements Serializable{
	private static final long serialVersionUID = 1L;
	private String nome;
	
	public Exame(String nome) {
		this.setNome(nome);
	}

	public String getNome() {
		return nome;
	}

	public boolean setNome(String nome) {
		if(nome.length()>0) {
			this.nome = nome;
			return true;
		}
		else {
			return false;
		}
	}

	@Override
	public String toString() {
		return this.getNome();
	}
	
	
	
	
}
