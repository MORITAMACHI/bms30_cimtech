<?php
header("Content-type: text/html; charset=UTF-8");

// セッションの利用開始
session_start();

require_once '../dto/ordered.inc';
require_once '../lib/db.inc';
require_once 'orderHistory.inc';

try {
    $obj = new OrderHistory();

    $obj->sessionCheck();

    $array = $obj->select($db);

    require_once 'orderHistory.phtml';

}catch(Exception $e){
    header("location:../error/error.php?errorMsg=想定外のエラーが発生しました。");
    exit();
}
?>
