<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="ro">
<head>
<title>Portocale (exemplu de invocare via SOAP a unui serviciu Web)</title>
<style>
.cod { 
	overflow: scroll; 
	white-space: normal; 
	border: thin dotted gray;
	padding: 0.2em;
}
body {
  font-family: sans-serif;
}

</style>
</head>
<body>

<form>
  a:<br>
  <input type="text" name="a"><br>
  b:<br>
  <input type="text" name="b"><br>
  <input type="submit" value="Submit">
</form>

<br><br>

<form>
  mai multe numere separate prin virgula:<br>
  <input type="text" name="v"> <br>
  <input type="submit" value="Submit">
</form>

<?php
/* Un client SOAP scris in PHP5 invocand operatii (metode) de obtinere 
   a stocului de portocale oferite de un serviciu Web

   Autor: Sabin-Corneliu Buraga - https://profs.info.uaic.ro/~busaco/
   Ultima actualizare: 22 aprilie 2019
*/

// de inlocuit cu URL-ul la care este operational serviciul Web
define ('WS_URL', 'http://localhost/oranges/oranges-server.php'); 

try {
	$client = new SoapClient(null,   // nu furnizam niciun WSDL 
	    [ 'location' => WS_URL, // adresa serviciului Web
        'uri'			 => 'http://web.info/porto', // spatiul de nume corespunzator serviciului Web apelat
        'trace'		 => 1 // se vor furniza informatii de depanare
		  ]
  );
  
  if(isset($_REQUEST['v'])) {  
    $a = $_REQUEST['a'];
    $b = $_REQUEST['b'];
    $v = $_REQUEST['v'];

    // realizam o suita de invocari ale metodei dorite
    foreach ([ 'blue', 'gray', 'celestial' ] as $product) {
      $res = $client->__soapCall('getQuantity', [ $product ]);
      // afisam si cererea si raspunsul SOAP incapsulate in documente XML 
      echo 'SOAP request:<pre class="cod">' . 
        htmlspecialchars($client->__getLastRequest(), ENT_QUOTES) . '</pre>';
      echo 'SOAP response:<pre class="cod">' . 
        htmlspecialchars($client->__getLastResponse(), ENT_QUOTES) . '</pre>';
      echo "<p>The quantity of $product oranges is <strong>$res</strong>.</p>";
    }
    
    $sum = $client->__soapCall('getSum', [$a,$b]);
    echo "$a + $b = $sum";
    echo "<br>";

    $arraysum = $client->__soapCall('getArraySum', [ $v ]);
    echo "array sum = $arraysum";
  }
  

  /*$number1 = 2;
  $number2 = 1;

  $res_num = $client->__soapCall ('addToSum', [$number1, $number2]);
  echo 'Sum of given numbers (no array): ' . $res_num;
  echo "<br>";

  $vector_numbs = array(1, 10, 3, 4, 5);
  $sum = $client->__soapCall ('vectorSum', [$vector_numbs]);
  echo 'Sum of given numbers (with array): ' . $sum;*/

} catch (SOAPFault $exception) { // eroare :(
   echo 'An exception occurred: ' . $exception->faultstring;
}
?>
</body>
</html>
