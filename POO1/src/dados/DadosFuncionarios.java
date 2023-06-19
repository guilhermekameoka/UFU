package dados;
import java.io.Serializable;
import java.util.ArrayList;
import clinica.*;


public class DadosFuncionarios implements Serializable{
	private static final long serialVersionUID = 1L;
	private static ArrayList<Funcionario> vetFunc = new ArrayList<>();
	
	public static void cadastrar(Funcionario func) {
		DadosFuncionarios.vetFunc.add(func);
	}
	
	public static void listar() {
		for(Funcionario f: DadosFuncionarios.vetFunc) {
			System.out.println(f.mostrarDados());
		}
	}
	
	public static Funcionario buscar(String cpf) {
		Funcionario c = null;
		String str = null;
		
		for(Funcionario f: DadosFuncionarios.vetFunc) {
			str = f.getCpf();
			if(str !=null ) {
				if(str.equals(ValidaCPF.imprimeCPF(cpf))) {
					c = f;
					break;
				
				}
			}
		}
		return c;
	}
	
	public static boolean excluir(String cpf) {
		Funcionario c = DadosFuncionarios.buscar(cpf);
		if(c!=null) {
			DadosFuncionarios.vetFunc.remove(c);
			return true;
		}
		else {
			return false;
		}
	}
	
	public static boolean gravarBin() {
		if(ArquivoIO.escritaObjeto(vetFunc, "funcionarioBin.arq")) {
			return true;
		}
		else {
			return false;
		}
	}
	
	
}
