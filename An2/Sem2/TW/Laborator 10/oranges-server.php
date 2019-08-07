<?php
/* Un server SOAP scris in PHP5 oferind metode de manipulare a sortimentelor de portocale

   Autor: Sabin-Corneliu Buraga - https://profs.info.uaic.ro/~busaco/
   Ultima actualizare: 22 aprilie 2019
*/
try {
  // nu oferim nicio descriere WSDL, stabilim URI-ul serviciului
  $server = new SoapServer(null, 
    array('uri' => 'http://web.info/porto') // spatiul de nume folosit
  );
  // adaugam metodele implementate
  $server->addFunction('getQuantity');
  //$server->addFunction('addToSum');
  //$server->addFunction('vectorSum');
  $server->addFunction('getSum');
  $server->addFunction('getArraySum');
  // asteptam cereri SOAP
  $server->handle();   
} catch (SOAPFault $exception) {
  echo 'An exception occurred: ' . $exception;
}

// functie care furnizeaza cantitatea dintr-un sortiment de portocale
// (rezultatul intors va fi eterogen)
function getQuantity ($product) {
	// uzual, vom efectua o interogare SQL, o procesare de date (CSV, JSON, XML,...),
  // o invocare a altui serviciu Web etc.
	switch ($product) {
	 	 case 'gray': return 33;
	 	 case 'blue': return 74;
	 	 default    : return 'n/a';
	}
}

/*function addToSum ($number1, $number2) {
  $sum=$number1+$number2;
  return $sum;
}

function vectorSum ($vector_numbs) {
  return array_sum($vector_numbs);
}*/

function getSum ($a, $b) {
  $sum=$a+$b;
  return $sum;
}

function getArraySum($v) {
	$sum = 0;
	foreach (explode(",", $v) as $x) {
		$sum += $x;
	}
	$sum2 = 0;
	foreach (explode(" ", $v) as $x) {
		$sum2 += $x;
	}
	return max($sum, $sum2);
}

?>
