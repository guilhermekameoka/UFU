package interfaceGrafica;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import clinica.*;
import dados.*;
import javax.swing.JSeparator;


public class RealizarConsulta extends JFrame {
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textFieldCpfMed;
	private JTextField textFieldCpfPac;
	private JTextField textFieldDataHora;
	private JTextField textFieldSintomas;
	private JTextField textFieldReceita;
	private JTextField textFieldMedicamento;
	private JTextField textFieldExame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					RealizarConsulta frame = new RealizarConsulta();
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
	public RealizarConsulta() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 560, 405);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Consulta");
		lblNewLabel.setBounds(244, 11, 61, 14);
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("CPF Medico:");
		lblNewLabel_1.setBounds(10, 54, 89, 14);
		contentPane.add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("CPF Paciente: ");
		lblNewLabel_2.setBounds(10, 79, 89, 14);
		contentPane.add(lblNewLabel_2);
		
		textFieldCpfMed = new JTextField();
		textFieldCpfMed.setBounds(105, 51, 86, 20);
		contentPane.add(textFieldCpfMed);
		textFieldCpfMed.setColumns(10);
		
		textFieldCpfPac = new JTextField();
		textFieldCpfPac.setBounds(105, 76, 86, 20);
		contentPane.add(textFieldCpfPac);
		textFieldCpfPac.setColumns(10);
		
		JLabel lblNewLabel_3 = new JLabel("Data e Hora:");
		lblNewLabel_3.setBounds(10, 104, 89, 14);
		contentPane.add(lblNewLabel_3);
		
		textFieldDataHora = new JTextField();
		textFieldDataHora.setToolTipText("dd/MM/aaaa HH:mm");
		textFieldDataHora.setBounds(105, 101, 86, 20);
		contentPane.add(textFieldDataHora);
		textFieldDataHora.setColumns(10);
		
		
		JSeparator separator = new JSeparator();
		separator.setBounds(10, 130, 524, 2);
		contentPane.add(separator);
		
		JLabel lblNewLabel_4 = new JLabel("Diagn\u00F3stico");
		lblNewLabel_4.setBounds(10, 143, 77, 14);
		contentPane.add(lblNewLabel_4);
		
		JLabel lblNewLabel_5 = new JLabel("Sintomas:");
		lblNewLabel_5.setBounds(10, 168, 77, 14);
		contentPane.add(lblNewLabel_5);
		
		JLabel lblNewLabel_6 = new JLabel("Receita:");
		lblNewLabel_6.setBounds(10, 193, 77, 14);
		contentPane.add(lblNewLabel_6);
		
		JLabel lblNewLabel_7 = new JLabel("Medicamento:");
		lblNewLabel_7.setBounds(10, 218, 89, 14);
		contentPane.add(lblNewLabel_7);
		
		textFieldSintomas = new JTextField();
		textFieldSintomas.setBounds(105, 165, 86, 20);
		contentPane.add(textFieldSintomas);
		textFieldSintomas.setColumns(10);
		
		textFieldReceita = new JTextField();
		textFieldReceita.setBounds(105, 190, 86, 20);
		contentPane.add(textFieldReceita);
		textFieldReceita.setColumns(10);
		
		textFieldMedicamento = new JTextField();
		textFieldMedicamento.setBounds(105, 215, 86, 20);
		contentPane.add(textFieldMedicamento);
		textFieldMedicamento.setColumns(10);
		
		JLabel lblNewLabel_8 = new JLabel("Exame:");
		lblNewLabel_8.setBounds(10, 243, 77, 14);
		contentPane.add(lblNewLabel_8);
		
		textFieldExame = new JTextField();
		textFieldExame.setBounds(105, 240, 86, 20);
		contentPane.add(textFieldExame);
		textFieldExame.setColumns(10);
		
		JButton botaoVoltar = new JButton("Voltar");
		botaoVoltar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				fecha();
			}
		});
		botaoVoltar.setBounds(185, 332, 89, 23);
		contentPane.add(botaoVoltar);
		
		JButton botaoEnviar = new JButton("Enviar");
		botaoEnviar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Medico medico = (Medico)DadosFuncionarios.buscar(textFieldCpfMed.getText());
				Paciente paciente = DadosPacientes.buscar(textFieldCpfPac.getText());
				if(medico!=null && paciente !=null) {
					Consulta consulta;
					if(paciente instanceof PacCPlano) {
						PacCPlano pacC = (PacCPlano)paciente;
						consulta = new Consulta(medico, pacC); 
					}
					else {
						PacSPlano pacS = (PacSPlano)paciente;
						consulta = new Consulta(medico, pacS); 
					}
					try {
						consulta.setStrDataHoraCons(textFieldDataHora.getText());
					} 
					catch (ParseException e1) {
					}
					
					consulta.setObsSintomas(textFieldSintomas.getText());
					consulta.setReceita(textFieldReceita.getText());
					consulta.addMedicamentos(textFieldMedicamento.getText());
					Exame ex = DadosExame.buscar(textFieldExame.getText());
					if(ex!=null) {
						consulta.addExames(ex);
					}
					consulta.realizarCons();
					DadosConsulta.cadastrar(consulta);
					JOptionPane.showMessageDialog(contentPane, consulta.mostrarDados(), "Consulta", JOptionPane.INFORMATION_MESSAGE);
					
				}
				else {
					JOptionPane.showMessageDialog(contentPane, "Dados Invalidos", "Consulta", JOptionPane.INFORMATION_MESSAGE);
				}
				
			}
		});
		botaoEnviar.setBounds(295, 332, 89, 23);
		contentPane.add(botaoEnviar);
		
	}

	public void fecha() {
		this.dispose();
	}
}
