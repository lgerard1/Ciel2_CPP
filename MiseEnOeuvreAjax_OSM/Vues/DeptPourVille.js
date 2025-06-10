/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/javascript.js to edit this template
 */
function remplirTable(e)
{
    e.preventDefault();
    var nomDeLaVille = $("#ville").val();
    $.getJSON('/Controleurs/controleur_1.1',
            {commande: 'obtenirAdresse',
                nomVille: nomDeLaVille})
            .done(function (donnees, stat, xhr) {
                $('deptVille').DataTable(
                        {
                            "data": donnees,
                            "columns": [
                                {title: "Villes"},
                                {title: "Code Postal"},
                                {title: "Départements"}
                            ],
                            "lengthMenu": [[5, 10, 15, 25, 50, 100, -1], [5, 10, 15, 25, 50, 100, "Tous"]],
                            "pageLength": 5,
                            "language": {
                                "lengthMenu": "Afficher _MENU_ lignes par page",
                                "info": "page _PAGE_ sur _PAGES_",
                                "infoEmpty": "pas de résultat",
                                "search": "Recherchez: ",
                                "paginate": {
                                    "first": "Premier ",
                                    "last": "Dernier ",
                                    "next": "Suivant ",
                                    "previous": "Précédent "
                                },
                            }
                        }
                );
            })
            .fail(function (xhr, text, error) {
                console.log("param : " + JSON.stringify(xhr));
                console.log("status : " + text);
                console.log("error : " + error);
            })
}
$(document).ready(function () {
    $('#envoyer').click(remplirTable);
});

