package clinica;
import java.util.ArrayList;

public class Medico extends Funcionario{
	private static final long serialVersionUID = 1L;
	private int crm;
	private int numConsRealiz;
	private float somaConsMes;
	private ArrayList<String> especialidades = new ArrayList<>();
	private ArrayList<PlanoSaude> planosAtend = new ArrayList<>();
	private ArrayList<Consulta> consulta = new ArrayList<>();
	private float valorSPlano; //armazena o valor da consulta para quando o paciente nao tem plano
	
	

	public Medico(ArrayList<PlanoSaude> planosAtend, String cpf) {
		this.planosAtend = planosAtend;
		this.setCpf(cpf);
	}
	
	public Medico(String nome, float valorSP) {
		this.setNome(nome);
		this.setValorSPlano(valorSP);
	}


	public Medico() {
		
	}
	
	
	public int getCrm() {
		return crm;
	}
	
	public boolean setCrm(int crm) {
		if(crm>0) {
			this.crm = crm;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public ArrayList<String> getEspecialidades() {
		return especialidades;
	}
	
	public void setEspecialidades(ArrayList<String> especialidades) {
		this.especialidades = especialidades;
	}
	
	
	public void addEspecialidades(String especialidades) {
		this.especialidades.add(especialidades);
	}
	
	
	public int getNumConsRealiz() {
		return numConsRealiz;
	}
	
	public boolean setNumConsRealiz(int numConsRealiz) {
		if(numConsRealiz>0) {
			this.numConsRealiz = numConsRealiz;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public float getSomaConsMes() {
		return somaConsMes;
	}

	public boolean setSomaConsMes(float somaConsMes) {
		if(somaConsMes>0) {
			this.somaConsMes = somaConsMes;			
			return true;
		}
		else {
			return false;
		}
	}
	

	public ArrayList<PlanoSaude> getPlanosAtend() {
		return planosAtend;
	}
	
	public void setPlanosAtend(ArrayList<PlanoSaude> planosAtend) {
		this.planosAtend = planosAtend;
	}
	
	
	public void addPlanosAtend(PlanoSaude planoAtend) {
		this.planosAtend.add(planoAtend);
	}
	
	
	public ArrayList<Consulta> getConsulta() {
		return consulta;
	}

	public void setConsulta(ArrayList<Consulta> consulta) {
		this.consulta = consulta;
	}
	
	public void addConsulta(Consulta cons) {
		this.consulta.add(cons);
	}
	
	
	public float getValorSPlano() {
		return valorSPlano;
	}

	
	public boolean setValorSPlano(float valorSPlano) {
		if(valorSPlano>0) {
			this.valorSPlano = valorSPlano;
			return true;
		}
		else {
			return false;
		}
	}


	public void maisCons() {
		this.setNumConsRealiz(getNumConsRealiz()+1);
	}
	
	public void somaValorCons(float valor) {
		this.setSomaConsMes(getSomaConsMes()+valor);
	}
	
	public void zeraSomaValorCons() {
		this.setSomaConsMes(0f);
	}


	@Override
	public float calcSalario() {
		if(this.getSomaConsMes()==0f && consulta!=null) {
			for(Consulta c: consulta) {
				this.setSomaConsMes(this.getSomaConsMes()+c.getValor());
			}
			return this.getSomaConsMes();
		}else {
			return this.getSomaConsMes();
		}
		
	}


	public String mostrarDados() {
		return 	super.mostrarDados() + "\nCargo: Medico" + "\nCRM: " + this.getCrm() + "\nNumero de consultas realizadas: " + this.getNumConsRealiz() +
				"\nEspecialidades: " +this.getEspecialidades() + "\nPlanos de saude atendidos: " + planosAtend.toString()+
				"\nValor consulta sem plano: " + this.getValorSPlano();
	}
	
	
	

}
