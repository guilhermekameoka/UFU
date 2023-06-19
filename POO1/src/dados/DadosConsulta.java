package dados;

import java.io.Serializable;
import java.util.ArrayList;
import clinica.*;

public class DadosConsulta implements Serializable{
	private static final long serialVersionUID = 1L;
	private static ArrayList<Consulta> vetCons = new ArrayList<>();
	
	public static void cadastrar(Consulta c) {
		DadosConsulta.vetCons.add(c);
	}
	
	public static void listar() {
		for(Consulta c: DadosConsulta.vetCons) {
			System.out.println(c.mostrarDados());
		}
	}
	
	public static  ArrayList<Consulta> buscarPorMed(String cpf) {
		ArrayList<Consulta> c = new ArrayList<>();
		String str = null;
		
		for(Consulta p: DadosConsulta.vetCons) {
			str = p.getMedico().getCpf();
			if(str != null) {
				if(str.equals(ValidaCPF.imprimeCPF(cpf))) {
					c.add(p);
					break;
				
				}
			}
		}
		return c;
	}
	
	public static ArrayList<Consulta> buscarPorPac(String cpf) {
		ArrayList<Consulta> c = new ArrayList<>();
		
		for(Consulta p: DadosConsulta.vetCons) {
			if(p.getPacSPlano().getCpf().equals(ValidaCPF.imprimeCPF(cpf))) {
				c.add(p);
				break;
			}
			else if(p.getPacCPlano().getCpf().equals(ValidaCPF.imprimeCPF(cpf))) {
				c.add(p);
				break;
			}
			
		}
		return c;
	}
	
	
	public static boolean excluirPorMed(String cpf) {
		for(Consulta p: DadosConsulta.vetCons) {
			if(p.getMedico().getCpf().equals(ValidaCPF.imprimeCPF(cpf))) {
				DadosConsulta.vetCons.remove(p);				
			}
			return true;
		}
		return false;
		
	}
	
	public static boolean excluirPorPac(String cpf) {
		for(Consulta p: DadosConsulta.vetCons) {
			if(p.getPacSPlano().getCpf().equals(ValidaCPF.imprimeCPF(cpf))) {
				DadosConsulta.vetCons.remove(p);				
			}
			else if(p.getPacCPlano().getCpf().equals(ValidaCPF.imprimeCPF(cpf))) {
				DadosConsulta.vetCons.remove(p);				
			}
			return true;
		}
		return false;
		
	}
	
	public static boolean gravarBin() {
		if(ArquivoIO.escritaObjeto(vetCons, "consultaBin.arq")) {
			return true;
		}
		else {
			return false;
		}
	}
	
}
