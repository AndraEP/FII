<?php

$host = 'localhost';
$user = 'root';
$pass = '';
$db = 'stud';

$dsn = "mysql:host=$host;dbname=$db";
$opt = [
    PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    PDO::ATTR_PERSISTENT 		 => TRUE
];

session_start();
if (!empty($_SESSION['session_var'])) {
    echo $_SESSION['session_var']++;
} else {
    $_SESSION['session_var'] = 1;
}

//session_destroy();

try {
	$new_pdo = new PDO ($dsn, $user, $pass, $opt);

	$query = "SELECT * FROM images";
	$sql = $new_pdo->prepare($query);
	$partial_result = $sql->execute();

	if ($partial_result) {
	 	while ($row = $sql->fetch()) {
	 		/**echo '<p>' . "ID: " . $row["id"] . "; Name: " . $row["name"] . "; Image: " . $row["path"] . '.</p>';**/
	 		echo '<p>' . "ID: " . $row["id"] . "; Name: " . $row["name"] . "; Image: " . "<img src=\"" . $row["path"] . "\">" . '</p>';
	 	}
	 }
	 else echo "The query was not executed.";

} catch (PDOException $e) {
	echo "Connection failed: " . $e->getMessage();
	exit; 
}

?>
