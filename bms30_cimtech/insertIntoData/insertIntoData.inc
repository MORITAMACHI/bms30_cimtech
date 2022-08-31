<?php
/*
 * 初期データ登録
 */
require_once '../lib/db.inc';
require_once '../dto/user.inc';
require_once '../dto/book.inc';

class InsertIntoData{

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
     * DBに書籍データが登録されているかちぇえくする関数
     */
    public function checkBookData($db){
        //SQL
        $sql = "SELECT * FROM bookinfo";
        $result = executeQuery($db, $sql);
        $rows = mysqli_num_rows($result);
        if($rows){
            $errMsg = "書籍データが既に存在するため、初期データは登録できません。";
            header("Location: ../error/error.php?ERR={$errMsg}");
            exit;
        }
    }

    /*
     * csvの初期データをDBに登録する関数
     */
    public function insertBookData($db){
        if(file_exists("../file/initial_data.csv")){
            //ファイル読み込み
            $fp = fopen("../file/initial_data.csv", "r");
            //配列宣言
            $booklist = array();

            //1行ごとのデータを配列に格納
            while(!feof($fp)){
                $book = fgetcsv($fp);
                $booklist[] = $book;
            }

            //csvのデータが格納された配列をDBへ登録
            foreach($booklist as $val){
                $sql = "INSERT INTO bookinfo VALUES('{$val[0]}', '{$val[1]}', {$val[2]})";
                executeQuery($db, $sql);
            }
            fclose($fp);
        }
    }

    /*
     * 登録したデータを取得
     */
    public function getInitialData($db)
    {
        // データ格納用配列
        $booklist = array();

        // SQL
        $sql = "SELECT * FROM bookinfo";
        $result = executeQuery($db, $sql);
        $rows = mysqli_num_rows($result);

        if ($rows) {
            while ($rows = mysqli_fetch_array($result)) {
                $book = new Book();
                $book->setIsbn($rows['isbn']);
                $book->setTitle($rows['title']);
                $book->setPrice($rows['price']);

                $booklist[] = $book;
            }
        }
        return $booklist;
    }
}
?>
