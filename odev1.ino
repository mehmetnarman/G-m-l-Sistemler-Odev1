bool basildi=false;   //butona basılıp basılmadığını kontrol etmek
int bekleme=500;      
int butonlar[]={13,12,11};
int ledler[]={6,7,8,9,10};

void setup() { //Giriş ve çıkışların belirlendiği reset düğmesine basıldıktan sonra yada program çalıştırıldıktan sonra birkez çalışan mototdur.
  for(int i=0; i<3; i++){  // butonlar dizisindeki pinler giriş olarak ayarlandı
    pinMode(butonlar[i],INPUT);
  }
  for(int i=0; i<5; i++){   // ledler dizisindeki pinler çıkış olarak ayarlandı
    pinMode(ledler[i],OUTPUT);
  }
}

void loop() {   //sonsuz döngü
  if((digitalRead(butonlar[0])) && !basildi){  //hiçbir butona basılmadıysa ve sıfır indisli butonlar dizisindeki pin enerjilendiyse birinci senaryoyu gerçekleştir
    basildi=true;     //butona basıldığı için diğer koşulları gerçekleştirmemesi için boolean değişkenine true değeri atandı
    for(int i=4; i>=0; i--){    //4.indisten başlayarak diğer indislere dolayısıyla pinlere enerji veren döngü yazıldı
      digitalWrite(ledler[i],HIGH); 
      delay(bekleme);
    }
    for(int i=0; i<5; i++){   //tüm pinlerin enerjisi kesildi
      digitalWrite(ledler[i],LOW);
  } basildi=false;
  }
  if((digitalRead(butonlar[1])) && !basildi){   //hiçbir butona basılmadıysa ve bir indisli butonlar dizisindeki pin enerjilendiyse ikinci senaryoyu gerçekleştir
    basildi=true;
    for(int i=0; i<5; i++){         //0.indisten başlanarak tüm indislere yani pinlere enerji verildi
      digitalWrite(ledler[i],HIGH);
      delay(bekleme);
    }
    for(int i=0; i<5; i++){
      digitalWrite(ledler[i],LOW);
  } basildi=false;
  }
  if((digitalRead(butonlar[2])) && !basildi){   //hiçbir butona basılmadıysa ve iki indisli butonlar dizisindeki pin enerjilendiyse ikinci senaryoyu gerçekleştir
    basildi=true;
    for(int j=0; j<10; j++){      //alttaki işlemleri 10 kez gerçekleştirmek için yapılan döngü
      for(int i=0; i<5; i++){     //aynı anda çıkış verildi 
        digitalWrite(ledler[i],HIGH);
      }
      delay(bekleme);           //bekleme süresince beklendi
      for(int i=0; i<5; i++){   //pinlerin enerjisi kesildi
        digitalWrite(ledler[i],LOW);
      }
      delay(bekleme);
    }
    basildi=false;
  }
}
