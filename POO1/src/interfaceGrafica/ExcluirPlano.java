package interfaceGrafica;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;

import dados.DadosPlanoSaude;


public class ExcluirPlano extends JFrame {
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
					ExcluirPlano frame = new ExcluirPlano();
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
	public ExcluirPlano() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblExcluirPlanoDe = new JLabel("Excluir Plano de Saude");
		lblExcluirPlanoDe.setBounds(139, 11, 144, 14);
		contentPane.add(lblExcluirPlanoDe);
		
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
		
		JButton botaoExcluir = new JButton("Excluir");
		botaoExcluir.setBounds(218, 227, 89, 23);
		contentPane.add(botaoExcluir);
		botaoExcluir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(DadosPlanoSaude.excluir(textFieldCnpj.getText())){
					JOptionPane.showMessageDialog(contentPane, "Plano de Saude excluido", "Excluir", JOptionPane.INFORMATION_MESSAGE);					
				}
				else {
					JOptionPane.showMessageDialog(contentPane, "Plano de Saude nao encontrado", "Excluir", JOptionPane.INFORMATION_MESSAGE);					
				}
				
			}
		});
	}
	public void fecha() {
		this.dispose();
	}

}
