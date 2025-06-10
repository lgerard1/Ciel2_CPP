var lat = 48.852969;
var lon = 2.349903;
var maCarte = null;
var marqueur;
var marqueurDyna;
var cercle;
var polygone;
var groupe = new L.featureGroup();

function initCarte() {
    maCarte = L.map('carte').setView([lat, lon], 11);
    // Leaflet ne récupère pas les cartes (tiles) sur un serveur par défaut. Nous devons lui préciser où nous souhaitons les récupérer. Ici, openstreetmap.fr
    L.tileLayer('https://{s}.tile.openstreetmap.fr/osmfr/{z}/{x}/{y}.png', {
        // Il est toujours bien de laisser le lien vers la source des données
        attribution: 'données © <a href="//osm.org/copyright">OpenStreetMap</a>/ODbL - rendu <a href="//openstreetmap.fr">OSM France</a>',
        minZoom: 1,
        maxZoom: 19
    }).addTo(maCarte);
}

function afficherAdresse()
{
    var idUser = $(this).val(); // on récupère la valeur de l'option de la liste
    $("#adresse").empty();  // vider la zone de texte
    if (idUser !== '-1') { // si l'utilisateur n'est pas le premier (choisissez....)

        $.getJSON('../Controleurs/controleur_1.1.php',
                {
                    'commande': 'obtenirAdresse',
                    'idUser': idUser
                }
        )
                .done(function (donnees, stat, xhr) {
                    //$("#adresse").text(donnees.adresse);
                    $("#adresse").text(donnees);

                })
                .fail(function (xhr, text, error) {
                    console.log("param : " + JSON.stringify(xhr));
                    console.log("status : " + text);
                    console.log("error : " + error);
                });
    }
}

function genererListeUser()
{
    $.getJSON('../Controleurs/controleur_1.1.php',
            {
                'commande': 'listeUtilisateurs'
            }
    )
            .done(function (donnees, stat, xhr) {
                // génération de la liste déroulante des utilisateurs
                $("#listeUtilisateur").append($('<option>', {value: -1}).text("Sélectionnez une personne"));
                $.each(donnees, function (index, ligne) {
                    // ligne contient un objet json de la forme
                    // {"id" : "id de la personne"},
                    // {"nom" : "nom de la personne"}                        
                    var utilisateur = ligne.nom + " " + ligne.prenom;
                    $("#listeUtilisateur").append($('<option>', {value: ligne.id}).text(utilisateur));
                });
            })
            .fail(function (xhr, text, error) {
                console.log("param : " + JSON.stringify(xhr));
                console.log("status : " + text);
                console.log("error : " + error);
            });
}

$(window).on('load', initCarte);

$(document).ready(function ()
{
    // génération de la liste déroulante au chargement de la page
    genererListeUser();
    // gestion de la selection d'un nom
    $("#listeUtilisateur").change(afficherAdresse);
});