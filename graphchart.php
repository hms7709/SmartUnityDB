<?php
    $conn = mysqli_connect('localhost', 'danielha', 'daniel123@', 'SensorDB');
?>

<html>
<head>
<title>Sensor_Data</title>
    <script type="text/javascript" src="https://www.google.com/jaspi"></script>
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <link rel = "stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <script type="text/javascript">
        google.load("visualization", "1", {packages:["corechart"]});
        google.setOnLoadCallback(drawChart);

function drawChart() {
    var data = google.visualization.arrayToDataTable([

['class Name', 'Sensor Value1'],

<?php  
    $query = "select * from sensorvalue order by Date_time desc limit 10";
    $exec = mysqli_query($conn, $query);
    while($row = mysqli_fetch_array($exec)) {
        echo "['".$row['Date_time'],"',".$row['Temperature']."],";
    }
    ?>
]);

var options = {
    title = 'Temperature',
    colors: ['red'],
    pieHole: 0.5,
        pieSliceTextStyle: {
            color: 'black',
        },
        legend: 'none',
};

var chart = new google.visualization.LineChart(document.getElementById("columnchart12"));
chart.draw(data, options);
}
</script>

</head>
<body>
    <div class="container-fluid">
    <div id="columnchart12" style="width: 100%; height: 500px"></div>    
</div>

<script type="text/javascript">
google.load("visualization", "2", {packages:["corechart"]});
google.setOnLoadCallback(drawChart);

function drawChart(){
    var data = google.visualization.arrayToDataTable([

['class Name', 'Sensor Value2'],

<?php
    $query = "select * from sensorvalue order by Date_time desc limit 10";
    $exec = mysqli_query($conn, $query);
    while($row = mysqli_fetch_array($exec)){
        echo "['".$row['Date_time']."',".$row['Humidity']."],";
    }
    ?>
]);

var options = {
    title: 'Humidity',
    colors: ['blue'],
    pieHole: 0.5,
        pieSliceTextStyle: {
            color: 'black',
        },
        legend: 'none'
};
var chart = new google.visualization.LineChart(document.getElementById("columnchart22"));
chart.draw(data, options);   
}
</script>
</head>

<body>  
    <div class="container-fluid">
    <div id="columnchart22" style="width: 100%; height: 500px;"></div>
</div>

<script type="text/javascript">
google.load("visualization", "3", {packages:["corechart"]});
google.setOnLoadCallback(drawChart);

function drawChart() {
    var data = google.visualization.arrayToDataTable([

['class Name', 'Sensor Value3'],

<?php
    $query = "select * from sensorvalue order by Date_time desc limit 10";
    $exec = mysqli_query($conn, $query);
    while($row = mysqli_fetch_array($exec)){
        echo "['".$row['Date_time']."',".$row['Cdsvalue']."],";
    }
    ?>
]);

var options = {
    title: 'Brightness',
    colors: ['green'],
    pieHole: 0.5,
        pieSliceTextStyle: {
            color: 'black',
        },
        legend: 'none'
};
var chart = new google.visualization.LineChart(document.getElementById("columnchart32"));
chart.draw(data, options);
}

</script>
</head>
<body>
    <div class="container-fluid">
    <div id="columnchart32" style="width: 100%; height: 500px;"></div>
</div>

</body>
</html>



