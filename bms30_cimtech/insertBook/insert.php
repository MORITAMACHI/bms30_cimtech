<?php
require_once '../dto/book.inc';
require_once '../lib/db.inc';

$book = new Book();

require_once './insert_model.inc';

$insertBook = new insertBook();


//フォームから情報を取得
$book = $insertBook->getForm($book);

//入力データを登録処理
$book = $insertBook->insert($db,$book);

//画面呼出し
include ("insert.phtml");

?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>

    </body>
</html>