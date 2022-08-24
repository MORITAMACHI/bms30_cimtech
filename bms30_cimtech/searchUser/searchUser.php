<?php
header("Content-type: text/html; charset=UTF-8");

require_once '../lib/db.inc';
require_once '../dto/user.inc';
require_once 'searchUser.inc';
$user = new User();
$obj = new SearchUser();

try {
    session_start();

    $obj->sessionCheck();

    $user = $obj->search($db, $user);

    require_once 'searchUser.phtml';
}catch (Exception $e){
    header("location:../error/error.php?errorMsg=想定外のエラーが発生しました。");
    exit();
}
?>
