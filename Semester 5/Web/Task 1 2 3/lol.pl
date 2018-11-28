#!/usr/local/perl/bin/perl

local ($buffer, @pairs, $pair, $name, $value, %FORM);

# ����������� ���������
$ENV{'REQUEST_METHOD'} =~ tr/a-z/A-Z/;
if ($ENV{'REQUEST_METHOD'} eq "POST"){
	read(STDIN, $buffer, $ENV{'CONTENT_LENGTH'});
	}

# ��������� ������ ������� �� ���� ���� ����/�������� 
@pairs = split(/&/, $buffer);
foreach $pair (@pairs) {
	($name, $value) = split(/=/, $pair);
	$value =~ tr/+/ /;
	$value =~ s/%(..)/pack("C", hex($1))/eg;
	$FORM{$name} = $value; # ��������� ������ � ������
	}

# ���������� ���������
print "Content-type: text/html\n\n";

# ���������� ����������
print <<HTML;
<html>
	<head><title>CGI say Hello</title></head>
<body>
	<h1>Hello, $FORM{user} from $FORM{from}!</h1>
</body>
HTML
exit; 