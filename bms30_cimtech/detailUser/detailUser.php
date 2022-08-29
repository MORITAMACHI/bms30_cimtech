<?php
/*
 * システム名：書籍管理システムWeb版Ver.3.0
 * 機能名：ユーザー詳細機能
 * 説明：ユーザーの詳細を確認する機能
 * 作成日：2022/8/26
 * 作成者：貝谷和則
 */
//インクルード
include '../dto/user.inc';
include ("../lib/db.inc");

$User = new User();

include("./detailUser.inc");

//オブジェクト化
$detailUser = new DetailUser();

//データの有無確認
$User = $detailUser->searchUser($db,$User);

//画面呼び出し
include 'detailUser.phtml';



?>
