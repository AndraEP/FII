<?php
$dir = "images";
$files = glob ($dir . "/*.jpg");
foreach ($files as $image)
echo "<img src=\"" .$image. "\">";
?>