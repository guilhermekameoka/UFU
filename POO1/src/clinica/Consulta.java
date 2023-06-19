package clinica;
import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class Consulta implements Serializable {
	private static final long serialVersionUID = 1L;
	private Date dataHoraCons;
	private ArrayList<String> medicamentos = new ArrayList<>();
	private String obsSintomas;
	private String receita;
	private float valor;
	private DemaisFunc funcMarc;
	private Medico medico;
	private PacCPlano pacCPlano;
	private PacSPlano pacSPlano;
	private ArrayList<Exame> exames = new ArrayList<>();
	
	
	SimpleDateFormat formato1 = new SimpleDateFormat("dd/MM/yyyy");
	SimpleDateFormat formato2 = new SimpleDateFormat("dd/MM/yyyy HH:mm");
	
	public Consulta(Medico med, PacCPlano pac) {
		this.setMedico(med);
		this.setPacCPlano(pac);
		this.setValor(this.pacCPlano.getValorConsP());
	}
	
	public Consulta(Medico med, PacSPlano pac) {
		this.setMedico(med);
		this.setPacSPlano(pac);
		this.setValor(this.medico.getValorSPlano());
	}
	
	
	public Date getDataHoraCons() {
		return dataHoraCons;
	}

	public void setDataHoraCons(Date dataHoraCons) {
		this.dataHoraCons = dataHoraCons;
	}
	
	public String getStrDataHoraCons() {
		return formato2.format(dataHoraCons);
	}
	
	
	public void setStrDataHoraCons(String dataHoraCons) throws ParseException {
		this.dataHoraCons = formato2.parse(dataHoraCons);
	}
	


	public ArrayList<String> getMedicamentos() {
		return medicamentos;
	}
	
	public void setMedicamentos(ArrayList<String> medicamentos) {
		this.medicamentos = medicamentos;
	}
	
	public void addMedicamentos(String med) {
		this.medicamentos.add(med);
	}
	
	
	public String getObsSintomas() {
		return obsSintomas;
	}
	
	public void setObsSintomas(String obsSintomas) {
		this.obsSintomas = obsSintomas;
	}
	
	
	public String getReceita() {
		return receita;
	}
	
	public void setReceita(String receita) {
		this.receita = receita;
	}
	
	
	public float getValor() {
		return valor;
	}
	
	public boolean setValor(float valor) {
		if(valor>0) {
			this.valor = valor;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public DemaisFunc getFuncMarc() {
		return funcMarc;
	}
	
	public String getNomeFuncMarc() {
		return this.funcMarc.getNome();
	}
	
	public void setFuncMarc(DemaisFunc funcMarc) {
		this.funcMarc = funcMarc;
	}
	
	
	public Medico getMedico() {
		return medico;
	}
	
	public void setMedico(Medico medico) {
		this.medico = medico;
	}
	
	
	public PacCPlano getPacCPlano() {
		return pacCPlano;
	}

	public boolean setPacCPlano(PacCPlano pacCPlano) {
		if(this.pacSPlano==null) {
			this.pacCPlano = pacCPlano;
			return true;
		}
		else {
			return false;
		}
	}

	public PacSPlano getPacSPlano() {
		return pacSPlano;
	}

	public boolean setPacSPlano(PacSPlano pacSPlano) {
		if(this.pacCPlano==null) {
			this.pacSPlano = pacSPlano;
			return true;
		}
		else {
			return false;
		}
	}

	public ArrayList<Exame> getExames() {
		return exames;
	}
	
	public void setExames(ArrayList<Exame> exames) {
		this.exames = exames;
	}
	
	public void addExames(Exame ex) {
		this.exames.add(ex);
	}
	
	
	public void realizarCons() {
		DemaisFunc.maisCons();
		medico.maisCons();
		medico.addConsulta(this);
		medico.somaValorCons(this.getValor());
		
		if(pacCPlano==null) {
			pacSPlano.addConsulta(this);
			pacSPlano.setDataUltCons(this.getDataHoraCons());
			pacSPlano.setValorUltCons(this.valor);
		}
		else {
			pacCPlano.addConsulta(this);
			pacCPlano.setDataUltCons(this.getDataHoraCons());
		}
		
	}
	public void realizarConsComPront(String sintomas, String receita, ArrayList<String> med, ArrayList<Exame> ex) {
		DemaisFunc.maisCons();
		medico.maisCons();
		medico.addConsulta(this);
		medico.somaValorCons(this.getValor());
		
		this.editarPront(sintomas, receita, med, ex);
		
		if(pacCPlano==null) {
			pacSPlano.addConsulta(this);
			pacSPlano.setDataUltCons(this.getDataHoraCons());
			pacSPlano.setValorUltCons(this.valor);
		}
		else {
			pacCPlano.addConsulta(this);
			pacCPlano.setDataUltCons(this.getDataHoraCons());
		}
		
	}
	
	public void editarPront(String sintomas, String receita, ArrayList<String> med, ArrayList<Exame> ex) {
		this.setObsSintomas(sintomas);
		this.setReceita(receita);
		this.setMedicamentos(med);
		this.setExames(ex);
	}

	
	public String mostrarDados() {
		if(pacSPlano==null) {
			return "\nConsulta" + "\nData e hora da Consulta: " + this.getStrDataHoraCons() + "\nPaciente: " + this.pacCPlano.getNome() + "\nPlano: " +this.pacCPlano.getNomePlano() +
			"\nMedico " + this.medico.getNome()+ "\nValor: " + this.getValor() + "\nSintomas: " + this.getObsSintomas()+ "\nReceita: " + this.getReceita() + "\nMedicamentos: " + this.getMedicamentos()
			+ "\nExames: " + this.exames.toString();
			
			
		}
		else {
			return "\nConsulta" + "\nData e hora da Consulta: " + this.getStrDataHoraCons() + "\nPaciente: " + this.pacSPlano.getNome() + "\nMedico " + this.medico.getNome()+
					"\nValor: " + this.getValor() + "\nSintomas: " + this.getObsSintomas()+ "\nReceita: " + this.getReceita() + "\nMedicamentos: " + this.getMedicamentos() +
					"\nExames: " + this.exames.toString();
		}
	}
	
	
	
}
	
