/*
const photoAlbum = document.getElementById("photo-album");
const photoCount = document.getElementById("photo-count");

fetch("https://jsonplaceholder.typicode.com/albums/2/photos")
.then(response => response.json())
.then(data => {
    data.forEach(photo => {
        photoCount.textContent = data.length;
        
        const photoHeader = document.createElement("h1");
        photoHeader.innerText = photo.title;
        
        const photoDiv = document.createElement("div");
        photoDiv.classList.add("photo");
        
        const photoImg = document.createElement("img");
        photoImg.src = photo.url;
        photoImg.alt = photo.title;
        
        photoAlbum.appendChild(photoDiv);
        photoDiv.appendChild(photoImg);
        photoDiv.appendChild(photoHeader);
        
        photoDiv.addEventListener('click', () => {
            photoDiv.style.opacity = "0";
            setTimeout(() => {
                photoDiv.remove();
                photoCount.textContent = photoAlbum.children.length - 1; // update photo count
            }, 1000);
        });
    });
})

.catch(error => console.error(error));
*/