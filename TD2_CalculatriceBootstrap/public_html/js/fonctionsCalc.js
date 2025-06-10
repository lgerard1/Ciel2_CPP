$(document).ready(function ()
{
    var expression = 0;
    $(".btn-secondary, .btn-primary").click(function () {

        if (expression === 0 || expression === "0") {
            expression = $(this).text();
            $('#afficheur').val(expression);
        } else {
            
            expression += $(this).text();
            $('#afficheur').val(expression);
        }
    });
    
    $(".btn-danger").click(function () {
        expression = 0;
        $('#afficheur').val(expression);
    });
    
    $(".btn-info").click(function () {
        expression = expression.replace("×", "*");
        console.log("test1");
        expression = expression.replace("÷" , "/");
        console.log("test2");
        var resultat = eval(expression);
        $('#afficheur').val(resultat);
        
    });
        
});