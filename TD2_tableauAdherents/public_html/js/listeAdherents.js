/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/javascript.js to edit this template
 */
$(document).ready(function () {
const adherentsParPage = 10;
        $.getJSON('adherents_10.json', function (data)
        {
        fabriquerPagination(data, adherentsParPage);
                afficherAdherents(data, 0, adherentsParPage);
                $(document).on("click", ".page-link", function () {
        event.preventDefault();
                var numpage = $(this).text();
                afficherAdherents(data, parseInt(numpage) - 1, adherentsParPage);
                $("#checkGeneral").prop("checked", false);
        });
                $("#checkGeneral").on("click", function () {
        var etat = $(this).is(':checked');
                $(".form-check-input").prop("checked", etat);
        });
        }).fail(function (jqxhr, textStatus, error)
        {
        const err = textStatus + ", " + error;
                console.error("Erreur de chargement des adhérents: " + err);
                });
});
        function fabriquerPagination(adherents, nbAdherents) {
        var totalAdherents = adherents.length;
                var nbPages = Math.ceil(totalAdherents / nbAdherents);
                for (i = 1; i < nbPages + 1; i++) {
        $("#pagination").append(`<li class="page-item"><a class="page-link" href="#">${i}</a></li>`);
        }
        }
function afficherAdherents(adherents, numPages, nbAdherents) {
    $("tbody").empty();
        var debut = numPages * nbAdherents;
        var fin = debut + nbAdherents;
        adherents.slice(debut, fin).forEach(function (adherent) {
$("tbody").append(`
                <tr class="align-middle">
                    <td class="text-center"><input type="checkbox" class="form-check-input"></td>
                    <td>${adherent.nom}</td>
                    <td>${adherent.prenom}</td>
                    <td>${adherent.adresse}, ${adherent.codePostal} ${adherent.ville}</td>
                    <td class="text-center">${adherent.telephone}</td>
                    <td class="text-center">${adherent.mail}</td>
                    <td class="text-center">
                        <div class="btn-group">
                            <button class="btn btn-light me-2 btn-edit">&#128394;</button>
                            <button class="btn btn-light">&#128465;</button>
                        </div>
                    </td>
                </tr>
            `);
        });
        $(".btn-edit").on("click", function (){
var parentRow = $(this).closest('tr');
        var nom = parentRow.find('td:eq(1)').text();
        var prenom = parentRow.find('td:eq(2)').text();
        var codePostal = parentRow.find('td:eq(3)').text();
        var tel = parentRow.find('td:eq(4)').text();
        var mail = parentRow.find('td:eq(5)').text();
        $('#detailsModal .modal-body #nom').val(nom);
        $('#detailsModal .modal-body #prenom').val(prenom);
        $('#detailsModal .modal-body ').val(`<p>Adresse : ${codePostal}</p>`);
        $('#detailsModal .modal-body ').val(`<p>Ville : ${codePostal}</p>`);
        $('#detailsModal .modal-body #telephone').val(tel);
        $('#detailsModal .modal-body #email').val(mail);
          $('#detailsModal').modal('show');
        });

}



