<?php
session_start(); // Démarrer la session

// Initialiser le tableau des messages s'il n'existe pas
if (!isset($_SESSION['messages'])) {
    $_SESSION['messages'] = [];
}

// Vérifier si un message a été soumis via GET
if ($_SERVER['REQUEST_METHOD'] === 'GET' && !empty($_GET['message'])) {
    $message = htmlspecialchars($_GET['message']); // Sécuriser l'entrée utilisateur
    $_SESSION['messages'][] = $message; // Ajouter le message à la session
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="js/libs/jquery/jquery.js" type="text/javascript"></script>
    <link href="js/libs/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css"/>
    <script src="js/libs/bootstrap/js/bootstrap.min.js" type="text/javascript"></script>
    <link href="projetDrone.css" rel="stylesheet" type="text/css"/>
    <title>Réception des Messages</title>
</head>
<body>

    <h2>Messages Reçus</h2>
    <form method="GET">
        <textarea name="message" placeholder="Écrivez un message" required></textarea><br>
        <button type="submit">Envoyer</button>
    </form>

    <h3>Messages enregistrés :</h3>
    <div>
        <textarea readonly style="width: 90%; height: 300px;">
<?php
if (!empty($_SESSION['messages'])) {
    echo htmlspecialchars(implode("\n", $_SESSION['messages']));
} else {
    echo "Aucun message reçu";
}
?>
        </textarea>
    </div>

</body>
</html>
