/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/javascript.js to edit this template
 */
var  cpt = 3;

function changerCouleur()
{
    $(this).css("background-color", "yellow");
    $("form").append('<input type= \"button\" value=cpt >');
    cpt++;
}
function afficherValeur()
{
    var valBouton = $(this).val();
    $("#duTexte").css("background-color", "white");
    $("#duTexte").css("color", "blue");
    $("#duTexte").text(valBouton);
    console.log(valBouton);
}
$(document).ready(function ()
{
    $("#duTexte").click(changerCouleur);
    $(document).on("mouseover", ":button", afficherValeur);
});