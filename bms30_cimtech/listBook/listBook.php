<?php
/*
 * システム名：書籍管理システムWeb版Ver.3.0（書籍一覧画面）
 * モジュール名：list.php
 * 説明：書籍管理システムの書籍一覧を表示する
 * 作成日：2022/08/22
 * 作成者：貝谷和則
 *
 */
//セッションの開始
session_start();
//インクルード
include ("../lib/db.inc");
include ("../lib/util.inc");
include ("listBook.inc");

try{

    //データベース接続
    if(!connectDatabase($db)){
        $errMsg = "DB接続エラーが発生しました。";
        //エラー画面に遷移
        callErrorPage($errMsg);
        exit;
    }
    //オブジェクト化
    $model = new ListBook();

    //画面項目取得
    $model->getForm();

    //処理
    $model->processing($db);

    //画面呼び出し
    include("listBook.phtml");

    //データベース切断
    closeDatabase($db);
}catch(Exception $e){
    $errMsg = "想定外のエラーが発生しました。";
    //エラー画面に遷移
    callErrorPage($errMsg);
    exit;
}

?>
