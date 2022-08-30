<?php
  if(isset($_GET['ERR'])){
    $msg = $_GET['ERR'];
  }elseif(isset($_GET['errMsg'])){
	  $msg = $_GET['errMsg'];
  }

?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>
    <div align="center">
    	<h1>書籍管理システム3.0版（シムテック)</h1>
    	<hr color="red">
    	<h3>エラー</h3>
    	<hr style="margin-bottom: 20px;">
    	<?=$msg?>
	    <a href="../menu/menu.php">メニューへ</a>
    </div>


    </body>
</html>
