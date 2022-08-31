<?php
class Logout{

    public function unset($user){
        session_start();
        unset($_SESSION['userInfo']);
        unset($_SESSION['cartInfo']);
    }
}
?>
