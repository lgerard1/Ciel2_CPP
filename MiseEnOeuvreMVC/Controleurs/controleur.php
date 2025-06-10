<?php

require_once '../Modeles/ModeleUtilisateurs.php';

$utilisateur = new ModeleUtilisateurs();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') == 'GET') {
    $action = filter_input(INPUT_GET, "action");
    switch ($action) {
        case 'obtenirUtilisateurs':
            header('Content-Type: application/json');
            echo json_encode($utilisateur->obtenirUtilisateurs());
            break;
        default:
            echo json_encode(["error" => "Action non reconnue"]);
            break;
    }
}

unset($utilisateur);

$toto = array();
