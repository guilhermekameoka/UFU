package interfaceGrafica;

import java.awt.EventQueue;

import clinica.DemaisFunc;
import clinica.Endereco;
import dados.DadosFuncionarios;
import javax.swing.*;
import java.awt.event.*;
import java.text.ParseException;

public class CadastroDemaisFunc extends JFrame {
	private static final long serialVersionUID = 1L;
	private JLabel lblNewLabel;
	private JLabel lblNewLabel_1;
	private JTextField textFieldCpf;
	private JTextField textFieldRg;
	private JTextField textFieldEstCivil;
	private JTextField textFieldRua;
	private JTextField textFieldNumEnd;
	private JTextField textFieldCompl;
	private JTextField textFieldBairro;
	private JTextField textFieldCidade;
	private JTextField textFieldCep;
	private JTextField textFieldNome;
	private JTextField textFieldSalBase;
	private JTextField textFieldCargo;
	private JTextField textFieldNumCartTrab;
	private JTextField textFieldDataAdm;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CadastroDemaisFunc frame = new CadastroDemaisFunc();
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
	public CadastroDemaisFunc() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 662, 457);
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
		
		JLabel lblNewLabel_2 = new JLabel("Cadastro Demais Funcionarios");
		lblNewLabel_2.setBounds(227, 11, 190, 14);
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
		
		JSeparator separator = new JSeparator();
		separator.setBounds(10, 153, 632, 2);
		getContentPane().add(separator);
		
		JLabel lblNewLabel_7 = new JLabel("Endere\u00E7o");
		lblNewLabel_7.setBounds(10, 158, 60, 23);
		getContentPane().add(lblNewLabel_7);
		
		JLabel lblNewLabel_8 = new JLabel("Rua");
		lblNewLabel_8.setBounds(10, 186, 30, 14);
		getContentPane().add(lblNewLabel_8);
		
		textFieldRua = new JTextField();
		textFieldRua.setBounds(49, 183, 86, 20);
		getContentPane().add(textFieldRua);
		textFieldRua.setColumns(10);
		
		JLabel lblNewLabel_9 = new JLabel("Numero");
		lblNewLabel_9.setBounds(145, 186, 46, 14);
		getContentPane().add(lblNewLabel_9);
		
		textFieldNumEnd = new JTextField();
		textFieldNumEnd.setBounds(201, 183, 86, 20);
		getContentPane().add(textFieldNumEnd);
		textFieldNumEnd.setColumns(10);
		
		JLabel lblNewLabel_10 = new JLabel("Complemento");
		lblNewLabel_10.setBounds(297, 186, 86, 14);
		getContentPane().add(lblNewLabel_10);
		
		textFieldCompl = new JTextField();
		textFieldCompl.setBounds(384, 183, 86, 20);
		getContentPane().add(textFieldCompl);
		textFieldCompl.setColumns(10);
		
		JLabel lblNewLabel_11 = new JLabel("Bairro");
		lblNewLabel_11.setBounds(10, 211, 46, 14);
		getContentPane().add(lblNewLabel_11);
		
		textFieldBairro = new JTextField();
		textFieldBairro.setBounds(49, 208, 86, 20);
		getContentPane().add(textFieldBairro);
		textFieldBairro.setColumns(10);
		
		JLabel lblNewLabel_12 = new JLabel("Cidade");
		lblNewLabel_12.setBounds(145, 211, 46, 14);
		getContentPane().add(lblNewLabel_12);
		
		textFieldCidade = new JTextField();
		textFieldCidade.setBounds(201, 208, 86, 20);
		getContentPane().add(textFieldCidade);
		textFieldCidade.setColumns(10);
		
		JLabel lblNewLabel_13 = new JLabel("CEP");
		lblNewLabel_13.setBounds(322, 211, 25, 14);
		getContentPane().add(lblNewLabel_13);
		
		textFieldCep = new JTextField();
		textFieldCep.setBounds(384, 208, 86, 20);
		getContentPane().add(textFieldCep);
		textFieldCep.setColumns(10);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(10, 239, 632, 2);
		getContentPane().add(separator_1);
		
		JLabel lblNewLabel_14 = new JLabel("Dados");
		lblNewLabel_14.setBounds(10, 253, 159, 14);
		getContentPane().add(lblNewLabel_14);
		
        JLabel lblNewLabel_16 = new JLabel("Data de Admissao");
        lblNewLabel_16.setBounds(10, 286, 159, 14);
        getContentPane().add(lblNewLabel_16);
        
        textFieldDataAdm = new JTextField();
        textFieldDataAdm.setToolTipText("dd/MM/yyyy");
        textFieldDataAdm.setBounds(179, 283, 86, 20);
        getContentPane().add(textFieldDataAdm);
        textFieldDataAdm.setColumns(10);
        
        textFieldNumCartTrab = new JTextField();
        textFieldNumCartTrab.setColumns(10);
        textFieldNumCartTrab.setBounds(180, 314, 86, 20);
        getContentPane().add(textFieldNumCartTrab);
        
        JLabel lblNewLabel_17 = new JLabel("Numero Carteira de Trabalho");
        lblNewLabel_17.setBounds(10, 314, 181, 14);
        getContentPane().add(lblNewLabel_17);
		
		JLabel lblNewLabel_15 = new JLabel("");
		lblNewLabel_15.setBounds(10, 273, 106, 14);
		getContentPane().add(lblNewLabel_15);
		
		JLabel lblNewLabel_5 = new JLabel("Salario Base");
		lblNewLabel_5.setBounds(275, 286, 76, 14);
		getContentPane().add(lblNewLabel_5);
		
		textFieldSalBase = new JTextField();
		textFieldSalBase.setBounds(362, 283, 86, 20);
		getContentPane().add(textFieldSalBase);
		textFieldSalBase.setColumns(10);
		
		textFieldCargo = new JTextField();
		textFieldCargo.setBounds(362, 311, 86, 20);
		getContentPane().add(textFieldCargo);
		textFieldCargo.setColumns(10);
		
		JLabel lblNewLabel_6 = new JLabel("Cargo");
		lblNewLabel_6.setBounds(276, 317, 46, 14);
		getContentPane().add(lblNewLabel_6);
		
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
				String nome = textFieldNome.getText();
				DemaisFunc p = new DemaisFunc();
				p.setNome(nome);
				p.setCpf(textFieldCpf.getText());
				p.setRg(textFieldRg.getText());
				p.setEstadoCivil(textFieldEstCivil.getText());
				try {
					p.setStrDataAdmi(textFieldDataAdm.getText());
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
				
				//dados funcionario
				float numS = Float.parseFloat(textFieldSalBase.getText());
				p.setSalarioBase(numS);
				int numC = Integer.parseInt(textFieldNumCartTrab.getText());
				p.setNumCartTrab(numC);
				p.setCargo(textFieldCargo.getText());
				
				
				
				DadosFuncionarios.cadastrar(p);
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
