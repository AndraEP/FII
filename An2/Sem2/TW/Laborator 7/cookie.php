<?php

$value = 'something from somewhere';
$name = "TestCookie";
//setcookie("TestCookie", $value);
setcookie($name, $value, time()+60);  /*3600 expire in 1 hour */
//setcookie("Cookie_name", $value, time()+3600, "/php/", "example.com", 1);

//var_dump ($_COOKIE);

if(!isset($_COOKIE[$name])) {
    echo "Cookie named '" . $name . "' is not set!";
} else {
    echo "Cookie '" . $name . "' is set!<br>";
    echo "Value is: " . $_COOKIE[$name];
}

?>
