document.addEventListener("DOMContentLoaded", function () {
    document.forms.login.onsubmit = validaLogin;

    async function validaLogin(event) {
        event.preventDefault();

        let form = event.target;
        let formValido = true;

        const spanEmail = form.email.nextElementSibling;
        const spanSenha = form.senha.nextElementSibling;

        spanEmail.textContent = "";
        spanSenha.textContent = "";

        if (form.email.value === "") {
            spanEmail.textContent = "O email deve ser preenchido!";
            formValido = false;
        }
        if (form.senha.value === "") {
            spanSenha.textContent = "A senha deve ser preenchida!";
            formValido = false;
        }

        if (!formValido) {
            return;
        }
    }
});
