$(document).ready(function () {
    $.getJSON('eleves.json', function (lesEleves)
    {
        console.log("Données reçues : ", lesEleves);
        lesEleves.forEach(function (unEleve) {
            console.log(unEleve.nom + " " + unEleve.prenom + " " + unEleve.age);
        });
    })
    .fail(function (jqXHR, textStatus, errorThrown) {
        console.error("Erreur de chargement des données:", textStatus, errorThrown);

    });
});
