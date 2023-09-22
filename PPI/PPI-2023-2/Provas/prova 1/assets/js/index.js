document.addEventListener("DOMContentLoaded", function () {
    const formulario = document.getElementById("formulario");
    const alerta = document.getElementById("alerta");

    formulario.addEventListener("submit", function (event) {
        event.preventDefault();

        const raca = document.getElementById("raca").value;
        const especie = document.getElementById("especie").value;
        const cor = document.getElementById("cor").value;
        const idade = document.getElementById("idade").value;
        const filhote = document.getElementById("filhote").value;
        const preco = document.getElementById("preco").value;
        const descricao = document.getElementById("descricao").value;

        if (raca.trim() === "") {
            alertaRaca.style.display = "block";
        }
        if (especie.trim() === "") {
            alertaEspecie.style.display = "block"
        }
        if (cor.trim() === "") {
            alertaCor.style.display = "block"
        }
        if (idade.trim() === "") {
            alertaIdade.style.display = "block"
        }
        if (filhote.trim() === "") {
            alertaFilhote.style.display = "block"
        }
        if (preco.trim() === "") {
            alertaPreco.style.display = "block"
        }
        if (descricao.trim() === "") {
            alertaDescricao.style.display = "block"
        }
    });
});