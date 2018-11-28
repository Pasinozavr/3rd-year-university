$(function(){
	$(document).ready(function(){
		
		
	});


	$("#send").click(function(){
		
		//var s = $('form').serializeArray();
		//console.log(document.forms["forma"].elements["login"].value);
		
		
		
		
		if(document.forms["forma"].elements["pass"].value != document.forms["forma"].elements["conf_pass"].value)
		{
			alert("Не похоже.");return;
		}
		if(document.forms["forma"].elements["pass"].value == "")
		{
			alert("Слишком пусто.");return;
		}
		
		var myRe = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).*$/;
		var myArray = myRe.exec(document.forms["forma"].elements["pass"].value);
		if(myArray==null)
		{
			$("#pass_error").removeClass("invisible");
			return;
		}
		else
			$("#pass_error").addClass("invisible");
		
		
		
		if(document.forms["forma"].elements["login"].value == "")
		{
			alert("Безымянный.");return;
		}
		if(document.forms["forma"].elements["email"].value == "")
		{
			alert("Куда?");return;
		}
		if(document.forms["forma"].elements["phone"].value == "")
		{
			alert("Куда? [x2]");return;
		}
		
		var a =document.forms["forma"].elements["phone"].value
		if(!(/\d{3}-\d{3}-\d{2}-\d{2}/.test(a)))
		{
			alert("Че-то не так.");return;
		}
		var a =document.forms["forma"].elements["email"].value
		if(!(/(.)*@(.)*\.(.)*/.test(a)))
		{
				return;
		}
		
		
		
		var str="";
		if(document.forms["forma"].elements["ch1"].checked) str=str+'&ch1='+document.forms["forma"].elements["ch1"].value;
		if(document.forms["forma"].elements["ch2"].checked) str=str+'&ch2='+document.forms["forma"].elements["ch2"].value;
		console.log(str);
		$.ajax({
            url: 'cgi-bin/perl_cgi.pl',
            data: 'login='+document.forms["forma"].elements["login"].value
            + '&password='+document.forms["forma"].elements["pass"].value
            + '&answer='+document.forms["forma"].elements["answer"].value
			+ str
			+ '&email='+document.forms["forma"].elements["email"].value
			+ '&phone='+document.forms["forma"].elements["phone"].value,
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
	
$("#send2").click(function(){
alert("По голове себе постучи.");return;
})
});