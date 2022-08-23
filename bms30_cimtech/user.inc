<?php

class User{
    // フィールド変数
    private $user;
    private $password;
    private $email;
    private $authority;

    /**
     * @return string
     */
    public function getUser()
    {
        return $this->user;
    }

    /**
     * @return string
     */
    public function getPassword()
    {
        return $this->password;
    }

    /**
     * @return string
     */
    public function getEmail()
    {
        return $this->email;
    }

    /**
     * @return number
     */
    public function getAuthority()
    {
        return $this->authority;
    }

    /**
     * @param string $userid
     */
    public function setUser($user)
    {
        $this->user = $user;
    }

    /**
     * @param string $password
     */
    public function setPassword($password)
    {
        $this->password = $password;
    }

    /**
     * @param string $email
     */
    public function setEmail($email)
    {
        $this->email = $email;
    }

    /**
     * @param number $authority
     */
    public function setAuthority($authority)
    {
        $this->authority = $authority;
    }

    public function __construct(){  // 初期化
        $this -> user = '';
        $this->password = '';
        $this->email = '';
        $this->authority = 0;
    }

}

?>
