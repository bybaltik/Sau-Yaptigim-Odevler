<?php 
 
 if(isset($_POST['submit'])){
     $v1=$_POST ['isimsoyisim'];
     $boşluk="\n";
     echo "Adiniz soyadiniz : ". $v1; 
     echo"<br> ";
    echo $boşluk;

 $v2=$_POST ['ogrno'];
 echo"Ogrenci no'nuz: " . $v2;
 echo"<br> ";
 echo $boşluk;

 $v5=$_POST ['konu'];
 echo"Konu : " . $v5;
 echo"<br> ";
 echo $boşluk;

 $v3=$_POST ['email'];
 echo"E-mail adresiniz : ". $v3;
 echo"<br> ";
 echo $boşluk;

 $v4=$_POST ['mesaj'];
 echo"Mesajınız : ". $v4;
 echo"<br> ";
 echo $boşluk;

 
 }
 
 
 
 ?>