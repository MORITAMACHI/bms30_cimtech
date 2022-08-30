<?php
require_once '../buyConfirm/buyConfirm.inc';
require_once '../dto/user.inc';

session_start();

$buyConfirm = new BuyConfirm();
$User = new User();

//ユーザー情報取得
$User = $buyConfirm->getUserInfo();
//セッションのカート内容を取得
$cartInfo = $buyConfirm->getCartInfo();
//DBに購入内容を登録
$buyConfirm->orderConfirm($db, $User, $cartInfo);

require_once 'buyConfirm.phtml';
?>