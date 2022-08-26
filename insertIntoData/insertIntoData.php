<?php
require_once './insertIntoData.inc';
require_once '../dto/user.inc';

$model = new InsertIntoData();
$User = new User();

$User = $model->getUserInfo();
$model->checkBookData($db);
$model->insertBookData($db);
$booklist = $model->getInitialData($db);

require_once './insertIntoData.phtml';
?>