<?php

$host = 'localhost';
$user = 'root';
$pass = '';
$db = 'stud';

/**$conn = new mysqli ($host, $user, $pass, $db) or die ("Unable to connect.");
echo "Connected!"; **/

//$charset = 'utf8';
//$dsn = "mysql:host=$host;dbname=$db;charset=$charset";
$dsn = "mysql:host=$host;dbname=$db";
$opt = [
    PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    PDO::ATTR_PERSISTENT 		 => TRUE
];

$year = $_REQUEST['year'] ?? 2;

try {
	$new_pdo = new PDO ($dsn, $user, $pass, $opt);

/** $new_pdo->query("SELECT * FROM students");
	echo "Executed!"; **/

	$query = "SELECT year, name, age FROM students WHERE year=? ORDER BY age";
	$sql = $new_pdo->prepare($query);
	$partial_result = $sql->execute([$year]);

	 if ($partial_result) {
	 	while ($row = $sql->fetch()) {
	 		echo '<p>' . $row['name'] . ' e in anul ' . $row['year'] . '.</p>';
	 	}
	 }
	 else echo "The query was not executed.";

/**	if ($partial_result) {
		foreach ($sql->fetchAll() as $row) {
			echo '<p>' . $row['name'] . ' e in anul ' . $row['year'] . '.</p>';
		}
	}
	//metoda foreach **/

/**	$partial_result = $sql->execute();
	$result = $sql->fetchAll(PDO::FETCH_ASSOC);
	print_r($result);
	//print in line as array**/


/** echo "\r\n";
	$query1 = "SELECT * FROM students";
	$sql1 = $new_pdo->prepare($query1);
	$partial_result1 = $sql1->execute();

	$result = $sql1->fetchAll();
	foreach($result as $output) {
		echo "Name: " . $output["name"] . "; Year: " . $output["year"] . "; ID: " . $output["id"] . "; Age: " . $output["age"] . "<br />";
	}
	//print rows for each person **/

} catch (PDOException $e) {
	echo "Connection failed: " . $e->getMessage();
	exit; 
}

?>
