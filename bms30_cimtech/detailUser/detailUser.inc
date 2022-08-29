<?php
class DetailUser{



    //書籍情報の有無を検索
    public function searchUser($db,$User){

        if(isset($_POST["user"])){
            $user = $_POST["user"];
        }else{
            $user = $_GET["user"];
        }

        $sql = "SELECT * FROM userinfo WHERE user ='{$user}'";
        $result = executeQuery($db,$sql);


        //検索結果から結果セットの行数、書籍の情報(タイトルと価格)を取得
        $row = mysqli_fetch_array($result);

        $password=$row['password'];
        $email=$row['email'];
        $authority=$row['authority'];

        $User->setUser($user);
        $User->setPassword($password);
        $User->setEmail($email);
        $User->setAuthority($authority);

        //リソース解放
        mysqli_free_result($result);

        return $User;

        }
    }

?>
