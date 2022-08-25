<?php
require_once './listUser.inc';
require_once '../dto/user.inc';
require_once '../lib/db.inc';

$User = new User();
$model = new listUser();;
$User = $model->getUserInfo();
$userList = $model->selectAllUser($db);

include './listUser.phtml';
?>