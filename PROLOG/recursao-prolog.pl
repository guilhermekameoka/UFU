%fat(Entrada,Resposta)
fat(0,1).                  %base / condicao de parada
fat(N,M) :- N > 0,         %passo / condicao do passo
            N1 is (N - 1), %simplifica o problema
            fat(N1,M1),    %obtem a solucao da instancia menor
            M is N*M1,     %constroi solucao final
            write("N = "),
            write(N),
            write("  "),
            write("Fat = "),
            writeln(M).

fatorial(N) :- fat(N,M), write("Fat = "), write(M). %diminuicao de termo
