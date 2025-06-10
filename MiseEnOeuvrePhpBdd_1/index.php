<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Project/PHP/PHPProject.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Liste des cours</title>
    
    </head>
    <body>
        <?php
        require_once 'php/config.inc.php';
        try {
            $dsn = 'mysql:host= ' . SERVEUR_BDD . 'dbname= '. NOM_DE_LA_BASE;
            $pdo = new PDO($dsn, LOGIN, MOTDE_PASSE);
            $pdo ->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $pdo ->exec("set names utf8");
            $requete = $pdo->query("select * from cours;");
            
            echo '<h2>Liste des cours</h2>\n';
            
            echo "<table border = '1'>" ;
            echo '<tr><th>ID</th><th>Titre</th><th>Niveau</th><th>Session</th></tr>\n';
            
            while ($ligne = $requete->fetch(PDO::FETCH_ASSOC)){
                echo '<tr>';
                echo '<td>' . $ligne['idcours'] . "</td>";
                echo '<td>' . $ligne['titre'] . "</td>";
                echo '<td>' . $ligne['niveau'] . "</td>";
                echo '<td>' . $ligne['session'] . "</td>";
                echo '</tr>\n';
            }
            echo '</table>\n';
} catch (Exception $ex) {
            print "La connexion a échoué : ".$excep->getMessage() . "</br>";
            die();
}
        ?>
    </body>
</html>
