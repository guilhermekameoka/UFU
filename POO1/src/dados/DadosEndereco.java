package dados;

import clinica.*;

import java.io.Serializable;
import java.util.ArrayList;

public class DadosEndereco implements Serializable{
	private static final long serialVersionUID = 1L;
	private static ArrayList<Endereco> vetEnd = new ArrayList<>();
	
	public static void cadastrar(Endereco end) {
		DadosEndereco.vetEnd.add(end);
	}
	
	public static void listar() {
		for(Endereco e: DadosEndereco.vetEnd) {
			System.out.println(e.mostrarDados());
		}
	}
	
	public static Endereco buscar(String cep, int num) {
		Endereco c = null;
		
		for(Endereco e: DadosEndereco.vetEnd) {
			if(e.getCep() != null && e.getCep().equals(cep) && e.getNum()==num) {
				c = e;
				break;
			}
		}
		return c;
	}
	
	public static boolean excluir(String cep, int num) {
		Endereco e = DadosEndereco.buscar(cep, num);
		if(e!=null) {
			DadosEndereco.vetEnd.remove(e);
			return true;
		}
		else {
			return false;
		}
	}
	
	public static boolean gravarBin() {
		if(ArquivoIO.escritaObjeto(vetEnd, "enderecoBin.arq")) {
			return true;
		}
		else {
			return false;
		}
	}
	
}
