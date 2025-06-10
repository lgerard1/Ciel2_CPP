$(document).ready(function ()
{
    $('#soumettre').click(verifierMdp);
    afficherMdp();
    mettreAJourVersion();
});

function verifierMdp()
{
    if ($(`#mdp`).val() !== $(`#confmdp`).val())
    {
        alert("Les deux mots de passe ne sont pas identiques");
        event.preventDefault();
    } else {
        $('#inscription').submit(verifierMdp);
    }
}
function afficherMdp() {

    $('.oeilMdp').mouseenter(function () {
        var inputId = $(this).data('target');
        $('#' + inputId).attr('type', 'text');
    });

    $('.oeilMdp').mouseleave(function () {
        var inputId = $(this).data('target');
        $('#' + inputId).attr('type', 'password');
    });

}
function mettreAJourVersion() {
    
    
    $('#os').change(function () {
        console.log($('#os').val());
        $('#version').empty();
        $("#version").append("<option>Selectionnez la version</option>");
        if ($('#os').val() === 'win') {
            alert("Vous avez changé de Système d'exploitation");
            $("#version").append("<option>Windows 7</option>");
            $("#version").append("<option>Windows 10</option>");
            $("#version").append("<option>Windows 11</option>");
            $("#version").append("<option>Windows Server</option>");
            
        }
        if ($('#os').val() === 'lin') {
            alert("Vous avez changé de Système d'exploitation");
            $("#version").append("<option>Mint</option>");
            $("#version").append("<option>Debian</option>");
            $("#version").append("<option>Suze</option>");
            $("#version").append("<option>Ubuntu</option>");
        }
        if ($('#os').val() === 'mac') {
            alert("Vous avez changé de Système d'exploitation");
            $("#version").append("<option>Sonoma</option>");
            $("#version").append("<option>Ventura</option>");
            $("#version").append("<option>Monterey</option>");
            $("#version").append("<option>Big Sur</option>");
        }
    });

}