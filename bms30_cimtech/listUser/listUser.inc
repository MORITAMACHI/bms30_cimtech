<?php
require '../dto/user.inc';
require '../lib/db.inc';

class listUser{

    /*
     * ユーザー情報取得メソッド
     */
    public function getUserInfo()
    {

        // ユーザークラスのオブジェクト生成
        $user = new User();

        // セッションからユーザー情報取得
        $userInfo = $_SESSION['userInfo'];
        if(isset($userInfo)){
            $user->setUser($userInfo['user']);
            if($userInfo['authority'] == 1){
                $authority = "一般ユーザー";
                $user->setAuthority($authority);
            }else{
                $authority = "管理者";
                $user->setAuthority($authority);
            }
        }else{
            $errMsg = "セッション切れの為、ログインし直してください。";
            header("Location: ../error/error.php?errMsg={$errMsg}");
            exit;
        }

        return $user;
    }

    /*
     * ユーザー一覧取得メソッド
     */
    public function selectAllUser($db){
        //userオブジェクト格納用配列変数
        $userList = array();

        //SQL
        $sql = "SELECT * FROM userinfo";
        $result = executeQuery($db, $sql);

        while($rows = mysqli_fetch_array($result)){
            $user2 = new User();

            $user2->setUser($rows['user']);
            $user2->setPassword($rows['password']);
            $user2->setEmail($rows['email']);
            if($rows['authority'] == 1){
                $authority = "一般ユーザー";
                $user2->setAuthority($authority);
            }else{
                $authority = "管理者";
                $user2->setAuthority($authority);
            }

            $userList[] = $user2;
        }

        return $userList;
    }
}
?>