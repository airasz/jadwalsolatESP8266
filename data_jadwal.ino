
void perhitungan(){
	j_1= j/10;
	j_2=j%10;
	m1=mn/10;
	m2=mn%10;
	d1=d/10;
	d2=d%10;
 	if (t1 ==1 && lt1 == false){ 
   		ct1+=1; if (ct1>19) {k=2;tm=1;ct1=1; lt1= true ;} }
  	else ct1=1;
  	if (t3==1 && lt3== false ){
  		k=3;tm=1; lt3= true; }
 	if (t2==1 && lt2== false ){
 		k=3;tm=2; lt3= true;
 	}

 	//baris1= "Jam : "+String (j_1)+String (j_2) +":"+ String (m1)+String (m2)+":"+String (d1)+String (d2) ;
    	if (jshalat==true){ }
		else
			baris2 = hari + " " + String(tg) + "-" + String(bl) + "-20" + String(th);

		ct3 += 1;
		if (ct3 > 22)
		{
			ct3 = 1;
			ht += 1;
			if (ht > 8)
				ht = 1;}
    		if (ht==1)   baris2 = hari+ " "+ String (tg) +"-"+ String (bl)+"-20"+ String (th) ;
	     	if (ht==2)   baris2 = "Jadwal Shalat" ;
	     	if (ht==3)   baris2 = "Isya :" + isya;
	     	if (ht==4)   baris2 = "Shubuh :" + shubuh; ;
	     	if (ht==5)   baris2 = "Zhuhur :"+ zhuhur ;
	     	if (ht==6)   baris2 = "Ashar :"+ ashar ;
	     	if (ht==7)   baris2 ="Maghrib :" + maghrib ;
	     	if (ht==8)   baris2 = "Terima Kasih" ;
	//Serial.println("perhitungan");

    // Serial.print("date time =");
    // Serial.print(j);
    // Serial.print("-");
    // Serial.print(mn);
    // Serial.print("-");
    // Serial.print(d);
    // Serial.print("-");
    // Serial.print(tg);
    // Serial.print("-");
    // Serial.print(bl);
    // Serial.print("-");
    // Serial.println(th);
    	data_bulan();
}


void data_bulan(){
	//if (tg != tg2 ) { 
		tg2=tg;
		tgl=tg ; 
		Bulan =bl;

		if (Bulan ==1) {
			if (tgl < 5 ) { sh = 418; dz = 1159; as =1525 ; mg = 1813 ; is = 1928 ;}
			if (tgl >4 ){ sh = 420; dz = 1201; as =1527 ; mg = 1814 ; is = 1929 ;}
			if (tgl>9 ){ sh = 423; dz = 1203; as =1528 ; mg = 1816 ; is = 1931 ;}
			if (tgl >14 ){ sh = 426; dz = 1205; as =1529 ; mg = 1818 ; is = 1932 ;}
			if (tgl >19 ){ sh = 420; dz = 1207; as =1530 ; mg = 1819 ; is = 1932 ;}
			if (tgl > 24 ){ sh = 432; dz = 1208; as =1530 ; mg = 1820 ; is = 1932 ;}
			if (tgl>27 ) { sh = 433; dz = 1209; as =1530 ; mg = 1820 ; is = 1933 ;}
			if (tgl>30 ){ sh = 434; dz = 1209; as =1530 ; mg = 1820 ; is = 1933 ;}
		}

		if (Bulan ==2) {
			if (tgl<5) { sh = 435; dz = 1209; as =1529 ; mg = 1820 ; is = 1932 ;}
			if (tgl>4) { sh = 437; dz = 1210; as =1528 ; mg = 1820 ; is = 1931 ;}
			if (tgl>9){ sh = 438; dz = 1210; as =1526 ; mg = 1820 ; is = 1930 ;}
			if (tgl>14){ sh = 440; dz = 1210; as =1523 ; mg = 1819 ; is = 1929 ;}
			if (tgl>19){ sh = 441; dz = 1209; as =1520 ; mg = 1818 ; is = 1928 ;}
			if (tgl>24) { sh = 442; dz = 1208; as =1517 ; mg = 1816 ; is = 1925 ;}
			if (tgl>27){ sh = 442; dz = 1208; as =1514 ; mg = 1814 ; is = 1924 ;}
		}

		if (Bulan ==3) {
			if (tgl<5){ sh = 442; dz = 1208; as =1512 ; mg = 1814 ; is = 1922 ;}
			if (tgl>4){ sh = 442; dz = 1207; as =1507 ; mg = 1813 ; is = 1921 ;}
			if (tgl>9) { sh = 441; dz = 1206; as =1509 ; mg = 1811 ; is = 1919 ;}
			if (tgl>14){ sh = 441; dz = 1204; as =1511 ; mg = 1808 ; is = 1916 ;}
			if (tgl>19){ sh = 441; dz = 1203; as =1512 ; mg = 1806 ; is = 1914 ;}
			if (tgl>24) { sh = 440; dz = 1201; as =1513 ; mg = 1804 ; is = 1912 ;}
			if (tgl>30) { sh = 439; dz = 1159; as =1513 ; mg = 1801 ; is = 1909 ;}
		}

		if (Bulan ==4) {
			if 		(tgl==1){sh = 440;  dz = 1159; as = 1514; mg = 1800; is = 1910 ;}
			else if (tgl==2){sh = 440;  dz = 1159; as = 1514; mg = 1800; is = 1909;}
			else if (tgl==3){sh = 440;  dz = 1158; as = 1514; mg = 1759; is = 1909;}
			else if (tgl==4){sh = 440;  dz = 1158; as = 1514; mg = 1759; is = 1908;}
			else if (tgl==5){sh = 440;  dz = 1158; as = 1514; mg = 1758; is = 1908;}
			else if (tgl==6){sh = 439;  dz = 1158; as = 1514; mg = 1758; is = 1907;}
			else if (tgl==7){sh = 439;  dz = 1157; as = 1514; mg = 1758; is = 1907;}
			else if (tgl==8){sh = 439;  dz = 1157; as = 1514; mg = 1757; is = 1907;}
			else if (tgl==9){sh = 439;  dz = 1157; as = 1514; mg = 1757; is = 1906;}
			else if (tgl==10){sh = 439;  dz = 1156; as = 1514; mg = 1756; is = 1906;}
			else if (tgl==11){sh = 439;  dz = 1156; as = 1514; mg = 1756; is = 1905;}
			else if (tgl==12){sh = 438;  dz = 1156; as = 1514; mg = 1755; is = 1905;}
			else if (tgl==13){sh = 438;  dz = 1156; as = 1514; mg = 1755; is = 1905;}
			else if (tgl==14){sh = 438;  dz = 1155; as = 1514; mg = 1755; is = 1904;}
			else if (tgl==15){sh = 438;  dz = 1155; as = 1514; mg = 1754; is = 1904;}
			else if (tgl==16){sh = 438;  dz = 1155; as = 1514; mg = 1754; is = 1904;}
			else if (tgl==17){sh = 438;  dz = 1155; as = 1514; mg = 1753; is = 1903;}
			else if (tgl==18){sh = 438;  dz = 1154; as = 1514; mg = 1753; is = 1903;}
			else if (tgl==19){sh = 437;  dz = 1154; as = 1514; mg = 1753; is = 1903;}
			else if (tgl==20){sh = 437;  dz = 1154; as = 1514; mg = 1752; is = 1902;}
			else if (tgl==21){sh = 437;  dz = 1154; as = 1514; mg = 1752; is = 1902;}
			else if (tgl==22){sh = 437;  dz = 1154; as = 1514; mg = 1751; is = 1902;}
			else if (tgl==23){sh = 437;  dz = 1153; as = 1514; mg = 1751; is = 1902;}
			else if (tgl==24){sh = 437;  dz = 1153; as = 1514; mg = 1751; is = 1901;}
			else if (tgl==25){sh = 437;  dz = 1153; as = 1514; mg = 1750; is = 1901;}
			else if (tgl==26){sh = 436;  dz = 1153; as = 1514; mg = 1750; is = 1901;}
			else if (tgl==27){sh = 436;  dz = 1153; as = 1514; mg = 1750; is = 1901;}
			else if (tgl==28){sh = 436;  dz = 1152; as = 1513; mg = 1749; is = 1900;}
			else if (tgl==29){sh = 436;  dz = 1152; as = 1513; mg = 1749; is = 1900;}
			else if (tgl==30){sh = 436;  dz = 1152; as = 1513; mg = 1749; is = 1900;}


		}

		if (Bulan ==5) {
			if		(tgl==1) {sh=436; dz = 1152; as = 1513; mg = 1749; is = 1900;}
			else if (tgl==2) {sh=436; dz = 1152; as = 1513; mg = 1748; is = 1900;}
			else if (tgl==3) {sh=436; dz = 1152; as = 1513; mg = 1748; is = 1900;}
			else if (tgl==4) {sh=436; dz = 1152; as = 1513; mg = 1748; is = 1859;}
			else if (tgl==5) {sh=436; dz = 1152; as = 1513; mg = 1748; is = 1859;}
			else if (tgl==6) {sh=435; dz = 1151; as = 1513; mg = 1747; is = 1859;}
			else if (tgl==7) {sh=435; dz = 1151; as = 1513; mg = 1747; is = 1859;}
			else if (tgl==8) {sh=435; dz = 1151; as = 1513; mg = 1747; is = 1859;}
			else if (tgl==9) {sh=435; dz = 1151; as = 1513; mg = 1747; is = 1859;}
			else if (tgl==10) {sh=435; dz = 1151; as = 1513; mg = 1747; is = 1859;}
			else if (tgl==11) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==12) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==13) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==14) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==15) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==16) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==17) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==18) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==19) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==20) {sh=435; dz = 1151; as = 1513; mg = 1746; is = 1859;}
			else if (tgl==21) {sh=435; dz = 1151; as = 1513; mg = 1745; is = 1859;}
			else if (tgl==22) {sh=435; dz = 1151; as = 1513; mg = 1745; is = 1859;}
			else if (tgl==23) {sh=435; dz = 1151; as = 1513; mg = 1745; is = 1859;}
			else if (tgl==24) {sh=435; dz = 1151; as = 1514; mg = 1745; is = 1859;}
			else if (tgl==25) {sh=436; dz = 1152; as = 1514; mg = 1745; is = 1859;}
			else if (tgl==26) {sh=436; dz = 1152; as = 1514; mg = 1745; is = 1859;}
			else if (tgl==27) {sh=436; dz = 1152; as = 1514; mg = 1745; is = 1859;}
			else if (tgl==28) {sh=436; dz = 1152; as = 1514; mg = 1745; is = 1859;}
			else if (tgl==29) {sh=436; dz = 1152; as = 1514; mg = 1746; is = 1859;}
			else if (tgl==30) {sh=436; dz = 1152; as = 1514; mg = 1746; is = 1900;}
			else if (tgl==31) {sh=436; dz = 1152; as = 1514; mg = 1746; is = 1900;}

		}
		if (Bulan ==6) {
			if 		(tgl==1){sh=436;  dz = 1152;  as = 1514;  mg = 1746;  is = 1900;}
			else if (tgl==2){sh=436;  dz = 1153;  as = 1515;  mg = 1746;  is = 1900;}
			else if (tgl==3){sh=437;  dz = 1153;  as = 1515;  mg = 1746;  is = 1900;}
			else if (tgl==4){sh=437;  dz = 1153;  as = 1515;  mg = 1746;  is = 1900;}
			else if (tgl==5){sh=437;  dz = 1153;  as = 1515;  mg = 1746;  is = 1901;}
			else if (tgl==6){sh=437;  dz = 1153;  as = 1515;  mg = 1746;  is = 1901;}
			else if (tgl==7){sh=437;  dz = 1153;  as = 1515;  mg = 1746;  is = 1901;}
			else if (tgl==8){sh=437;  dz = 1154;  as = 1515;  mg = 1746;  is = 1901;}
			else if (tgl==9){sh=438;  dz = 1154;  as = 1516;  mg = 1747;  is = 1901;}
			else if (tgl==10){sh=438;  dz = 1154;  as = 1516;  mg = 1747;  is = 1902;}
			else if (tgl==11){sh=438;  dz = 1154;  as = 1516;  mg = 1747;  is = 1902;}
			else if (tgl==12){sh=438;  dz = 1154;  as = 1516;  mg = 1747;  is = 1902;}
			else if (tgl==13){sh=438;  dz = 1155;  as = 1516;  mg = 1747;  is = 1902;}
			else if (tgl==14){sh=439;  dz = 1155;  as = 1517;  mg = 1747;  is = 1902;}
			else if (tgl==15){sh=439;  dz = 1155;  as = 1517;  mg = 1748;  is = 1903;}
			else if (tgl==16){sh=439;  dz = 1155;  as = 1517;  mg = 1748;  is = 1903;}
			else if (tgl==17){sh=439;  dz = 1155;  as = 1517;  mg = 1748;  is = 1903;}
			else if (tgl==18){sh=439;  dz = 1156;  as = 1517;  mg = 1748;  is = 1903;}
			else if (tgl==19){sh=440;  dz = 1156;  as = 1518;  mg = 1748;  is = 1903;}
			else if (tgl==20){sh=440;  dz = 1156;  as = 1518;  mg = 1749;  is = 1904;}
			else if (tgl==21){sh=440;  dz = 1156;  as = 1518;  mg = 1749;  is = 1904;}
			else if (tgl==22){sh=440;  dz = 1157;  as = 1518;  mg = 1749;  is = 1904;}
			else if (tgl==23){sh=440;  dz = 1157;  as = 1519;  mg = 1749;  is = 1904;}
			else if (tgl==24){sh=441;  dz = 1157;  as = 1519;  mg = 1750;  is = 1904;}
			else if (tgl==25){sh=441;  dz = 1157;  as = 1519;  mg = 1750;  is = 1904;}
			else if (tgl==26){sh=441;  dz = 1157;  as = 1519;  mg = 1750;  is = 1904;}
			else if (tgl==27){sh=441;  dz = 1158;  as = 1519;  mg = 1750;  is = 1904;}
			else if (tgl==28){sh=442;  dz = 1158;  as = 1520;  mg = 1750;  is = 1904;}
			else if (tgl==29){sh=442;  dz = 1158;  as = 1520;  mg = 1751;  is = 1906;}
			else if (tgl==30){sh=442;  dz = 1158;  as = 1520;  mg = 1751;  is = 1906;}


			//===== temporary for ponorogo region========//
			// if		(tgl==1)  {sh=1120; dz=1134	; as=1455; mg=1725	; is=1839;}
			// else if	(tgl==2)  {sh=1120; dz=1134	; as=1455; mg=1725	; is=1839;}
			// else if	(tgl==3)  {sh=1120; dz=1134	; as=1455; mg=1725	; is=1839;}
			// else if	(tgl==4)  {sh=1120; dz=1134	; as=1455; mg=1725	; is=1840;}
			// else if	(tgl==5)  {sh=1121; dz=1135	; as=1455; mg=1725	; is=1840;}
			// else if	(tgl==6)  {sh=1121; dz=1135	; as=1456; mg=1725	; is=1840;}
			// else if	(tgl==7)  {sh=1121; dz=1135	; as=1456; mg=1725	; is=1840;}
			// else if	(tgl==8)  {sh=1121; dz=1135	; as=1456; mg=1725	; is=1840;}
			// else if	(tgl==9)  {sh=1121; dz=1135	; as=1456; mg=1726	; is=1840;}
		}

		else if (Bulan ==7) {
			if 		(tgl==01) {sh=442; dz=1158; as=1520; mg=1751; is=1906; }
			else if (tgl==2) {sh=442; dz=1159; as=1520; mg=1751; is=1906; }
			else if (tgl==3) {sh=443; dz=1159; as=1521; mg=1752; is=1906; }
			else if (tgl==4) {sh=443; dz=1159; as=1521; mg=1752; is=1907; }
			else if (tgl==5) {sh=443; dz=1159; as=1521; mg=1752; is=1907; }
			else if (tgl==6) {sh=443; dz=1159; as=1521; mg=1752; is=1907; }
			else if (tgl==7) {sh=443; dz=1200; as=1521; mg=1752; is=1907; }
			else if (tgl==8) {sh=443; dz=1200; as=1522; mg=1753; is=1907; }
			else if (tgl==9) {sh=444; dz=1200; as=1522; mg=1753; is=1907; }
			else if (tgl==10) {sh=444; dz=1200; as=1522; mg=1753; is=1907; }
			else if (tgl==11) {sh=444; dz=1200; as=1522; mg=1753; is=1908; }
			else if (tgl==12) {sh=444; dz=1200; as=1522; mg=1753; is=1908; }
			else if (tgl==13) {sh=444; dz=1200; as=1522; mg=1754; is=1908; }
			else if (tgl==14) {sh=444; dz=1201; as=1523; mg=1754; is=1908; }
			else if (tgl==15) {sh=445; dz=1201; as=1523; mg=1754; is=1908; }
			else if (tgl==16) {sh=445; dz=1201; as=1523; mg=1754; is=1908; }
			else if (tgl==17) {sh=445; dz=1201; as=1523; mg=1754; is=1908; }
			else if (tgl==18) {sh=445; dz=1201; as=1523; mg=1755; is=1908; }
			else if (tgl==19) {sh=445; dz=1201; as=1523; mg=1755; is=1908; }
			else if (tgl==20) {sh=445; dz=1201; as=1523; mg=1755; is=1909; }
			else if (tgl==21) {sh=445; dz=1201; as=1523; mg=1755; is=1909; }
			else if (tgl==22) {sh=445; dz=1201; as=1523; mg=1755; is=1909; }
			else if (tgl==23) {sh=445; dz=1201; as=1523; mg=1755; is=1909; }
			else if (tgl==24) {sh=445; dz=1201; as=1523; mg=1755; is=1909; }
			else if (tgl==25) {sh=445; dz=1201; as=1523; mg=1756; is=1909; }
			else if (tgl==26) {sh=445; dz=1201; as=1523; mg=1756; is=1909; }
			else if (tgl==27) {sh=445; dz=1201; as=1523; mg=1756; is=1909; }
			else if (tgl==28) {sh=445; dz=1201; as=1523; mg=1756; is=1909; }
			else if (tgl==29) {sh=445; dz=1201; as=1523; mg=1756; is=1909; }
			else if (tgl==30) {sh=445; dz=1201; as=1523; mg=1756; is=1909; }
			else if (tgl==31) {sh=445; dz=1201; as=1523; mg=1756; is=1909; }


		}

		else if (Bulan ==8) {
			if		(tgl==1){ sh=445; dz=1201; as=1523	; mg=1756	; is=1909;}
			else if(tgl==2){ sh=445; dz=1201	; as=1523	; mg=1756	; is=1909;}
			else if(tgl==3){ sh=445; dz=1201	; as=1523	; mg=1756	; is=1909;}
			else if(tgl==4){ sh=445; dz=1201	; as=1523	; mg=1756	; is=1909;}
			else if(tgl==5){ sh=445; dz=1201	; as=1523	; mg=1756	; is=1908;}
			else if(tgl==6){ sh=445; dz=1201	; as=1523	; mg=1756	; is=1908;}
			else if(tgl==7){ sh=445; dz=1201	; as=1523	; mg=1756	; is=1908;}
			else if(tgl==8){ sh=445; dz=1201	; as=1522	; mg=1757	; is=1908;}
			else if(tgl==9){ sh=444; dz=1200	; as=1522	; mg=1757	; is=1908;}
			else if(tgl==10){ sh=444; dz=1200	; as=1522	; mg=1757	; is=1908;}
			else if(tgl==11){ sh=444; dz=1200	; as=1522	; mg=1756	; is=1908;}
			else if(tgl==12){ sh=444; dz=1200	; as=1522	; mg=1756	; is=1908;}
			else if(tgl==13){ sh=444; dz=1200	; as=1521	; mg=1756	; is=1908;}
			else if(tgl==14){ sh=444; dz=1200	; as=1521	; mg=1756	; is=1908;}
			else if(tgl==15){ sh=443; dz=1159	; as=1521	; mg=1756	; is=1907;}
			else if(tgl==16){ sh=443; dz=1159	; as=1521	; mg=1756	; is=1907;}
			else if(tgl==17){ sh=443; dz=1159	; as=1520	; mg=1756	; is=1907;}
			else if(tgl==18){ sh=443; dz=1159	; as=1520	; mg=1756	; is=1907;}
			else if(tgl==19){ sh=442; dz=1159	; as=1520	; mg=1756	; is=1907;}
			else if(tgl==20){ sh=442; dz=1158	; as=1519	; mg=1756	; is=1907;}
			else if(tgl==21){ sh=442; dz=1158	; as=1519	; mg=1756	; is=1906;}
			else if(tgl==22){ sh=441; dz=1158	; as=1518	; mg=1756	; is=1906;}
			else if(tgl==23){ sh=441; dz=1158	; as=1518	; mg=1756	; is=1906;}
			else if(tgl==24){ sh=441; dz=1157	; as=1518	; mg=1756	; is=1906;}
			else if(tgl==25){ sh=441; dz=1157	; as=1517	; mg=1756	; is=1906;}
			else if(tgl==26){ sh=440; dz=1157	; as=1517	; mg=1755	; is=1906;}
			else if(tgl==27){ sh=440; dz=1157	; as=1516	; mg=1755	; is=1905;}
			else if(tgl==28){ sh=439; dz=1156	; as=1516	; mg=1755	; is=1905;}
			else if(tgl==29){ sh=439; dz=1156	; as=1515	; mg=1755	; is=1905;}
			else if(tgl==30){ sh=439; dz=1156	; as=1515	; mg=1755	; is=1905;}
			else if(tgl==31){ sh=438; dz=1155	; as=1514	; mg=1755	; is=1905;}  



		}

		else if (Bulan ==9) {
			if		(tgl==1){ sh=438; dz=1155; as=1514; mg=1755; is=1904; }
			else if (tgl==2){ sh=438; dz=1155; as=1513; mg=1754; is=1904; }
			else if (tgl==3){ sh=437; dz=1155; as=1513; mg=1754; is=1904; }
			else if (tgl==4){ sh=437; dz=1154; as=1512; mg=1754; is=1904; }
			else if (tgl==5){ sh=436; dz=1154; as=1512; mg=1754; is=1903; }
			else if (tgl==6){ sh=436; dz=1154; as=1511; mg=1754; is=1903; }
			else if (tgl==7){ sh=435; dz=1153; as=1510; mg=1754; is=1903; }
			else if (tgl==8){ sh=435; dz=1153; as=1510; mg=1753; is=1903; }
			else if (tgl==9){ sh=434; dz=1153; as=1509; mg=1753; is=1903; }
			else if (tgl==10){ sh=434; dz=1152; as=1508; mg=1753; is=1902; }
			else if (tgl==11){ sh=433; dz=1152; as=1508; mg=1753; is=1902; }
			else if (tgl==12){ sh=433; dz=1151; as=1507; mg=1753; is=1902; }
			else if (tgl==13){ sh=432; dz=1151; as=1506; mg=1753; is=1902; }
			else if (tgl==14){ sh=432; dz=1151; as=1506; mg=1752; is=1902; }
			else if (tgl==15){ sh=431; dz=1150; as=1505; mg=1752; is=1901; }
			else if (tgl==16){ sh=431; dz=1150; as=1504; mg=1752; is=1901; }
			else if (tgl==17){ sh=430; dz=1150; as=1503; mg=1752; is=1901; }
			else if (tgl==18){ sh=430; dz=1149; as=1503; mg=1752; is=1901; }
			else if (tgl==19){ sh=429; dz=1149; as=1502; mg=1751; is=1901; }
			else if (tgl==20){ sh=429; dz=1149; as=1501; mg=1751; is=1900; }
			else if (tgl==21){ sh=428; dz=1148; as=1500; mg=1751; is=1900; }
			else if (tgl==22){ sh=428; dz=1148; as=1500; mg=1751; is=1900; }
			else if (tgl==23){ sh=427; dz=1148; as=1559; mg=1751; is=1900; }
			else if (tgl==24){ sh=427; dz=1147; as=1558; mg=1751; is=1900; }
			else if (tgl==25){ sh=426; dz=1147; as=1557; mg=1750; is=1859; }
			else if (tgl==26){ sh=426; dz=1146; as=1556; mg=1750; is=1859; }
			else if (tgl==27){ sh=425; dz=1146; as=1555; mg=1750; is=1859; }
			else if (tgl==28){ sh=425; dz=1146; as=1555; mg=1750; is=1859; }
			else if (tgl==29){ sh=424; dz=1145; as=1554; mg=1750; is=1859; }
			else if (tgl==30){ sh=424; dz=1145; as=1553; mg=1750; is=1859; }

		}

		else if (Bulan ==10) {
			if 		(tgl==1) { sh=423; dz=1145; as=1452; mg=1749; is=1859; }
			else if (tgl==2) { sh=422; dz=1144; as=1451; mg=1749; is=1859; }
			else if (tgl==3) { sh=422; dz=1144; as=1450; mg=1749; is=1858; }
			else if (tgl==4) { sh=421; dz=1144; as=1449; mg=1749; is=1858; }
			else if (tgl==5) { sh=421; dz=1144; as=1448; mg=1749; is=1858; }
			else if (tgl==6) { sh=420; dz=1143; as=1447; mg=1749; is=1858; }
			else if (tgl==7) { sh=420; dz=1143; as=1446; mg=1749; is=1858; }
			else if (tgl==8) { sh=419; dz=1143; as=1445; mg=1748; is=1858; }
			else if (tgl==9) { sh=419; dz=1142; as=1444; mg=1748; is=1858; }
			else if (tgl==10) { sh=418; dz=1142; as=1443; mg=1748; is=1858; }
			else if (tgl==11) { sh=418; dz=1142; as=1444; mg=1748; is=1858; }
			else if (tgl==12) { sh=417; dz=1142; as=1444; mg=1748; is=1858; }
			else if (tgl==13) { sh=417; dz=1141; as=1445; mg=1748; is=1858; }
			else if (tgl==14) { sh=416; dz=1141; as=1445; mg=1748; is=1858; }
			else if (tgl==15) { sh=416; dz=1141; as=1446; mg=1748; is=1858; }
			else if (tgl==16) { sh=415; dz=1141; as=1446; mg=1748; is=1858; }
			else if (tgl==17) { sh=415; dz=1140; as=1447; mg=1748; is=1858; }
			else if (tgl==18) { sh=414; dz=1140; as=1447; mg=1748; is=1858; }
			else if (tgl==19) { sh=414; dz=1140; as=1448; mg=1748; is=1858; }
			else if (tgl==20) { sh=413; dz=1140; as=1448; mg=1748; is=1858; }
			else if (tgl==21) { sh=413; dz=1140; as=1449; mg=1748; is=1858; }
			else if (tgl==22) { sh=412; dz=1139; as=1449; mg=1748; is=1858; }
			else if (tgl==23) { sh=412; dz=1139; as=1450; mg=1748; is=1859; }
			else if (tgl==24) { sh=411; dz=1139; as=1450; mg=1748; is=1859; }
			else if (tgl==25) { sh=411; dz=1139; as=1451; mg=1748; is=1859; }
			else if (tgl==26) { sh=411; dz=1139; as=1451; mg=1748; is=1859; }
			else if (tgl==27) { sh=410; dz=1139; as=1452; mg=1748; is=1859; }
			else if (tgl==28) { sh=410; dz=1139; as=1452; mg=1748; is=1859; }
			else if (tgl==29) { sh=409; dz=1139; as=1453; mg=1748; is=1859; }

		}


		else if (Bulan ==11) {
			if (tgl==1) { dz=408; dz=1138; as=1454; mg=1748; is=1900; }
			else if (tgl==2) { dz=408; dz=1138; as=1454; mg=1748; is=1900; }
			else if (tgl==3) { dz=408; dz=1138; as=1455; mg=1749; is=1901; }
			else if (tgl==4) { dz=407; dz=1138; as=1455; mg=1749; is=1901; }
			else if (tgl==5) { dz=407; dz=1138; as=1456; mg=1749; is=1901; }
			else if (tgl==6) { dz=407; dz=1138; as=1456; mg=1749; is=1901; }
			else if (tgl==7) { dz=407; dz=1138; as=1457; mg=1749; is=1902; }
			else if (tgl==8) { dz=406; dz=1138; as=1457; mg=1749; is=1902; }
			else if (tgl==9) { dz=406; dz=1138; as=1458; mg=1750; is=1902; }
			else if (tgl==10) { dz=406; dz=1139; as=1458; mg=1750; is=1903; }
			else if (tgl==11) { dz=406; dz=1139; as=1459; mg=1750; is=1903; }
			else if (tgl==12) { dz=406; dz=1139; as=1459; mg=1750; is=1904; }
			else if (tgl==13) { dz=405; dz=1139; as=1500; mg=1751; is=1904; }
			else if (tgl==14) { dz=405; dz=1139; as=1500; mg=1751; is=1904; }
			else if (tgl==15) { dz=405; dz=1139; as=1501; mg=1751; is=1905; }
			else if (tgl==16) { dz=405; dz=1139; as=1501; mg=1752; is=1905; }
			else if (tgl==17) { dz=405; dz=1139; as=1502; mg=1752; is=1906; }
			else if (tgl==18) { dz=405; dz=1140; as=1502; mg=1752; is=1906; }
			else if (tgl==19) { dz=405; dz=1140; as=1503; mg=1752; is=1907; }
			else if (tgl==20) { dz=405; dz=1140; as=1503; mg=1753; is=1907; }
			else if (tgl==21) { dz=405; dz=1140; as=1504; mg=1753; is=1907; }
			else if (tgl==22) { dz=405; dz=1141; as=1504; mg=1754; is=1908; }
			else if (tgl==23) { dz=405; dz=1141; as=1505; mg=1754; is=1908; }
			else if (tgl==24) { dz=405; dz=1141; as=1505; mg=1754; is=1909; }
			else if (tgl==25) { dz=405; dz=1141; as=1506; mg=1755; is=1909; }
			else if (tgl==26) { dz=405; dz=1142; as=1506; mg=1755; is=1910; }
			else if (tgl==27) { dz=405; dz=1142; as=1507; mg=1756; is=1910; }
			else if (tgl==28) { dz=405; dz=1142; as=1507; mg=1756; is=1911; }
			else if (tgl==29) { dz=405; dz=1143; as=1508; mg=1756; is=1912; }
			else if (tgl==30) { dz=405; dz=1143; as=1508; mg=1757; is=1912; }

		}
		else if (Bulan ==12) {
			if 		(tgl==11) { sh=405; dz=1143; as=1509; mg=1757; is=1913; } 
			else if (tgl==12) { sh=405; dz=1144; as=1509; mg=1758; is=1913; } 
			else if (tgl==13) { sh=406; dz=1144; as=1510; mg=1758; is=1914; } 
			else if (tgl==14) { sh=406; dz=1144; as=1510; mg=1759; is=1914; } 
			else if (tgl==15) { sh=406; dz=1145; as=1511; mg=1759; is=1915; } 
			else if (tgl==16) { sh=406; dz=1145; as=1512; mg=1800; is=1915; } 
			else if (tgl==17) { sh=407; dz=1146; as=1512; mg=1800; is=1916; } 
			else if (tgl==18) { sh=407; dz=1146; as=1513; mg=1801; is=1917; } 
			else if (tgl==19) { sh=407; dz=1147; as=1513; mg=1801; is=1917; } 
			else if (tgl==10) { sh=407; dz=1147; as=1514; mg=1802; is=1918; } 
			else if (tgl==11) { sh=408; dz=1147; as=1514; mg=1802; is=1918; } 
			else if (tgl==12) { sh=408; dz=1148; as=1515; mg=1803; is=1919; } 
			else if (tgl==13) { sh=408; dz=1148; as=1515; mg=1803; is=1919; } 
			else if (tgl==14) { sh=409; dz=1149; as=1516; mg=1804; is=1920; } 
			else if (tgl==15) { sh=409; dz=1149; as=1516; mg=1804; is=1920; } 
			else if (tgl==16) { sh=410; dz=1150; as=1517; mg=1805; is=1921; } 
			else if (tgl==17) { sh=410; dz=1150; as=1518; mg=1805; is=1921; } 
			else if (tgl==18) { sh=410; dz=1151; as=1518; mg=1806; is=1922; } 
			else if (tgl==19) { sh=411; dz=1151; as=1519; mg=1806; is=1923; } 
			else if (tgl==20) { sh=411; dz=1152; as=1519; mg=1807; is=1923; } 
			else if (tgl==21) { sh=412; dz=1152; as=1520; mg=1807; is=1924; } 
			else if (tgl==22) { sh=412; dz=1153; as=1520; mg=1808; is=1924; } 
			else if (tgl==23) { sh=413; dz=1153; as=1521; mg=1808; is=1925; } 
			else if (tgl==24) { sh=413; dz=1154; as=1521; mg=1809; is=1925; } 
			else if (tgl==25) { sh=414; dz=1154; as=1522; mg=1809; is=1926; } 
			else if (tgl==26) { sh=414; dz=1155; as=1522; mg=1810; is=1926; } 
			else if (tgl==27) { sh=415; dz=1155; as=1523; mg=1810; is=1926; } 
			else if (tgl==28) { sh=415; dz=1156; as=1523; mg=1811; is=1927; } 
			else if (tgl==29) { sh=416; dz=1156; as=1523; mg=1811; is=1927; } 
			else if (tgl==30) { sh=416; dz=1157; as=1524; mg=1811; is=1928; } 
			else if (tgl==31) { sh=417; dz=1157; as=1524; mg=1812; is=1928; } 

		}
		if(b1!= baris1 || b2!=baris2 ) {
  			b1= baris1 ; b2=baris2 ;
			// lcd.clear() ;
			// // lcd.setCursor(0,0);
			// // lcd.print(b1);
			// lcd.setCursor(0,1);
			// lcd.print(b2);
  		}


		jamshubuh=sh/100;
		jamshubuh1=jamshubuh/10;
		jamshubuh2=jamshubuh%10 ;
		menitshubuh =sh%100;
		menitshubuh1 =menitshubuh /10;
		menitshubuh2 =menitshubuh %10;
		shubuh =  String(jamshubuh1) + String(jamshubuh2) +":" + String(menitshubuh1) + String(menitshubuh2);

		//	04
		
		jamzhuhur =dz/100;
		jamzhuhur1= jamzhuhur/10;
		jamzhuhur2=jamzhuhur%10 ;
		menitzhuhur=dz%100;
		menitzhuhur1 =menitzhuhur /10;
		menitzhuhur2 =menitzhuhur %10;
		zhuhur = String(jamzhuhur1) + String(jamzhuhur2) +":" + String(menitzhuhur1) + String(menitzhuhur2);
		
		jamashar =as /100;
		jamashar1= jamashar/10;
		jamashar2=jamashar%10 ;
		menitashar=as%100;
		menitashar1 =menitashar /10;
		menitashar2 =menitashar %10;
		ashar = String(jamashar1) + String(jamashar2) +":" + String(menitashar1) + String(menitashar2);
		
		jammaghrib =mg /100;
		jammaghrib1= jammaghrib/10;
		jammaghrib2=jammaghrib%10 ;
		menitmaghrib =mg %100;
		menitmaghrib1 =menitmaghrib /10; menitmaghrib2 =menitmaghrib %10;
		maghrib = String(jammaghrib1) + String(jammaghrib2) +":" + String(menitmaghrib1) + String(menitmaghrib2);
		
		jamisya =is /100;
		jamisya1= jamisya/10;
		jamisya2=jamisya%10 ;
		menitisya =is %100;
		menitisya1 =menitisya /10;
		menitisya2 =menitisya %10;
		isya = String(jamisya1) + String(jamisya2) +":" + String(menitisya1) + String(menitisya2);


	//}
	//Serial.println("data_bulan");
}