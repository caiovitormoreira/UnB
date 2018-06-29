<?php 

	//recebe as variaveis do formulario por POST
$cidade   					= $_POST['cidade'];
$pais			   			= $_POST['pais'];
$apikey			   			= $_POST['apikey'];

//checando se a variavel é numerica
if ((is_numeric($cidade)) OR (is_numeric($pais))) {
	$retorno_get.= "erro2=1&";
	header('Location: ./index.php?'.$retorno_get);
	die();
}

######## PROCEDIMENTO DE INSERT DOS DADOS DO WEATHER #########
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
			
			$temp 		= $data->main->temp;
			$temp_max 	= $data->main->temp_max;
			$temp_min 	= $data->main->temp_min;
			$humidity 	= $data->main->humidity;
			$name 		= $data->name;
			$country	= $data->sys->country;
			$code		= $data->cod;
			
			$description = $data->weather;
			$description = $description['0'];
			$description = $description->description;
			//var_export($description);

			//conversion of kelvin values to celcius
			$temp 		= ($temp - 273.15);
			$temp_min 	= ($temp_min - 273.15);
			$temp_max 	= ($temp_max - 273.15);



    $pdo = new PDO("mysql:host=localhost;dbname=api_forecast","root","");

    echo $sql = "INSERT INTO `current`(`temperature`, `temp_min`, `description`, `temp_max`, `humidity`, `name`, `country`) 
    		VALUES ('$temp', '$temp_min', '$description', '$temp_max', '$humidity', '$name', '$country')";

	$stmt = $pdo->prepare($sql);
	$stmt->execute();

######## FIM DO PROCEDIMENTO DE INSERT DOS DADOS DO WEATHER #########

######## INICIO DO INSERT DE DADOS DO FORECAST #########	

######## FIM DO INSERT DE DADOS DO FORECAST #########	
	
	
	if($code == 200){		
		$retorno_get.= "sucesso_registro=1&";
		header('Location: ./index.php?'.$retorno_get);
		die();
	}
	else{
		$retorno_get.= "erro=1&";
		header('Location: ./index.php?'.$retorno_get);
		die();
	}

?>