<?php

/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */
require_once("PHP/config.inc.php");

function connecterBdd() {
    $dsn = 'mysql:host=' . SERVEUR_BDD . ';dbname=' . NOM_DE_LA_BASE;
    $pdo = new PDO($dsn, LOGIN, MOTDE_PASSE);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $pdo->exec("set names utf8");

    return $pdo;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['personne_id']) && isset($_POST['nouvelle_date_naissance'])) {
        $personne_id = $_POST['personne_id'];
        $nouvelle_date_naissance = $_POST['nouvelle_date_naissance'];

        try {
            $pdo = connecterBdd();

            $requete = $pdo->prepare("UPDATE utilisateurs SET dateNaissance = :nouvelle_date_naissance WHERE utilisateur_id = :personne_id");
            $requete->bindParam(':nouvelle_date_naissance', $nouvelle_date_naissance);
            $requete->bindParam(':personne_id', $personne_id);
            $requete->execute();

            echo "La date de naissance a été mise à jour.";
        } catch (Exception $ex) {
            echo "Erreur lors de la mise à jour de la date de naissance : " . $ex->getMessage();
        }
    } else {
        echo "Tous les champs doivent être remplis.";
    }
} else {
    echo "Méthode non autorisée.";
}

