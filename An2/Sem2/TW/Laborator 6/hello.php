<?php

require "App.php";

/*main*/
$path = './images/';
$app = new App();
echo $app->run($path);

?>