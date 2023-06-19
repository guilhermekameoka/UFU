package clinica;

import java.io.Serializable;

public class Pessoa implements Mostrar, Serializable {
	private static final long serialVersionUID = 1L;
	private String nome;
	private String cpf, rg;
	private byte estadoCivil;
	private Endereco endereco;
	
	
	
	
	public Pessoa(String nome, String cpf, String rg, String estadoCivil, Endereco endereco) {
		this.setNome(nome);
		this.setCpf(cpf);
		this.setRg(rg);
		this.setEstadoCivil(estadoCivil);
		this.endereco = endereco;
	}
	
	public Pessoa(String nome, String cpf) {
		this.setNome(nome);
		this.setCpf(cpf);
	}
	
	public Pessoa(){
		
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
	
	public String getCpf() {
		return ValidaCPF.imprimeCPF(cpf);
	}
	
	public boolean setCpf(String cpf) {
		if(ValidaCPF.isCPF(cpf)==true) {
			this.cpf = cpf;
			return true;
		}
		else {
			return false;
		}
	}
	
	public String getRg() {
		return rg;
	}
	
	public boolean setRg(String rg) {
		if(rg.length()>0) {
			this.rg = rg;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String getEstadoCivil() {
		if(this.estadoCivil==0) {
			return "Solteiro";
		}
		else if(this.estadoCivil==1){
			return "Casado";
		}
		else if(this.estadoCivil==2) {
			return "Divorciado";
		}
		else {
			return "Estado Invalido";
		}
	}
	
	public boolean setEstadoCivil(String estadoCivil) {
		if(estadoCivil.equals("Solteiro")) {
			this.estadoCivil = 0;
			return true;
		}
		else if(estadoCivil.equals("Casado")) {
			this.estadoCivil = 1;
			return true;
		}
		else if(estadoCivil.equals("Divorciado")) {
			this.estadoCivil = 2;
			return true;
		}
		else {
			return false;
		}
	}

	public Endereco getEndereco() {
		return endereco;
	}

	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}
	
	public String mostrarDados() {
		return this.getNome() + "\nCPF: " + this.getCpf() + "\nRG: " + this.getRg() + "\nEstado Civil: " + this.getEstadoCivil() + endereco.mostrarDados();
	}
	
	
}
