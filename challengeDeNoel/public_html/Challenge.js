$(document).ready(function () {
    if (window.WebSocket) { // Vérifier si l'API WebSocket est supportée
        let socket;
        let mancheEnCours = true;

        // Initialisation des boutons pour WebSocket
        $('#btn-connexion').on('click', function () {
            const pseudo = $('#pseudo').val();
            const ip = $('#ip-serveur').val();
            const port = $('#port-serveur').val();
            $('#connexion-interface').addClass('d-none'); //cacher la premiere page et faire apparaitre la deuxieme
                    $('#jeu-interface').removeClass('d-none');
            if (pseudo && ip && port) {
                // Création de la connexion WebSocket
                const wsUrl = `ws://${ip}:${port}`;
                socket = new WebSocket(wsUrl);

                socket.onopen = function () {
                    console.log("Connecté au serveur WebSocket.");
                    alert("Connexion réussie au serveur WebSocket.");

                    // Basculer vers l'interface de jeu
                    
                    $('#nom-personnage').val(`Personnage-${pseudo}`);
                };

                socket.onmessage = function (event) {
                    console.log("Message reçu :", event.data);
                    $('#receivedMessages').append(`Message reçu : ${event.data}\n`);
                };

                socket.onerror = function (error) {
                    console.error("Erreur WebSocket :", error);
                    alert("Erreur de connexion au serveur WebSocket.");
                };

                socket.onclose = function () {
                    console.log("Déconnecté du serveur WebSocket.");
                    alert("Déconnexion du serveur WebSocket.");
                };
            } else {
                alert("Veuillez remplir tous les champs.");
            }
        });

        // Déconnexion WebSocket
        $('#disconnect').on('click', function () {
            if (socket) {
                socket.close();
                console.log("Connexion WebSocket fermée.");
            }
        });

        // Envoi de message via WebSocket
        $('#btn-envoyer').on('click', function () {
            const message = $('#message').val();

            if (socket && socket.readyState === WebSocket.OPEN) {
                socket.send(message);
                console.log("Message envoyé :", message);

                if (mancheEnCours) {
                    // Cacher le nom du personnage après le premier message envoyé
                    $('#nom-personnage').closest('.mb-3').hide();
                    mancheEnCours = false;
                }

                // Réduire le compteur des manches
                let manchesRestantes = parseInt($('#compteur-manches').text(), 10);
                manchesRestantes--;
                $('#compteur-manches').text(manchesRestantes);

                if (manchesRestantes <= 0) {
                    alert("Fin du jeu ! Merci d'avoir joué.");
                    $('#btn-envoyer').prop('disabled', true); // Désactiver le bouton d'envoi
                }

                // Effacer le champ de message après envoi
                $('#message').val('');
            } else {
                alert("La connexion WebSocket n'est pas ouverte.");
            }
        });
    } else {
        console.log("L'API WebSocket n'est pas supportée par ce navigateur.");
    }
});
