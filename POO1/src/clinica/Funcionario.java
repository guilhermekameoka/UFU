package clinica;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public abstract class Funcionario extends Pessoa {
	private static final long serialVersionUID = 1L;
	private Date dataAdmi;
	private int numCartTrab;
	private String usuario, senha;
	
	SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
	
	
	
	public Funcionario(String nome, String cpf, String rg, String estadoCivil, Endereco endereco, Date dataAdmi, int numCartTrab, String usuario, String senha) {
		super(nome, cpf, rg, estadoCivil, endereco);
		this.setDataAdmi(dataAdmi);
		this.setNumCartTrab(numCartTrab);
		this.setUsuario(usuario);
		this.setSenha(senha);;
	}
	
	public Funcionario(String nome, String cpf, String rg, String estadoCivil, Endereco endereco) {
		super(nome, cpf, rg, estadoCivil, endereco);
	}

	public Funcionario() {
		
	}
	
	public abstract float calcSalario();
	
	
	public Date getDataAdmi() {
		return dataAdmi;
	}
	
	public void setDataAdmi(Date dataAdmi) {
		this.dataAdmi = dataAdmi;
	}
	
	
	public String getStrDataAdmi() {
		return formato.format(dataAdmi);
	}
	
	public void setStrDataAdmi(String dataAdmi) throws ParseException {
		this.dataAdmi = formato.parse(dataAdmi);
	}
	
	
	public int getNumCartTrab() {
		return numCartTrab;
	}
	
	public boolean setNumCartTrab(int numCartTrab) {
		if(numCartTrab>0) {
			this.numCartTrab = numCartTrab;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String getUsuario() {
		return usuario;
	}
	
	public boolean setUsuario(String usuario) {
		if(usuario.length()>0) {
			this.usuario = usuario;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String getSenha() {
		return senha;
	}
	
	public boolean setSenha(String senha) {
		if(senha.length()>0) {
			this.senha = senha;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String mostrarDados() {
		return "\nFuncionario: " + super.mostrarDados() + "\nNumero na carteira de Trabalho: " + this.getNumCartTrab() + "\nData de admissao: "+ 
				this.getStrDataAdmi();
	}
	
	
	
}
