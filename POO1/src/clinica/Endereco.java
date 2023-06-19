package clinica;

import java.io.Serializable;

public class Endereco implements Mostrar, Serializable {
	private static final long serialVersionUID = 1L;
	private String rua;
	private int num;
	private String compl, bairro, cidade;
	private String cep;
	
	
	public Endereco(String rua, int num, String compl, String bairro, String cidade, String cep) {
		this.setRua(rua);
		this.setNum(num);
		this.setCompl(compl);
		this.setBairro(bairro);
		this.setCidade(cidade);
		this.setCep(cep);
	}

	public Endereco(String rua, int num) {
		this.setRua(rua);
		this.setNum(num);
	}
	
	public Endereco() {
		
	}
	

	public String getRua() {
		return rua;
	}
	
	public boolean setRua(String rua) {
		if(rua.length()>0) {
			this.rua = rua;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public int getNum() {
		return num;
	}
	
	public boolean setNum(int num) {
		if(num>0) {
			this.num = num;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String getCompl() {
		return compl;
	}
	
	public void setCompl(String compl) {
		this.compl = compl;
	}
	
	
	public String getBairro() {
		return bairro;
	}
	
	public boolean setBairro(String bairro) {
		if(bairro.length()>0) {
			this.bairro = bairro;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String getCidade() {
		return cidade;
	}
	
	public boolean setCidade(String cidade) {
		if(cidade.length()>0) {
			this.cidade = cidade;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String getCep() {
		return cep;
	}
	
	public boolean setCep(String cep) {
		if(cep.length()>0) {
			this.cep = cep;
			return true;
		}
		else {
			return false;
		}
	}
	
	public String mostrarDados() {
		return "\nEndereco: Rua " + this.getRua() + " " + this.getNum();
	}
	
	
}
