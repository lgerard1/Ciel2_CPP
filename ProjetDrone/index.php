<?php
session_start(); 

// Affichage des erreurs pour le débogage
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Fichier où les messages seront stockés
$messageFile = 'messages.txt';

// Initialisation de la session pour stocker les messages
if (!isset($_SESSION['messages'])) {
    $_SESSION['messages'] = [];
}

// Traitement des messages envoyés via GET
if ($_SERVER['REQUEST_METHOD'] === 'GET' && isset($_GET['message'])) {
    $message = htmlspecialchars(trim($_GET['message'])); // Échapper et nettoyer le message
    // Ajoutez le message à la session
    $_SESSION['messages'][] = $message; // Stocke le message dans la session

    // Écrire le message dans le fichier
    file_put_contents($messageFile, $message . PHP_EOL, FILE_APPEND);

    // Passer le message à JavaScript pour l'afficher dans la console
    echo "<script>console.log('Message reçu: " . addslashes($message) . "');</script>";
}

// Lire le contenu du fichier pour l'afficher
if (file_exists($messageFile)) {
    $fileContent = file($messageFile, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
    $_SESSION['messages'] = $fileContent; // Mettre à jour les messages de la session avec le contenu du fichier
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">        
    <link href="js/libs/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css"/>
    <script src="js/libs/bootstrap/js/bootstrap.min.js" type="text/javascript"></script>
    <script src="js/libs/jquery/jquery.js" type="text/javascript"></script>
    
    <link href="projetDrone.css" rel="stylesheet" type="text/css"/>
    <title>Réception des Messages</title>
</head>
<body>

    <div class="container">
        <h2>Messages Reçus</h2>
        <form method="GET">
            <div class="form-group">
                <textarea name="message" class="form-control" placeholder="Écrivez un message" required></textarea>
            </div>
            <button type="submit" class="btn btn-primary">Envoyer</button>
        </form>

        <h3>Messages enregistrés :</h3>
        <div>
            <textarea readonly class="form-control" style="width: 100%; height: 300px;">
<?php
if (!empty($_SESSION['messages'])) {
    echo htmlspecialchars(implode("\n", $_SESSION['messages']));
} else {
    echo "Aucun message reçu";
}
?>
            </textarea>
        </div>
    </div>

</body>
</html>