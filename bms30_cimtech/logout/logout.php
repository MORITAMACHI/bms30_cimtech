<?php

require_once 'logout.inc';
require_once '../lib/db.inc';
require_once '../lib/util.inc';

$Logout = new Logout();

$Logout->unset($user);

//画面呼び出し
include ("logout.phtml");
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>

    </body>
</html>