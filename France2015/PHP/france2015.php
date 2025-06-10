<?php

require_once("PHP/config.inc.php");

function afficherPersonnes() {
    try {
        $pdo = connecterBdd();
        
        // Ajout de la ligne pour afficher le mois en français
        $requete = $pdo->query("set lc_time_names = 'fr_FR' ;") ;
        
        $requete = $pdo->query("select nom, prenom,date_format(dateNaissance,'%d %M %Y') as dateNaissance, ville_nom,departement_nom,region_nom from utilisateurs u, villes v,departements d, regions r where u.ville_id = v.ville_id and v.ville_departement_id=d.departement_id and d.departement_region_id=r.regions_id;");
        echo "<table class='table table-striped table-bordered'>";
        echo '<tr><th>Nom</th><th>Prénom</th><th>Date de Naissance</th><th>Nom de la Ville</th><th>Nom du département</th><th>Nom de la Région</th></tr>';
        while ($ligne = $requete->fetch(PDO::FETCH_ASSOC)) {
            echo '<tr>';
            echo '<td>' . $ligne['nom'] . "</td>";
            echo '<td>' . $ligne['prenom'] . "</td>";
            echo '<td>' . $ligne['dateNaissance'] . "</td>";
            echo '<td>' . $ligne['ville_nom'] . "</td>";
            echo '<td>' . $ligne['departement_nom'] . "</td>";
            echo '<td>' . $ligne['region_nom'] . "</td>";
            echo '</tr>';
        }
    } catch (Exception $ex) {
        print "La connexion a échoué : " . $ex->getMessage() . "</br>";
        die();
    }
}

function connecterBdd() {

    $dsn = 'mysql:host=' . SERVEUR_BDD . ';dbname=' . NOM_DE_LA_BASE;
    $pdo = new PDO($dsn, LOGIN, MOTDE_PASSE);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $pdo->exec("set names utf8");

    return $pdo;
}
function afficherCompteVillesFromCp($code_postal) {
    try {
        $pdo = connecterBdd();
        
        $requete = $pdo->prepare("SELECT COUNT(*) AS nombre_villes FROM villes WHERE ville_code_postal = :code_postal");
        $requete->bindParam(':code_postal', $code_postal, PDO::PARAM_STR);
        $requete->execute();
        
        $resultat = $requete->fetch(PDO::FETCH_ASSOC);
        $nombre_villes = $resultat['nombre_villes'];

        echo "<p>Le nombre de villes correspondant au code postal $code_postal est : $nombre_villes</p>";
    } catch (Exception $ex) {
        print "La connexion a échoué : " . $ex->getMessage() . "</br>";
        die();
    }
}
function afficherNombreCommuneParDepartement() {
    try {
        $pdo = connecterBdd();
        
        $requete = $pdo->query("SELECT departements.departement_nom, COUNT(villes.ville_id) AS nombre_communes 
                                FROM departements 
                                LEFT JOIN villes ON departements.departement_id = villes.ville_departement_id 
                                GROUP BY departements.departement_id");
        
        echo "<h2>Nombre de communes par département :</h2>";
        echo "<table class='table table-striped table-bordered'>";
        echo "<tr><th>Nom du département</th><th>Nombre de communes</th></tr>";
        while ($ligne = $requete->fetch(PDO::FETCH_ASSOC)) {
            echo "<tr>";
            echo "<td>" . $ligne['departement_nom'] . "</td>";
            echo "<td>" . $ligne['nombre_communes'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    } catch (Exception $ex) {
        print "La connexion a échoué : " . $ex->getMessage() . "</br>";
        die();
    }
}
function genererListePersonne() {
    try {
        $pdo = connecterBdd();
        
        // Définir la locale française pour le formatage de la date
        $requete = $pdo->query("SET lc_time_names = 'fr_FR'");
        
        $requete = $pdo->query("SELECT utilisateur_id, CONCAT(nom, ' ', prenom, ' - ', DATE_FORMAT(dateNaissance, '%d %M %Y') COLLATE utf8_general_ci) AS personne_info FROM utilisateurs");
        
        echo "<select name='personne' id='personne'>";
        while ($row = $requete->fetch(PDO::FETCH_ASSOC)) {
            echo "<option value='" . $row['utilisateur_id'] . "'>" . $row['personne_info'] . "</option>";
        }
        echo "</select>";
    } catch (Exception $ex) {
        print "La connexion a échoué : " . $ex->getMessage() . "</br>";
        die();
    }
}
