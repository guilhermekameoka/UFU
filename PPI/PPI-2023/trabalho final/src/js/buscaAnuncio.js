async function buscarAnuncios(palavraChave) {
    const palavraChave = document.getElementById('busca').value;

    try {
        const response = await fetch("../php/buscaAnuncio.php?busca=" + palavraChave)
        if (!response.ok) throw new Error(response.statusText);
        const resposta = await response.json();
        //
        //
        //

    } catch (error) {
        console.error(error);
        return;
    }
}

document.addEventListener('DOMContentLoaded', function () {
    window.onload = function () {
        const botaoBusca = document.getElementById('busca');
        botaoBusca.addEventListener('click', buscarAnuncios);
    };
});
