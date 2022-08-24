<?php

require_once '../dto/user.inc';
// ユーザー情報をインスタンス化
$user = new User();

session_start();

require_once 'changePassword.inc';
require_once ("../lib/db.inc");
require_once ("../lib/util.inc");
require_once '../searchUser/searchUser.inc';
$searchObj = new SearchUser();

$searchObj->sessionCheck();

$obj = new changePassword();

$user = $obj->getUser($user);   // 遷移元からのユーザー情報が入っているオブジェクト

$result = $obj->checkParameter($user);

require_once 'changePassword.phtml';


?>
