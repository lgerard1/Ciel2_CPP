<?php

function verifierDoubleMotPasse($mdp, $confmdp){
    if($mdp == $confmdp){
        echo 'OK';
    }else{
        echo 'KO';
    }
}
function verifierDoubleMotPasse2($mdp, $confmdp){
    if($mdp == $confmdp){
        return true;
    }else{
        return false;
    }
}

