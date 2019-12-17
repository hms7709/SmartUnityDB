<?php
$servername = "localhost";
$username = "danielha";
$password = "daniel123@";
$dbname = "SensorDB";

$conn = mysqli_connect($servername, $username, $password, $dbname);

$Temperature = $_GET['Temperature'];
$Humidity = $_GET['Humidity'];
$Cdsvalue = $_GET['Cdsvalue'];
$sql = "INSERT INTO sensorvalue(Temperature, Humidity, Cdsvalue) VALUES($Temperature, $Humidity, $Cdsvalue)";

mysqli_query($conn, $sql);
mysqli_close($conn);
?>