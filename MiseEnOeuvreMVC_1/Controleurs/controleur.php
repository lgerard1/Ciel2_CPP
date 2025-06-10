<?php

/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

require_once '../Modeles/ModeleUtilisateurs.php';

$utilisateur = new ModeleUtilisateurs();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') == 'GET'){
    $action = filter_input(INPUT_GET, "action");
    header('Content-Type: application/json');
    switch ($action){
        case 'obtenirUtilisateurs' :
            
            echo json_encode($utilisateur->obtenirUtilisateurs());
            break;
        default :
            echo json_encode(["error" => "Action non reconnue"]);
            break;
    }
}

unset ($utilisateur);