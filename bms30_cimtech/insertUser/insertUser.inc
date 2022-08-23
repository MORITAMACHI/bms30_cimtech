<?php
class insertUser{

//データ取得
public function getForm($user){
    //ユーザーID
    if(isset($_POST['userid'])){
        $user->setUserid($_POST['userid']);
    }
    //パスワード
    if(isset($_POST['password'])){
        $user->setPassword($_POST['password']);
    }
    //メールアドレス
    if(isset($_POST['email'])){
        $user->setEmail($_POST['email']);
    }
    //権限
    if(isset($_POST['authority'])){
        $user->setAuthority($_POST['authority']);
    }
}

/*
 *重複チェック
 * public function processing($db){
    //処理種別で実行する判断
    if(strlen($this->getExecute()) == 0){
        //初期起動時は何もしない
    }elseif($this->getExecute() == "登録"){
        //入力ユーザーIDの重複チェック
        $rtn = $this->searchUserid($db);

        if($rtn === false){
            //ユーザーID重複の為エラーメッセージ
            $errMsg = "重複しているため、登録は出来ませんでした";

            //エラー画面に遷移
           header("Location: http://localhost/bms30_cimtech/error.php?errMsg={$errMsg}");
            exit;
        }else{
            //入力データを登録処理
            $this->insert($db);
        }
    }
}
 */

public function insert($user,$db){
    $userid = $user->getUserid();
    $password = $user->getPassword();
    $email = $user->getEmail();
    $authority = $user->getAuthority();

    $sql = "INSERT INTO userinfo VALUES('{$userid}', '{$password}', '{$email}', '{$authority}')";

    executeQuery($db,$sql);
}



}
?>