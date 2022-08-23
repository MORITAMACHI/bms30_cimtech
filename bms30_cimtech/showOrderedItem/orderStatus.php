<?php
require_once '../dto/Ordered.inc';
$ordered = new Ordered();

require_once 'orderStatus.inc';
$orderStatus = new OrderStatus();

require_once '../lib/db.inc';
require_once '../lib/util.inc';

//購入情報を取得
$orderedArray = $orderStatus->OrderedSearch($db);

//画面呼出し
include ("orderStatus.phtml");
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>

    </body>
</html>