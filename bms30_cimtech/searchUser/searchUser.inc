<?php
/*
 * listUserからの検索ボタン押下時遷移
 * 該当ユーザー名を持つユーザーのデータを一件のみ取得
 *
 * 作成者：武田
 *
 */

class SearchUser{

    /** 概要：該当のユーザーIDが押下時、検索した結果をオブジェクトに格納して返す
     *
     * @return object
     */
    function search($db,$user){
        // 遷移元：listUserのform
        if(isset($_POST['search'])){    //検索ボタン押下時

            $sql = "select * from userinfo where user like '%{$_POST['user']}%' ";

            $result = executeQuery($db, $sql);
            if($result){
                while($row = mysqli_fetch_array($result)){
                    $user->setUser($row['user']);
                    $user->setEmail($row['email']);

                    $user->setAuthority($this->changeString($row['authority']));
                }

                //結果保持用メモリを開放する
                mysqli_free_result($result);
                return $user;
            }
        }
    }

    /** 概要：引数で与えられた数字をもとに、権限を文字列で返すメソッド
     *
     */
    public function changeString($num){
        if($num == 1){
            return '管理者';
        }elseif($num == 2){
            return '一般ユーザー';
        }else{
            // 0ならば初期化されたまま、他の数字はなぞ
            return false;
        }
    }

    // セッション保持か確認
    function sessionCheck (){
        if (! isset($_SESSION['userInfo'])) { // セッション非保持時
            header("Location:../login/login.php?errorMsg=セッション切れです。ログインしてください");
            exit();
        }
    }
}
?>
