<?php


$login_enter=($_POST[login]);
$password_enter=($_POST[password]);


$link = mysql_connect('localhost', 'root', '')
    or die('Не удалось соединиться: ' . mysql_error());

mysql_select_db('pasha') or die('Что-то наша БД накрылась болью экзистенциализма. Соре.');

$query = 'SELECT * FROM users';
$result = mysql_query($query) or die('Мда, лажа бывает разная: ' . mysql_error());

while ($line = mysql_fetch_array($result, MYSQL_ASSOC))
{
	if($login_enter==$password_enter){
		echo("Такое читерство больше не проканает, но сейчас можешь пройти. Ур^^");exit;
	}
	if(($login_enter==$line['user'])&&($password_enter==$line['password']))
	{
		echo("Ну и ладно. Го дружить?^^");exit;
	}
	
}
echo("Му-ха-ха-ха, ты никогда не узнаешь пароль, му-ха-ха-ха!");

	//$hi="hi, ";
	//$hi=$hi.$_POST["login"];
	//return json_encode($hi);

	?>
