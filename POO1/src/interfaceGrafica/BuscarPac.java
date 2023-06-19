package interfaceGrafica;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import clinica.Paciente;
import dados.DadosPacientes;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;

public class BuscarPac extends JFrame {
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textFieldCpf;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					BuscarPac frame = new BuscarPac();
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
	public BuscarPac() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblBuscarPaciente = new JLabel("Buscar Paciente");
		lblBuscarPaciente.setBounds(157, 11, 116, 14);
		contentPane.add(lblBuscarPaciente);
		
		JLabel lblNewLabel_1 = new JLabel("CPF:");
		lblNewLabel_1.setBounds(10, 50, 32, 14);
		contentPane.add(lblNewLabel_1);
		
		textFieldCpf = new JTextField();
		textFieldCpf.setColumns(10);
		textFieldCpf.setBounds(43, 47, 86, 20);
		contentPane.add(textFieldCpf);
		
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
				Paciente p = DadosPacientes.buscar(textFieldCpf.getText());
				if(p!=null) {
					JOptionPane.showMessageDialog(contentPane, p.mostrarDados(), "Busca", JOptionPane.INFORMATION_MESSAGE);
				}
				else {
					JOptionPane.showMessageDialog(contentPane, "Paciente nao encontrado", "Busca", JOptionPane.INFORMATION_MESSAGE);
				}
				
			}
		});
	}
	public void fecha() {
		this.dispose();
	}

}
