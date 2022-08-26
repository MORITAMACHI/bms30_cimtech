<?php
class deleteUser{



    //削除対象のyユーザー情報の有無を検索
    public function deleteData($db,$user){

        if(isset($_GET["user"])){
            $userId = $_GET["user"];
        }else{
            return false;
        }

        $sql = "SELECT * FROM userinfo WHERE user ='{$userId}'";
        $result = executeQuery($db,$sql);

        if ($result) {

            //検索結果から結果セットの行数、ユーザー情報を取得
            $row = mysqli_fetch_array($result);

            $password=$row['password'];
            $email=$row['email'];
            $authority=$row['authority'];

            $user->setUser($userId);
            $user->setPassword($password);
            $user->setEmail($email);
            $user->setAuthority($authority);



            return $user;
        }else{
            return false;
        }



        //リソース解放
        mysqli_free_result($result);

    }


    //ユーザー削除
    public function delete($db,$user){

        if($user!==false){

            //削除処理を実行
            $sql = "DELETE FROM userinfo WHERE user ='{$user->getUser()}'";
            executeQuery($db,$sql);


            return $user;
        }

    }
}







?>