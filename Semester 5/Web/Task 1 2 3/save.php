$name=$_POST['name'];
$pass=$_POST['pass'];
$result=mysql_query("INSER INTO table(name, pass) VALUES ('$name', '$pass')");
if($resul == 'true')
{echo "Вы авторизованы";}
else{echo "Вы не авторизованы";}