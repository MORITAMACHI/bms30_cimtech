<?php
//セッションの開始
session_start();

class ShowCart{

    //削除リンクから戻ってきている場合、書籍情報を削除
    public function DeleteBook(){

        if(isset($_GET['delno'])){
            unset($_SESSION['cartInfo'][$_GET['delno']]);
        }
    }

}
?>