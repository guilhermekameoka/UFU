SELECT DISTINCT emprestimo.nome_cliente, emprestimo.numero_conta, emprestimo.nome_agencia 
FROM emprestimo, deposito 
WHERE emprestimo.numero_conta = deposito.numero_conta