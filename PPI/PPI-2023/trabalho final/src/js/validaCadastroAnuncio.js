document.addEventListener('DOMContentLoaded', function () {

    window.onload = function () {
        document.forms.formCadastro.onsubmit = validaCadastroAnuncio;
        const botao = document.querySelector(".botaoFormulario");
        const mainCadastro = document.querySelector(".mainCadastroAnuncio");
        botao.onclick = () => mainCadastro.style.height = "950px";
    }

    function validaCadastroAnuncio(e) {
        let form = e.target;
        let formValido = true;

        const spanTitulo = form.titulo.nextElementSibling;
        const spanDescricao = form.descricao.nextElementSibling;
        const spanPreco = form.preco.nextElementSibling;
        const spanDatahora = form.datahora.nextElementSibling;
        const spanCep = form.cep.nextElementSibling;
        const spanBairro = form.bairro.nextElementSibling;
        const spanCidade = form.cidade.nextElementSibling;
        const spanEstado = form.estado.nextElementSibling;

        spanTitulo.textContent = "";
        spanDescricao.textContent = "";
        spanPreco.textContent = "";
        spanDatahora.textContent = "";
        spanCep.textContent = "";
        spanBairro.textContent = "";
        spanCidade.textContent = "";
        spanEstado.textContent = "";

        if (form.titulo.value === "") {
            spanTitulo.textContent = 'O título deve ser preenchido!';
            formValido = false;
        }
        if (form.descricao.value === "") {
            spanDescricao.textContent = 'A descrição deve ser preenchida!';
            formValido = false;
        }
        if (form.preco.value === "") {
            spanPreco.textContent = 'O preço deve ser preenchido!';
            formValido = false;
        }
        if (form.datahora.value === "") {
            spanDatahora.textContent = 'A data e hora devem ser preenchidas!';
            formValido = false;
        }
        if (form.cep.value === "") {
            spanCep.textContent = 'O cep deve ser preenchido!';
            formValido = false;
        }
        if (form.bairro.value === "") {
            spanBairro.textContent = 'O bairro deve ser preenchido!';
            formValido = false;
        }
        if (form.cidade.value === "") {
            spanCidade.textContent = 'A cidade deve ser preenchida!';
            formValido = false;
        }
        if (form.estado.value === "") {
            spanEstado.textContent = 'O estado deve ser preenchido!';
            formValido = false;
        }
        if (!formValido) {
            return;
        }
    }
});