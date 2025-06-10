<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHPWebPage.php to edit this template
-->
<html>
    <head>

        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
        echo '<pre>';
        //print_r($_POST);
        echo '</pre>';   //Que voyez vous dans la barre d’url ? le mot de passe et la confirmation du mot de passe
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            // Traitement pour le nom
            echo 'Nom : ' . filter_input(INPUT_POST, "nom") . '</br>';
            echo 'Prenom : ' . filter_input(INPUT_POST, "prenom") . '</br>';
            echo 'E-mail : ' . filter_input(INPUT_POST, "email", FILTER_VALIDATE_EMAIL) . '</br>';
            echo 'Site : ' . filter_input(INPUT_POST, "site") . '</br>';
            echo 'Sexe : ' . filter_input(INPUT_POST, "sexe") . '</br>';
            echo 'Condition : ' . filter_input(INPUT_POST, "condition") . '</br>';
            echo 'Version : ' . filter_input(INPUT_POST, "version") . '</br>';
            echo 'Login : ' . filter_input(INPUT_POST, "login") . '</br>';
            echo 'Mot de Passe : ' . filter_input(INPUT_POST, "mdp") . '</br>';
            $mdp = filter_input(INPUT_POST, "mdp");
            echo 'Confirmation du Mot de passe : ' . filter_input(INPUT_POST, "confmdp") . '</br>';
            $confmdp = filter_input(INPUT_POST, "confmdp");
        }
        require_once './fonctions.inc.php';
        verifierDoubleMotPasse($mdp, $confmdp);
        echo '<br/>';
        verifierDoubleMotPasse2($mdp, $confmdp);
        $pers=filter_input(INPUT_POST, "nom") ."/" .filter_input(INPUT_POST, "prenom");
        //echo "the cake is a lie : [$pers]<br/>";
        setcookie("personne", $pers, time()+3600);
        echo $_COOKIE["personne"];
        ?>
    </body>
</html>
