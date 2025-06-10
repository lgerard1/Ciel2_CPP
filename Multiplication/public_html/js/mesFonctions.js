/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/javascript.js to edit this template
 */

function multiplier() {
    window.document.forms["monForm"].afficheur3.value =
            window.document.forms["monForm"].afficheur1.value * window.document.forms["monForm"].afficheur2.value;
}
function additionner() {
    window.document.forms["monForm2"].afficheur3.value =
            parseFloat(window.document.forms["monForm2"].afficheur1.value) + parseFloat(window.document.forms["monForm2"].afficheur2.value);
}