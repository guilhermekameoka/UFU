package dados;

import java.io.Serializable;
import java.util.ArrayList;
import clinica.*;

public class DadosPlanoSaude implements Serializable{
	private static final long serialVersionUID = 1L;
	private static ArrayList<PlanoSaude> vetPlan = new ArrayList<>();
	
	public static void cadastrar(PlanoSaude plano) {
		DadosPlanoSaude.vetPlan.add(plano);
	}
	
	public static void listar() {
		for(PlanoSaude p: DadosPlanoSaude.vetPlan) {
			System.out.println(p.toString());
		}
	}
	
	public static PlanoSaude buscar(String cnpj) {
		PlanoSaude c = null;
		String str = null;
		
		for(PlanoSaude p: DadosPlanoSaude.vetPlan) {
			str = p.getCnpj();
			if(str!=null) {
				if(str.equals(cnpj)) {
					c = p;
					break;				
				}
			}
		}
		return c;
	}
	
	public static boolean excluir(String cnpj) {
		PlanoSaude c = DadosPlanoSaude.buscar(cnpj);
		if(c!=null) {
			DadosPlanoSaude.vetPlan.remove(c);
			return true;
		}
		else {
			return false;
		}
	}
	
	public static boolean gravarBin() {
		if(ArquivoIO.escritaObjeto(vetPlan, "planoSaudeBin.arq")) {
			return true;
		}
		else {
			return false;
		}
	}
	
}
