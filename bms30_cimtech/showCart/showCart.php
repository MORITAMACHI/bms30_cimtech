<?php
require_once '../dto/Cart.inc';
$sales = new Sales();

require_once 'showCart.inc';
$showCart = new ShowCart();

require_once '../lib/util.inc';

//セッションの開始
session_start();

//書籍情報を削除
$showCart->DeleteBook();


//画面呼出し
include ("showCart.phtml");
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>

    </body>
</html>
