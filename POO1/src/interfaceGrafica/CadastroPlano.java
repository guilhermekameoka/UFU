package interfaceGrafica;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JSeparator;
import javax.swing.JTextField;

import clinica.*;
import dados.*;

public class CadastroPlano extends JFrame {
	private static final long serialVersionUID = 1L;
	private JLabel lblNewLabel;
	private JTextField textFieldNome;
	private JLabel lblNewLabel_1;
	private JTextField textFieldCnpj;
	private JTextField textFieldRua;
	private JTextField textFieldNumEnd;
	private JTextField textFieldCompl;
	private JTextField textFieldBairro;
	private JTextField textFieldCidade;
	private JTextField textFieldCep;
	private JTextField textFieldValor;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CadastroPlano frame = new CadastroPlano();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public CadastroPlano() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 700, 457);
		getContentPane().setLayout(null);
		
		lblNewLabel = new JLabel("Nome:");
		lblNewLabel.setBounds(10, 47, 51, 14);
		getContentPane().add(lblNewLabel);
		
		textFieldNome = new JTextField();
		textFieldNome.setBounds(83, 44, 86, 20);
		getContentPane().add(textFieldNome);
		textFieldNome.setColumns(10);
		
		lblNewLabel_1 = new JLabel("CNPJ:");
		lblNewLabel_1.setBounds(10, 75, 51, 14);
		getContentPane().add(lblNewLabel_1);
		
		textFieldCnpj = new JTextField();
		textFieldCnpj.setBounds(83, 72, 86, 20);
		getContentPane().add(textFieldCnpj);
		textFieldCnpj.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("Cadastro Plano de Saude");
		lblNewLabel_2.setBounds(233, 11, 168, 14);
		getContentPane().add(lblNewLabel_2);
		
		
		JSeparator separator = new JSeparator();
		separator.setBounds(10, 114, 664, 2);
		getContentPane().add(separator);
		
		JLabel lblNewLabel_7 = new JLabel("Endere\u00E7o");
		lblNewLabel_7.setBounds(10, 129, 60, 23);
		getContentPane().add(lblNewLabel_7);
		
		JLabel lblNewLabel_8 = new JLabel("Rua");
		lblNewLabel_8.setBounds(10, 157, 30, 14);
		getContentPane().add(lblNewLabel_8);
		
		textFieldRua = new JTextField();
		textFieldRua.setBounds(49, 154, 86, 20);
		getContentPane().add(textFieldRua);
		textFieldRua.setColumns(10);
		
		JLabel lblNewLabel_9 = new JLabel("Numero");
		lblNewLabel_9.setBounds(145, 157, 46, 14);
		getContentPane().add(lblNewLabel_9);
		
		textFieldNumEnd = new JTextField();
		textFieldNumEnd.setBounds(201, 154, 86, 20);
		getContentPane().add(textFieldNumEnd);
		textFieldNumEnd.setColumns(10);
		
		JLabel lblNewLabel_10 = new JLabel("Complemento");
		lblNewLabel_10.setBounds(297, 157, 86, 14);
		getContentPane().add(lblNewLabel_10);
		
		textFieldCompl = new JTextField();
		textFieldCompl.setBounds(384, 154, 86, 20);
		getContentPane().add(textFieldCompl);
		textFieldCompl.setColumns(10);
		
		JLabel lblNewLabel_11 = new JLabel("Bairro");
		lblNewLabel_11.setBounds(10, 182, 46, 14);
		getContentPane().add(lblNewLabel_11);
		
		textFieldBairro = new JTextField();
		textFieldBairro.setBounds(49, 179, 86, 20);
		getContentPane().add(textFieldBairro);
		textFieldBairro.setColumns(10);
		
		JLabel lblNewLabel_12 = new JLabel("Cidade");
		lblNewLabel_12.setBounds(145, 182, 46, 14);
		getContentPane().add(lblNewLabel_12);
		
		textFieldCidade = new JTextField();
		textFieldCidade.setBounds(201, 179, 86, 20);
		getContentPane().add(textFieldCidade);
		textFieldCidade.setColumns(10);
		
		JLabel lblNewLabel_13 = new JLabel("CEP");
		lblNewLabel_13.setBounds(322, 182, 25, 14);
		getContentPane().add(lblNewLabel_13);
		
		textFieldCep = new JTextField();
		textFieldCep.setBounds(384, 179, 86, 20);
		getContentPane().add(textFieldCep);
		textFieldCep.setColumns(10);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(10, 210, 664, 2);
		getContentPane().add(separator_1);
		
		JLabel lblNewLabel_14 = new JLabel("Valor da Consulta");
		lblNewLabel_14.setBounds(10, 223, 159, 14);
		getContentPane().add(lblNewLabel_14);
		
		textFieldValor = new JTextField();
		textFieldValor.setBounds(115, 220, 86, 20);
		getContentPane().add(textFieldValor);
		textFieldValor.setColumns(10);
		
		JButton botaoVoltar = new JButton("Voltar");
		botaoVoltar.setBounds(213, 384, 89, 23);
		getContentPane().add(botaoVoltar);
		botaoVoltar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fecha();
				
			}
		});
		
		JButton botaoEnviar = new JButton("Enviar");
		botaoEnviar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//String nome = textFieldNome.getText();
				PlanoSaude pla = new PlanoSaude();
				pla.setNome(textFieldNome.getText());
				pla.setCnpj(textFieldCnpj.getText());
				
				//endereco
				Endereco end = new Endereco();
				end.setRua(textFieldRua.getText());
				int num = Integer.parseInt(textFieldNumEnd.getText());
				end.setNum(num);
				end.setCompl(textFieldCompl.getText());
				end.setBairro(textFieldBairro.getText());
				end.setCidade(textFieldCidade.getText());
				end.setCep(textFieldCep.getText());
				pla.setEndereco(end);
				
				
				//valor
				float numV = Float.parseFloat(textFieldValor.getText());
				pla.setValorCons(numV);
				
				DadosPlanoSaude.cadastrar(pla);
				JOptionPane.showMessageDialog(getContentPane(), pla.toString(), "Cadastro", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		botaoEnviar.setBounds(312, 384, 89, 23);
		getContentPane().add(botaoEnviar);
		
		
	}
	public void fecha() {
		this.dispose();
	}

}
