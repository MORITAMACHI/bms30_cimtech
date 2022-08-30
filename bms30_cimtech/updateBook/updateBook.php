<?php
/*
 * システム名：upadate.php
 * 説明：書籍更新画面を表示する
 * 作成日：2022/08/23
 * 作成者：貝谷和則
 */

//インクルード
include_once ("../lib/db.inc");
include_once ("../lib/util.inc");
include_once ("./updateBook.inc");

try{
    //データベース接続
    if(!connectDatabase($db)){
        $errMsg = "DB接続エラーが発生しました。";
        //エラー画面へ遷移する
        callErrorPage($errMsg);
        exit;
    }

    //クラスをインスタンス化
    $model = new UpdateBook();

    //画面項目取得
    $model->getForm();

    //処理
    $model->processing($db);

    //画面呼出し
    include ("updateBook.phtml");

    //データベース切断
    closeDatabase($db);

}catch(Exception $e){
    $errMsg = "想定外のエラーが発生しました。";
    //エラー画面へ遷移する
    callErrorPage($errMsg);
    exit;
}
?>
