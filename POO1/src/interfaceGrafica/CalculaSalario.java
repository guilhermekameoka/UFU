package interfaceGrafica;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JTextField;

import clinica.DemaisFunc;
import clinica.Medico;
import dados.DadosFuncionarios;


public class CalculaSalario extends JFrame {
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
					CalculaSalario frame = new CalculaSalario();
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
	public CalculaSalario() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Calcular Salario");
		lblNewLabel.setBounds(170, 11, 121, 14);
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("CPF:");
		lblNewLabel_1.setBounds(10, 49, 46, 14);
		contentPane.add(lblNewLabel_1);
		
		textFieldCpf = new JTextField();
		textFieldCpf.setBounds(41, 46, 86, 20);
		contentPane.add(textFieldCpf);
		textFieldCpf.setColumns(10);
		
		JLabel lblNewLabelCalc = new JLabel("");
		lblNewLabelCalc.setBounds(10, 123, 395, 14);
		contentPane.add(lblNewLabelCalc);

		
		JButton botaoVoltar = new JButton("Voltar");
		botaoVoltar.setBounds(119, 227, 89, 23);
		contentPane.add(botaoVoltar);
		botaoVoltar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fecha();
				
			}
		});
		
		JButton botaoCalc = new JButton("Calcular");
		botaoCalc.setBounds(218, 227, 89, 23);
		contentPane.add(botaoCalc);
		
		botaoCalc.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				 if(DadosFuncionarios.buscar(textFieldCpf.getText()) instanceof Medico) {
					 Medico m = (Medico)DadosFuncionarios.buscar(textFieldCpf.getText());
					 lblNewLabelCalc.setText("O salário do Medico " + m.getNome() + "é R$ " + m.calcSalario());
				 }
				 else if(DadosFuncionarios.buscar(textFieldCpf.getText()) instanceof DemaisFunc) {
					 DemaisFunc d = (DemaisFunc)DadosFuncionarios.buscar(textFieldCpf.getText());
					 lblNewLabelCalc.setText("O salário do  " + d.getCargo() + " " + d.getNome() + " é R$ " + d.calcSalario());
				 }
				 else {
					 lblNewLabelCalc.setText("Funcionario não encontrado");
				 }
				
				
			}
		});
	}
	public void fecha() {
		this.dispose();
	}
}
