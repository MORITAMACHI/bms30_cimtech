<?php
/*
 * システム名：書籍管理システムWeb版Ver.3.0
 * 機能名：ユーザー更新機能
 * 説明：ユーザーの情報を変更するための機能
 * 作成日：2022/8/26
 * 作成者：貝谷和則
 */

class UpdateUser{

    //フィールド変数の定義
    private $user;  //ユーザー名
    private $password;  //パスワード
    private $email;  //メールアドレス
    private $authority;  //権限
    private $userInfo;  //ユーザー情報
    private $execute;  //処理種別

    //コンストラクタ
    public function __construct(){
        $this->init();
    }
    //フィールド変数の初期化
    public function init(){
        $this->user = "";
        $this->password = "";
        $this->email = "";
        $this->authority = "";
        $this->userInfo = "";
        $this->execute = "";
    }
    //セッターメソッド
    public function setUser($param){
        $this->user = $param;
    }
    public function setPassword($param){
        $this->password = $param;
    }
    public function setEmail($param){
        $this->email = $param;
    }
    public function setAuthority($param){
        $this->authority = $param;
    }
    public function setUserInfo($param){
        $this->userInfo = $param;
    }
    public function setExecute($param){
        $this->execute = $param;
    }
    //ゲッターメソッド
    public function getUser(){
        return $this->user;
    }
    public function getPassword(){
        return $this->password;
    }
    public function getEmail(){
        return $this->email;
    }
    public function getAuthority(){
        return $this->authority;
    }
    public function getUserInfo(){
        return $this->userInfo;
    }
    public function getExecute(){
        return $this->execute;
    }

    public function getForm() {
        //ユーザー名
        if (isset($_POST['user'])){
            $this->user=$_POST['user'];
        }else if(isset($_GET['user'])){
            $this->user=$_GET['user'];
        }
        //パスワード
        if (isset($_POST['password'])){
            $this->password=$_POST['password'];
        }
        //メールアドレス
        if (isset($_POST['email'])){
            $this->email=$_POST['email'];
        }
        //権限
        if (isset($_POST['authority'])){
            $this->authority=$_POST['authority'];
        }
        //ユーザー一覧
        if (isset($_POST['userInfo'])){
            $this->userInfo=$_POST['userInfo'];
        }
        //処理種別
        if (isset($_POST['execute'])){
            $this->execute=$_POST['execute'];
        }
    }
    public function processing($db) {
        //変更対象のユーザー情報を取得する
        $this->searchUser($db);
        //処理種別を判定
        if($this->getExecute() == ""){
            /* 初期遷移処理 */

            //変更対象データが取得出来たか判断
            if($this->getUserInfo() == null){
                //エラーメッセージを設定
                $errMsg = "更新対象の書籍は存在しない為、更新処理は行なえませんでした。ここ！";

                //エラー画面へ遷移する
                callErrorPage($errMsg);

                exit;

            }else{
                //初期表示用のタイトルと価格をセットする
                //$book = $this->getBookInfo();
                //$this->setTitle($book[title]);
                //$this->setPrice($book[price]);
            }

        }else{
            /* 変更完了ボタン押下からの処理 */
            //変更対象データが取得出来たか判断
            if($this->getUserInfo() == null){
                //エラーメッセージを設定
                $errMsg = "更新対象の書籍は存在しない為、更新処理は行なえませんでした。ボタンは押せた";

                //エラー画面へ遷移する
                callErrorPage($errMsg);

                exit;
            }

            //更新処理を実行
            $this->update($db);
        }
    }
    public function searchUser($db){
        $sql  = "";
        $row  = null;

        //抽出SQL生成
        $sql  = "SELECT *";
        $sql .= " FROM userinfo";
        $sql .= " WHERE user =".createSqlString($this->user);

        //SQL文の表示
        //echo $sql;

        //SQL発行
        $result = mysqli_query($db, $sql);

        //該当ISBNデータを取得
        $this->userInfo = mysqli_fetch_assoc($result);

        //リソースの開放
        mysqli_free_result($result);

    }
    public function update($db){
        $sql  = "";
        $row  = null;

        //抽出SQL生成
        $sql  = "UPDATE userinfo SET";
        $sql .= " password=".createSqlString($this->password).",";
        $sql .= " email=".createSqlString($this->email).",";
        $sql .= " authority=".$this->authority;
        $sql .= " WHERE user=".createSqlString($this->user);


        //echo $sql;

        //SQL発行
        $result = mysqli_query($db, $sql);

    }
}
?>

