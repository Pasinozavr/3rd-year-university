$(function(){
	$(document).ready(function(){
		
		
	});
	$("#send").click(function(){
		
		//var s = $('form').serializeArray();
		//console.log(document.forms["forma"].elements["login"].value);
		
		if(document.forms["forma"].elements["login"].value == "")
		{
			alert("Я так и знал. Нельзя доверять человеку без имени.");return;
		}
		
		
		
		
		
		
		$.ajax({
            url: 'server_login.php',
            data: 'login='+document.forms["forma"].elements["login"].value
            + '&password='+document.forms["forma"].elements["pass"].value,
            dataType: 'json',
            type: 'post',
            complete: function(){

            },
            error:function(xhr){
                console.error( xhr.responseText );
				$("#answer").html(xhr.responseText);
            },
            

            
        })

	});
	
});