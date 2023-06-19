window.onload = function () {
    const inputCep = document.getElementById('cep');
    inputCep.onkeyup = () => buscaEndereco(inputCep.value);
  }
  
  async function buscaEndereco(cep) {
    if (cep.length != 9) return;
    let form = document.querySelector("form");
  
    try {
      const response = await fetch("../php/buscaEndereco.php?cep=" + cep);
      if (!response.ok) {
        throw new Error(response.status);
      }
      const endereco = await response.json();
      form.logradouro.value = endereco.logradouro;
      form.cidade.value = endereco.cidade;
      form.estado.value = endereco.estado;
    } catch (error) {
      console.error('Falha inesperada: ' + error);
    }
  }
  