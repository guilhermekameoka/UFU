CREATE OR REPLACE FUNCTION contas_cliente(p_nome varchar(100))
  RETURNS varchar(100) AS
  $BODY$
DECLARE
    f_nome_agencia varchar(100);
    f_numero_conta integer;
    f_concatenado varchar(5000) :='';
	cursor_relatorio CURSOR FOR SELECT DISTINCT e.nome_agencia, e.numero_conta
                                    from emprestimo e,
                                        deposito d
                                    where e.numero_conta = d.numero_conta
                                    and e.nome_cliente = p_nome;
BEGIN
   OPEN cursor_relatorio;
	LOOP
		FETCH cursor_relatorio INTO f_nome_agencia, f_numero_conta;
		IF FOUND THEN
			f_concatenado := f_concatenado || f_nome_agencia || ' - ' || f_numero_conta || ' ';
		END IF;
		IF NOT FOUND THEN EXIT; END IF;
	END LOOP;
   CLOSE cursor_relatorio;
   RETURN f_concatenado;
END
$BODY$
  LANGUAGE plpgsql VOLATILE COST 100;