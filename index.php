<!DOCTYPE html>
<html lang="en">

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0, user-scalable=no">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="msapplication-tap-highlight" content="no">
	<meta name="description" content="Materialize is a Material Design Admin Template,It's modern, responsive and based on Material Design by Google. ">
	<meta name="keywords" content="materialize, admin template, dashboard template, flat admin template, responsive admin template,">
	<title>Listas de acesso</title>

	<!-- CORE CSS-->
	<link href="css/materialize.min.css" type="text/css" rel="stylesheet" media="screen,projection">
	<link href="css/style.min.css" type="text/css" rel="stylesheet" media="screen,projection">
	<!-- Custome CSS-->
	<link href="css/custom/custom.min.css" type="text/css" rel="stylesheet" media="screen,projection">

	<!-- INCLUDED PLUGIN CSS ON THIS PAGE -->
	<link href="js/plugins/prism/prism.css" type="text/css" rel="stylesheet" media="screen,projection">
	<link href="js/plugins/perfect-scrollbar/perfect-scrollbar.css" type="text/css" rel="stylesheet" media="screen,projection">
	<link href="js/plugins/chartist-js/chartist.min.css" type="text/css" rel="stylesheet" media="screen,projection">
</head>
<body>

	<header id="header" class="page-topbar">
		<!--NavBar-->
		<div class="navbar-fixed">
			<nav>
				<div class="nav-wrapper green darken-1">
					<h4 class="brand-logo">Lab APR - Experimento 10 </h4>
				</div>
			</nav>
		</div>
		<!--NavBar-->
	</header>

	<!-- START MAIN -->
	<div id="main">
		<!-- START WRAPPER -->
		<div class="wrapper">

			<!-- START LEFT SIDEBAR NAV-->
			<aside id="left-sidebar-nav">
				<ul id="slide-out" class="side-nav fixed leftside-navigation">
					<li>
						<div class="row">
							<div class="col col s8 m8 l8">
								<a>Caio Moreira</a>
								<a>Vinicius Oliveira</a>
							</div>
						</div>
					</li>
					<!-- Aqui começa a navbar lateral-->
					<li class="bold"><a href="index.php" class="waves-effect waves-cyan"><i class="mdi-image-wb-sunny"></i> Forecast API simulation</a>
					</li>

					<li class="bold"><a href="lista_cidade.php" class="waves-effect waves-cyan"><i class="mdi-action-search"></i>Lista de cidades</a>
					</li>

				</ul>
			</div>




			<!-- acaba aqui por enquanto-->
		</aside>
		<!-- END LEFT SIDEBAR NAV-->

		<!-- //////////////////////////////////////////////////////////////////////////// -->

		<!-- START CONTENT -->
		<section id="content">




			<!--start container-->
			<div class="container">
				<div class="section">
					<div class="row">

						<!-- Início do primeiro card-->


						<h5>API de previsão do tempo  -  Open Weather Map  </h5>
						<?php 
								//if ($_POST) {
									$resposta = file_get_contents("php://input");
									//$resposta 	= json_decode($_POST, true);
									var_export($resposta);
								//}
								
						?>

						<div class="divider"></div>
						<div class="card panel white col s12">
							<form action="./controle.php" method="POST">
								<div class="container">
									<div class="row" >
										<div class="input-field col s6">
											<input placeholder="Cidade" name="cidade" type="text" class="validate">
										</div>

										<div class="input-field col s2">
											<input  name="pais" type="text" placeholder="País (ex: BR)" class="validate">
										</div>
										<div class="input-field col s4">
											<select name="apikey">
												<option value="c3564bb2efb1702ef9eb41ed2af91453">Key 1</option>
												<option value="af1f6358ef485bd265bc1fb3c1834f81">Key 2</option>
											</select>
										</div>
									</div>
									<div class="row">
										<div class="input-field col s6">
											<button type="submit" style="background-color:yellow;color:black; width: 200px; height: 100%; border: 2px solid #eee;">Consultar</button>
											<br></br>
										</div>
									</div>

								</div>
							</form>
							
						</div>
						<div class="card panel white col s12">
							<div class="input-field col s6">
								<input placeholder="Cidade" name="cidade" type="text" class="validate">
							</div>
						</div>
					</div>
				</div>

    <!-- ================================================
    Scripts
    ================================================ -->

    <!-- jQuery Library -->
    <script type="text/javascript" src="js/plugins/jquery-1.11.2.min.js"></script>
    <!--materialize js-->
    <script type="text/javascript" src="js/materialize.min.js"></script>
    <!--prism
    	<script type="text/javascript" src="js/prism/prism.js"></script>-->
    	<!--scrollbar-->
    	<script type="text/javascript" src="js/plugins/perfect-scrollbar/perfect-scrollbar.min.js"></script>
    	<!-- chartist -->
    	<script type="text/javascript" src="js/plugins/chartist-js/chartist.min.js"></script>

    	<!--plugins.js - Some Specific JS codes for Plugin Settings-->
    	<script type="text/javascript" src="js/plugins.min.js"></script>
    	<!--custom-script.js - Add your own theme custom JS-->
    	<script type="text/javascript" src="js/custom-script.js"></script>

    </body>

    </html>