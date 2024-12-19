$(document).ready(function () {
    let nbTour = true;
    $('body').css('background-image', 'url("fondNoel.jpg")');
                    $('body').css('background-size', 'cover');
    $('#deux').hide();
//    $("#testeur").click(function(){
//        $('#premier').hide();
//       $('#ancienMot').text("Le dernier mot était : "); 
//    $('body').css('background-image', 'url("forlenny.png")');
//                $('body').css('background-size', '50%');
//    });
    if (window.WebSocket) {
        
        var socket;
        $('#connect').on('click', function () {
          //  var adresseIP = document.getElementById("adresseIP").value; //récupérer les valeurs des input
        var adresseIP = $("#adresseIP").val(); //récupérer les valeurs des input
        var pseudo = $("#pseudo"); //récupérer les valeurs des input
        var port = $("#port").val();   //récupérer les valeurs des input// l'API WebSocket est-elle installee ?
            socket = new WebSocket("ws://" + adresseIP + ':' + port);
            socket.onopen = function () {
                console.log("Connecté au serveur WebSocket.");
                $('#connect').prop('disabled', true);
                $('#disconnect, #send').prop('disabled', false);
                $('#premier').hide();
                $('#deux').show();
                $('body').css('background-image', 'url("fond.jpg")');
                $('body').css('background-size', 'cover');
                const message = $('#pseudo').val();
                if (socket && socket.readyState === WebSocket.OPEN) {
                    socket.send("14;C;" + message);
                    console.log("Message envoyé :", message);
                } else {
                    alert("La connexion WebSocket n'est pas ouverte.");
                }
                ;
                $('#envoyerMot').on('click', function () {
                    const motPerso = $('#motPerso').val();
                    if (socket && socket.readyState === WebSocket.OPEN) {
                        socket.send("14;P;" + motPerso);
                        console.log("Message envoyé :", motPerso);
                        $('#motPerso').val('');
                    } else {
                        alert("La connexion WebSocket n'est pas ouverte.");
                    }
                });
            };
            socket.onmessage = function (event) {
                console.log("Données reçues : " + event.data);
                var obj = JSON.parse(event.data);
                console.log("Données reçues : " + obj.commande);
                if (obj.commande === "P"){
                    $('#nomPerso').val(obj.donnees);
                }
                if (obj.commande === "A"){
                    alert("En attente d'autres joueurs...");
                }
                if (obj.commande === "M"){
                    let manchesRestantes = $('#nbTour').text();
                    manchesRestantes--;
                    $('#nbTour').text(manchesRestantes);
                    $('#nomPerso').val(obj.donnees);
                    $('#ancienMot').text("Le dernier mot était : ");
                    
                }
                if (obj.donnees === "Fin"){
                    alert("Fin de partie");
//                    $('#premier').hide();
//                    $('#deux').hide();
//                    $('body').css('background-image', 'url("forlenny.png")');
//                $('body').css('background-size', 'cover');
                }
            };
            socket.onerror = function (error) {
                console.error("Erreur WebSocket :", error);
            };
            socket.onclose = function () {
                console.log("Déconnecté du serveur WebSocket.");
                $('#connect').prop('disabled', false);
                $('#disconnect, #send').prop('disabled', true);
            };
        });
        $('#disconnect').on('click', function () {
            if (socket) {
                socket.close();
                $('#deux').hide();
                $('#premier').show();
                $('#connect').prop('disabled', false);
                $('body').css('background-image', 'url("fondNoel.jpg")');
                $('body').css('background-size', 'cover');
            }
        });

    } else
        console.log('L\'API WebSocket n\'est pas supportée par ce navigateur.');
});