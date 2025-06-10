<?php

require_once '../Modeles/Modele.php';

class ModeleVille extends Modele {

    public function ObtenirListeVille($idDepartement) {
        try {

            $requete = $this->bdd->prepare('SELECT ville_id, ville_nom FROM villes where ville_departement_id = :id;');
            $requete->bindParam(":id", $idDepartement);
            $requete->execute();

            $ville = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($ville, $reponse);
            }
            $requete->closeCursor();
            return $ville;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirVilleDuDépartement :" . $exc->getMessage());
            die();
        }
    }

    public function obtenirDepartementsPourVille($nomVille) {
        try {
            $requete = $this->bdd->prepare('SELECT ville_nom, ville_code_postal,departement_nom from villes,departements where villes.ville_departement_id=departements.departement_id and ville_nom = :nom;');
            $requete->bindParam(":nom", $nomVille);
            $requete->execute();
            $departements = array();
            while ($reponse = $requete->fetch()) {
                array_push($departements, array(
                    $reponse['ville_nom'],
                    $reponse['ville_code_postal'],
                    $reponse['departement_nom']// Elements à mettre dans le tableau pour le DataTables
                ));
            }
            $requete->closeCursor();
            return $departements;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirDepartementsDeLaRegion :" . $exc->getMessage());
            die();
        }
    }
}
