﻿$(function(){
	$(document).ready(function(){
		
		
	});


	$("#send").click(function(){
		
		//var s = $('form').serializeArray();
		//console.log(document.forms["forma"].elements["login"].value);
		
		
		
		
		if(document.forms["forma"].elements["pass"].value != document.forms["forma"].elements["conf_pass"].value)
		{
			alert("Я так и знал, что блефуешь. Пше на тебя.");return;
		}
		if(document.forms["forma"].elements["pass"].value == "")
		{
			alert("Совсем народ обленился. Ну накалякай что-то в графе пароля..");return;
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
			alert("Мда, у тебя, видимо, проблемы с самоидентификацией. Придумай, плес, ник.");return;
		}
		if(document.forms["forma"].elements["email"].value == "")
		{
			alert("Я понимаю, что ты моешься без мыла, но e-mail все же введи");return;
		}
		if(document.forms["forma"].elements["phone"].value == "")
		{
			alert("Лол, в наш-то век и без телефона? Да кого ты обманываешь.");return;
		}
		
		var a =document.forms["forma"].elements["phone"].value
		if(!(/\d{3}-\d{3}-\d{2}-\d{2}/.test(a)))
		{
			alert("Тебе что, слабо черточки в нужные места поставить?");return;
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