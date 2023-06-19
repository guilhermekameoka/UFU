package clinica;

public class DemaisFunc extends Funcionario {
	private static final long serialVersionUID = 1L;
	private float salarioBase;
	private String cargo;
	private static int numConsTot;
	private static int limite;
	private static float valorGrat;
	
	
	public DemaisFunc(String nome, String cpf, String rg, String estadoCivil, Endereco endereco, float salarioBase, String cargo) {
		super(nome, cpf, rg, estadoCivil, endereco);
		this.setSalarioBase(salarioBase);
		this.setCargo(cargo);
	}
	
	public DemaisFunc(String nome, String cargo) {
		this.setNome(nome);
		this.setCargo(cargo);
	}

	public DemaisFunc() {
		
	}

	public float getSalarioBase() {
		return salarioBase;
	}
	
	public boolean setSalarioBase(float salarioBase) {
		if(salarioBase>0) {
			this.salarioBase = salarioBase;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public String getCargo() {
		return cargo;
	}
	
	public boolean setCargo(String cargo) {
		if(cargo.length()>0) {
			this.cargo = cargo;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public static int getNumConsTot() {
		return numConsTot;
	}
	
	public static boolean setNumConsTot(int numConsTot) {
		if(numConsTot>0) {
			DemaisFunc.numConsTot = numConsTot;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public static int getLimite() {
		return limite;
	}
	
	public static boolean setLimite(int limite) {
		if(limite>0) {
			DemaisFunc.limite = limite;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	public static float getValorGrat() {
		return valorGrat;
	}
	
	public static boolean setValorGrat(float valorGrat) {
		if(valorGrat>0) {
			DemaisFunc.valorGrat = valorGrat;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	@Override
	public float calcSalario() {
		if(DemaisFunc.numConsTot>DemaisFunc.limite) {
			return this.salarioBase+DemaisFunc.valorGrat; 
		}
		else {
			return salarioBase;
		}
	}
	
	public static void zeraCons() {
		DemaisFunc.setNumConsTot(0);
	}
	
	public static void maisCons() {
		DemaisFunc.setNumConsTot(getNumConsTot()+1);
	}
	
	public String mostrarDados() {
		return super.mostrarDados() + "\nCargo: " + this.getCargo() + "\nSalario base R$ " + this.getSalarioBase();
	}
	
	public static String mostraDadosDF() {
		return  "\nNumero de consultas totais: " + DemaisFunc.getNumConsTot() + "\nNumero limite de consultas: " + DemaisFunc.getLimite() +
				"\nValor de gratificacao R$ " + DemaisFunc.valorGrat;
	}
	
	

}
