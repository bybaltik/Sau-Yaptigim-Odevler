<?php
$kadi ="b221211145@sakarya.edu.tr";
$şifre="b221211145";

if (($_POST['username']==$kadi) and ($_POST['password']==$şifre) ){
    echo "HOŞGELDİN b221211145 SENİ ANA SAYFAYA YÖNLENDİRİYORUM.";

    header("refresh:5;Anasayfa.html");
}
else if(!$_POST)
{
    echo("Veri girmeden sayfaya giriş yapmış bulunmaktasınız !");
}
else {


    (header('location: Login.php'));
}


?>