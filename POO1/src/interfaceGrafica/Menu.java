package interfaceGrafica;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JSeparator;

import dados.*;

import java.awt.Color;

public class Menu {

	public JFrame frmClinica;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Menu window = new Menu();
					window.frmClinica.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Menu() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmClinica = new JFrame();
		frmClinica.setTitle("Clinica Medica");
		frmClinica.setBounds(100, 100, 558, 403);
		frmClinica.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmClinica.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Menu");
		lblNewLabel.setBounds(256, 11, 46, 14);
		frmClinica.getContentPane().add(lblNewLabel);
		
		JButton botaoCadPacC = new JButton("Paciente com Plano");
		botaoCadPacC.setBackground(Color.LIGHT_GRAY);
		botaoCadPacC.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoCadPacC.setBounds(22, 70, 150, 23);
		frmClinica.getContentPane().add(botaoCadPacC);
		
		JLabel lblNewLabel_1 = new JLabel("Cadastro");
		lblNewLabel_1.setBounds(68, 45, 61, 14);
		frmClinica.getContentPane().add(lblNewLabel_1);
		
		JSeparator separator = new JSeparator();
		separator.setBounds(10, 36, 520, 2);
		frmClinica.getContentPane().add(separator);
		
		JButton botaoCadPacS = new JButton("Paciente sem Plano");
		botaoCadPacS.setBackground(Color.LIGHT_GRAY);
		botaoCadPacS.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							CadastroPacSPlano frame = new CadastroPacSPlano();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		botaoCadPacS.setBounds(22, 104, 150, 23);
		frmClinica.getContentPane().add(botaoCadPacS);
		
		JButton botaoCadMed = new JButton("Medico");
		botaoCadMed.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoCadMed.setBackground(Color.LIGHT_GRAY);
		botaoCadMed.setBounds(22, 138, 150, 23);
		frmClinica.getContentPane().add(botaoCadMed);
		
		JButton botaoCadDF = new JButton("Funcionarios");
		botaoCadDF.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoCadDF.setBackground(Color.LIGHT_GRAY);
		botaoCadDF.setBounds(22, 172, 150, 23);
		frmClinica.getContentPane().add(botaoCadDF);
		
		JButton botaoCadPlano = new JButton("Plano de Saude");
		botaoCadPlano.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoCadPlano.setBackground(Color.LIGHT_GRAY);
		botaoCadPlano.setBounds(22, 206, 150, 23);
		frmClinica.getContentPane().add(botaoCadPlano);
		
		JButton botaoCadExame = new JButton("Exame");
		botaoCadExame.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoCadExame.setBackground(Color.LIGHT_GRAY);
		botaoCadExame.setBounds(22, 240, 150, 23);
		frmClinica.getContentPane().add(botaoCadExame);
		
		JLabel lblNewLabel_2 = new JLabel("Buscar");
		lblNewLabel_2.setBounds(251, 45, 61, 14);
		frmClinica.getContentPane().add(lblNewLabel_2);
		
		JButton botaoBusPac = new JButton("Paciente");
		botaoBusPac.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoBusPac.setBackground(Color.LIGHT_GRAY);
		botaoBusPac.setBounds(208, 70, 125, 23);
		frmClinica.getContentPane().add(botaoBusPac);
		
		JButton botaoBusFunc = new JButton("Funcionario");
		botaoBusFunc.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							BuscarFunc frame = new BuscarFunc();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
						
					}
				});
			}
		});
		botaoBusFunc.setBackground(Color.LIGHT_GRAY);
		botaoBusFunc.setBounds(208, 104, 125, 23);
		frmClinica.getContentPane().add(botaoBusFunc);
		
		JButton botaoBusPlano = new JButton("Plano de Saude");
		botaoBusPlano.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoBusPlano.setBackground(Color.LIGHT_GRAY);
		botaoBusPlano.setBounds(208, 138, 125, 23);
		frmClinica.getContentPane().add(botaoBusPlano);
		
		JLabel lblNewLabel_3 = new JLabel("Excluir");
		lblNewLabel_3.setBounds(416, 45, 46, 14);
		frmClinica.getContentPane().add(lblNewLabel_3);
		
		JButton botaoExPlac = new JButton("Paciente");
		botaoExPlac.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							ExcluirPac frame = new ExcluirPac();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		botaoExPlac.setBackground(Color.LIGHT_GRAY);
		botaoExPlac.setBounds(372, 70, 129, 23);
		frmClinica.getContentPane().add(botaoExPlac);
		
		JButton botaoExFunc = new JButton("Funcionario");
		botaoExFunc.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							ExcluirFunc frame = new ExcluirFunc();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		botaoExFunc.setBackground(Color.LIGHT_GRAY);
		botaoExFunc.setBounds(372, 104, 128, 23);
		frmClinica.getContentPane().add(botaoExFunc);
		
		JButton botaoExPlan = new JButton("Plano de Saude");
		botaoExPlan.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoExPlan.setBackground(Color.LIGHT_GRAY);
		botaoExPlan.setBounds(372, 138, 129, 23);
		frmClinica.getContentPane().add(botaoExPlan);
		
		JButton botaoExExa = new JButton("Exame");
		botaoExExa.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EventQueue.invokeLater(new Runnable() {
					public void run() {
						try {
							ExcluirExame frame = new ExcluirExame();
							frame.setVisible(true);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
			}
		});
		botaoExExa.setBackground(Color.LIGHT_GRAY);
		botaoExExa.setBounds(372, 172, 129, 23);
		frmClinica.getContentPane().add(botaoExExa);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(10, 283, 520, 2);
		frmClinica.getContentPane().add(separator_1);
		
		JButton botaoRealCons = new JButton("Realizar Consulta");
		botaoRealCons.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoRealCons.setBackground(Color.LIGHT_GRAY);
		botaoRealCons.setBounds(22, 312, 150, 23);
		frmClinica.getContentPane().add(botaoRealCons);
		
		JButton botaoCalcSal = new JButton("Calcular Salario");
		botaoCalcSal.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
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
		});
		botaoCalcSal.setBackground(Color.LIGHT_GRAY);
		botaoCalcSal.setBounds(208, 312, 125, 23);
		frmClinica.getContentPane().add(botaoCalcSal);
		
		JButton botaoSalvar = new JButton("Salvar Dados");
		botaoSalvar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				DadosPacientes.gravarBin();
				DadosFuncionarios.gravarBin();
				DadosPlanoSaude.gravarBin();
				DadosConsulta.gravarBin();
				DadosExame.gravarBin();
				DadosEndereco.gravarBin();
				
				JOptionPane.showMessageDialog(frmClinica, "Dados salvos", "Salvar", JOptionPane.INFORMATION_MESSAGE);
				
			}
		});
		botaoSalvar.setBackground(Color.LIGHT_GRAY);
		botaoSalvar.setBounds(372, 312, 129, 23);
		frmClinica.getContentPane().add(botaoSalvar);
		
	}
}
