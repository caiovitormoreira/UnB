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

			if($code != 200){		
				$retorno_get.= "erro=1&";
				header('Location: ./index.php?'.$retorno_get);
				die();
			}
			
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

$url2 = "api.openweathermap.org/data/2.5/forecast?q=".$cidade.",".$pais."&APPID=".$apikey;

$curl2 = curl_init();

curl_setopt_array($curl2, array(
	CURLOPT_URL => $url2,
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

	$resposta2 = curl_exec($curl2);
	$data2 = json_decode($resposta2);
	//pegando as informacoes de forecast de cada dia, à mesma hora
	$list = $data2->list;
	$dia1 = $list['0'];
	$dia2 = $list['8'];
	$dia3 = $list['16'];
	$dia4 = $list['24'];
	$dia5 = $list['32'];
	
	$name 	= $data2->city->name;
	$country= $data2->city->country;
	$t1 = ($dia1->main->temp)-273.15;
	$x1 = ($dia1->main->temp_max)-273.15;
	$n1 = ($dia1->main->temp_min)-273.15;
	$d1 = $dia1->dt_txt;
	$t2 = ($dia2->main->temp)-273.15;
	$x2 = ($dia2->main->temp_max)-273.15;
	$n2 = ($dia2->main->temp_min)-273.15;
	$d2 = $dia2->dt_txt;
	$t3 = ($dia3->main->temp)-273.15;
	$x3 = ($dia3->main->temp_max)-273.15;
	$n3 = ($dia3->main->temp_min)-273.15;
	$d3 = $dia3->dt_txt;
	$t4 = ($dia4->main->temp)-273.15;
	$x4 = ($dia4->main->temp_max)-273.15;
	$n4 = ($dia4->main->temp_min)-273.15;
	$d4 = $dia4->dt_txt;
	$t5 = ($dia5->main->temp)-273.15;
	$x5 = ($dia5->main->temp_max)-273.15;
	$n5 = ($dia5->main->temp_min)-273.15;
	$d5 = $dia5->dt_txt;

	


	
    $sql2 = "INSERT INTO `forecast`(`country`, `city`, `temp_1`, `max_1`, `min_1`, `date_1`, `temp_2`, `max_2`, `min_2`, `date_2`, `temp_3`, `max_3`, `min_3`, `date_3`, `temp_4`, `max_4`, `min_4`, `date_4`, `temp_5`, `max_5`, `min_5`, `date_5`) VALUES ('$country', '$name', '$t1', '$x1', '$n1', '$d1', '$t2', '$x2', '$n2', '$d2', '$t3', '$x3', '$n3', '$d3', '$t4', '$x4', '$n4', '$d4', '$t5', '$x5', '$n5', '$d5')";

	$stmt2 = $pdo->prepare($sql2);
	$stmt2->execute();
	echo "fim";

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