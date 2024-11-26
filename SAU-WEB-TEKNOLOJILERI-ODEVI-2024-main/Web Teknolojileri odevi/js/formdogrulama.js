function formDogrulama(){

    var isimsoyisim=document.iletisimformu.isimsoyisim;
    var ogrNo=document.iletisimformu.ogrNo;
    var konu=document.iletisimformu.konu;
    var email=document.iletisimformu.email;
    var mesaj=document.iletisimformu.mesaj;

    if(isimsoyisim_dogrulama(isimsoyisim,3,35)){
        if(ogrNo_dogrulama(ogrNo)){
            if(emailKontrol(email)){
                return true;
            }
        }
    }
    

}

function isimsoyisim_dogrulama(isimsoyisim, mx, my) {
	var isimsoyisim_len = isimsoyisim.value.length;
	if (isimsoyisim_len !=0 && (isimsoyisim_len >= my || isimsoyisim_len < mx)) {
		alert("JS  ile kontrol isim soyisim için izin verilen karakter " + mx + " - " + my +" sayıları arasında olmalıdır.");
		isimsoyisim.focus();
		return false;
	}
	else if(isimsoyisim_len==0){
		alert("JS  ile kontrol isim soyisim boş bırakılmamalı !!");
		return false;
	}
	return true;
}

function ogrNo_dogrulama(ogrNo) {
	var ogrNoformat = /^[bBgG]\d{9}$/;
	if (ogrNo.value.match(ogrNoformat)) {
		return true;
	}
	else {
		if(ogrNo.value.length==0){
			alert("JS  ile kontrol öğrenci numarasi  boş bırakılmamalı !!");
		}
		else {
			alert("JS  ile kontrol  geçersiz ogrenci numarası girdiniz!");
		}
		
		return false;
	}
	return true;
}

function emailKontrol(email) {
	var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
	if (email.value.match(mailformat)) {
		return true;
	}
	else {
		if(email.value.length==0){
			alert("JS  ile kontrol email boş bırakılmamalı !!");
		}
		else {
			alert("JS  ile kontrol email istenilen formatta değil !!");
		}
		
		return false;
	}
	return true;
} 