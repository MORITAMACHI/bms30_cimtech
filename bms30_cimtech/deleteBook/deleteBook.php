<?php
require_once '../dto/book.inc';
require_once '../lib/db.inc';

$book = new Book();

require_once './deleteBook_model.inc';

$deleteBook = new deleteBook();


//フォームから情報を取得
// $book = $deleteBook->getForm($book);

//データの有無確認
$book = $deleteBook->deleteData($db,$book);

//入力データを登録処理
$book =  $deleteBook->delete($db,$book);

//画面呼出し
include ("deleteBook.phtml");

?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
	</head>
    <body>

    </body>
</html>