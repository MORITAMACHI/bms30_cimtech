<?php
/*
 * 概要：Userオブジェクト
 * 作成者：森田
 */
class User{

    //各フィールド変数宣言
    private $user;
    private $password;
    private $email;
    private $authority;

    //コンストラクタ
    public function __construct(){
        $this->init();
    }

    //フィールド変数初期化
    public function init(){
        $this->user = null;
        $this->password = null;
        $this->email = null;
        $this->authority = null;
    }

    //getterメソッド宣言
    public function getUser()
    {
        return $this->user;
    }

    public function getPassword()
    {
        return $this->password;
    }

    public function getEmail()
    {
        return $this->email;
    }

    public function getAuthority()
    {
        return $this->authority;
    }

    //setterメソッド宣言
    public function setUser($user)
    {
        $this->user = $user;
    }

    public function setPassword($password)
    {
        $this->password = $password;
    }

    public function setEmail($email)
    {
        $this->email = $email;
    }

    public function setAuthority($authority)
    {
        $this->authority = $authority;
    }

}
?>