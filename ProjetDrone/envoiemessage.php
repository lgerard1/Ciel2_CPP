<?php
// URL de votre script PHP qui reçoit les messages
$receiverUrl = 'http://localhost/projetDrone/index.php'; // Remplacez par l'URL correcte

// Message à envoyer
$message = 'Bonjour, ceci est un message depuis un autre code!';

// Construction de l'URL avec le message
$url = $receiverUrl . '?message=' . urlencode($message);

// Envoi de la requête GET
$response = file_get_contents($url);

// Vérifiez la réponse
if ($response === FALSE) {
    die('Erreur lors de l\'envoi du message.');
} else {
    echo 'Message envoyé avec succès.';
}
?>