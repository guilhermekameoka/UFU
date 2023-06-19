package dados;
import clinica.*;

import java.io.Serializable;
import java.util.ArrayList;

public class DadosPacientes implements Serializable{
	private static final long serialVersionUID = 1L;
	private static ArrayList<Paciente> vetPac = new ArrayList<>();
	
	public static void cadastrar(Paciente ps) {
		DadosPacientes.vetPac.add(ps);
	}
	
	public static void listar() {
		for(Paciente p: DadosPacientes.vetPac) {
			System.out.println(p.mostrarDados());
		}
	}
	
	public static Paciente buscar(String cpf) {
		Paciente c = null;
		String str = null;
		
		for(Paciente p: DadosPacientes.vetPac) {
			str = p.getCpf();
			if(str !=null) {
				if(str.equals(ValidaCPF.imprimeCPF(cpf))) {
					c = p;
					break;
				
				}
			}
		}
		return c;
	}
	
	public static boolean excluir(String cpf) {
		Paciente c = DadosPacientes.buscar(cpf);
		if(c!=null) {
			DadosPacientes.vetPac.remove(c);
			return true;
		}
		else {
			return false;
		}
	}
	
	public static boolean gravarBin() {
		if(ArquivoIO.escritaObjeto(vetPac, "pacienteBin.arq")) {
			return true;
		}
		else {
			return false;
		}
	}
	
	
	
	
}
