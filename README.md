# FP_SISOP19_B14

##SOAL

Buatlah program C yang menyerupai crontab menggunakan daemon dan thread. Ada sebuah file crontab.data untuk menyimpan config dari crontab. Setiap ada perubahan file tersebut maka secara otomatis program menjalankan config yang sesuai dengan perubahan tersebut tanpa perlu diberhentikan. Config hanya sebatas * dan 0-9 (tidak perlu /,- dan yang lainnya)

## Langkah-langkah Penyelesaian

- Mebuat Struct yang berisi 
    -integer tgl : yang nantinya untuk menyimpan day of month;
    - integer bul : yang nantinya untuk menyimpan month;
    - integer jam : yang nantinya untuk menyimpan hour;
    - integer hari : yang nantinya untuk menyimpan day of week;
    - integer men : yang nantinya untuk menyimpan minute;
    - char path[256] : yang nantinya untuk menyimpan perintah pada crontab
 
- Membuat variable bertipe FILE lalu membuka file itu untuk diread;
- Membuat char s1[10], s2[10] , s3[10], s4[10], s5[10], s6[256] yang masing-masing akan argumen pada file "crontab.data"
        - s1 = dimasukkan di line[ind].men; 
        - s2 = dimasukkan di line[ind].jam;
        - s3 = dimasukkan di line[ind].tgl;
        - s4 = dimasukkan di line[ind].bul;
        - s5 = dimasukkan di line[ind].hari;
        - s6 = dimasukkan di line[ind].path;
        
- Lalu dicek di setiap argumen s1-s5 , 
  - jika :  
        - s1 =  '*' 
        - s2 =  '*' 
        - s3 =  '*' 
        - s4 =  '*' 
        - s5 =  '*' 
  maka bernilai -1;
  - jika tidak maka setiap nilai s1-s5 di (atoi) //converts the string argument str to an integer
 
 - Dan untuk setiap-setiap nilai dari s1-s5 disimpan di
  
- Setelah itu mengecek kembali jika 
  - line[ind].men = timeinfo->tm_min atau line[ind].men= -1
  - line[ind].jam = timeinfo->tm_hour atau line[ind].jam= -1
  - line[ind].tgl  = timeinfo->tm_mday atau line[ind].tgl= -1
  - line[ind].bul = timeinfo->tm_mon+1 atau line[ind].bul= -1
  - line[ind].hari = timeinfo->tm_wday atau line[ind].hari= -1
    maka perintah di "line[ind].path" dijalankan

  
  
