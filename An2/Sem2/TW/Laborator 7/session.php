<?php
session_start();
if (!empty($_SESSION['session_var'])) {
  echo $_SESSION['session_var']++;
} else {
  $_SESSION['session_var'] = 1;
}

//session_destroy();
?>
