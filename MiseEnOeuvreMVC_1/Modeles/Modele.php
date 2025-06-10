<?php

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHP.php to edit this template
 */

require_once '../Modeles/config.inc.php';

class Modele {

    protected $bdd;

    public function __construct() {
        try {
            $dsn = 'mysql:host=' . SERVEUR_BDD . ';dbname=' . NOM_DE_LA_BASE;
            $this->bdd = new PDO($dsn, LOGIN, MOTDE_PASSE);
            $this->bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $this->bdd->exec("set names utf8");
            
        } catch (Exception $ex) {
            echo ('</br> Erreur de connexion au serveur BDD : '. $ex->getMessage());
            die();
        }
    }
    
    public function __destruct(){
        unset($this->bdd);
    }
}
