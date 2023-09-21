function insereElemento() {
  const novoElemento = document.criaElemento("div");
  const novoItem = document.criaElemento("div");
  const novaImagem = document.criaElemento("img");
  const NovoParagrafo = document.criaElemento("p");
  
  novoElemento.classList.add("item");
  novaImagem.src = "https://br.web.img2.acsta.net/pictures/14/02/04/14/08/054280.jpg";
  novaImagem.height = "150";
  novaImagem.width = "150";
  NovoParagrafo.textContent = "Lorem ipsum dolor sit, amet consectetur adipisicing elit. Ipsum eaque et sunt temporibus voluptatum, in aperiam ab modi sit ipsam quasi qui hic voluptates cupiditate, dolorem debitis placeat, officia commodi.";
  
  novoItem.appendChild(novaImagem);
  novoItem.appendChild(NovoParagrafo);
  novoElemento.appendChild(novoItem);
  
  document.body.appendChild(novoElemento);
}