function inserirElemento() {
    const novoElemento = document.createElement("div");

    novoElemento.innerHTML = `
      <div class="item">
        <img src="https://br.web.img2.acsta.net/pictures/14/02/04/14/08/054280.jpg" height="150" width="150">
        <p>
          Lorem ipsum dolor sit, amet consectetur adipisicing elit. Ipsum eaque et sunt temporibus voluptatum, in
          aperiam ab modi sit ipsam quasi qui hic voluptates cupiditate, dolorem debitis placeat, officia commodi.
        </p>
      </div>
    `;
    document.body.appendChild(novoElemento);
}