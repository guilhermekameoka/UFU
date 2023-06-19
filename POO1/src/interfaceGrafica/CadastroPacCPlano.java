package interfaceGrafica;

import clinica.Endereco;
import clinica.PacCPlano;
import dados.DadosPacientes;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.ParseException;

public class CadastroPacCPlano extends JFrame {
	private static final long serialVersionUID = 1L;
	private JLabel lblNewLabel;
	private JLabel lblNewLabel_1;
	private JTextField textFieldCpf;
	private JTextField textFieldRg;
	private JTextField textFieldEstCivil;
	private JTextField textFieldSexo;
	private JTextField textFieldDatNasc;
	private JTextField textFieldRua;
	private JTextField textFieldNumEnd;
	private JTextField textFieldCompl;
	private JTextField textFieldBairro;
	private JTextField textFieldCidade;
	private JTextField textFieldCep;
	private JTextField textFieldNome;
	private JTextField textFieldNumCart;
	private JTextField textFieldDataIng;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CadastroPacCPlano frame = new CadastroPacCPlano();
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
	public CadastroPacCPlano() {
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
		
		lblNewLabel_1 = new JLabel("CPF:");
		lblNewLabel_1.setBounds(10, 75, 51, 14);
		getContentPane().add(lblNewLabel_1);
		
		textFieldCpf = new JTextField();
		textFieldCpf.setBounds(83, 72, 86, 20);
		getContentPane().add(textFieldCpf);
		textFieldCpf.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("Cadastro Paciente com Plano");
		lblNewLabel_2.setBounds(233, 11, 168, 14);
		getContentPane().add(lblNewLabel_2);
		
		JLabel lblNewLabel_3 = new JLabel("RG:");
		lblNewLabel_3.setBounds(10, 103, 51, 14);
		getContentPane().add(lblNewLabel_3);
		
		textFieldRg = new JTextField();
		textFieldRg.setBounds(83, 100, 86, 20);
		getContentPane().add(textFieldRg);
		textFieldRg.setColumns(10);
		
		
		JLabel lblNewLabel_4 = new JLabel("Est. Civil:");
		lblNewLabel_4.setBounds(10, 128, 51, 14);
		getContentPane().add(lblNewLabel_4);
		
		textFieldEstCivil = new JTextField();
		textFieldEstCivil.setBounds(83, 125, 86, 20);
		getContentPane().add(textFieldEstCivil);
		textFieldEstCivil.setColumns(10);
		
		
		JLabel lblNewLabel_5 = new JLabel("Sexo:");
		lblNewLabel_5.setBounds(10, 153, 46, 14);
		getContentPane().add(lblNewLabel_5);
		
		JLabel lblNewLabel_6 = new JLabel("Data Nasc:");
		lblNewLabel_6.setBounds(10, 178, 69, 14);
		getContentPane().add(lblNewLabel_6);
		
		textFieldSexo = new JTextField();
		textFieldSexo.setBounds(83, 150, 86, 20);
		getContentPane().add(textFieldSexo);
		textFieldSexo.setColumns(10);
		
		textFieldDatNasc = new JTextField();
		textFieldDatNasc.setToolTipText("dd/MM/yyyy");
		textFieldDatNasc.setBounds(83, 175, 86, 20);
		getContentPane().add(textFieldDatNasc);
		textFieldDatNasc.setColumns(10);
		
		JSeparator separator = new JSeparator();
		separator.setBounds(10, 206, 664, 2);
		getContentPane().add(separator);
		
		JLabel lblNewLabel_7 = new JLabel("Endere\u00E7o");
		lblNewLabel_7.setBounds(10, 214, 60, 23);
		getContentPane().add(lblNewLabel_7);
		
		JLabel lblNewLabel_8 = new JLabel("Rua");
		lblNewLabel_8.setBounds(10, 242, 30, 14);
		getContentPane().add(lblNewLabel_8);
		
		textFieldRua = new JTextField();
		textFieldRua.setBounds(49, 239, 86, 20);
		getContentPane().add(textFieldRua);
		textFieldRua.setColumns(10);
		
		JLabel lblNewLabel_9 = new JLabel("Numero");
		lblNewLabel_9.setBounds(145, 242, 46, 14);
		getContentPane().add(lblNewLabel_9);
		
		textFieldNumEnd = new JTextField();
		textFieldNumEnd.setBounds(201, 239, 86, 20);
		getContentPane().add(textFieldNumEnd);
		textFieldNumEnd.setColumns(10);
		
		JLabel lblNewLabel_10 = new JLabel("Complemento");
		lblNewLabel_10.setBounds(297, 242, 86, 14);
		getContentPane().add(lblNewLabel_10);
		
		textFieldCompl = new JTextField();
		textFieldCompl.setBounds(384, 239, 86, 20);
		getContentPane().add(textFieldCompl);
		textFieldCompl.setColumns(10);
		
		JLabel lblNewLabel_11 = new JLabel("Bairro");
		lblNewLabel_11.setBounds(10, 267, 46, 14);
		getContentPane().add(lblNewLabel_11);
		
		textFieldBairro = new JTextField();
		textFieldBairro.setBounds(49, 264, 86, 20);
		getContentPane().add(textFieldBairro);
		textFieldBairro.setColumns(10);
		
		JLabel lblNewLabel_12 = new JLabel("Cidade");
		lblNewLabel_12.setBounds(145, 267, 46, 14);
		getContentPane().add(lblNewLabel_12);
		
		textFieldCidade = new JTextField();
		textFieldCidade.setBounds(201, 264, 86, 20);
		getContentPane().add(textFieldCidade);
		textFieldCidade.setColumns(10);
		
		JLabel lblNewLabel_13 = new JLabel("CEP");
		lblNewLabel_13.setBounds(322, 267, 25, 14);
		getContentPane().add(lblNewLabel_13);
		
		textFieldCep = new JTextField();
		textFieldCep.setBounds(384, 264, 86, 20);
		getContentPane().add(textFieldCep);
		textFieldCep.setColumns(10);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(10, 295, 664, 2);
		getContentPane().add(separator_1);
		
		JLabel lblNewLabel_14 = new JLabel("Dados do Plano");
		lblNewLabel_14.setBounds(10, 308, 159, 14);
		getContentPane().add(lblNewLabel_14);
		
		JLabel lblNewLabel_15 = new JLabel("Numero Carteirinha");
		lblNewLabel_15.setBounds(10, 328, 125, 14);
		getContentPane().add(lblNewLabel_15);
		
		textFieldNumCart = new JTextField();
		textFieldNumCart.setBounds(129, 325, 86, 20);
		getContentPane().add(textFieldNumCart);
		textFieldNumCart.setColumns(10);
		
		JLabel lblNewLabel_16 = new JLabel("Data Ingresso");
		lblNewLabel_16.setBounds(225, 328, 86, 14);
		getContentPane().add(lblNewLabel_16);
		
		textFieldDataIng = new JTextField();
		textFieldDataIng.setToolTipText("dd/MM/yyyy");
		textFieldDataIng.setBounds(312, 325, 86, 20);
		getContentPane().add(textFieldDataIng);
		textFieldDataIng.setColumns(10);
		
		JButton botaoVoltar = new JButton("Voltar");
		botaoVoltar.setBounds(213, 384, 89, 23);
		getContentPane().add(botaoVoltar);
		botaoVoltar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fecha();
				//JOptionPane.showMessageDialog(null, "Voltar", "Teste", JOptionPane.INFORMATION_MESSAGE);
				
			}
		});
		
		
		JButton botaoEnviar = new JButton("Enviar");
		botaoEnviar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String nome = textFieldNome.getText();
				PacCPlano p = new PacCPlano();
				p.setNome(nome);
				p.setCpf(textFieldCpf.getText());
				p.setRg(textFieldRg.getText());
				p.setEstadoCivil(textFieldEstCivil.getText());
				p.setSexo(textFieldSexo.getText());
				try {
					p.setStrDataNasc(textFieldDatNasc.getText());
					p.setStrDataIngPlano(textFieldDataIng.getText());
				} catch (ParseException e1) {
					
				}
				//Endereco
				Endereco end = new Endereco();
				end.setRua(textFieldRua.getText());
				int num = Integer.parseInt(textFieldNumEnd.getText());
				end.setNum(num);
				end.setCompl(textFieldCompl.getText());
				end.setBairro(textFieldBairro.getText());
				end.setCidade(textFieldCidade.getText());
				end.setCep(textFieldCep.getText());
				p.setEndereco(end);
				
				//Plano
				int numC = Integer.parseInt(textFieldNumCart.getText());
				p.setNumCarteirinha(numC);
				
				
				DadosPacientes.cadastrar(p);
				JOptionPane.showMessageDialog(getContentPane(), p.mostrarDados(), "Cadastro", JOptionPane.INFORMATION_MESSAGE);					
					
			
			}
		});
		botaoEnviar.setBounds(312, 384, 89, 23);
		getContentPane().add(botaoEnviar);
		
		
	}
	public void fecha() {
		this.dispose();
	}

}
