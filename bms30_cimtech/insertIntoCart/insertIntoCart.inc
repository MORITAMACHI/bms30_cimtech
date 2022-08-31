<?php
/*
 * カート追加機能
 */
require_once '../lib/db.inc';
require_once '../dto/user.inc';
require_once '../dto/cart.inc';

class InsertIntoCart{

    /*
     * ユーザー情報取得メソッド
     */
    public function getUserInfo()
    {

        // ユーザークラスのオブジェクト生成
        $user = new User();

        if(isset($_SESSION['userInfo'])){
            // セッションからユーザー情報取得
            $userInfo = $_SESSION['userInfo'];
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
     * 指定された書籍データを取得する関数
     */
    public function getBookData($db){
        if(isset($_POST['insertIntoCart'])){
            $book = new Book();
           $isbn = $_POST['isbn'];

           $sql = "SELECT * FROM bookinfo WHERE isbn = '{$isbn}'";
           $result = executeQuery($db, $sql);
           $row = mysqli_num_rows($result);
           if($row){
               $row = mysqli_fetch_array($result);
               $book->setIsbn($row['isbn']);
               $book->setTitle($row['title']);
               $book->setPrice($row['price']);

               return $book;
           }else{
               $errMsg = "指定された書籍データが存在しない為、書籍をカートに追加できません。";
               header("Location: ../error/error.php?{$errMsg}");
               exit;
           }
        }
    }

        /*
     * カート情報（指定書籍、指定数量、ユーザー名）をセッションに登録
     */
    public function intoCart($book)
    {
        if (isset($_POST['insertIntoCart'])) {
            if (isset($book)) {
                $quantity = (int)$_POST['quantity'];

                $cart = new Cart();
                $cart->setIsbn($book->getIsbn());
                $cart->setTitle($book->getTitle());
                $cart->setPrice($book->getPrice());
                $cart->setQuantity($quantity);

                $_SESSION['cartInfo'][] = $cart;

                return $cart;
            }
        }
    }
}
?>