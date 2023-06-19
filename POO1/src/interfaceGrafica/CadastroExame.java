package interfaceGrafica;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import clinica.Exame;
import dados.DadosExame;


public class CadastroExame extends JFrame {
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textFieldNome;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CadastroExame frame = new CadastroExame();
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
	public CadastroExame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Cadastro de Exame");
		lblNewLabel.setBounds(157, 11, 121, 14);
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Nome: ");
		lblNewLabel_1.setBounds(10, 44, 46, 14);
		contentPane.add(lblNewLabel_1);
		
		textFieldNome = new JTextField();
		textFieldNome.setBounds(56, 41, 86, 20);
		contentPane.add(textFieldNome);
		textFieldNome.setColumns(10);
		

		JButton botaoVoltar = new JButton("Voltar");
		botaoVoltar.setBounds(129, 227, 89, 23);
		contentPane.add(botaoVoltar);
		botaoVoltar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fecha();				
			}
		});
		
		JButton botaoEnviar = new JButton("Enviar");
		botaoEnviar.setBounds(228, 227, 89, 23);
		contentPane.add(botaoEnviar);
		botaoEnviar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Exame ex = new Exame(textFieldNome.getText());
				
				DadosExame.cadastrar(ex);
				JOptionPane.showMessageDialog(contentPane, ex.toString(), "Cadastro", JOptionPane.INFORMATION_MESSAGE);
				
			}
		});
		
	}
	public void fecha() {
		this.dispose();
	}
}
