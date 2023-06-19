package interfaceGrafica;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import clinica.PlanoSaude;
import dados.DadosPlanoSaude;

public class BuscarPlano extends JFrame {
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textFieldCnpj;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					BuscarPlano frame = new BuscarPlano();
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
	public BuscarPlano() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblBuscarPlano = new JLabel("Buscar Plano de Saude");
		lblBuscarPlano.setBounds(143, 11, 155, 14);
		contentPane.add(lblBuscarPlano);
		
		JLabel lblNewLabel_1 = new JLabel("CNPJ:");
		lblNewLabel_1.setBounds(10, 50, 51, 14);
		contentPane.add(lblNewLabel_1);
		
		textFieldCnpj = new JTextField();
		textFieldCnpj.setColumns(10);
		textFieldCnpj.setBounds(61, 47, 86, 20);
		contentPane.add(textFieldCnpj);
		
		JButton botaoVoltar = new JButton("Voltar");
		botaoVoltar.setBounds(119, 227, 89, 23);
		contentPane.add(botaoVoltar);
		botaoVoltar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fecha();
				
			}
		});
		
		JButton botaoBuscar = new JButton("Buscar");
		botaoBuscar.setBounds(218, 227, 89, 23);
		contentPane.add(botaoBuscar);
		botaoBuscar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				PlanoSaude pla = DadosPlanoSaude.buscar(textFieldCnpj.getText());
				if(pla!=null) {
					JOptionPane.showMessageDialog(contentPane, pla.toString(), "Busca", JOptionPane.INFORMATION_MESSAGE);
				}
				else {
					JOptionPane.showMessageDialog(contentPane, "Plano nao encontrado", "Busca", JOptionPane.INFORMATION_MESSAGE);
				}
				
			}
		});
	}
	public void fecha() {
		this.dispose();
	}

}
