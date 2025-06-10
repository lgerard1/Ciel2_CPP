<?php

require_once '../Modeles/Modele.php';

class ModeleProfs extends Modele{
    public function obtenirListeProfs() {
        try {
            $requete = $this->bdd->query('SELECT idProf, nom, prenom FROM profs;');
            $requete->execute();
            
            $profs = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($profs, $reponse);
            }
            $requete->closeCursor();
            return $profs;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirProfs :" . $exc->getMessage());
            die();
        }
    }
}