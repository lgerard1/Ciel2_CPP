/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/javascript.js to edit this template
 */
$(document).ready(function () {
    $.getJSON('../Controleurs/controleur.php', {action:'obtenirNomPrenom'})
        .done(function (data) {
            data.forEach(function (utilisateur) {
                $('label').append(
                    `
                        ${utilisateur.nom}
                        ${utilisateur.prenom}
                    `
                );
            });
        })
        .fail(function (jqxhr, textStatus, error) {
            const err = textStatus + ", " + error;
            console.error("Erreur de chargement des données : " + err);
            alert("Erreur lors du chargement des données... Veuillez réessayer.");
    });
    
    $("#retour").click(function(){
        window.location.href = '../index.php';
    });
});

