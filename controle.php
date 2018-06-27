<?php 

	//recebe as variaveis do formulario por POST
$cidade   					= $_POST['cidade'];
$pais			   			= $_POST['pais'];
$apikey			   			= $_POST['apikey'];

$url = "api.openweathermap.org/data/2.5/weather?q=".$cidade.",".$pais."&APPID=".$apikey;

$curl = curl_init();

curl_setopt_array($curl, array(
	CURLOPT_URL => $url,
	CURLOPT_RETURNTRANSFER => true,
	CURLOPT_ENCODING => "",
	CURLOPT_MAXREDIRS => 10,
	CURLOPT_TIMEOUT => 30,
	CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
	CURLOPT_CUSTOMREQUEST => "POST",
	CURLOPT_HTTPHEADER => array(
		"Content-Type:application/json; charset=ISO-8859-1"
		),
	));
			$resposta = curl_exec($curl);
			
			$data = json_decode($resposta);
			
			$obj_main 	= $data->main;
			//$obj_weather= $data->weather;
			$temp 		= $obj_main->temp;
			$temp_max 	= $obj_main->temp_max;
			$temp_min 	= $obj_main->temp_min;
			$humidity 	= $obj_main->humidity;
			//$description= $obj_weather->description;
			$name 		= $data->name;

			//conversion of kelvin values to celcius
			$temp 		= ($temp - 273.15);
			$temp_min 	= ($temp_min - 273.15);
			$temp_max 	= ($temp_max - 273.15);



    $pdo = new PDO("mysql:host=localhost;dbname=api_forecast","root","");

    echo $sql = "INSERT INTO `current`(`temperature`, `temp_min`, `temp_max`, `humidity`, `name`) 
    		VALUES ('$temp', '$temp_min', '$temp_max', '$humidity', '$name')";

	$stmt = $pdo->prepare($sql);
	$stmt->execute();
	
	if($stmt->rowCount()>0){		
		$resultado = $stmt->fetch(PDO::FETCH_OBJ);
		var_export($resultado);
	}
  

	
	// header('Location: ./index.php?');
	// die();
?>