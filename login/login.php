<?
require_once './login.inc';
require_once '../dto/user.inc';

$User = new User();
$model = new Login();

$User = $model->getForm();
$result = $model->searchUser($User);

include './login.phtml';
?>