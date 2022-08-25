<?php
require_once '../dto/book.inc';
require_once '../lib/db.inc';

$book = new Book();

require_once './detailBook_model.inc';

$detailBook = new detailBook();


//フォームから情報を取得
// $book = $detailBook->getForm($book);

//データの有無確認
$book = $detailBook->detailData($db,$book);


//画面呼出し
include ("detailBook.phtml");

?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>

    </body>
</html>