<?php

require_once '../Modeles/Modele.php';

class ModeleUtilisateurs extends Modele {

    public function obtenirListeUtilisateurs() {
        try {
            $requete = $this->bdd->query('SELECT id, nom, prenom FROM user;');
            $requete->execute();

            $listeUtilisateurs = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($listeUtilisateurs, $reponse);
            }
            $requete->closeCursor();
            return $listeUtilisateurs;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirPersonnes :" . $exc->getMessage());
            die();
        }
    }

    public function obtenirAdresse($id) {
        try {

            $requete = $this->bdd->prepare("select adresse from user where id = :idU ;");
            $requete->bindParam(":idU", $id);
            $requete->execute() or die(print_r($requete->errorInfo()));
            if ($requete->rowCount() == 0) {
                $adresse = "pas d'adresse";
            } else {
                $adresse = $requete->fetchColumn();
            }
            $requete->closeCursor();
            return($adresse);
        } catch (PDOException $ex) {
            print "Erreur : " . $ex->getMessage() . "<br/>";
            die();
        }
    }

    public function verifierLogin($log, $mdp) {
        try {
            
            // recherche du couple login/mdp dans la table user
//            $requete = $this->bdd->prepare("select id from user where login = :log and mdp = :mdp ;");
            $requete = $this->bdd->prepare("select id from user where login = :log ;");
            $requete->bindParam(":log", $log);
//            $requete->bindParam(":mdp", $mdp);
            $requete->execute() or die(print_r($requete->errorInfo()));
            // comptage du nombre de resultats
            $nbLigne = $requete->rowCount();
            
            if ($nbLigne == 0) {// le couple login/mdp n'est pas présent dans la table user
                // il faudra retourner 'r'
                $retour = 'd';
            } else {   // le couple login/mdp est présent dans la table user
                // il faudra retourner 'v'
                if ($requete -> fetchColumn() === $mdp){
                    $retour = 's';
                }else{
                    $retour = 'w';
                }
                $requete->closeCursor();
//                $retour = 'v';
            }
            return $retour;
        } catch (Exception $exc) {
            print "Erreur : " . $exc->getMessage() . "<br/>";
            die();
        }
    }
}