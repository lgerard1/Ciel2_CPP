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
        require_once 'php/config.inc.php';
        try {
            $dsn = 'mysql:host= ' . SERVEUR_BDD . 'dbname= ' . NOM_DE_LA_BASE;
            $pdo = new PDO($dsn, LOGIN, MOTDE_PASSE);
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $pdo->exec("set names utf8");
            if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') == 'GET') {
                $nom = filter_input(INPUT_GET, 'nom');
                echo "nom = $nom";
                if (!empty($nom)) {
                    $idcours = filter_input(INPUT_GET, 'numCours', FILTER_VALIDATE_INT);
                    if ($idCours === false) {
                        echo "ID du cours n'est pas dans le bon format ou non présent";
                    } else {
                        $requete = $pdo->prepare("INSERT INTO participants (nom,idcours) VALUES (:nom,:idCours);");
                        $requete->bindParam(':nom', $nom);
                        $requete->bindParam(':idCours', $idCours, PDO::PARAM_INT);
                        $requete->execute();
                        echo "L'insertion à été réalisé avec succès.";
                    }
                } else {
                    echo "le nom n'a pas été renseigné";
                }
            }
        } catch (Exception $ex) {
            print "La connexion a échoué : " . $excep->getMessage() . "</br>";
            die();
        }
        ?>
    </body>
</html>
