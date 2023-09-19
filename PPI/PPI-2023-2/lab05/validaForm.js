document.addEventListener("DOMContentLoaded", function () {
    const formulario = document.getElementById("formulario");
    const alerta = document.getElementById("alerta");

    formulario.addEventListener("submit", function (event) {
        event.preventDefault();

        const email = document.getElementById("email").value;
        const senha = document.getElementById("senha").value;

        if (email.trim() === "" || senha.trim() === "") {
            alerta.style.display = "block";
        } else {
            alerta.style.display = "none";
        }
    });
});