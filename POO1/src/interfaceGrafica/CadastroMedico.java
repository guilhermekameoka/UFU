package interfaceGrafica;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JSeparator;
import javax.swing.JTextField;
import clinica.Endereco;
import clinica.Medico;
import dados.DadosFuncionarios;

public class CadastroMedico extends JFrame {
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
	private JTextField textFieldDataAdm;
	private JTextField textFieldNumCartTrab;
	private JTextField textFieldCRM;
	private JTextField textFieldEsp;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CadastroMedico frame = new CadastroMedico();
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
	public CadastroMedico() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(0, -29, 672, 529);
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
		
		JLabel lblNewLabel_2 = new JLabel("Cadastro M\u00E9dico");
		lblNewLabel_2.setBounds(287, 11, 168, 14);
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
		separator.setBounds(10, 153, 626, 2);
		getContentPane().add(separator);
		
		JLabel lblNewLabel_7 = new JLabel("Endere\u00E7o");
		lblNewLabel_7.setBounds(10, 162, 60, 23);
		getContentPane().add(lblNewLabel_7);
		
		JLabel lblNewLabel_8 = new JLabel("Rua");
		lblNewLabel_8.setBounds(10, 190, 30, 14);
		getContentPane().add(lblNewLabel_8);
		
		textFieldRua = new JTextField();
		textFieldRua.setBounds(49, 187, 86, 20);
		getContentPane().add(textFieldRua);
		textFieldRua.setColumns(10);
		
		JLabel lblNewLabel_9 = new JLabel("Numero");
		lblNewLabel_9.setBounds(145, 190, 46, 14);
		getContentPane().add(lblNewLabel_9);
		
		textFieldNumEnd = new JTextField();
		textFieldNumEnd.setBounds(201, 187, 86, 20);
		getContentPane().add(textFieldNumEnd);
		textFieldNumEnd.setColumns(10);
		
		JLabel lblNewLabel_10 = new JLabel("Complemento");
		lblNewLabel_10.setBounds(297, 190, 86, 14);
		getContentPane().add(lblNewLabel_10);
		
		textFieldCompl = new JTextField();
		textFieldCompl.setBounds(384, 187, 86, 20);
		getContentPane().add(textFieldCompl);
		textFieldCompl.setColumns(10);
		
		JLabel lblNewLabel_11 = new JLabel("Bairro");
		lblNewLabel_11.setBounds(10, 215, 46, 14);
		getContentPane().add(lblNewLabel_11);
		
		textFieldBairro = new JTextField();
		textFieldBairro.setBounds(49, 212, 86, 20);
		getContentPane().add(textFieldBairro);
		textFieldBairro.setColumns(10);
		
		JLabel lblNewLabel_12 = new JLabel("Cidade");
		lblNewLabel_12.setBounds(145, 215, 46, 14);
		getContentPane().add(lblNewLabel_12);
		
		textFieldCidade = new JTextField();
		textFieldCidade.setBounds(201, 212, 86, 20);
		getContentPane().add(textFieldCidade);
		textFieldCidade.setColumns(10);
		
		JLabel lblNewLabel_13 = new JLabel("CEP");
		lblNewLabel_13.setBounds(322, 215, 25, 14);
		getContentPane().add(lblNewLabel_13);
		
		textFieldCep = new JTextField();
		textFieldCep.setBounds(384, 212, 86, 20);
		getContentPane().add(textFieldCep);
		textFieldCep.setColumns(10);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(10, 253, 626, 2);
		getContentPane().add(separator_1);
		
		JLabel lblNewLabel_14 = new JLabel("Dados do Funcion\u00E1rio");
		lblNewLabel_14.setBounds(10, 266, 159, 14);
		getContentPane().add(lblNewLabel_14);
		
		JLabel lblNewLabel_15 = new JLabel("Data de Admissao");
		lblNewLabel_15.setBounds(10, 286, 159, 14);
		getContentPane().add(lblNewLabel_15);
		
		textFieldDataAdm = new JTextField();
		textFieldDataAdm.setToolTipText("dd/MM/yyyy");
		textFieldDataAdm.setBounds(171, 283, 86, 20);
		getContentPane().add(textFieldDataAdm);
		textFieldDataAdm.setColumns(10);
		
		textFieldNumCartTrab = new JTextField();
		textFieldNumCartTrab.setColumns(10);
		textFieldNumCartTrab.setBounds(171, 311, 86, 20);
		getContentPane().add(textFieldNumCartTrab);
		
		JLabel lblNewLabel_15_1 = new JLabel("Numero Carteira de Trabalho");
		lblNewLabel_15_1.setBounds(10, 314, 159, 14);
		getContentPane().add(lblNewLabel_15_1);
		
		JSeparator separator_1_1 = new JSeparator();
		separator_1_1.setBounds(10, 352, 626, 2);
		getContentPane().add(separator_1_1);
		
		JLabel lblNewLabel_14_1 = new JLabel("Dados do M\u00E9dico");
		lblNewLabel_14_1.setBounds(10, 365, 159, 14);
		getContentPane().add(lblNewLabel_14_1);
		
		JLabel lblNewLabel_15_2 = new JLabel("CRM");
		lblNewLabel_15_2.setBounds(10, 393, 51, 14);
		getContentPane().add(lblNewLabel_15_2);
		
		textFieldCRM = new JTextField();
		textFieldCRM.setColumns(10);
		textFieldCRM.setBounds(105, 390, 86, 20);
		getContentPane().add(textFieldCRM);
		
		textFieldEsp = new JTextField();
		textFieldEsp.setColumns(10);
		textFieldEsp.setBounds(105, 417, 86, 20);
		getContentPane().add(textFieldEsp);
		
		JLabel lblNewLabel_15_2_1 = new JLabel("Especialidades");
		lblNewLabel_15_2_1.setBounds(10, 420, 159, 14);
		getContentPane().add(lblNewLabel_15_2_1);
		
		JButton botaoVoltar = new JButton("Voltar");
		botaoVoltar.setBounds(229, 458, 89, 23);
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
				Medico p = new Medico();
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
				
				//dados func
				int numCT = Integer.parseInt(textFieldNumCartTrab.getText());
				p.setNumCartTrab(numCT);
				p.addEspecialidades(textFieldEsp.getText());
				
				//dados medico
				int numC = Integer.parseInt(textFieldCRM.getText());
				p.setCrm(numC);
				
				DadosFuncionarios.cadastrar(p);
				JOptionPane.showMessageDialog(getContentPane(), p.mostrarDados(), "Cadastro", JOptionPane.INFORMATION_MESSAGE);
				
			}
		});
		botaoEnviar.setBounds(328, 458, 89, 23);
		getContentPane().add(botaoEnviar);
		
		
		
	}
	public void fecha() {
		this.dispose();
	}
}
