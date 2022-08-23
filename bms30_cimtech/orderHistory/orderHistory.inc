<?php
/*
 *  ユーザーの購入履歴確認のためのモデルクラス
 *  作成者：たけだ
 */

class OrderHistory{


    /* セッションにユーザーテーブル一行分が格納されている
     * →セッション保持かどうか確認するメソッド
     */
    function sessionCheck (){
        if (! isset($_SESSION['user'])) { // セッション非保持時
            header("Location:../login/login.php?errorMsg=セッション切れです。ログインしてください");
            exit();
        }
    }

    /** 概要：ユーザーの個人IDより、過去の購入履歴を確認する
     *
     */
    public function select($db) {
        $sql = "SELECT b.title,o.quantity,o.date FROM orderinfo o inner join bookinfo b on o.isbn=b.isbn
            WHERE o.user = '{$_SESSION['user']['user']}'";

        $result = executeQuery($db, $sql);
        if(mysqli_num_rows($result) > 0){
            while($row = mysqli_fetch_array($result)){
                $order = new Ordered();

                $order->setTitle($row['title']);
                $order->setQuantity($row['quantity']);
                $order->setDate($row['date']);

                $orderArray[] = $order;
            }
            return $orderArray;
        }
    }

    /** 概要：日付フォーマット 〇〇月〇〇日の形へ～
     *
     */
    public function dateFormat($date){

    }
}
?>
