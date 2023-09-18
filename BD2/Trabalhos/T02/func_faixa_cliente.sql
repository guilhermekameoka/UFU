CREATE OR REPLACE FUNCTION faixa_cliente(p_nome_cliente varchar(100))
RETURNS varchar(1000) AS $BODY$
DECLARE
    soma_deposito float;
    faixa char;
    nome_cliente varchar(100);
    info varchar(1000);
    cursor_relatorio CURSOR FOR
        SELECT
            nome_cliente,
            SUM(D.SALDO_DEPOSITO) AS TOTAL_DEP
        FROM
            DEPOSITO AS D
        WHERE
            D.NOME_CLIENTE = p_nome_cliente
        GROUP BY
            D.NOME_CLIENTE;
BEGIN
    OPEN cursor_relatorio;
    FETCH cursor_relatorio INTO nome_cliente, soma_deposito;
    IF FOUND THEN
        IF soma_deposito IS NULL THEN
            soma_deposito = 0;
        END IF;
        IF soma_deposito > 6000.0 THEN
            faixa := 'A';
        ELSIF soma_deposito > 4000.0 THEN
            faixa := 'B';
        ELSE
            faixa := 'C';
        END IF;
        info := nome_cliente || ' - ' || faixa;
    END IF;
    CLOSE cursor_relatorio;
    RETURN info;
END
$BODY$
LANGUAGE plpgsql VOLATILE COST 100;
