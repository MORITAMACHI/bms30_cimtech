<?php
require_once './insertIntoCart.inc';
require_once '../dto/cart.inc';
require_once '../dto/book.inc';
require_once '../dto/user.inc';

session_start();

$model = new InsertIntoCart();
$cart = new Cart();
$book = new Book();
$user = new User();

$user = $model->getUserInfo();
$book = $model->getBookData($db);
$cart = $model->intoCart($book);

require_once './insertIntoCart.phtml';
?>