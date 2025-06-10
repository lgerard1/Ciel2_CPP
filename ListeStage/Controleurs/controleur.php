<?php

require_once '../Modeles/ModeleProfs.php';

$profs = new ModeleProfs();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'GET') {
    header('Content-Type: application/json');
    // récupération de la donnée 'commande'
    $commande = filter_input(INPUT_GET, 'commande');

    switch ($commande) {
        case 'getProfs':
            echo json_encode($profs->obtenirListeProfs());
            break;
        default:
            echo json_encode("commande inconnue");
    }
}