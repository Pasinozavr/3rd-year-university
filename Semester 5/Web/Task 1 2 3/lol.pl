#!/usr/local/perl/bin/perl

local ($buffer, @pairs, $pair, $name, $value, %FORM);

# Анализируем окружение
$ENV{'REQUEST_METHOD'} =~ tr/a-z/A-Z/;
if ($ENV{'REQUEST_METHOD'} eq "POST"){
	read(STDIN, $buffer, $ENV{'CONTENT_LENGTH'});
	}

# Разделяем строку запроса на пары вида ключ/значение 
@pairs = split(/&/, $buffer);
foreach $pair (@pairs) {
	($name, $value) = split(/=/, $pair);
	$value =~ tr/+/ /;
	$value =~ s/%(..)/pack("C", hex($1))/eg;
	$FORM{$name} = $value; # Сохраняем данные в массив
	}

# Отправляем заголовок
print "Content-type: text/html\n\n";

# Отправляем гипертекст
print <<HTML;
<html>
	<head><title>CGI say Hello</title></head>
<body>
	<h1>Hello, $FORM{user} from $FORM{from}!</h1>
</body>
HTML
exit; 