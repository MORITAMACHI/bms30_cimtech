<?php
header("Content-type: text/html; charset=UTF-8");

require_once '../lib/db.inc';
require_once '../lib/util.inc';
require_once '../dto/sales.inc';
require_once 'showSalesByMonth.inc';

try {
    $obj = new uriage_model();

    $salesArray = $obj->showSales($db);

    $total = $obj->total($salesArray);

    require_once 'showSalesByMonth.phtml';

} catch (Exception $e) {
    // エラー時画面遷移
    header("location:../error/error.php?errorMsg=想定外のエラーが発生しました。");
    exit();
}


?>