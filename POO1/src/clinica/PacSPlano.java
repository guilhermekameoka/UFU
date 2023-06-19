package clinica;
import java.text.ParseException;

public class PacSPlano extends Paciente {
	private static final long serialVersionUID = 1L;
	private boolean descEsp;
	private float valorUltCons;
	

	public PacSPlano(String nome, String cpf, boolean descEsp, float valorUltCons) {
		super(nome, cpf);
		this.setDescEsp(descEsp);
		this.setValorUltCons(valorUltCons);
	}

	public PacSPlano(String nome, String cpf, Endereco endereco, String dataNasc) throws ParseException {
		super(nome, cpf);
		this.setEndereco(endereco);
		this.setStrDataNasc(dataNasc);
	}
	
	public PacSPlano(String nome, String cpf) {
		super(nome, cpf);
	}
	
	public PacSPlano() {
		
	}
	
	@Override
	public String geraRecibo() { //valor pode ter desconto especial, que representa 10% de desconto 
		if(this.descEsp) {
			float valor = this.getValorUltCons()*0.9f;
			return "\nRecibo\nCliente: "+ this.getNome() + "\nCPF: " + this.getCpf() + "\nValor: R$ " + valor;
		}
		else {
			return "\nRecibo\nCliente: "+ this.getNome() + "\nCPF: " + this.getCpf() + "\nValor: R$ " + this.getValorUltCons();						
		}
	}

	public boolean getDescEsp() {
		return descEsp;
	}

	public void setDescEsp(boolean descEsp) {
		this.descEsp = descEsp;
	}

	public float getValorUltCons() {
		return valorUltCons;
	}

	public boolean setValorUltCons (float valorcons){
		if(valorcons>0) {
			this.valorUltCons = valorcons;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String mostrarDados() {
		return super.mostrarDados() + "\nDesconto especial: " + this.getDescEsp() + "\nValor da ultima consulta: " + this.getValorUltCons();
	}

}
