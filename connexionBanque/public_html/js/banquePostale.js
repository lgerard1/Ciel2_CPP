/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/javascript.js to edit this template
 */
$(document).ready(function ()
{
    var valeurInitiale = "----------";
    initialiser();
    $('#identifiant').on('input', function ()
    {
        $("#effaceIdentifiant").show(); // Affichage du bouton avec la croix pour effacer l'identifiant
        $("#effaceIdentifiant").on("click", function () {
            initialiser();
        });
        $("#erreur").empty(); // Suppression du message d'erreur
        $(".input-group").removeClass("border-danger text-danger").addClass("border-primary");
        var inputVal = $("#identifiant").val(); // récupération de la valeur de la zone de saisie
        console.log(inputVal);
        inputVal = inputVal.replace(/[^0-9]/g, ""); // conserver seulement les chiffres
        if (inputVal.length > 10) {
            inputVal = inputVal.substring(0, 10); // Limiter à 10 chiffres
        }
        var valeurAffichee = inputVal;
        console.log(valeurAffichee); // Reconstitution de la valeur à afficher
        $("#identifiant").val(valeurAffichee); // Affichage de cette valeur
        this.setSelectionRange(inputVal.length, inputVal.length);
        console.log(inputVal.length);
        $("#continuer").on("click", function ()
        {
            var valId = valeurAffichee;
            var taille = (inputVal.length, inputVal.length);
            console.log(taille);
            if (valId !== '-') {
                if (taille === 10) {
                    console.log("toto");
                    $("#erreur").empty();
                    console.log("Affichage du clavier");
                } else {
                    valId.replace(/[^0-9]/g, "");
                    $(".input-group").removeClass("border-primary").addClass("border-danger text-danger");
                    if (taille === 0) {
                        alert("Veuillez renseigner votre identifiant.");
                    }
                    if (taille !== 0 & taille !== 10) {
                        alert("Votre identifiant est incomplet.");
                    }
                }
            }
        });
        $('#clavier').on("click", ":button", function () {
            $("#effaceMdp").show();
            let puceVide = $('#mdp .vide:first');
            puceVide.replace("&#8226;");
            console.log("#motDePasse");
        });
        $('#effaceMdp').on("click", function () {
            $('#mdp span').each(function () {
                "&#8226;".replace("&#9702;");
            });
            $("#motDePasse").empty;
            $("#effaceMdp").hide;
        });

    });
    function initialiser(placeholder) {
        placeholder = valeurInitiale;
        $("#identifiant").val(placeholder);
        $("#identifiant").focus();
        $("#effaceIdentifiant").hide();
        $("#motDePasse").hide();
        $("#erreur").empty();
    }
    var tailleMdp = ("#motDePasse").length;
    if(tailleMdp === 6){
        alert("#identifiant", "#motDePasse");
    }
});

function afficherClavier() {
    if ($('#motDePasse').is(':hidden')) {
        let chiffres = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
        chiffres = melangerTableau(chiffres);
        $("#clavier").on("click", melangerTableau()`
<table>
    <tr>        
    <div class="row">
        <button>7</button> 
        <button>8</button> 
        <button>9</button> 
    </div>
    </tr>
    <tr>        
    <div class="row">
        <button>4</button> 
        <button>5</button> 
        <button>6</button> 
    </div>
    </tr>
    <tr>        
    <div class="row">
        <button>1</button> 
        <button>2</button> 
        <button>3</button> 
    </div>
    </tr>
    <tr>
        <button>0</button>
    </tr>
</table>
<div class="col p-1">
    <button type="button" class="btn btn-light text-primary fs-4 border border-primary w-100">
    </button>
</div>`);

        $('#motDePasse').show();
    }
}
function melangerTableau(tableau) {
    for (let i = tableau.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
// Échange des éléments
        [tableau[i], tableau[j]] = [tableau[j], tableau[i]];
    }
    return tableau;
}