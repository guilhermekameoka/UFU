package clinica;

import java.io.Serializable;

public class PlanoSaude implements Serializable{
	private static final long serialVersionUID = 1L;
	private String nome;
	private String cnpj;
	private Endereco endereco;
	private float valorCons; //armazena o valor da consulta com plano
	
	
	public PlanoSaude(String nome, String cnpj, Endereco endereco, float valor) {
		this.setNome(nome);
		this.setCnpj(cnpj);
		this.setEndereco(endereco);
		this.setValorCons(valor);
	}
	
	public PlanoSaude(String nome, float valor) {
		this.setNome(nome);
		this.setValorCons(valor);
	}
	
	public PlanoSaude() {
		
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
	
	
	public String getCnpj() {
		return cnpj;
	}
	
	public boolean setCnpj(String cnpj) {
		if(cnpj.length()>0) {
			this.cnpj = cnpj;
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

	
	public float getValorCons() {
		return valorCons;
	}

	public boolean setValorCons(float valorCons) {
		if(valorCons>0) {
			this.valorCons = valorCons;
			return true;
		}
		else {
			return false;
		}
	}

	@Override
	public String toString() {
		return this.getNome() + " com valor de consulta R$ " + this.getValorCons();
	}
	
	
}
