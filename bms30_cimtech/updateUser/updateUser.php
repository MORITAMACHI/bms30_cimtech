<?php
/*
 * システム名：書籍管理システムWeb版Ver.3.0
 * 機能名：ユーザー更新機能
 * 説明：ユーザー更新画面を表示する
 * 作成日：2022/08/26
 * 作成者：貝谷和則
 */
//セッションの開始
session_start();

//インクルード
include_once ("../lib/db.inc");
include_once ("../lib/util.inc");
include_once ("./updateUser.inc");

try{
    //データベース接続
    if(!connectDatabase($db)){
        $errMsg = "DB接続エラーが発生しました。";
        //エラー画面へ遷移する
        callErrorPage($errMsg);
        exit;
    }

    //クラスをインスタンス化
    $model = new UpdateUser();

    //画面項目取得
    $model->getForm();

    //処理
    $model->processing($db);

    //画面呼出し
    include ("updateUser.phtml");

    //データベース切断
    closeDatabase($db);

}catch(Exception $e){
    $errMsg = "想定外のエラーが発生しました。";
    //エラー画面へ遷移する
    callErrorPage($errMsg);
    exit;
}
?>