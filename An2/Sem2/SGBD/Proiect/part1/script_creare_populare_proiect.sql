 DROP TABLE carti CASCADE CONSTRAINTS
/

DROP TABLE genuri CASCADE CONSTRAINTS
/

DROP TABLE voturi_gen CASCADE CONSTRAINTS
/

DROP TABLE autori CASCADE CONSTRAINTS
/

DROP TABLE users CASCADE CONSTRAINTS
/

CREATE TABLE carti (
	id INT NOT NULL PRIMARY KEY,
	titlu VARCHAR2(126) NOT NULL,
	id_gen INT NOT NULL,
	id_autor INT NOT NULL,
	an INT NOT NULL,
	ISBN INT NOT NULL,
	rating FLOAT NOT NULL,
	voturi INT NOT NULL
)
/

CREATE TABLE genuri (
	id INT NOT NULL PRIMARY KEY,
	gen VARCHAR2(126) NOT NULL
)
/

CREATE TABLE voturi_gen (
	id INT NOT NULL PRIMARY KEY,
	id_gen INT NOT NULL,
	id_user INT NOT NULL
)
/

CREATE TABLE autori (
	id INT NOT NULL PRIMARY KEY,
	nume VARCHAR2(126) NOT NULL
)
/

CREATE TABLE users (
	id INT NOT NULL PRIMARY KEY,
	nume VARCHAR2(126) NOT NULL,	
	prenume VARCHAR2(126) NOT NULL,
    parola VARCHAR2(126) NOT NULL
)	
/

--cod inspirat din scriptul initial de creare a tabelelor pentru studenti
SET SERVEROUTPUT ON;
DECLARE
	TYPE varr IS VARRAY(1000) OF varchar2(255);

	lista_nume varr := varr('Ababei','Acasandrei','Adascalitei','Afanasie','Agafitei','Agape','Aioanei','Alexandrescu','Alexandru','Alexe','Alexii','Amarghioalei','Ambroci','Andonesei','Andrei','Andrian','Andrici','Andronic','Andros','Anghelina','Anita','Antochi','Antonie','Apetrei','Apostol','Arhip','Arhire','Arteni','Arvinte','Asaftei','Asofiei','Aungurenci','Avadanei','Avram','Babei','Baciu','Baetu','Balan','Balica','Banu','Barbieru','Barzu','Bazgan','Bejan','Bejenaru','Belcescu','Belciuganu','Benchea','Bilan','Birsanu','Bivol','Bizu','Boca','Bodnar','Boistean','Borcan','Bordeianu','Botezatu','Bradea','Braescu','Budaca','Bulai','Bulbuc-aioanei','Burlacu','Burloiu','Bursuc','Butacu','Bute','Buza','Calancea','Calinescu','Capusneanu','Caraiman','Carbune','Carp','Catana','Catiru','Catonoiu','Cazacu','Cazamir','Cebere','Cehan','Cernescu','Chelaru','Chelmu','Chelmus','Chibici','Chicos','Chilaboc','Chile','Chiriac','Chirila','Chistol','Chitic','Chmilevski','Cimpoesu','Ciobanu','Ciobotaru','Ciocoiu','Ciofu','Ciornei','Citea','Ciucanu','Clatinici','Clim','Cobuz','Coca','Cojocariu','Cojocaru','Condurache','Corciu','Corduneanu','Corfu','Corneanu','Corodescu','Coseru','Cosnita','Costan','Covatariu','Cozma','Cozmiuc','Craciunas','Crainiceanu','Creanga','Cretu','Cristea','Crucerescu','Cumpata','Curca','Cusmuliuc','Damian','Damoc','Daneliuc','Daniel','Danila','Darie','Dascalescu','Dascalu','Diaconu','Dima','Dimache','Dinu','Dobos','Dochitei','Dochitoiu','Dodan','Dogaru','Domnaru','Dorneanu','Dragan','Dragoman','Dragomir','Dragomirescu','Duceac','Dudau','Durnea','Edu','Eduard','Eusebiu','Fedeles','Ferestraoaru','Filibiu','Filimon','Filip','Florescu','Folvaiter','Frumosu','Frunza','Galatanu','Gavrilita','Gavriliuc','Gavrilovici','Gherase','Gherca','Ghergu','Gherman','Ghibirdic','Giosanu','Gitlan','Giurgila','Glodeanu','Goldan','Gorgan','Grama','Grigore','Grigoriu','Grosu','Grozavu','Gurau','Haba','Harabula','Hardon','Harpa','Herdes','Herscovici','Hociung','Hodoreanu','Hostiuc','Huma','Hutanu','Huzum','Iacob','Iacobuta','Iancu','Ichim','Iftimesei','Ilie','Insuratelu','Ionesei','Ionesi','Ionita','Iordache','Iordache-tiroiu','Iordan','Iosub','Iovu','Irimia','Ivascu','Jecu','Jitariuc','Jitca','Joldescu','Juravle','Larion','Lates','Latu','Lazar','Leleu','Leon','Leonte','Leuciuc','Leustean','Luca','Lucaci','Lucasi','Luncasu','Lungeanu','Lungu','Lupascu','Lupu','Macariu','Macoveschi','Maftei','Maganu','Mangalagiu','Manolache','Manole','Marcu','Marinov','Martinas','Marton','Mataca','Matcovici','Matei','Maties','Matrana','Maxim','Mazareanu','Mazilu','Mazur','Melniciuc-puica','Micu','Mihaela','Mihai','Mihaila','Mihailescu','Mihalachi','Mihalcea','Mihociu','Milut','Minea','Minghel','Minuti','Miron','Mitan','Moisa','Moniry-abyaneh','Morarescu','Morosanu','Moscu','Motrescu','Motroi','Munteanu','Murarasu','Musca','Mutescu','Nastaca','Nechita','Neghina','Negrus','Negruser','Negrutu','Nemtoc','Netedu','Nica','Nicu','Oana','Olanuta','Olarasu','Olariu','Olaru','Onu','Opariuc','Oprea','Ostafe','Otrocol','Palihovici','Pantiru','Pantiruc','Paparuz','Pascaru','Patachi','Patras','Patriche','Perciun','Perju','Petcu','Pila','Pintilie','Piriu','Platon','Plugariu','Podaru','Poenariu','Pojar','Popa','Popescu','Popovici','Poputoaia','Postolache','Predoaia','Prisecaru','Procop','Prodan','Puiu','Purice','Rachieru','Razvan','Reut','Riscanu','Riza','Robu','Roman','Romanescu','Romaniuc','Rosca','Rusu','Samson','Sandu','Sandulache','Sava','Savescu','Schifirnet','Scortanu','Scurtu','Sfarghiu','Silitra','Simiganoschi','Simion','Simionescu','Simionesei','Simon','Sitaru','Sleghel','Sofian','Soficu','Sparhat','Spiridon','Stan','Stavarache','Stefan','Stefanita','Stingaciu','Stiufliuc','Stoian','Stoica','Stoleru','Stolniceanu','Stolnicu','Strainu','Strimtu','Suhani','Tabusca','Talif','Tanasa','Teclici','Teodorescu','Tesu','Tifrea','Timofte','Tincu','Tirpescu','Toader','Tofan','Toma','Toncu','Trifan','Tudosa','Tudose','Tuduri','Tuiu','Turcu','Ulinici','Unghianu','Ungureanu','Ursache','Ursachi','Urse','Ursu','Varlan','Varteniuc','Varvaroi','Vasilache','Vasiliu','Ventaniuc','Vicol','Vidru','Vinatoru','Vlad','Voaides','Vrabie','Vulpescu','Zamosteanu','Zazuleac');

	lista_prenume_fete varr := varr('Adina','Alexandra','Alina','Ana','Anca','Anda','Andra','Andreea','Andreia','Antonia','Bianca','Camelia','Claudia','Codrina','Cristina','Daniela','Daria','Delia','Denisa','Diana','Ecaterina','Elena','Eleonora','Elisa','Ema','Emanuela','Emma','Gabriela','Georgiana','Ileana','Ilona','Ioana','Iolanda','Irina','Iulia','Iuliana','Larisa','Laura','Loredana','Madalina','Malina','Manuela','Maria','Mihaela','Mirela','Monica','Oana','Paula','Petruta','Raluca','Sabina','Sanziana','Simina','Simona','Stefana','Stefania','Tamara','Teodora','Theodora','Vasilica','Xena');

	lista_prenume_baieti varr := varr('Adrian','Alex','Alexandru','Alin','Andreas','Andrei','Aurelian','Beniamin','Bogdan','Camil','Catalin','Cezar','Ciprian','Claudiu','Codrin','Constantin','Corneliu','Cosmin','Costel','Cristian','Damian','Dan','Daniel','Danut','Darius','Denise','Dimitrie','Dorian','Dorin','Dragos','Dumitru','Eduard','Elvis','Emil','Ervin','Eugen','Eusebiu','Fabian','Filip','Florian','Florin','Gabriel','George','Gheorghe','Giani','Giulio','Iaroslav','Ilie','Ioan','Ion','Ionel','Ionut','Iosif','Irinel','Iulian','Iustin','Laurentiu','Liviu','Lucian','Marian','Marius','Matei','Mihai','Mihail','Nicolae','Nicu','Nicusor','Octavian','Ovidiu','Paul','Petru','Petrut','Radu','Rares','Razvan','Richard','Robert','Roland','Rolland','Romanescu','Sabin','Samuel','Sebastian','Sergiu','Silviu','Stefan','Teodor','Teofil','Theodor','Tudor','Vadim','Valentin','Valeriu','Vasile','Victor','Vlad','Vladimir','Vladut');

	lista_titluri varr := varr ('Maitreyi','O mie noua sute optzeci si patru','Batranul si marea','Portretul lui Dorian Gray','Don Quijote de la Mancha','Ferma animalelor','Lolita','Micul print','Puterea prezentului','Inteligenta emotionala','Pe culmile disperarii','Tropicul capricornului','Strainul','Procesul','Alchimistul','Amintiri din pribegie','Harry Potter');

	lista_genuri varr := varr ('autobiografie','romanta','nuvela','fictiune','satira','dezvoltare','filozofie','fantezie');

	lista_autori varr := varr ('Mircea Eliade','George Orwell','Ernest Hemingway','Miguel de Cervantes','Vladimir Nabokov','Antoine de Saint-Exupery','Eckhart Tolle','Daniel Goleman','Emil Cioran','Henry Miller','Albert Camus','Paulo Coelho','Neagu Djuvara','J. K. Rowling');

	v_nume VARCHAR2(255);
	v_prenume VARCHAR2(255);
	v_prenume1 VARCHAR2(255);
	v_prenume2 VARCHAR2(255);
    v_titlu VARCHAR2(255);
    v_id_gen INT;
    v_id_autor INT;
    v_an INT;
    v_isbn INT;
    v_rating FLOAT;
    v_voturi INT;
    v_id_user INT;
  
BEGIN
	DBMS_OUTPUT.PUT_LINE('Inserarea a 100.000 useri.');
	FOR v_i IN 1..100000 LOOP
        v_nume := lista_nume(TRUNC(DBMS_RANDOM.VALUE(0,lista_nume.count))+1);
        IF (DBMS_RANDOM.VALUE(0,100)<50) THEN      
            v_prenume1 := lista_prenume_fete(TRUNC(DBMS_RANDOM.VALUE(0,lista_prenume_fete.count))+1);
            LOOP
                v_prenume2 := lista_prenume_fete(TRUNC(DBMS_RANDOM.VALUE(0,lista_prenume_fete.count))+1);
                exit when v_prenume1<>v_prenume2;
            END LOOP;
       		ELSE
         		v_prenume1 := lista_prenume_baieti(TRUNC(DBMS_RANDOM.VALUE(0,lista_prenume_baieti.count))+1);
         		LOOP
                	v_prenume2 := lista_prenume_baieti(TRUNC(DBMS_RANDOM.VALUE(0,lista_prenume_baieti.count))+1);
            		exit when v_prenume1<>v_prenume2;
         		END LOOP;       
       		END IF;

	     	IF (DBMS_RANDOM.VALUE(0,100)<60) THEN  
        		IF LENGTH(v_prenume1 || ' ' || v_prenume2) <= 20 THEN
          			v_prenume := v_prenume1 || ' ' || v_prenume2;
        		END IF;
        		else 
           			v_prenume:=v_prenume1;
      		END IF; 
		INSERT INTO users VALUES (v_i, v_nume, v_prenume, 'hash');
	END LOOP;
  
    DBMS_OUTPUT.PUT_LINE('Inserarea a 100.000 carti.');
    FOR v_i IN 1..100000 LOOP
        v_titlu := lista_titluri(TRUNC(DBMS_RANDOM.VALUE(0,lista_titluri.count))+1);
        v_id_gen := TRUNC(DBMS_RANDOM.VALUE(0,lista_genuri.count))+1;
        v_id_autor := TRUNC(DBMS_RANDOM.VALUE(0,lista_autori.count))+1;
        v_an := TRUNC(DBMS_RANDOM.VALUE(1200, 2019));
        v_isbn := TRUNC(DBMS_RANDOM.VALUE(1000000000000, 9999999999999));
        v_rating := DBMS_RANDOM.VALUE(1, 5);
        v_voturi := TRUNC(DBMS_RANDOM.VALUE(500, 10000));
        INSERT INTO carti VALUES (v_i, v_titlu, v_id_gen, v_id_autor, v_an, v_isbn, v_rating, v_voturi);
	END LOOP;

    DBMS_OUTPUT.PUT_LINE('Simularea a 1.000.000 voturi de callback.');
    FOR v_i IN 1..1000000 LOOP
        v_titlu := lista_titluri(TRUNC(DBMS_RANDOM.VALUE(0,lista_titluri.count))+1);
        v_id_gen := TRUNC(DBMS_RANDOM.VALUE(0,lista_genuri.count))+1;
        v_id_user := TRUNC(DBMS_RANDOM.VALUE(1,100000))+1;
        INSERT INTO voturi_gen VALUES (v_i, v_id_gen, v_id_user);
	END LOOP;

	DBMS_OUTPUT.PUT_LINE('Inserarea genurilor.');
	FOR v_i IN 1..8 LOOP
		INSERT INTO genuri VALUES (v_i, lista_genuri(v_i));
	END LOOP;
    
    DBMS_OUTPUT.PUT_LINE('Inserarea autorilor.');
	FOR v_i IN 1..14 LOOP
		INSERT INTO autori VALUES (v_i, lista_autori(v_i));
	END LOOP;

END;
