<?php
class Logout{

    public function unset($user){
        session_start();
        unset($_SESSION['user']);
        unset($_SESSION['cartInfo']);
    }
}
?>
