<?php
require_once '../dto/Sales.inc';
$sales = new Sales();

require_once 'showCart.inc';
$showCart = new ShowCart();

require_once '../lib/util.inc';

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