<?php
/*
 * 購入確定機能（buyConfirm）
 */
require_once '../dto/user.inc';
require_once '../dto/order.inc';
require_once '../lib/db.inc';
require_once '../dto/cart.inc';
//require '../lib/mail.inc';


class BuyConfirm
{
    /*
     * ユーザー情報取得メソッド
     */
    public function getUserInfo()
    {

        // ユーザークラスのオブジェクト生成
        $user = new User();

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
        return $user;
    }

    /*
     * セッションからカート内容を取得するメソッド
     */
    public function getCartInfo(){
        if(isset($_SESSION['cartInfo'])){
            $cartInfo = $_SESSION['cartInfo'];
            return $cartInfo;
        }
    }

    /*
     * カート内容をDBに登録するメソッド
     */
   public function orderConfirm($db, $User, $cartInfo){
        if(isset($cartInfo)){
            $cart = new Cart();
            foreach($cartInfo as $cart){
                $sql = "INSERT INTO orderinfo VALUES(NULL, '{$User->getUser()}', '{$cart->getIsbn()}', {$cart->getQuantity()}, now())";
                $result = executeQuery($db, $sql);
            }

            //セッション削除
            $_SESSION['cartInfo'] = array();
            unset($_SESSION['cartInfo']);
        }
    }


}
?>