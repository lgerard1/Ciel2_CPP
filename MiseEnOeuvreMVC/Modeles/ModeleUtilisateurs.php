<?php

require_once  '../Modeles/Modele.php';

class ModeleUtilisateurs extends Modele {

    public function obtenirUtilisateurs() {
        try {
            $requete = $this->bdd->query('SELECT u.nom, u.prenom, DATE_FORMAT(u.dateNaissance, "%d/%m/%Y") AS dateFormatee,'
                    . 'v.ville_nom, r.region_nom, d.departement_nom FROM utilisateurs u '
                    . 'JOIN villes v ON u.ville_id = v.ville_id JOIN departements d '
                    . 'ON v.ville_departement_id = d.departement_id JOIN regions r '
                    . 'ON departement_region_id = regions_id;');
            $requete->execute();
            
            $lesUtilisateurs = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($lesUtilisateurs, $reponse);
            }
            $requete->closeCursor();
            return $lesUtilisateurs;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirPersonnes :" . $exc->getMessage());
            die();
        }
    }
    public function obtenirNomPrenom(){
        $requete = $this->bdd->query('SELECT nom, prenom, utilisateur_id FROM utilisateurs;');
        
        
        echo "<select name='personne' id='personne'>";
        while ($row = $requete->fetch(PDO::FETCH_ASSOC)) {
            echo "<option value='" . $row['nomPrenom'] . "</option>";
        }
        echo "</select>";
        
    }
}
