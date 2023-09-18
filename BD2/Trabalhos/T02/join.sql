SELECT emprestimo.nome_cliente, emprestimo.numero_conta, emprestimo.nome_agencia FROM emprestimo 
INNER JOIN deposito 
ON emprestimo.numero_conta = deposito.numero_conta 
-- Faz o agrupamento por nome_cliente, numero_conta e nome_agencia para evitar duplicação
GROUP BY emprestimo.nome_cliente, emprestimo.numero_conta, emprestimo.nome_agencia