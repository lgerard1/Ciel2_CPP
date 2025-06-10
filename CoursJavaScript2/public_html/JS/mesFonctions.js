/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/javascript.js to edit this template
 */


function demanderNom() {
    nom = prompt("Quel est votre nom ? ");
    alert("Salut : " + nom);
}
function confirmer() {
    envoyer = confirm("Etes vous certain de vouloir envoyer les données ? ");
    if (envoyer === true ){
        document.forms["monForm"].submit();
    }
}
function afficherInfo(){
    var texteDeLaDiv = document.getElementById("divClique").textContent;
    alert("Texte dans la div : " + texteDeLaDiv);
}