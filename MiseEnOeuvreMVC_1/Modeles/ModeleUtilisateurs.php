<?php

/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

require_once '../Modeles/Modele.php';

class ModeleUtilisateurs extends Modele {
    public function obtenirUtilisateurs(){
        try {
            $requete = $this->bdd->query('SELECT u.nom, u.prenom, DATE_FORMAT(u.dateNaissance, "%d/%m/%Y") AS dateFormatee,'
                    . 'v.ville_nom, r.region_nom, d.departement_nom FROM utilisateurs u '
                    . 'JOIN villes v ON u.ville_id = v.ville_id JOIN departements d '
                    . 'ON v.ville_departement_id = d.departement_id JOIN regions r '
                    . 'ON departement_region_id = regions_id;');
            $requete->execute();
            $lesUtilisateurs = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)){
                array_push($lesUtilisateurs, $reponse);
            }
            $requete->closeCursor();
            return $lesUtilisateurs;
            
        } catch (Exception $exc) {
            print_r("<br/> Problème obtenirUtilisateurs :" . $exc->getMessage());
            die();
        }
    }
}