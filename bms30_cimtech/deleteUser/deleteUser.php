<?php
require_once '../dto/user.inc';
require_once '../lib/db.inc';

$user = new User();

require_once './deleteUser_model.inc';

$deleteUser = new deleteUser();


//データの有無確認
$user = $deleteUser->deleteData($db,$user);

//入力データを登録処理
$user =  $deleteUser->delete($db,$user);

//画面呼び出し
include ("deleteUser.phtml");

?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>

    </body>
</html>