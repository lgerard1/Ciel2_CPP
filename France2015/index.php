<!DOCTYPE html>
<html>
    <head>
        <title>TD2_PHP_PDO</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">

        <script src="js/bootstrap.min.js"></script>
        <link href="css/bootstrap.min.css" rel="stylesheet" type="text/css"/>
    </head>
    <body>
        <div class="container pt-5">
            <div class="row">
                <div class="col-md-6">
                    <h5>Code Postal</h5>
                    <form action="traitement.php" method="post">
                        <label for="code_postal">Code Postal :</label>
                        <input type="text" id="code_postal" name="code_postal" maxlength="5" pattern="[0-9]{5}" required>
                        <button type="submit">Rechercher</button>
                    </form>
                </div>
                <div class="col-md-6">
                    <h5>Liste des personnes</h5>
                    <form action="DateDeNaissance.php" method="post">
                        <label for="personne">Choisissez une personne :</label>
                        <?php
                        require_once("PHP/france2015.php");
                        genererListePersonne();
                        ?>

                        <button type="submit">Envoyer</button>
                </div>
                <div class="pt-3 col-md-12">
                    <?php
                    afficherPersonnes();
                    ?>

                    </form>
                </div>
            </div>
        </div>
    </body>
</html>
