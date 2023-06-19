document.addEventListener('DOMContentLoaded', function () {

    window.onload = function () {
        document.forms.formCadastro.onsubmit = validaCadastro;
        const botao = document.querySelector(".botaoFormulario");
        const mainCadastro = document.querySelector(".mainCadastro");
        botao.onclick = () => mainCadastro.style.height = "840px";
    }

    function validaCadastro(e) {
        let form = e.target;
        let formValido = true;

        const spanNome = form.nome.nextElementSibling;
        const spanCpf = form.cpf.nextElementSibling;
        const spanEmail = form.email.nextElementSibling;
        const spanSenha = form.senha.nextElementSibling;
        const spanTelefone = form.telefone.nextElementSibling;

        spanNome.textContent = "";
        spanCpf.textContent = "";
        spanEmail.textContent = "";
        spanSenha.textContent = "";
        spanTelefone.textContent = "";

        if (form.nome.value === "") {
            spanNome.textContent = 'O nome deve ser preenchido!';
            formValido = false;
        }
        if (form.cpf.value === "") {
            spanCpf.textContent = 'O cpf deve ser preenchido!';
            formValido = false;
        }
        if (form.email.value === "") {
            spanEmail.textContent = 'O email deve ser preenchido!';
            formValido = false;
        }
        if (form.senha.value === "") {
            spanSenha.textContent = 'A senha deve ser preenchida!';
            formValido = false;
        }
        if (form.telefone.value === "") {
            spanTelefone.textContent = 'O telefone deve ser preenchido!';
            formValido = false;
        }

        if (!formValido) {
            e.preventDefault();
        }
    }
});
