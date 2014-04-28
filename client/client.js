errorInfo= function(text)
{
    $("#output").
        css("background", "yellow").
        html(text);
}

info= function(text)
{
    $("#output").
        css("background", "green").
        html(text);
}

info2= function(text)
{
    $("#output2").
        css("background", "green").
        html(text);
}

callAjaxGet = function(destination, outputDest)
{
    $.ajax({
        type: "GET",
        dataType: "text",
        cache: false,
        url: destination,
        success: function(data) {
        	$(outputDest).replaceWith(data);
        } 
    });
    return false;
}


check = function()
{
    var playername = $("#playername").val();

    
    if(!playername)
    {
        errorInfo("Podaj imię!");
        return false;
    }
    else if(playername.match(/\d/))
    {
        errorInfo("W imieniu nie powinno byc liczb!");
        return false;
    }
    else if(playername.match(/\s/))
    {
        errorInfo("W imieniu nie powinno być znaków białych!");
        return false;
    }
    else 
    {
        info("Prawidłowo");
        return true;
        
    }    
}

login = function()
{
    if (check())
    {
        callAjaxGet("http://" + window.location.host + "/calculation/login.py", "#login_info");
        return true;
    }
    return false;
}

startGame = function()
{
    if (login())
    {
        callAjaxGet("http://" + window.location.host + "/calculation/initGame.py", "#game_info");
    }
}


