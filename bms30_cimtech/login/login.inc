<?php
/*
 * ログイン機能
 */
require '../dto/user.inc';
require '../lib/db.inc';

class Login
{

    private $errMsg;

    public function __construct(){
        $this->init();
    }

    public function init(){
        $this->errMsg = "";
    }

    public function setErrMsg($errMsg){
        $this->errMsg = $errMsg;
    }

    public function getErrMsg(){
        return $this->errMsg;
    }

        /*
     * 入力情報を取得するメソッド
     */
    public function getForm()
    {
        $User = new User();
            if (isset($_POST['user'])) {
                $User->setUser($_POST['user']);
            }
            if (isset($_POST['password'])) {
                $User->setPassword($_POST['password']);
            }
            return $User;

    }

    /*
     * DBに登録データがあるか確認
     */
    public function searchUser($User)
    {
        if (isset($_POST['login'])) {
            // SQL
            $sql = "SELECT * FROM userinfo WHERE user = '{$User->getUser()}' AND password = '{$User->getPassword()}'";
            $result = executeQuery($db, $sql);
            $row = mysqli_num_rows($result);

            if ($row > 0) {
                session_start();
                $user = mysqli_fetch_array($result);
                $_SESSION['userInfo'] = $user;
                setcookie("user",$User->getUser(),(time() + 30 * 86400),'/');
                setcookie("password",$User->getPassword(),(time() + 30 * 86400),'/');
                header('Location: ../menu/menu.php');
                exit();
            } else {
                $errMsg = "ユーザー名またはパスワードが間違っています。";
                return $errMsg;
            }
        }
    }
}
?>