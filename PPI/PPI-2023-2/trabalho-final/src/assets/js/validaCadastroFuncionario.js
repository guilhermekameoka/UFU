import { validaInput } from "./validaInput.js";
import { checaValorInput } from "./checaValorInput.js";

document.addEventListener("DOMContentLoaded", function () {
    const form = document.querySelector("form");

    const campos = [
        { input: document.getElementById("nome"), alerta: document.getElementById("alertaNome") },
        { input: document.getElementById("cpf"), alerta: document.getElementById("alertaCpf") },
        { input: document.getElementById("email"), alerta: document.getElementById("alertaEmail") },
        { input: document.getElementById("data-nascimento"), alerta: document.getElementById("alertaDataNascimento") },
        { input: document.getElementById("sexo"), alerta: document.getElementById("alertaSexo") },
        { input: document.getElementById("especialidade"), alerta: document.getElementById("alertaEspecialidade") },
        { input: document.getElementById("regpro"), alerta: document.getElementById("alertaRegpro") },
        { input: document.getElementById("senha"), alerta: document.getElementById("alertaSenha") },
        { input: document.getElementById("telefone"), alerta: document.getElementById("alertaTelefone") },
        { input: document.getElementById("rua"), alerta: document.getElementById("alertaRua") },
        { input: document.getElementById("bairro"), alerta: document.getElementById("alertaBairro") },
        { input: document.getElementById("cidade"), alerta: document.getElementById("alertaCidade") },
        { input: document.getElementById("estado"), alerta: document.getElementById("alertaEstado") }
    ];

    form.addEventListener("submit", function (event) {
        event.preventDefault();

        campos.forEach(({ input, alerta }) => {
            validaInput(input, alerta);
        });
    });

    campos.forEach(({ input, alerta }) => {
        checaValorInput(input, alerta);
    });
});