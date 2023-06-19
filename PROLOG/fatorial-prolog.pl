fat(0,1).                  %0! = 1.
fat(N,M) :- N > 0,         %se N > 1, entao fazer: fat(n-1)*n.
            N1 is (N - 1),
            fat(N1,M1),
            M is N*M1,
            write("N = "),
            write(N),
            write("  "),
            write("Fat = "),
            writeln(M).

fatorial(N) :- fat(N,M), write("Fat = "), write(M).

