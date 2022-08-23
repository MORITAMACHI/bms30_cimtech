<?php
require_once '../dto/user.inc';
$user = new User();

require_once 'insertUser.inc';
$insertUser = new insertUser();

require_once '../lib/db.inc';
require_once '../lib/util.inc';


//フォームから情報を取得
$insertUser->getForm($user);

//入力データを登録処理
$insertUser->insert($user, $db);

//画面呼出し
include ("insertUser.phtml");
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>

    </body>
</html>