<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHPWebPage.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Mise à jour date de naissance</title>
        <script src="js/bootstrap.min.js"></script>
    <link href="css/bootstrap.min.css" rel="stylesheet" type="text/css"/>
    </head>
    <body>
        <div class="p-3">
        <h5>Choisir une nouvelle date de naissance</h5>
        <form action="mise_a_jour_date_naissance.php" method="post">
            <input type="hidden" id="personne_id" name="personne_id">
            <label for="nouvelle_date_naissance">Nouvelle date de naissance :</label>
            <input type="date" id="nouvelle_date_naissance" name="nouvelle_date_naissance" required>
            <button type="submit">Mettre à jour</button>
        </form>
        <?php
        // put your code here
        ?>
        </div>
    </body>
</html>
