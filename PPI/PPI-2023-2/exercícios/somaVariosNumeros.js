var numeros = [];

while (true) {
    var input = window.prompt("Digite um número (ou 's' para parar):");

    if (input === 's') {
        break;
    } else {
        var numero = parseInt(input);
        if (!isNaN(numero)) {
            numeros.push(numero);
        } else {
            window.alert("Por favor, digite um número válido.");
        }
    }
}

if (numeros.length > 0) {
    var resultado = numeros.reduce(function (acumulador, numero) {
        return acumulador + numero;
    });

    window.alert("A soma dos números é: " + resultado);
} else {
    window.alert("Nenhum número foi informado.");
}
